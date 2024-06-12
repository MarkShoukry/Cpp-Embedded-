# Object Oiented Design Patterns
#### Reusable solutions to common problems that occur during software development.


## 1.Creational Patterns:
deal with the process of object creation

a) **Singleton Pattern:**
>Ensures that a class has only one instance and provides a global point of access to that instance.

b) **Factory Method Pattern:** 
>Defines an interface for creating an object, but allows subclasses to alter the type of objects that will be created.

c) **Abstract Factory Pattern:** 
>Provides an interface for creating families of related or dependent objects without specifying their concrete classes.


## 2.Structural Patterns:
deal primarily with the static composition and structure of classes and objects


a) **Adapter Pattern:** 
>Allows incompatible interfaces to work together by converting the interface of one class into another interface clients expect.

b) **Decorator Pattern:** 
>Attaches additional responsibilities to an object dynamically. It provides a flexible alternative to subclassing for extending functionality.

c) **Composite Pattern:**
> Composes objects into tree structures to represent part-whole hierarchies. Clients can treat individual objects and compositions of objects uniformly.

## 3.Behavioral Patterns:
which deal primarily with dynamic interaction among classes and objects


a) **Observer Pattern:**
>Defines a one-to-many dependency between objects so that when one object changes state, all its dependents are notified and updated automatically.

b) **Strategy Pattern:**
>Defines a family of algorithms, encapsulates each one, and makes them interchangeable. Strategy lets the algorithm vary independently from clients that use it.

c) **Command Pattern:**
>Encapsulates a request as an object, thereby allowing for parameterization of clients with queues, requests, and operations.

---
---
---
## Observer
* _To solve a Problem Need to notify a changing number of objects that something has changed_
* Define a one-to-many dependency between objects so that when one object changes state, all its dependents are notified and updated automatically.

## Iterator

## Proxy
* A Proxy provides an interface that forwards function calls to another interface of the same form.
  1. case(1):Implement lazy instantiation of the RealSubject object.
  2. case(2): Implement access control to the RealSubject object.
  3. case(3): Support debug or dry-run modes.
  4. case(4): Make the RealSubject class to be thread safe. __(Mutex)__
  5. case(5): Share resources.
  6. case(6): Protect against future changes in the RealSubject class.


## Adaptor
* Convert the interface of a class into another interface clients expect.
* Adapter pattern's motivation is that we can reuse existing software if we can modify the interface. **(Wrapper)**

## Singleton
* The Singleton pattern ensures a class has only one instance, and provides a global point of access to it.
* A Singleton is an elegant way of maintaining global state, but we should always question whether we need global state.
* Ensures that a class has only one instance and provides a global point of access to that instance.