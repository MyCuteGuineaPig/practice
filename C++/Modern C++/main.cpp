//
//  main.cpp
//  Modern C++
//
//  Created by beckswu on 7/6/17.
//  Copyright © 2017 beckswu. All rights reserved.
//

#include <iostream>
#include "lesson1.h"
#include "lesson2.h"
#include "lesson3Rvalue_Reference.h"
#include "lesson4Perfect_Forwarding.h"
#include "lesson5User_Defined_Iterals.h"
#include "lesson6Compiler_Generated_Function.h"
#include "lesson7Shared_Pointer.h"
#include "lesson8Shared_PointerII.h"

int main(int argc, const char * argv[]) {
    
    cout<<"-----------------------------lesson1 C++11 introduction I---------------------------"<<endl;
    lesson_1();
    
    cout<<endl<<"-----------------------------lesson2 C++11 introduction II---------------------------"<<endl;
    lesson_2();
    
    cout<<endl<<"-----------------------------lesson 3 Rvalue Reference--------------------------"<<endl;
    lesson_3();
    
    cout<<endl<<"-----------------------------lesson 4 Rvalue Reference Perfect Forwarding--------------------------"<<endl;
    lesson_4();
    
    cout<<endl<<"-----------------------------lesson 5 User Defined Literals---------------------------"<<endl;
    lesson_5();
    
    cout<<endl<<"-----------------------------lesson 6 Compiler Generated Functions-------------------------"<<endl;
    lesson_6();
    
    cout<<endl<<"-----------------------------lesson 7 Shared Pointer I--------------------------"<<endl;
    lesson_7();
    
    cout<<endl<<"-----------------------------lesson 8 Shared Pointer II--------------------------"<<endl;
    lesson_8();
    
    return 0;
}
