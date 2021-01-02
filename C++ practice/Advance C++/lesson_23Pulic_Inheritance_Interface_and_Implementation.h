#ifndef lesson_23Pulic_Inheritance_Interface_and_Implementation_h
#define lesson_23Pulic_Inheritance_Interface_and_Implementation_h

#include <iostream>
using namespace std;


/*
    Types of Inheritance in C++:
    1. Pure virtual public function - inherit interface only
    2. Non-virtual public function - inherit both interface and implemention 
    3. Impure virtual public function - inherit interface and default implementation
    4. Protected function - inherit implementation only
 
    需要区分interface and implementation
 
 
    1. Interface Inheritance
 
    (1). subtyping 
    (2). polymorphism 
    virtual void bark() = 0;
 
    Pitfalls:
    -- Be careful of interface float
    -- interfaces do not reveal implementation  interface是fixed
 
    2. Implementation Inheritance 不建议 (non-virtual function and impure virtual function)
    (1). Increase code complexity 
    (2). - Not encouraged 
    In order to get something write in derived class, I must have a good understanding in the base class,In order to change something in the base class, I have to be careful
    If I have something in base class
 
 
 
    Guidelines for Implementation Inheritance:
    1. Do not use inheritance for code reuse, use composition.
    2. minimize the implementation in base classes, Base classes should be thin
    3. Minimize the level of hierarchies in implementation inheritance
 
    Inheritance is often useful, but more often overused(abused)
 
 
 
 
 
 
    The Duality of Public Inheritance
 
    - Inheritance of Interface
    - Inheritance of Impliementatiton
 
    class Dog{
        public:
            virtual void bark() = 0;
            virtual void eat() {cout << "I am eating. "; }
 
            //如果yellowdog overwrite Dog, 将会provide 
            //non virtual function will replace interface and default implementation
        protected:
            void sleep() {cout<<"I am sleeping ";} //如果yellowdog 继承，只会provide implementation，不会provide interface of function
 
    };
 
    class yellowdog: public Dog{
        public:
            virtual void bark() { cout<<"I am a yellowdog "<<endl;} // Interface only Inheritance
            // not inheritance base class implementation
    //yellowdog have choice either overwrite eat or not
    }
 

 
 
 
 */

void lesson_23() {


}


#endif 
#pragma once
