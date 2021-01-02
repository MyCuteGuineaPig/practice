//
//  lesson2.h
//  Modern C++
//
//  Created by beckswu on 7/6/17.
//  Copyright © 2017 beckswu. All rights reserved.
//


/*
        override: keyword override, 意思是创建一个function，然后又override 必须跟base class的function type一样，是被覆盖的
        要是没有override， 可能会建一个新的virtual function，因为有可能这个function的return type或者input 不一样，有了这个关键字，
        假如return/input type 不一样，就会报error
 
        final： 就是没有这个class 没有子function 或者没有子的virtual function，derived class不能覆盖这个function，到头了
 
        compiler generated function:  dog() = default;
        这样default constructor 会建立，不用设值
 
 
        delete： 删除class特定的function，比如constructor只能pass int，比如assignment = operator
 
 
        constexpr always tells compiler that function return constant 可以用来initialization
        比如
        constexpr int A() {return 3;}
        int arr[A()+3]; // Complier Error, 因为complier 不知道是否function always return constant
 

        constexpr int A() {return 3;} // Forces the computation to happen at compiler time
        constexpr int cubed (int x) {return x*x*x;} this function will not consume any run time
        会compiler function 在compile time 不会在run time

    
        14: String Literal
        char * a = u8"string"; // to define an UTF-8 string
        char16_t * b = u"string"; // to define an UTF-16 string
        char32_t* c = U"string"; // to define an UTF-32 string
        char* d = R"String \\" // to defien a new string 就是两个\\, 因为是raw string，第一个\ 不会被解释成escape character anymore
 
        15. Lambda function
        cout << [](int x, int y){return x+y(3,4) <<endl; // output 7
        auto f  = [](int x, int y){return x+y};
        cout << f(3,4)<<endl; // output 7
 
        functional programming, 把function 传入template
        template<typename func>
        void filter(func f, vector<int>arr){
            for(auto i:arr){
                if(f(i))    // if functioon is true we print out function
                cout << i<<"  "<<endl;
            }
        }
 
        vector<int> v ={1,2,3,4,5,6};
 
        functional programming:
        filter([](int x){return (x>3);}, v); // Output 4,5,6
        filter([](int x){return (x>2 && x<5);} v), output  3,4
 
        int y = 4;
        filter ([&](int x) {return (x>y);}, v); // Ouput 5,6 把variable传入function
        // Note [&] tells compiler that we want variable capture
 




 */


#ifndef lesson2_h
#define lesson2_h
#include <iostream>
#include <vector>
using namespace std;


template<typename func>
void filter(func f, vector<int>arr){
    for(auto i:arr){
        if(f(i))    // if functioon is true we print out function
            cout << i<<"  "<<endl;
    }
}
    



void lesson_2(){
    
    /* 9 overide (for virtual function) 有keyword override
     to avoid inadvertently create new function in derived classes
     
     C++ 03 
     
     class dog{
        virtual void A(int);
        virtual void B() const
     }
     
    class yellowdog: public dog{
        virtual void A(float); // create a new function with float
        virtual void B(); // Create a new Function coz not const
     
     }
     
     C++ 11
     class dog{
        virtual void A(int);
        virtual void B() const;

     }
     
     class yellowdog: public dog{
        virtual void A(float) override; // Error: no function to override
        virtual void B() override; // Error: no function to override
        void C() override; // Error: no function to override
     }
     
    */
    
    
    /*
        10 final (for virtual function and for class) 关键字final
        class dog final{ // no class be derived from dog, 没有子class
        ....
     
        }
     
        class dog{
            virtual void bark() final; // No class can override bark() 
            // final virtual function, 没有dog的子类可以又bark的virtual function
     
        }

     */
    
    
    /*
     11  Compiler Generated Default COnstructor
        class dog{
            dog(int age ){}
     
     };
     
     dog 11; // Error compiler will not generate the default constructor
     
     C++ 11
     
     class dog{
        dog(int age);
        dog() = default; // Force compiler to generate the default constructor 强制compiler产生default constructor
     
     }
     
     */
    
    
    /*
     
        12. Delete: is used to delete function
     
        class dog{
            dog(int age){}
     }
     
     dog a(2);
     dog b(3.0); // 3.0 is converted from double to int
     a = b; // comipler generated assignment operator
     
     
     C++ 11 
     class dog{
        dog(int age){}
        dog(double) = delete  // 删除dog constructor当pass double,不能让double pass to constructor
        dog & operator = (const dog & )= delete;  // 删除dog = assignment operator
     }
    
     
     */
    
    /*
        13. Constexpr
     
        int arr[6]; // OK
        int A() {return 3;} 
        int arr[A()+3]; // Complier Error, 因为complier 不知道是否function always return constant
     
        
        C++ 11
        constexpr always tells compiler that function return constant 可以用来initialization
        
        constexpr int A() {return 3;} // Forces the computation to happen at compiler time 
        
        int arr[A()+3]; // create a array of size 6
        让function compile在compiler time
     
     
        write faster program with constexpr
        
        constexpr int cubed (int x) {return x*x*x;} this function will not consume any run time
        int y = cubed (1789); // computed at compile time
     */
    
    
    /*
        14 New String Literals
     
        C++ 03
        char * a = "string";
     
        C++ 11
        char * a = u8"string"; // to define an UTF-8 string
        char16_t * b = u"string"; // to define an UTF-16 string
        char32_t* c = U"string"; // to define an UTF-32 string
        char* d = R"String \\" // to defien a new string 就是两个\\, 因为是raw string，第一个\ 不会被解释成escape character anymore
     */
    
    /*
        15 Lambda fucntion
     
        cout << [](int x, int y){return x+y(3,4) <<endl; // output 7
        auto f  = [](int x, int y){return x+y};
        cout << f(3,4)<<endl; // output 7
     
        template<typename func>
        void filter(func f, vector<int>arr){
            for(auto i:arr){
                if(f(i))    // if functioon is true we print out function
                    cout << i<<"  "<<endl;
            }
        }
        vector<int> v ={1,2,3,4,5,6};
     
        functional programming:
        filter([](int x){return (x>3);}, v); // Output 4,5,6
        filter([](int x){return (x>2 && x<5);} v), output  3,4
     
        int y = 4;
        filter ([&](int x) {return (x>y);}, v); // Ouput 5,6 把variable传入function
        // Note [&] tells compiler that we want variable capture
     
     }
     
     */
    vector<int> v ={1,2,3,4,5,6};
    int y = 4;
    filter ([&](int x) {return (x>y);}, v);
}




#endif /* lesson2_h */
