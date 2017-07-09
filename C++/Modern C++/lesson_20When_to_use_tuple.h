//
//  lesson_20When_to_use_tuple.h
//  Modern C++
//
//  Created by beckswu on 7/9/17.
//  Copyright © 2017 beckswu. All rights reserved.
//

#ifndef lesson_20When_to_use_tuple_h
#define lesson_20When_to_use_tuple_h

/*
    tuple: 用于function，只用一次，然后return 多个值得，
 
    用于compare 时间序列
    //Comparion of tuples
    tuple<int, int, int> time1, time2; // hours, minutes, seconds
    if (time> time){
        cout << "time 1 is a later time ";
    }
 
    做为map, 和unordered_map 的index
    map<tuple<int,char,float>,string>m;
    m[make_tuple(2,'a',2.3)] = "Faith will move mountains";
    unordered_map<tuple<int,char,float>,string> hastable;
 
 
    数据交换
    int a, b ,c; // reverse data
    tie (b,c,a) = make_tuple(a,b,c);

 
 */

#include <tuple>
#include <string>
#include <map>
using namespace std;


struct Person20 {
    string name;
    int age;
};

tuple<string,int> getNameAge(){
    
    return make_tuple("Bob",34);
}




void lesson_20(){
    struct Person20 p;
    tuple<string, int> t;
    //cout<<p.name<< " "<<p.age<<endl;
    //cout << get<0>(t) << "  "<<get<1>(t)<<endl; struct and tuple are defined differently but they can achieve the same goal
    
    //tuple 不知道什么位置是存的name, 什么位置存的name, 然后得去找，figure out
    //如果把鼠标移动到p的位置，会显示是struct person，但是把鼠标移动到tuple，不知道the meaning of t, make my code readable,
    string name;
    int age;
    tie(name,age) = getNameAge();
    // tuple 是有优势的对于 one time only structure to transfer a group of data
    // using tuple can solve hassle to 定义struct
    
    
    //Comparion of tuples
    tuple<int, int, int> time1, time2; // hours, minutes, seconds
    if (time> time){
        cout << "time 1 is a later time ";
        
    }
    // work for map
    // multiindex map
    map<tuple<int,char,float>,string>m;
    m[make_tuple(2,'a',2.3)] = "Faith will move mountains";
    
    // use tuple to create a multiindex hashtable
    //unordered_map<tuple<int,char,float>,string> hastable;
    
    int a, b ,c; // reverse data
    tie (b,c,a) = make_tuple(a,b,c);
}

#endif /* lesson_20When_to_use_tuple_h */
