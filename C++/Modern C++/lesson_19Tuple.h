//
//  lesson_19Tuple.h
//  Modern C++
//
//  Created by beckswu on 7/9/17.
//  Copyright © 2017 beckswu. All rights reserved.
//

/*
 tuple initialization:  tuple <int, string, char> t(32, "Penny wise",'a');
 或者用make_tuple    tuple<char,int>a;
                    a = make_tuple('f',4);
 
 
        get<0>(t), get<1>(t), 获取tuple 第一个值，第二个值
        get<1>(t) = "Pound Foolish" 改变tuple的值
        //index for get<> 必须是compile time constant
 
        tuple 是可以存入reference的，没有任何stl 可以存入reference
        string st = "In for a penny";
        tuple <string&> t3 (st);
        get<0>(t3) = "In for a pound"; // St contains "In for a pound"，改变string 和 tuple的值
        t3 = make_tuple(ref(st)); 将string 做为reference存入tuple
 
        将tuple的值从tuple中取出来，放进int,char,string
        int x;
        string y;
        char z;
        make_tuple(ref(x),ref(y),ref(z)) = t2;
        或者：
 
        tie(x,y,z) = t2; // tie 的优势是假如一个value in tie是不需要的，we can ignore it
        tie(x, std::ignore, z) = t2; // string value is ignored

        将两个tuple 结合起来
        std::tuple_cat(t2,t3); // t4 is a tuple <int, string, char, string &>
 
        tuple_size<decltype(t4)>::value << endl; 返回tuple的size
        std::tuple_element<1,decltype(t4)>::type d;  根据tuple里面类型定义
 */


#ifndef lesson_19Tuple_h
#define lesson_19Tuple_h

#include <tuple>
using namespace std;

void lesson_19(){
    std::pair<int,string> p = make_pair(23,"hello");
    cout << p.first << " "<<p.second<<endl;
    
    tuple <int, string, char> t(32, "Penny wise",'a');
    cout << get<0>(t)<<endl;
    cout << get<1>(t)<<endl;
    cout << get<2>(t)<<endl;
    
    get<1>(t) = "Poound foolish";
    string & s = get<1>(t);
    s = "Patience is virtue";
    
    //get<3>(t); 不能compile
    vector<int> v(3);
    //index for get<> 必须是compile time constant
    
    int i = 1;
    //get<i>(t); // 不能被compile,
    tuple <int, string, char> t2; // default constructor
    t2 = tuple <int, string,char>(12,"curiosity kills the cat",'d');
    
    t2 = make_tuple(12,"curiosity kills the cat",'d');
    
    if(t>t2){
        //lexicographical comparison
        cout << "t is larger than t2"<<endl; // 因为32>12
        t = t2; // member by member copying
    }
    
    //Tuple can store references，没有任何的stl container可以储存references; STL 都是需要copy，move的
    string st = "In for a penny";
    tuple <string&> t3 (st);
    t3 = make_tuple(ref(st));
    get<0>(t3) = "In for a pound"; // St contains "In for a pound"
    t3 = make_tuple(ref(st));
    cout << get<0> (t3) <<endl;
    //string member of tuple is a reference of tuple member st
    
    int x;
    string y;
    char z;
    make_tuple(ref(x),ref(y),ref(z)) = t2;
    
    cout << "x "<< x << " y "<< y << " z "<<z<<endl;
    
    // tie do the same thing
    tie(x,y,z) = t2; // tie 的优势是假如一个value in tie是不需要的，we can ignore it
    tie(x, std::ignore, z) = t2; // string value is ignored
    
    auto t4 = std::tuple_cat(t2,t3); // t4 is a tuple <int, string, char, string &>
    
    //type traits
    cout << tuple_size<decltype(t4)>::value << endl; // 4 tuple 的size
    std::tuple_element<1,decltype(t4)>::type d;  // d是string
    tuple<char,int>a;
    a = make_tuple('f',4);
}

















#endif /* lesson_19Tuple_h */
