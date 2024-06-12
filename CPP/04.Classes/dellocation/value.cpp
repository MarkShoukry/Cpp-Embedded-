#include <iostream>

class Value 
{
public:
    Value (int capacity) : m_capacity(capacity)
    {
        p = new int [capacity];   //heep
    }
    ~Value ()
    {
        delete [] p ;
    }


    void setValue (int fill_value)
    {
        for (int i=0 ; i < m_capacity ; i++)
        {
            p[i] = fill_value;  
        }
    }


private:
    int *p;
    int m_capacity;
};


    void UseValue (int value_cap)
    {
        // Value value(value_cap);   //stack
        // value.setValue(value_cap);
        Value* value  = new Value (value_cap) ; //heep
        value->setValue(value_cap) ;
    
    }


int main ()
{
  for (int i= 1 ; i < 11 ; i ++ )
  {
      UseValue(i) ;
  }  

    return 0;
}