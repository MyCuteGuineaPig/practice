//
//  lesson5User_Defined_Iterals.h
//  Modern C++
//
//  Created by beckswu on 7/8/17.
//  Copyright © 2017 beckswu. All rights reserved.
//

/*  User Defined Literal has some restriction for parameters:
    char const*
    unsigned long long
    long double
    char const*, std::size_t
    wchar_t const*, std::size_t
    char16_t const*, std::size_t
    char32_t const*, std::size_t
    input parameter只能是以上的几个之一
 */





#ifndef lesson5User_Defined_Iterals_h
#define lesson5User_Defined_Iterals_h

/*
    User Defined Literals
    Literals are constants.
 
    C++ has 4 kinds of literals:
    integer         ------  45
    floating point  ------  4.5
    character       ------  'z'
    string          ------  "Dog"
 
    45; //
 */

// User Defined Literals:

constexpr long double operator ""_cm(long double x){return x*10;} // use run time cost 所以加上constexpr
constexpr long double operator ""_m(long double x){return x*1000;}
constexpr long double operator ""_mm (long double x){return x;}

// operator "" 表示user defined iterals _cm 是identifier, suffix, return result 是long double
int operator ""_bin(const char * str, size_t l){ // 把二进制char转化成int make class as
    int ret = 0;
    for(int i = 0; i<l; i++){
        ret = ret << 1; // 向右推一位
        if (str[i]=='1') // 如果是1， 加1
         ret+= 1;
    }
    return ret;
}
// C++ went a long way to make user defined types (classes) to behave same as build-in types.
// user defined literals pushes this effort even further
// C++ 尽可能让user define class behaved 跟built in 一样（user defined literal behave as built in built literal）


void lesson_5(){
    45; // INT LITERAL
    45u; // unisnged int (suffix specified type)
    45l; // long
    
    //C++ 99
    // long double height = 34; // Metres? Centimeters? Inches? only writer know what it is 单位不统一
    
    /*
     理想是：
     height = 3.4cm;
     ratio = 3.4cm / 2.1 mm; ratio = 3.4*10/2.1 C++ don't support this sentax, 即使support，也不太喜欢，因为unit translation 有runtime cost
     */
    long double height = 3.4_cm;
    cout << "height is "<< height << endl;
    cout << (height+13.0_m)<<endl;

    cout << "110"_bin<<endl;
    cout << "1100110"_bin<<endl;
    cout << "110100010001001110001"_bin <<endl;
}



#endif /* lesson5User_Defined_Iterals_h */
