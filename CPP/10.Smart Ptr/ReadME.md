# Smart Pointers:

### problems in pointers:
1) Memory leak problem (Not delete ptr )---> in memory heap
2) Double deleted ptr -----> delete ptr; delete ptr ;
3) Dangling pointer -------> return ptr was deleted ;


## Smart Ptr:
- Alloction by user and no need to delete ----->automatic delete by destractor
## RAII: Resource Aquisition Is Initialization

        Types of Smart_ptr:
          /       |       \
         /        |        \    
        /         |         \
    1-Unique    2-Shared      3-Weak 



## 1) Unique Ptr:
- set obj. in heap and delete at end of scope 
- OwnerShip --------> don't copy or equal (=)  (can move to another Ptr)
- make_unique<int>(int a , int b) ---- unique_ptr<int>...(new <int>(int a, int b))
- ptr2= move(ptr1)     

- (Exclusive Ownership) Use unique_ptr when you want exactly one owner 
of a resource and automatic deallocation when that owner goes out of scope.
-It enforces exclusive ownership, preventing accidental copies or multiple pointers to the same resource.






## 2) Shared_Ptr
- can copy and assigned
- Referance count --------> ownership every ptr increase count++
--> .data (static)  / heap (memory allocated)
- auto myptr = make_shared<foo>()--------shared_ptr<foo>myptr(new foo())--------- myptr->method()
- problem (cyclic dependency): obj. pointing to another obj whith smart_ptr

- Use shared_ptr when you need multiple owners to share a resource and
automatic deallocation when the last owner goes out of scope.
- It uses reference counting to keep track of how many shared_ptr instances
point to the same resource. The resource is deallocated when the reference count reaches zero.




##                Comparison between unique_ptr and shared_ptr                          
                                                                                     
Use unique_ptr : when you have a single owner and prefer simplicity and efficiency   
(no reference counting overhead).                                                    

Use shared_ptr : when you need to share ownership among multiple parts of your code  
and want automatic deallocation when the last owner is gone.                         




## 3) Weak_Ptr
- Referance count can't decrease 
- observe obj but doesn't influence its lifetime 
- solve a problem from shared_ptr : Cyclic Dependency
  this make memory won't be free = memory leak 




# How Smart Pointers Work:

       Shared_ptr     Manger obj
                     ______________________
      S1 ---------->|       pointer        |              Managed obj
      S2 ---------->|                      |              __________
      S3 ---------->|   shared count:  3   |------------->|        |
                    |   weak count :   2   |              |________|
                    |______________________|
                            ^       ^
                            |       |
                            |       |
              Weak_Ptr:    Wp1     Wp2   