#ifndef lesson_24Code_Reuse_Inheritance_Composition_h
#define lesson_24Code_Reuse_Inheritance_Composition_h

#include <iostream>
using namespace std;

/*
    Code Reuse: Inheritance vs Composition 
 
 
 
 
   这个BaseDog class 不好，BaseDog reveals more details, lose benefits of abstraction, 取名为Dog
    
    // code resume
    class Dog{
        //common activities
    };
 
    class BullDog: public Dog {
        // call the common activites
 
    };
 
 
    class shepherdDog: public Dog {
        // call the common activites
 
    };
 
    //Composition is much more inheritance
    1.  Less code coupling between reused code and reuser of the code 
        a. Child class automatically inherits ALL parent class's public members
        b. Child class can access parent's protected members
            - Inheriatnace breaks encapsulation
 
            encapsulation enemy: friends and inheritance 
 
    2. Dynamic binding
        1. Inheritance is bound at compile time
        2. Composition can be bound either at compile time and running time
 
    
    class OutdoorActivityManager: public ActivityManager{}
 
    class IndoorActivityManager: public ActivityManager{}
 
 
 
    Flexible code construct
        
        Dog         ActivityManager
    BullDog        OutdoorAcitivyManager
    ShepherdDog    IndoorActivityManager
 */



void lesson_24() {


}


#endif 
#pragma once
