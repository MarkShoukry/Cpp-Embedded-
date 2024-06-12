#pragma once 
#include <vector>

template<class T>
class Stack
{
public:

    
    Stack(int s = 10) 
    {
        size = s > 0 && s < 1000 ? s : 10 ;  
        top = -1 ;  // initialize stack
        stackptr = new T[size] ;  
    }
    ~Stack() {delete [] stackptr; }

    int isEmpty() const    {return top == -1 ;}
    int isFull() const     {return top == size -1 ;}
    
   
    int push(const T& item)
    {
        if (!isFull())
	    {
		    stackptr[++top] = item ;
		    return 1 ;  // push successful
	    }
	    return 0 ;  // push unsuccessful   
    }
    

   	int pop(T& popValue) 
    {
        if (!isEmpty())
	    {
		    popValue = stackptr[top--] ;
		    return 1 ;  // pop successful
	    }
	    return 0 ;  // pop unsuccessful   
    }
    

private:
    int size ; // no. of elements on stack
    int top ;
    T* stackptr ;
};

