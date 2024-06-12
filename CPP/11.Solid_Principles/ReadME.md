# SOLID PRINCIPLES

##           Software Design 

              sotware design
                  /  \
                 /    \
                /      \ 
    Static Design   |  Dnamic Design
    Architechare:   | Behavior:
    Class Diagram   | -Finite state machine        
                    | -Sequance Diagram


## Agile: water fall
- requairment   
- design                
- developing            
- testing       

SDLC: software developing life cycle


### Code problem : (code Smells)
Refactoring: improving the design of existing code

### Agile & Practices:-
1) **Rigidity:** Ever change causes a cascade of related of changes (not flexibile).
2) **Fragility:** Distant & apparently unrelated code breaks after every change.
3) **Viscosity:** Code is helplessly entarglad you can't reuse anything.
4) **Immobility:** Behaving bodly is the must attractive alternative.


### CLEAN_CODE:
Solid Principles of Object Oriented Design:

1. **SRP** :- _Single Responsibility Principle_
     * The class has one reason to change.
 
1. **OCP** :- _Open/Close Principle_
     * Open for extension, but Closed for modification.
 
 1. **LSP** :- _Liskov Sbstitution Principle_
     * objects of a superclass should be replaceable
     with objects of its subclasses without affecting the correctness of the program.
     
2. **ISP** :- _Interface Segregation Principle_
     * Clients should not be forced to depend on methods that they don't need.

3. **DIP** :- _Dependency Inversion Principle_
     * Classes depend on interface (pure virtual fn.)
          not concrete class.
     * Advocating for high-level modules to depend on abstractions rather than concrete implementations.