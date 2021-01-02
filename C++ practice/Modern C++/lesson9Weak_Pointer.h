//
//  lesson9Weak_Pointer.h
//  Modern C++
//
//  Created by beckswu on 7/8/17.
//  Copyright © 2017 beckswu. All rights reserved.
//

#ifndef lesson9Weak_Pointer_h
#define lesson9Weak_Pointer_h
/*
    weak_ptr: I only want to have access to the object and I don;t want any ownership of the object
    换句话说：什么时候创建，什么时候删除object 跟我无关
 
    having weak pointer similar to raw pointer, but weak pointer provide one level of protection 
    and noboby can perform delete on this pointer, weak pointer is not always valid 
    如果指向的对象已经被删除，weak pointer 就是invalid
 
    weak_ptr<Dog9>m_pFriend;
    if(!m_pFriend.expired()) 检测是不是这个weak pointer是不是还是valid的，如果不是valid，不加这个话，会throw exception
    m_pFriend.lock()->name_  lock function 是创建shared_ptr not weak_ptr
    //1. make sure whtether pointed object is still valid
    // 2. make sure that when access object is not deleted
 
    m_pFriend.use_count() 检测这个weak pointer 有几个reference number
 */



#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Dog9{
    //shared_ptr<Dog9>m_pFriend; // cyclic reference
    weak_ptr<Dog9>m_pFriend;
    public:
        string name_;
        Dog9(string name){cout << "Dog is created: "<<name<<endl; name_=name;}
        ~Dog9() {cout<< "dog is destroyed: "<<name_<<endl;}
        void makeFriend(shared_ptr<Dog9>f){m_pFriend=f;}
    
        void showFriend(){
            if (!m_pFriend.expired()) // 检测不被删除
                cout << "My friend is "<<m_pFriend.lock()->name_<<endl;
            cout << "He is owned by "<<m_pFriend.use_count() << " pointed "<<endl;
            // lock 是创建shared_ptr not weak_ptr
            //1. make sure pointed object is still valid
            // 2. make sure that when access object is not deleted
            //如果已经被删掉，会throw exception
        }
    
};
            
            
void lesson_9(){
    shared_ptr<Dog9>pd(new Dog9("Gunner"));
    shared_ptr<Dog9>pd2(new Dog9("Smoky"));
    pd->makeFriend(pd2); // Gunner has the pointer to smoky
    pd2->makeFriend(pd); // smoky has the pointer to Gunner
    // cyclic reference: none of pointer out of scope and 没有会run destructor
    // solution is to use weak_ptr
    pd->showFriend();
}



#endif /* lesson9Weak_Pointer_h */
