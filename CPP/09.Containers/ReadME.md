(STL)The Standard Template Library Containers:
               /           \
              /             \
             /               \
            /                 \ 
           /                   \
     sequence         |        Asspciative
    countainer        |          countainer
(linear arrangement)  |      (provide fast retrieval of date based on keys)
<vector>              |       <set>
<deque>               |       <map>
<list>                |-----------------
<stack>               |key    | value  
                      |-----------------
                      |  1    | "Mark" 
                      |  2    | "Ali"      (search by key)



(1) Sequence Countainer (linear arrangement) :
1) vector:
____________________
|___|____|____|_____----------->

2) deque:
         ______________________
<--------|_____|____|_____|____-------->

3) list:
          ____     _______    _____       _____
<------- |____|<-->|_____|<-->|____|<--> |____|-------->

1- forward         
2- double
-memory in heap
-linked by pointers
-logical list


(2) Asspciative Countainer :
1) map:
-map: uniqe values
-multimap: allows duplicates
map<ke,value>

2) set: