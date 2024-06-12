/*
codewars: https://www.codewars.com/kata/54da539698b8a2ad76000228/train/cpp


You live in the city of Cartesia where all roads are laid out in a perfect grid. 
You arrived ten minutes too early to an appointment, so you decided to take the opportunity to go for a short walk. 
The city provides its citizens with a Walk Generating App on their phones -- everytime you press 
the button it sends you an array of one-letter strings representing directions to walk 
(eg. ['n', 's', 'w', 'e']). 
You always walk only a single block for each letter (direction) 
and you know it takes you one minute to traverse one city block, 
so create a function that will return true if the walk the app gives you will take you exactly ten minutes 
(you don't want to be early or late!) and will, of course, return you to your starting point. Return false otherwise.

Note: you will always receive a valid array containing a random assortment of direction letters
('n', 's', 'e', or 'w' only). It will never give you an empty array (that's not a walk, that's standing still!).
*/

#include <iostream>
#include <vector>
#include <unordered_map>



bool isValidWalk(const std::vector<char>& walk) 
{
    if (walk.size() != 10)
    {    return false ;    }

  int NorthSouth = 0 ;
  int EastWast = 0 ;

  for (char direction : walk)
  {
    switch (direction)
    {
    case 'n': NorthSouth++;  break;
    case 'e': EastWast++;  break;
    case 's': NorthSouth--;  break;
    case 'w': EastWast--;  break;
    }
  }

  return NorthSouth == 0 && EastWast == 0 ;

}
int main ()
{
    std::vector<char> walk = {'n', 's' ,'n', 's' ,'n', 's' ,'n', 's' ,'n', 's' };
    std::cout << std::boolalpha << isValidWalk(walk)  << std::endl ;

    walk = {'n', 's' ,'n', 's' };
    std::cout << std::boolalpha << isValidWalk(walk)  << std::endl ;
    
    walk = {'n', 's' ,'e', 'w' ,'n', 's' ,'e', 'w' ,'n', 's' };
    std::cout << std::boolalpha << isValidWalk(walk)  << std::endl ;
    
    walk = {'n', 's' ,'n', 'e' ,'n', 'e' ,'n', 'e' ,'n', 'e' };
    std::cout << std::boolalpha << isValidWalk(walk)  << std::endl ;    
    
    walk = {'n', 's' ,'n', 'e' ,'n', 'e' ,'n', 'e' ,'n', 'e' };
    std::cout << std::boolalpha << isValidWalk(walk)  << std::endl ;

    return 0 ;
}