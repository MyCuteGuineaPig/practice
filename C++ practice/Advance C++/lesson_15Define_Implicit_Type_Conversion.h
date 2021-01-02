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
    method 1. Use Constructor that can accept a single parameter
        convert other type conversion function
 
    method 2: Use the type conversion function 
        convert an object of your class into other types
 
 
    General Guideline:
    1. Avoid defining seemingly unexpected conversion 避免定义看起来不想要的conversion
    比如string a = Dog15
    2. avoid defining two-way implicit conversion
 
 
    Impicit Type conversion is useful when creating numerical types of class
    such as a rational class
 
 

 */

class dog15{
    public:
        dog15(string name){m_name=name;}
        //explicit dog15(string name){m_name=name;}// constructor + explicit type, 避免implicit type conversion
        // it is constructor + type converter 当constructor 有input type
        // If you only want to define a constructorm and no implicity type conversion
        //always put "explicit" before the constructor to avoid inadvertent type conversion
        string getName() {return m_name;}
        operator string() const {return m_name;}
    private:
        string m_name;
};

class Rational{
    public:
        Rational(int numerator = 0, int dennominator = 1): num(numerator), den(dennominator){}
        //constructor 是explicit + implicit type conversion
    
        int num, den;
        const Rational operator *(const Rational & rhs){
            return Rational(num*rhs.num, den*rhs.den);
        }
    
        operator int() const {
            return num/den;
        }
};


#include <iostream>
using namespace std;

void f(int i){}


void lesson_15() {
    char c = 'A';
    int i = c; // Integral promotion
    char * pc = 0; // int -> Null pointer null pointer initialization
    f(c); // convert c to A
    //dog * pd = new yellowdog(); // pointer type conversion
    // not user type conversion
    
    string dogname = "Bob";
    dog15 dog1(dogname);
    string a = dog1;//不好，因为也是implicit type conversion
    cout << "My name is  "<< a <<endl;
    
    Rational r1 = 23;
    //Rational r2 = r1*2;
    //Rational r3 = 3*r1;会把3 当成int， *就是integer的乘法，所以会把r1 convert to integer

    //但是加上r 变成integer，就会有error，因为r1*2, 又可以是integer，又可以是rational class *，ambiguity
    
    
    /*
        让两个都work的方法：
        const Rational operator*(const Rational & rhs, const Rational & rhs){
        return Rational(lhs.num*rhs.num), lhs.den*rhs.den
     }
     
     */
}


























#endif 
#pragma once
