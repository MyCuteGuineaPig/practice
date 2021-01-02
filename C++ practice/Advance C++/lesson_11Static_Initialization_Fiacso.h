#ifndef lesson_11Static_Initialization_Fiacso_h
#define lesson_11Static_Initialization_Fiacso_h

#include <iostream>
#include <string>
using namespace std;

class Singleton;

class Cat11{
    string _name;
    
    public:
        void meow(){
            cout << "Cate rules! My name is "<<_name<<endl;
        
        }
        Cat11(string name){
            cout << "Constructing Cat "<<name <<endl;
            _name = name;
            //Singleton::getDog()->bark();
        }
};



//Cat11 c("Smokey"); // make it global variable

class Dog11{
    string _name;
    
public:
    void bark(){
        cout << "Dog rules! My name is "<<_name<<endl;
        
    }
    Dog11(string name){
        cout << "Constructing Dog "<<name <<endl;
        _name = name;
        //c.meow();
    }
};

//Dog11 d("Gunner");
// 有两个global variable, cat 和dog, the order of initializing of cat and dog is undefined, 如果dog11 d, cat11 c 在两个file
// 因为假如c 在b之后constructor，program die

// extern Dog d; 这样d可以在其他file 用
 
 
//singleton design pattern if 我们class dog 里面用class cat的，class cat里面用class dog的

class Singleton{
    static Dog11* pd;
    static Cat11* pc;
public:
    
    static Dog11* getDog() {
        if (!pd)
            pd = new Dog11("Gunner"); // Initialize Upon First USage Idiom
        return pd;
    }
    static Cat11* getCat(){
        if (!pc)
            pc = new Cat11("Smokey");
        return pc;
    }
    
    /*~Singleton(){
        if (pd) delete pd;
        if (pc) delete pc;
        pd = 0;
        pc = 0;
        
    }*/

};



 
 
void lesson_11(){
    //d.bark();
    Singleton s; // RAII, after scrope delete pc or pg
    //Singleton::getCat()->meow();

}


#endif
#pragma once
