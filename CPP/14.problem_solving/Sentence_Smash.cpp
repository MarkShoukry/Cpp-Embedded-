/*
Write a function that takes an array of words and smashes them together into a sentence 
and returns the sentence. You can ignore any need to sanitize words or add punctuation, 
but you should add spaces between each word. 
Be careful, there shouldn't be a space at the beginning or the end of the sentence!

Example
['hello', 'world', 'this', 'is', 'great']  =>  'hello world this is great'
*/


#include <iostream>
#include <vector>
#include <string>
using namespace std;




std::string smash(const std::vector<std::string>& words)
{
    if (words.empty())
    {return "";}

    string sentence ;
    for (int i = 0 ; i < words.size() ; i++)
    {
        if (i != 0)
        {
            sentence = sentence + " " ;
        }
        sentence = sentence + words[i];
    }

    
   return sentence ;
}


int main ()
{
    vector<string> words = {"hello", "world", "this", "is", "great"} ;

    auto sentence = smash(words) ;
    
    cout << sentence ;

    

    return 0;
}