//
//  lesson1.h
//  Modern C++
//
//  Created by beckswu on 7/6/17.
//  Copyright © 2017 beckswu. All rights reserved.
//

#ifndef lesson1_h
#define lesson1_h

#include <initializer_list>
#include <iostream>
#include <vector>
using namespace std;

//can define my own initialized list constructor:

class boVector{
    vector<int> m_vec;
    public:
        boVector(const initializer_list<int> & v){
            for(initializer_list<int>::iterator itr = v.begin(); itr!=v.end();itr++)
                m_vec.push_back(*itr);
        
        }
};


class dog{
    public:
        int age;
        string name;
        dog(int age_, string name_): age(age_),name(name_){};

};

void foo(int i) {cout << "foo_int"<<endl;}
void foo(char *pc) {cout << "foo_char*"<<endl;}





void lesson_1(){
    /*
        vector<int>v;
        v.push_back(3);
        v.push_back(2);
        v.push_back(4);
        v.push_back(5); 这么做很不effecient。没有效率
        
        所以用initialized list curly brace
     */
    vector<int> v ={3,4,1,9}; // calling initializer_list constructor
    //All the relevant STL containers have been updated to accept initializer_List
    // 所有的container都用initialized list

    boVector vv{0,2,3,4};
    boVector m = {0,2,3,4}; // the same
    
    
    
    //Uniform Initialization
    /*
        Uniform Initialization search Order:
        1. Initializer_list Constructor
        2. Regular Constructor that takes the appropriate parameters
        3, Aggregate initializer
     
     
     class dog{   // Aggregate class or struct
        public:
            int age;
            string name;
     }
     
     class dog{
        public:
            int age;   // 3rd choice
            
            dog(int a){  age = a;} // 2nd choice 
     
            dog(const initializer_list<int> & vec){
            age = *(vec.begin()); // 1 st choice
     }
     
     
     }
     
     
     
     */
    dog d = {11,"Bob"};
    
    
    
    /*
        3 auto type
     */
    std::vector<int> vec = {2,3,4,5};
    /*  C++ 03
        for(vector<int>::iterator it = vec.begin(); it!=vec.end();++it)
            m_vec.push_back(*it);
    
        C++ 11 use auto type
        for(auto it = vec.begin(); it!=vec.end(); it++)
            m_vec.push_back(*it)
    */
    
    auto a= 6; // a is a integer
    auto b = 9.6; // b is double
    auto c = a;// c is an integer
    
    
    /*
     4 foreach
     */
    
    /*  C++ 03
     for(vector<int>::iterator it = vec.begin(); it!=vec.end();++it)
        cout << (*itr);
     
     C++ 11 use auto type
     for (int i:v) // works on any class that has begin() and end()
        cout << i;  // randomly access
     
     for(auto& i:v)
        i++ // change the values in v
     */
    
    /*
     4 nullptr: null pointer is defined as null 0 , replace NULL in C++ 03
     */
    //foo(NULL); ambiguity
    
    // C++ 11
    foo(nullptr); // call for(char*) call char pointer
    
    /*
     6 enum
     */
    // C++ 03
    enum apple {green_a, red_a};
    enum orange {big_o, small_o};
    apple aa= green_a;
    orange o = big_o; // green_a和big_o 都是1
    
    cout << " apple aa "<<aa<<endl;
    cout << "  orange o "<<o<<endl;
    if (aa == o)
        cout << "green apple and big orange are the same \n";
    else
        cout << "green apple and big orange are not the same \n";
    
    // C++ 11 introduce enum class
    /*
    enum class applee {green,red};
    enum class orangee {big,small};
    
    applee a1 = applee::green;
    orangee o1 = orangee::big;
    
    if (a1==o1)
        cout << "enum class green apple and big orange the the same\n";
    else
        cout << "green apple and big orange are not the same\n";
    // compile fails becuase we haven't define == apple, orange
     没有定义 = operator
    */
    
    /*
     7 static assert
     */
    
    // run-time assert
    //assert(myPointer != NULL);
    
    // COmpile time assert (C++11)
    static_assert(sizeof(int)==4); // following code will not work if integer is not equal to 4
    // If not equal, cannot compile
    
    
    /*
     8 delegating constructor
     
     
     class dog11{
        public:
        dog() {};
        dog(int a): {dog(); do OtherThings(a);} // use for another constructor
     }; 上面不能work for C++
     
     
     C++ 03
     class dog11{
        init(){...}
        public:
        dog() {init(); };
        dog(int a): { init(); do OtherThings(a);}
     }; init function works for both constructored, 
        Cons:
            1. will be duplicated, cumbersome code
            2. init() could be invoked by other functions, take additional complexity, 
     
     
     C++ 11
     class dog{
        int age = 10; // allow in class data member initialization 
        // 因此age will be initialized in every constructor
        public:
            dog() {...}
            dog(int a): dog() {dootherthing(); } // called first constructor in the initialized list, 
            // this can be invoked before second constructor start
     }
     
     Limitation: dog() has to be called first, cannot be envoked in the middle or end of second construuctor
     
     */
    
    
    
    
    
    
    
    
}





































#endif /* lesson1_h */
