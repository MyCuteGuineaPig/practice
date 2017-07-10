#ifndef lesson_15Define_Implicit_Type_Conversion_h
#define lesson_15Define_Implicit_Type_Conversion_h

/*
    User Defined Implicit Type Conversion
    Categories of Type Conversion:
                                                            Implicit          Expilict
 
    Standard Type Conversion (build-in type)                   A                 B
    User Defined Type Conversion(user defined class)           C                 D (casting)
 
 
 
    Category A: Impicit Standard Type Conversion
        char c = 'A';
        int i = c;
 
    Category C: Implicit User Defined Type Conversion:
    Defined inside class (user defined type)
 
    There are 2 methods to define implicit user defined type conversion:
    1. Use Constructor that can accept a single parameter

 */



#include <iostream>
using namespace std;

void f(int i){}


void lesson_15() {
    char c = 'A';
    int i = c; // Integral promotion
    char * pc = 0; // int -> Null pointer null pointer initialization
    f(c); // convert c to A
    //dog * pd = new yellowdog(); // pointer type conversion
    
    

}


























#endif 
#pragma once
