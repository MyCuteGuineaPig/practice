//
//  lesson3Rvalue_Reference.h
//  Modern C++
//
//  Created by beckswu on 7/6/17.
//  Copyright © 2017 beckswu. All rights reserved.
//

#ifndef lesson3Rvalue_Reference_h
#define lesson3Rvalue_Reference_h



/*
    Understaning Rvalue and Lvalue
    
    Why do I care?
    1. Understand C++ construct, and decypher compiler errors or warnings
    2. C++ 11 introduced rvalue reference
 
    Simplified Definition:
    lvalue - An Object that occupies some identifiable location in memory  （在memory中，有特殊的address）
    rvalue - Any Object that is not a lvale
 
    // Lvalue Example:
    int i; // i isa lvalue
    int *p = &i; // i's address is identifiable
    i = 2; // memory content is modified
    
    class dog;
    dog d1; // lvalue of user defined type(class)
    // Most variables in C++ code are lvalues 大多数的variable都是lvalue
 
    rvalue Example:
    int x = 2; // x是lvalue, 2 is an rvalue
    int x = i+2; // i+2 r value  
 
    why i+2 是rvalue 因为get address is an rvalue 所以*p = &(i+2) 有error
    int *p = &(i+2); // Error
    
    i+2 = 4; Error 不能assign rvalue different value
    2 = i;  //Error
 
    dog d1;
    d1= dog(); // dog is rvalue of user defined tyoe class
 
    int sums(int x, int y){return x+y;}
    int i = sum(3,4); // sum (3,4 )is r value
 
    Rvalues: 2, i+2, dog, sum(3,4), x+y
    Lvalues: x, i, d1, p
 
 
    Reference (or lvalue reference):
    int i;
    int & r = i;
    int &r = 5; // Error 
    Exception: constant lvalue reference can be assign a rvalue 
    必须是constant reference lvalue reference，才能assign lvalue 用rvalue
 
    const int & r = 5;
 
    int sqaure(int &x){return x*x;}
    square(i); // OK
    square(40); // Error 必须assign lvalue 
 
    workaround 
    int sqaure(const int&x) {return x*x; } // 改变reference成const 
    // square(i) 和 square(40) both work
 
 
    lvalue can be used to create an rvalue
    int i = 1; // i 是lvalue
    int x = i+2; // i+2 是rvalue
 
    int x = i; // i 是 lvalue,但是这种情况下, i is implicitly transformed into rvalue
    // 反过来rvalue 不能implicitly tranformed to lvalue 只能是单向的
 
        
    rvalue can be used to create an lvalue
 
    int v[3];
    *(v+2) = 4;
 
 
    Misconcetption 1: function or operator always yields rvalue 错误的观念
    并不是所有function 都pass rvalue
    int x = i+3;
    int y = sum(3,4);
    int myglobal;
 
    int & foo(){
        return myglobal; // fucntion return integer reference
    }
    foo() = 50; // 正确，会compiler，
    // A more common example
    array[3] = 50; // Operator[] almost generates lvalue
 
 
    Misconception 2: lvalues are modifiable  不是所有的lvalue是可以修改的
    C language: lvalue means lvalue suitable for left-hand-side of assignment
    
    const int c = 1; // c is a lvalue
    c = 2; // Error c is not modifiable
 
 
 
    Misconception 3: rvalues are not modifiable. rvalue 是可以修改的
 
    i+3 = 6; //Error  i+3 是rvalue，不能修改
    sum(3,4) = 7 // Error  sum(3,4)  是rvalue，不能修改
 
    It is not true for user defined type(class) 用户自己定义的rvalue，是可以修改的
    class dog;
    dog().bark(); // bark() may change the state of dog object
 
 
    Summary:  总结
    1. Every C++ expression yield either an rvalue or a lvalue 
    所有C++ 表达式都会产生rvalue 或者lvalue,
    2. If the expression has an identifiable memory address, it's lvalue, otherwise, rvalue
    如果有memory占据是lvalue
 */


/*
    Rvalue Reference:
        1. Moving Semantics
        2. Perfect Forwarding
 
 
 */

void printInt(int &i) { cout << "lvalue reference: "<<i<<endl;}
void printInt(int &&i ){cout << "rvalue reference: "<<i<<endl;}
/*
    如果加一个function, 会有compiler error
    void printInt(int i) {}
    int a =5;
    printInt(a); 不知道叫哪个function run,void printInt(int &i) 或者void printInt(int i)
    printInt(6); 也不知道叫哪个function， printInt(int &i) 或者 void printInt(int i)
    只能overload function with rvalue reference or lvalue reference
 
 */

class boVector3{
    int size;
    double * arr_; // A big array
    public:
        boVector3(const boVector3 & rhs){ // lvalue deep copy expensive
            size = rhs.size;
            arr_ = new double [size];
            for(int i = 0; i<size; i++) {arr_[i] = rhs.arr_[i];}
        }
        boVector3(boVector3 && rhs){ // move constructor (shallow copy) inexpensive
            size = rhs.size;
            arr_ = rhs.arr_; // move the rhs to this
            rhs.arr_ = nullptr;
            // or when rhs destroyed, destory will delete his array
        }
    
        ~boVector3() {delete arr_;}
};

//void foo(boVector3 v); // take boVector as parameter
// void foo_by_ref(boVector &v); // if we don't have move constructor, can use pass by value or reference to pass that,very messy

//boVector3 createBoVector(); // Create a boVector



/*
        Note 1: the most useful place for rvalue reference is overloading copy 
        constructor and copy assignment operator to achieve move semantics (rvalue copy constructor)
 
    
        x& x: operator = (X const & rhs);
        x& x: operato = （X && rhs）;
 
    Note 2： move semantic is implemented for all STL containers, which meanss: 
    a. Move tp C++11 Your code will be faster without changing a thing
    b. Passing by value can be used for STL containers
 
    vector<int> foo(){
        return myvector;
    }
    void hoo(string a)
    bool goo(vector<int> & arg): Pass by reference if you use arg ot carry data back from goo()
 
 */


/*
    Summary:
    Move Constructor / Move Assignment Operator:
    Purpose: conveniently avoid costly and unnecessary deep copying
 
    1. They are particularly powerful where passing by reference and passing by value are both used 
    2. They give you finer control of which part of your object to be moved
 
 
 
 */


void lesson_3(){
    // Lvalue Example:
    int i; // i isa lvalue
    int *p = &i; // i's address is identifiable
    i = 2; // memory content is modified
    
    
    
    // What is rvalue reference?
    
    int a = 5; // a is a lvalue
    int &b = a; // b is a lvalue reference (reference)
    //int && c; // c is a rvalue reference
    printInt(a); // call lvalue reference function
    printInt(6); // call second function
    
    //boVector3 resuable = createBoVector();
    // foo(resuable); //resuable是lvalue invoke copy constructor. 之后用copy的resuable再pass to function foo
    //foo_by_ref(createBovector()) createBovector()会return 一个rvalue
    
    // foo(std::move(reusable));  move reusable to foo function // resuable.arr = nullptr by moving, you should not call reuseable one more
    // move 会pass to move constructor
    
    //
    // foo_by_ref(reuseable); // call no constructor 通过pass by reference 最efficient
    // foo(resuable) ; call copy constructor 最expensive 的
    // foo_by_ref(createBovector()); call move constructor;
    // resuable is distroyed here
    
    // foo_by_ref(createBovector());//createBovector() will return rvalue (temporary) error

}




















#endif /* lesson3Rvalue_Reference_h */
