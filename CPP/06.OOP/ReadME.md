# UML:
# Unified Modeling Language (Strong Containment) 
## 1. Inheritance (is_a) 
## 2. Accosiation (has_a) (strong/weak)_Containment

------------------------------------------------
## Inheritance: is_a :-
* **Private inheritance**
* **Multiple inheritance**
* **Public inheritance**

super_Class <----is_a-------  Sub_Class
Animal <-------is_a--------- Cat

-----------------------------------------------------------

## Accosiation: Has_a:-
like: window (has_a) button ----->Accosiation

### **1) Composition: Strong Containment**
### **2) Aggregation: Weak Containment**
----------

### *1. composition (Strong Containment):-*
Memory allocation inside the class
- (RAII) Resource acquisition is initialization :
- Allocate and deallocate  pointer of object from Basic Class



### *2. Aggregation (Weak Containment):*
Memory allocation outside the class
- obj alocation out of class A _ but (pointer / referance ) on class A 


------------------------------------------------------------------


**composition (Strong Containment) [Memory allocation inside the class]**

```cpp
class B{} ;

class A  {
    private :
    B b ;
};
```


**Resource acquisition is initialization (RAII)**
* pointer:
```cpp
class A 
{
public:
    //allocate

    A(){
        b = new B ();
    }
    //deallocate

    ~A()
    { delete b;  }
private :
    B* b ;
};
```

__Aggregation -------> (Weak Containment) [Memory allocation outside the class]__
 obj alocation out of class A , but (pointer / referance ) on 
class A :
* pointer:

```cpp
class A   {
public:
    A(B* pb):b(pb) {}

private :
    B* b ;
};
```


- Referance:

```cpp
class A   {
public:
    A (B& pb) :b(pb) {}

private :
    B &b ;
};
```



             OOP_relationships
                   /   \
                  /     \
                 /       \
                /         \
               /           \
             is_a            has_a
            - private           Association
            - Multiple               /    \
            - publice               /      \
                                   /        \ 
                            composition    Aggregation
                        (Strong_con.)      (Week _containment)




<img src= "https://i.stack.imgur.com/jNyV5.jpg" width="400" height="400">



<img src= "https://qph.cf2.quoracdn.net/main-qimg-3b497e7d7b692c8f90c48142428f6392" width="800" height="200">





<img src= "https://i.stack.imgur.com/smuC7.jpg" width="200" height="200">

