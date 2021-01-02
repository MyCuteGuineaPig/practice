#ifndef lesson_13Resource_Managing_Class_h
#define lesson_13Resource_Managing_Class_h

#include <iostream>
#include <string>
using namespace std;

//class own other objects through pointer

// Persons owns the string through  pointer
class Person13{
    public:
        Person13(string name){
            pName_ = new string(name);
        }
        Person13 (const Person13 & rhs){
            pName_ = new string(*(rhs.pName()));
        }
        Person & operator= (const Person & rhs); // Deep copying
    
        ~Person13(){delete pName_;}
    
        string * pName() const {return pName_;}
        void printName() {cout << *pName_;}
    
        Person13* clone(){
            return (new Person13(*(pName_))); // copy all the object,
        }
    
    
    private:
        string * pName_;

};


void lesson_13() {
    vector <Person13> persons;
    persons.push_back(Person13("George"));
    /*
        persons.push_back(Person13("Google"));
        envoke 3 steps;
            1. George is constructed
            2. A copy of George is saved in the vector （shallow copy） the default copy constructor will do
            3. "George " is destroyed; 
     
     Person George and Person in the vector 不是同一个vector
     尽管他们identical但不是一个object
     但是person George 和person in the vector 是point the same object string
     
     Person George 是rvalue will be destroyed at the end of statement 
     但是当delete 会删除the pName pointer 因此person in the vector 将会指向一个deleted object string
     当叫printName object pName 将指向object that is deleted
     
     
     
     
     Solution 1 Define copy constructor and copy assignment operator for deep copying
     
     Solution 2: Delete copy constructor and copy assignment operator  and define clone function
            make copy constructor and copy assignment private
     
     
            Person13 (const Person13 & rhs);
            Person & operator= (const Person & rhs); // Deep copying
     
    perfer solution 2, 很少定义copy constructor and copy assignment operator,
     STL 会让container 有copy constructor and copy assignment operator
     
     
     
     the problem with working with copy constructor: making copy implicit
     the copy can happen implicitly when object is passed as parameter to another fucntion or in returned from another function
     
     
     the object can be passed implicitly or return implicitly if we use copy constructor, then bug sometimes introduce
     
     
     vector <Person13*> persons;
     persons.push_back(new Person13("George"));

     */
    
    

    
    persons.back().printName();
    
    cout << "Goodbye "<<endl;

}


#endif 
#pragma once

#pragma once
