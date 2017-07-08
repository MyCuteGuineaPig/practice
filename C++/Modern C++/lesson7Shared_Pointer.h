//
//  lesson7Shared_Pointer.h
//  Modern C++
//
//  Created by beckswu on 7/8/17.
//  Copyright © 2017 beckswu. All rights reserved.
//

#ifndef lesson7Shared_Pointer_h
#define lesson7Shared_Pointer_h


/*
    shared_ptr 可以指出有count 有多少个pointer 指向一个object share_ptr<被指向的类型>
 
    初始化shared_ptr:
        shared_ptr<Dog7> p (new Dog7("Gunner")); // Gunner is created and then p is created
        // 不是罪理想的方法，也许Gunner 被创造，但是p 没有被created, 之后Gunner不能被delete，memory leak
        shared_ptr<Dog7>p2 = p
    
        or:
        Dog7 * d = new Dog7("Trank");
        shared_ptr<Dog7> p(d); // p.get_count() == 1
 
        or 最好的方法： 更快，更安全
        shared_ptr<Dog7>p = make_shared<Dog7> ("Trank"); () 括号里要写上传入Dog7的constructor 的值
        combine above two steps to one step
 
    如果call point的对象，用 ->, 如果用pointer 自己，比如数多少个pointer，用.  e.g: p.use_count()
 
    当一个普通的pointer 被called 到shared_ptr, 这个普通的pointer 就不要再次被用了
    shared_ptr 也可以用deference operator 去call object member (*p).bark
 
    // stati_pointer_cast
    // dynamic_pointer_cast
    // const_pointer_cast 可以用这些function去cast 就像cast raw pointer
 */

#include <iostream>
#include <string>
#include <memory>
using namespace std;



class Dog7{
    string name_;
    
    public:
        Dog7(string name){cout << "Dog is created: "<<name<<endl;name_=name;}
        Dog7() {cout<<"Nameless Dog is created "<<endl; name_ = "nameless";}
        ~Dog7() {cout<< "dog is destroyed: "<<name_<<endl;}
        void bark(){cout<< "Dog "<<name_<<" rules!"<<endl;}
    
};

void foo7(){
    /*Dog7 *p = new Dog7("Gunner");
     delete p;
      p -> bark();// p is adangling pointer - undefined behavior
      如果不delete p的话，会memory leak, main trouble: delete, we are not able to delete at appropriate time
     let program to see when to delet every object not only hard, but aslo is tediousto work
     */
    shared_ptr<Dog7> p (new Dog7("Gunner")); // count = 1; pointer并不是真的被share 了
    // the way shared pointer works is to keep track of how many pointers or shared pointers to point objects
    // shared point 可以detect 有多少个pointer 指向 the objects，当number is 0， 会delete the objects
    {
        shared_ptr<Dog7>p2 = p; // count = 2;
        p2->bark();
        cout <<" the count of shared pointer "<< p2.use_count()<<endl; // 2 p.use_count 和p2.use_count() 一样
    } // 在scope end, count = 1
    p -> bark();
} // at the end of function p out of scope, count will be zero

void lesson_7(){
    foo7();
    
    /* bad way to use shared_ptr,
     我们假设shared_ptr p,p2指向 d, 在scope 外面，会delete p, p2, 从而delete d
     
     Dog7 * d = new Dog7("Trank");
     shared_ptr<Dog7> p(d); // p.get_count() == 1
     shared_ptr<Dog7> p2(d); // p.get_count() == 1;  还是1
    
     当p Out of scope, d will be destoryed, 当p2 out of scope, d will be destoryed again
     
     // An objet should be assigned to a smart pointer as soon as it is created, Raw pointer should not be used again
     */
    // 正确方法
    shared_ptr<Dog7>p = make_shared<Dog7> ("Trank"); // 最好的方法initialization faster and safer
    (*p).bark();
    // stati_pointer_cast
    // dynamic_pointer_cast
    // const_pointer_cast 可以用这些function去cast 就像cast raw pointer
}


#endif /* lesson7Shared_Pointer_h */
