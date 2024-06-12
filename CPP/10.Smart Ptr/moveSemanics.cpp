#include <iostream>
#include <string.h>
using namespace std ;

//String Class
class String
{
public:
// Constructor: Initializes a String object with the given character array
    String(const char* string)
    {
        printf("Created\n");
        // Determine the length of the input string:
        //(strlen):Returns the length of the given byte string
        msize = strlen(string);  
        m_data = new char[msize];   // Allocate memory and copy the string
        //void* memcpy( void* dest, const void* src, std::size_t count )
        memcpy(m_data, string , msize);     
    }

    // Copy Constructor: Creates a new String object by copying another String object
    String(const String& other) 
    {
        printf("Copied\n");
        msize = other.msize ;
        m_data = new char[msize] ;
        memcpy(m_data, other.m_data , msize);
    }

    //Move Constructor: Creates a new String object by transferring resources from another String object
    //rvalue reference in move constructor
    String(String&& other)
    {
        printf("Moved\n");
        msize = other.msize ;
        m_data = other.m_data;
        other.m_data = nullptr; // pointer: reset the pointer to avoid double deletion
        other.msize = 0 ;
    }

    // Print method: Prints the characters of the string.
    void print()
    {
        for(int i ; i< msize ; i++)
        {
            printf("%c", m_data[i]);
            printf("\n");
        }
    }
    // Destructor: Frees the dynamically allocated memory.
    ~String()
    {
        delete m_data ;
    }

private:
    char* m_data; // pointer to the char array
    uint32_t msize ; //size of the string
};


//Entity class 
class Entity
{
public:
    //Constructor : initializes an Entity obj. with the provided name
    Entity(const String& name) : m_Name(name)
    {
    }
    //Move constructor: initializes an Entity obj. by transferring resources from another Entity obj.
    Entity(String&& name) : m_Name(std::move(name))
    {
        cout << "Entity move constructor" ;
    }
    // Function method to print the name of Entity
    void printName()
    {
        m_Name.print() ;  
    }

private:
    String m_Name ; // name of the Entity
};



int main ()
{
    String str("RoboticsCorner") ;
    Entity entity(str);
    entity.printName();

    printf("\n");
    Entity entity2(String("Embeddedc++"));

    printf("\n");
    

    return  0;
}