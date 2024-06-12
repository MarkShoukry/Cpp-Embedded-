#include <iostream>
#include <map>
#include <unordered_map>
#include <iterator>

using namespace std ;

std::pair<int, int> g_pair(8,10) ;
std::unordered_map<int , string> x_unordered_map;


template<class T1 , class T2>
struct xPair
{
    xPair(){}
    xPair(T1 first_ , T2 second_) : first(first_) , second(second_)
    {
    }
    //factory method
    static xPair Make_xPair(T1 local_first , T2 local_second)
    {
        //xPair temp_pair(local_first, local_second);
        return xPair(local_first, local_second);
    }

    T1 first , second ;
};




int main()
{
    xPair<int, string> x_pair = xPair<int, string>::Make_xPair(11 , "Mark Shokry");


    map<string, int> myMap ;
    //factory method
    myMap.insert(make_pair<string, int > ("Rebotics" , 12));
    myMap.insert(make_pair<string, int> ("Corner" , 34)) ;

    //empty map container
    map<int, int> quiz ;
    //quiz_id , time limit
    //insert elements in random order
    quiz.insert(make_pair<int,int>(1,20));
    quiz.insert(pair<int, int> (2,30));
    quiz.insert(pair<int, int> (3,40));
    quiz.insert(pair<int, int> (4,50));
    quiz.insert(pair<int, int> (5,60));
    quiz.insert(pair<int, int> (6,70));

    quiz[7] = 10 ; // another way of inserting a value in a map
    quiz[8] = 100 ;

    for (auto& pair : quiz)
    {
        auto key = pair.first ;
        auto value = pair.second ;
    }
    //print map quiz
    map<int, int>::iterator itr ;
    cout << "\nThe map quiz is : \n" ;
    cout << "\tKey\tElement\n" ;
    for(itr = quiz.begin(); itr != quiz.end() ; ++itr)
    {
        cout << '\t' << itr->first << '\t' << itr->second << '\n' ;
    }
    cout << endl ;




    // assigning the elements from quiz to quiz2
    map<int , int> quiz2(quiz.begin(), quiz.end()) ;
    cout << "\nThe map quiz2 after"
         << " assign from quiz is : \n" 
         << "\tKey\tElement\n" ;
    for (itr = quiz2.begin() ; itr != quiz2.end(); ++itr)
    {
        cout << '\t' << itr->first << '\t' << itr->second << '\n' ;
    }
    cout << endl ;






    //remove all elements up to
    //element with key=3 in gquiz2
    cout << "\nquiz2 after removal of"
            " elements less than key=3 \n"
         << "\tKey\tElement\n"  ;
    quiz2.erase(quiz2.begin(), quiz2.find(3));
    for (itr = quiz2.begin() ; itr != quiz2.end() ; ++itr)
    {
        cout << '\t' << itr->first << '\t' << itr->second  << '\n' ; 
    }




    //remove all elements with key = 4 
    int num ;
    num  = quiz.erase(4) ;
    cout << "\ngqize2.erase(4) : " 
         << num << " removed \n"
         << "\tKey\tElement\n" ;
    for(itr =quiz2.begin(); itr !=quiz2.end() ; ++itr)
    {
        cout << '\t' << itr->first << '\t' << itr->second << '\n';
    }
    cout << endl ;




    // lower bound and upper bound for map gquiz1 key = 5
    cout << "gquiz1.lower_bound(5) : " << "\tKey = " ;

    auto it = quiz2.lower_bound(5) ;
    cout << it->first << '\t' << "\tElement = "
         << it->second << endl;

    cout << "gquiz1.upper_bound(5) : " << "\tKey = " ;
    cout << quiz2.upper_bound(5)->first << '\t' << "\tElement = " 
         << quiz2.upper_bound(5)->second << endl ;

         

    return 0 ;
}