#ifndef lesson_12Struct_Class_h
#define lesson_12Struct_Class_h


/*
    Convention:
        Struct: small passive objects that carry public data and have no or few basic member functions
        数据是public的，然后basic member function数量较少
        Struct is used for data container
 
        Class: bigger active objects that carry private data, interfaced throught public member functions
        有private data, 是complicate objects, 用于complex data Structure
 
    Difference:
        Stuct:
            1. Data Member are public by default
            2. struct data member are named as regular variable
 
        Class
            1. Data Member are private by default
            2. class data member are usually named with trailing underscore: string name_
 
    Summary:
        1. Use Struct for passive objects with public data and use class for active objects with private data
        2. Use setter/getter to access class's data
        3. Avoid making setter/getter if possible
 
 */


#include <iostream>
using namespace std;

struct Person_t{
    string name;
    unsigned age;
    private:
        int height;
};

class Person{
    string name_;
    unsigned age_; // _age used for global variable （convention）
    public:
        int height;
        unsigned age() const{return age_;} // getter accesser, getter function almost always const function
        void set_age(unsigned a){age_ = a;} // setter or mutator
};

/*
    who don't we not setting access and setter and make data member public?
    when we use oo programming, we want to separate interface from implementation 
    and talk through outside via interface, 变量variable 是implementation， function 是interface
 
    如果让Data member public 让internal implementaion outside world
    比如你想让age set 在一定范围内，set function easily do that, but if the variable is public, there is no easy way to do that
 
    当有很多的getter 和setter is not good, if somebody use that so many data, 为什么这个data 属于我，而不是somebody else
 
    如果有太多的setter 和getter function, some problems with my desgin
 
 */



void lesson_12() {
    Person_t Pt;
    Person p;
    p.set_age(4);
    cout << "age is "<<p.age() <<endl;

}


#endif 
#pragma once

