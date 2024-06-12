/*
stack :data structure
(FiLo) first in ---> last out
(push & pop) operation
is_Empty() & is_Full() ---> function to helper
have to know size of array & top of stack
array or pointer
*/


#pragma once 
#include <vector>

template<typename T>
class Stack
{
public:

    
    Stack(int s = 10) ;
    ~Stack() ;
    int isEmpty() const    {return top == -1 ;}
    int isFull() const     {return top == size -1 ;}
    int push(const T& item);
   	int pop(T& popValue) ;
    

private:
    int size ; // no. of elements on stack
    int top ;
    T* stackptr ;
};




template class Stack<int>;   //explicitly instanciate the stack <int>
template class Stack<float>;
