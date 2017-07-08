//
//  lesson6Compiler_Generated_Function.h
//  Modern C++
//
//  Created by beckswu on 7/8/17.
//  Copyright © 2017 beckswu. All rights reserved.


#ifndef lesson6Compiler_Generated_Function_h
#define lesson6Compiler_Generated_Function_h

class dog6{}; // looks empty 但实际并不是empty 1，2，3，4，5，6
/*
 C++03:
 1. default constructor(generated only if no constructor is declared by user)
 2. copy constructor (generatred only if no 3, 4, 5,6 declared by user)
 3. copy assignment operator (generated only if2,4, 5,6 not declared by user) C++ 11 让generated copy constructor 和copy assignment operator 更难（跟move constructor, move assignment operator一样难）
 4 .destructor
 
 C++ 11:
 5. move constructor  (generated on if 2,3,4,6  not declared by user)
 6. move assignment operator (generated only 2,3,4,5 not declared by user)
 for copy constructor 如果已经定义了 move constructor or move assisgnment operator
 
 
 class dog(){
    dog(){}; // constructor
    dog& operator= (const dog & rhs); // copy assignment operator
    dog(dog &rhs) {this = rhs;}// copy constructor
    ~dog(){};// destructor
 
 //C++ 11
    Dog(Dog&&)  // move constructor
    Dog& operator = (Dog&&) // move assignment operator
 }
 
 class Cat{ // 3，4 (3 is decrecated)
    cat(const Cat&) {} // copy constructor
    //copy assignment operator, destructor will be generated
    // default constructor 不会产生因为已经有constructor了，move constructor, move assignment operator 也不会产生，因为已经产生copy constructor
 }
 */

class Duck{ // Duck object can only be moved constructor not used for copied
    // 比如mutex，socket只能被move 不能被copied
    Duck(Duck&&) {} // move constructor
    // only generate destructor by complier

};

class Frog{ // 4
    // only destructor is being generated
    Frog(Frog&&, int = 0){} // it is actually move constructor
    Frog(int = 0){}// default constructor
    Frog(const Frog&, int = 0){} //copy constructor
};

class Fish{ // 1,2,3 generated (2,3 are deprecated)
    ~Fish() {}
};

class Cow { // 1,2,4
    //default constructor, copy constructor, destructor will be generated（C++11 copy constructor deprecated）
    // even if copy assignment operator is gnereated, this assignment 也算是copy assignment operatpr被declare，
    // 所以move constructor, move assignment operator 不会被generated
    Cow & operator= (const Cow&) = delete;
    Cow(const Cow &) = default;  // bring copy constructor back
};

void lesson_6(){
    



}





#endif /* lesson6Compiler_Generated_Function_h */
