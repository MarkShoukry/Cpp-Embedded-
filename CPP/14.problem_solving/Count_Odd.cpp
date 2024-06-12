/*
https://www.codewars.com/kata/59342039eb450e39970000a6/train/cpp    (codewars)
Given a number n, return the number of positive odd numbers below n, EASY!

Examples (Input -> Output)
7  -> 3 -----------------> (because odd numbers below 7 are [1, 3, 5])
15 -> 7 -----------------> (because odd numbers below 15 are [1, 3, 5, 7, 9, 11, 13])

*/





#include <iostream>
using  namespace std ;


int odd_count(int n) 
{
    //if n = even: odd numbers below n is n/2 
    //if n = odd: odd numbers below n is n/2 rounded down
    return (n > 0) ? (n >> 1) : 0;
}

int main() {
    int n;
    cout << "Please enter a number: ";
    cin >> n;
    
    int result = odd_count(n);
    cout << "Count of odd numbers below " << n << ": " << result << endl;

    return 0;
}