#ifndef lesson_14Virtual_Constructor_Clone_Function_h
#define lesson_14Virtual_Constructor_Clone_Function_h

#include <iostream>
using namespace std;


class Dog14{
    // define a public virtual clone function
    public:
        virtual Dog14* clone(){
            return new Dog14(*this);
        }

};

class YellowDog14:public Dog14{
    public:
        virtual YellowDog14 * clone(){ // co-variant return type
            return (new YellowDog14(*this));
        } // the return type is different, 一个是yellowdog，一个是dog，即使一个是另一个的virtual,
    // co-varient return type, 允许derived virtual function return type is derived from base class return type
    
};

void foo(Dog14 *d){
    // d is yellow dog
    // but c is dog
    //Dog14 *c = new Dog14(*d); //c is not Identically copy of d
    // d is a Yellowdog, c is a dog
    
    Dog14 * c = d->clone(); // c is a yellow dog
}

// clone function is alike constructor, it makes sure appropriate type of data will be constructed
// no matter what kind of original type of data are casted into



void lesson_14() {
    YellowDog14 d;
    foo (&d);

}


#endif 
#pragma once
