//
//  lesson_10Unique_Pointer.h
//  Modern C++
//
//  Created by beckswu on 7/8/17.
//  Copyright © 2017 beckswu. All rights reserved.
//

/*
    unique Pointers: exclusive ownership
    one object can only be own by one unique pointer
    当unique pointer point to 另一个object，或者unique pointer out of scope， 原来的object会被自动删除
 
    另一个unique pointer特殊的地方是，他是light weight smart pointer. It is less expensive to use than shared pointer
    如果你的program 有很多pointer，但是都没有被share，prefer to use unqiue pointer
 
    initialized 的方法：
        unique_ptr<Dog10> pd(new Dog("Gunner"));
    call member function： pd->bark()
 
    Dog *p = pd.release();  获取原来raw pointer的方法： 但是这样的话，pd会放弃原pointer的ownership，也不会自动删除dog
    
    ！pd 检测是不是unqie pointer empty的方法：
    pd.reset(new Dog ("SS")) 改变unique pointer指的对象：
    pd.reset() 等于把pd set 成nuLlptr
    
    release 和 reset 的区别在于：reset会destroy原来的object，release 不会，只会把原来object ownership交出去
 
    unique pointer 不能shared same object at the same time 但是他们可以share object 在different time
    pd2 = move(pd)：  transfer ownership 从一个unique ptr到另一个unqiue— ptr 用 move function
 
    f(move(pd2)); 把unqiue pointer传入function 因为只能有一个unique pointer point to object, 所以必须用move // gunner 是被destroyed in f function 因为move 了pd2
    假如想return function的返回值不用设置move，因为return自动是move
 
    unique pointer 不需要custom deleter
    shared_ptr 需要有时delete object, 但是对于unique——ptr 不需要
    unique_ptr<Dog10[] > pDD(new Dog[3]); 可以这么写，因为unique——ptr 是specialized for array
 */



#ifndef lesson_10Unique_Pointer_h
#define lesson_10Unique_Pointer_h
#include <iostream>
#include <string>
#include <memory>
using namespace std;



class Dog10{
    public:
        string m_name;
        void bark() {cout << "Dog "<<m_name<<" rules! "<<endl;}
    
        Dog10(){ cout<<"Nameless dog created"<<endl; m_name = "nameless";}
    
        Dog10(string name){cout << "Dog is created: "<<name<<endl; m_name = name;}
    
        ~Dog10(){cout <<"dog is destroyed: "<<m_name<<endl;}
    
};

void test() {
    /*
    Dog10 * pd = new Dog("Gunner"); // dog is created on the heap
    pd->bark();
    //pd does a bunch of different things
    // 如果过程中有error，dog会有memory leak
    delete pd;*/
    
    unique_ptr<Dog10> pd(new Dog10("Gunner"));
    pd->bark();
    
    //Dog10 *p = pd.release(); //pd give up ownership to p
    pd.reset(new Dog10 ("SS")); // "Gunner“ 在这里就被删除了
    // reset detroyed original object but release 不会destroy 原来的object
    pd.reset();
    if(!pd){
        cout << "pD is empty "<<endl;
    
    }else {cout<< "pD is not empty "<<endl;}
    
}

void f(unique_ptr<Dog10>p){
    p->bark();
    
}

unique_ptr<Dog10> getDog(){
    unique_ptr<Dog10> p (new Dog10("guess"));
    return p; // return value 就像是move function，所以p不再是guess 的拥有者
}

void test10(){
    unique_ptr<Dog10> pd(new Dog10("Gunner"));
    unique_ptr<Dog10> pd2(new Dog10("smoke"));
    pd2 -> bark();
    pd2 = move(pd);
    // 1. smoke is destroyed
    // 2. pd becomes empty()
    // 3. pd2 owns Gunner
    pd2 -> bark();
    // 然后我们想call function有unique pointer的，因为只能有一个unqiue ptr指向object，而function又是在copy value
    // 所以用move
    f(move(pd2)); // gunner 是被destroyed in f function 因为move 了pd2，所以再test10里面，已经没有了pd2，所以除了function f，object 被destroyed
    
    unique_ptr<Dog10>pd3 = getDog();
    //shared_ptr 需要有时delete object, 但是对于unique——ptr 不需要
    //unique_ptr<Dog10[] > pDD(new Dog[3]); 可以这么写，因为unique——ptr 是specialized for array
    
}




void lesson_10(){
    test();
    cout<<endl;
    test10();

}

#endif /* lesson_10Unique_Pointer_h */
