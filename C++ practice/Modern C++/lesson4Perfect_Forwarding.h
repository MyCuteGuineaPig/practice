//
//  lesson4Perfect_Forwarding.h
//  Modern C++
//
//  Created by beckswu on 7/7/17.
//  Copyright © 2017 beckswu. All rights reserved.
//

#ifndef lesson4Perfect_Forwarding_h
#define lesson4Perfect_Forwarding_h

//void foo4(boVector arg) boVector has both move constructor and copy constructor

/*
template<typename T>
void relay(T arg){
    foo(arg)； take argument and take agrument to function foo
    // it is argument forwarding
 }
 
 boVector reusable = createBoVector();
 relay(reusable); with lvalue, copy constructor with be invoked
 
 relay(createBoVector())  with rvalue, move constructor will be invoked

}
 
 1. No costly and unnecessary copy construction of beVector is made 
 argument forwarded from relay should be the same type as foo
 2. rvalue is forwarded as rvalue, and lvalue is forwarded as lvalue
 e.g 如果rvalue pass to relay,  then rvalue should be pass to foo
     如果lvalue pass to relay, then lvalue should be pass to foo
 
 solution: 解决方法
 
 template <typename T> 
 void relay ( T&& arg) {
    foo (std::forward<T>(arg));
 }
 rvalue reference is specified with type && 
 type && is rvalue reference?  并不是永远是rvalue reference
 如果arg 是rvalue, T&& 是rvalue reference
 如果arg 是lvalue, T&& 是lalue reference
 
 T && variable is initialized with rvalue => rvalue reference 
 relay(9) => T = int && => T&& = int && && = int &&（9是rvalue，int &&）
 
 T && variable is nitiaized with lvalue => lvalue reference
 relay(x); => T = int & => T && = int & && = int &（9是lvalue， int &）
 以上的缩写都是根据（ Reference Collapsing Rules）
 所以&& 是Universal reference 
 
 当T&&是universial reference 的条件
 1. T is a template tye T只能是template type 必须是template么
 2. Type deduction (reference collapsing ) happens to T:  T必须是functional template 不能是class template
    - T is a function template type not class template type
 
 Implmentation of std::Forward()
 template <class T?
 T && forward (typename remove_reference<T>:: type & arg){
    return static_cast<T&&>(arg);
 }
 
foward 实际上cast arg to && 不论arg 是lvalue rvalue， 都会先cast 成&&（但有可能decrease to &）， 之后pass to function foo
 所以foo 和relay有一样的type of argument, 
 如果function arg 是rvalue， foward会forward rvalue 到foo
  如果function arg 是lvalue， foward会forward lvalue 到foo
 
 
 Reference Collapsing Rules （C++11）
 1. T& & => T&
 2. T& && => T&
 3. T&& & => T&
 4. T&& && => T&&     T DOUBLE REF  is t ref, 
 You cannot write & &, but compiler can generate function
 
 
 Remove Reference:
 template<class T? 
 struct remove_reference // It removes reference on type T
 // what remove_reference 功能， remove reference
 
 // T is int & 
 remove_reference<int&>:: type i; // 等于 int i
 
 //T is int
 remove_reference<int>:: type i; // 等于int i
 
 
 
 move 和foward的区别：
 
 std::move<T> (arg); Turn arg into an rvaluee int 
 std::foward<T?args; // Turn arg to tyoe of T&& (有可能rvalue 也有可能lvalue)
 
 summary: 
 
Usage of rvalue reference:
 1. Move semanticcs
 2. Perfect Fow
 
 */

void lesson_4(){
    

}


#endif /* lesson4Perfect_Forwarding_h */
