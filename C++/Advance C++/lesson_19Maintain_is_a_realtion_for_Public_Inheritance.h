#ifndef lesson_19Maintain_is_a_realtion_for_Public_Inheritance_h
#define lesson_19Maintain_is_a_realtion_for_Public_Inheritance_h

#include <iostream>
using namespace std;


/*
 
 summary:
 
 1. Precise definition of classes 精确class的定义
 2. Don't overwrite non-virtual functions  不要覆盖在non-virtual function，在inheritance、base 里面不要定义一个function两回without virtual
 3. Don;t override defualt parameter values for virtual function
  不要覆盖virtual function 的default parameter
 4. Force inheritance of shadowed functions
    如果想用base class的function，using dog::bark;  假如derived的class有bark function，但跟想要的base barkfunction 不是一个function，因为parameter不同，一个string，一个int的parameter，假如想要两个都用，
    就要加上，using dog::bark; 
 
 
 
    public inheitance => "is a " relation
 
    A Derived class should be able to do everything the base class can do.
 
 
    class bird{
 
    };
 
    class flyablebird : public bird{
        public:
        void fly();
    }
 
    class penguin: public bird{
 
    };
 
 
    penguin p;
    //p.fly(); // is not correct to fly
 
 
 
    polymorphism: means different class object react to the same API will behave differently 
    都不要overwrite non-virtual function
    
    class dog19{
        public:
            virtual void bark(string msg = "just a "){
            cout << " I am "<<msg<<"  dog "<<endl;
        }
        }
 
    class yellowdog19:public dog19{
        public:
            virtual void bark(string msg = "a yellow "){
            cout << " I am "<<msg<<"  dog "<<endl;
        }
    }

    yellowdog * py = new yellowdog();
    py ->bark();
    dog *pd = py;
    py -> bark(); 
 
    output:
    I am a yellow   dog
    I am just a   dog
 
    virtual function bunld at run time
    virtual function default value for parameter bund at complier time
    所以dog *pd = py;
    py -> bark();      会叫default value for virtual function的input，是base class的
 
    所以永远不要overwrite default value for virtual function
 
 */

class dog19{
public:
    virtual void bark(string msg = "just a "){
        cout << " I am "<<msg<<"  dog "<<endl;
    }
};

class yellowdog19: public dog19{
public:
    virtual void bark(string msg = "a yellow "){
        cout << " I am "<<msg<<"  dog "<<endl;
    }
};

/*
    假如现在
 class dog19{
    public:
    int bark(int age){cout << "I am  "<<age<<" years old"<<endl;}
 
    virtual void bark(string msg = "just a "){
        cout << " I am "<<msg<<"  dog "<<endl;
    }
 };
 
 class yellowdog19: public dog19{
    public:
        virtual void bark(string msg = "a yellow "){
            cout << " I am "<<msg<<"  dog "<<endl;
        }
 };
 
 yellowdog19 * py = new yellowdog19;
 py -> bark(5); 不能compile
 因为compile的机制是首先找yellowdog19，发现yellowdog有这个bark的function，就会停止寻找dog 的class
 所以不会找到那个int做为parameter 的bark function，假如在yellowdog找不到这个function，才会继续寻找function 在base class
 
 如果想要的话
 class yellowdog19: public dog19{
    public:
        using dog::bark; 加上这句话
        virtual void bark(string msg = "a yellow "){
        cout << " I am "<<msg<<"  dog "<<endl;
        }
 };
 

 
 */



void lesson_19() {
    yellowdog19 * py = new yellowdog19();
    py ->bark();
    dog19 *pd = py;
    pd -> bark();
    /*
     I am a yellow   dog
     I am just a   dog
     
     */


}


#endif
#pragma once
