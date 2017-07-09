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
#include "lesson9Weak_Pointer.h"
#include "lesson_10Unique_Pointer.h"
#include "lesson_11Resource_Managing_Class.h"
#include "lesson_12Regular_Expression.h"
#include "lesson_13Regular_Expression_II.h"
#include "lesson_14Regular_Expression3_Iterator.h"
#include "lesson_17Random_Number_Engine.h"
#include "lesson_18Random_Number_Distribution.h"
#include "lesson_19Tuple.h"
#include "lesson_20When_to_use_tuple.h"

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
    
    cout<<endl<<"-----------------------------lesson 9 Weak Pointer-------------------------"<<endl;
    lesson_9();
    
    cout<<endl<<"-----------------------------lesson 10 Unique Pointer-------------------------"<<endl;
    lesson_10();
    
    cout<<endl<<"-----------------------------lesson 11 Resource Managing Class-------------------------"<<endl;
    lesson_11();
    
    cout<<endl<<"-----------------------------lesson 12 Regular Expression I-------------------------"<<endl;
    lesson_12();
    
    cout<<endl<<"-----------------------------lesson 13 Regular Expression II Submatch-------------------------"<<endl;
    lesson_13();
    
    cout<<endl<<"-----------------------------lesson 14 Regular Expression III Iterators-------------------------"<<endl;
    lesson_14();
    
    cout<<endl<<"-----------------------------lesson 17 Random Number Engine-------------------------"<<endl;
    lesson_17();
    
    cout<<endl<<"-----------------------------lesson 18 Random Number Distribution-------------------------"<<endl;
    lesson_18();
    
    cout<<endl<<"-----------------------------lesson 19 Tuple-------------------------"<<endl;
    lesson_19();
    
    cout<<endl<<"-----------------------------lesson 20 when to use tuple-------------------------"<<endl;
    lesson_20();
    
    return 0;
}
