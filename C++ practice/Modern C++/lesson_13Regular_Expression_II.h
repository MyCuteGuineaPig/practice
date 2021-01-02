//
//  lesson_13Regular_Expression_II.h
//  Modern C++
//
//  Created by beckswu on 7/8/17.
//  Copyright © 2017 beckswu. All rights reserved.
//

#ifndef lesson_13Regular_Expression_II_h
#define lesson_13Regular_Expression_II_h

//Various Regular Expression Grammars
// Regex Submatch

/*
    C++ support six regular expression grammer:
    1. ECMAScript (default)
    2. basic
    3. extended
    4. awk
    5. grep
    6. egrep
 
    想要找submatch 并提取出来需要在regex 中分组()
    regex e_email("([[:w:]]+)@([[:w:]]+)\.edu");
 
     smatch m; // typedef std@match_result<string>, used to store sub group name
    bool match1 = regex_search(str,m,e_email); // 搜索pattern e，并存在m中
    
    smatch 的function
    mm.size() // 返回m中的个数， 有多少个sub match在regex_search中
    叫第i个 match 在smatch中：mm[n].str().mm.str(n),*(mm.begin()+n)

    mm.prefix().str() // prefix is everything in front of matched string in original string
    mm.suffix().str() // suffix is everything is end of matched string in original string
 
 
 
 */
#include <regex>
using namespace std;

void lesson_13(){
    // FOR example, I don't want to use ECMA grammar, I want to use grep grammer
    regex e("^abc.+",regex_constants::grep); // +不是很多次的意思在grep 中
    
    string str = "abcd+";
    
    bool match = regex_search(str,e);
    cout << (match?"Matched":"Not Matched")<<endl;
    
    
    //submatch
    str = "jwu@illinois.edu";
    smatch m; // typedef std@match_result<string>, used to store sub group name
    regex e_email("([[:w:]]+)@([[:w:]]+)\.edu"); // \. means 就是。而不是means any character
    // we want grab username or domain name for email
    
    bool match1 = regex_search(str,m,e_email); // search e and store in m
    
    cout << " m.size() "<<m.size() <<endl; // call num of result stored in m
    for(int n=0; n<m.size();n++)
        cout << "m["<<n<<"]: str() = "<<m[n].str() <<endl;
    
    cout << "m.prefix().str(): "<<m.prefix().str()<<endl; // prefix is everything in front of matched string
    cout << "m.suffix().str():  "<<m.suffix().str()<<endl; // suffix is everything is end of matched string
    
    
    
    
    
    //
    cout << "example 2"<<endl;
    str = "<begin>jwu@illinois.edu<end>";
    smatch mm; // typedef std@match_result<string>, used to store sub group name
    regex e_email2("([[:w:]]+)@([[:w:]]+)\.edu"); // \. means 就是。而不是means any character
    // we want grab username or domain name for email
    
    match1 = regex_search(str,mm,e_email2); // search e and store in m
    
    cout << " m.size() "<<mm.size() <<endl; // call num of result stored in m
    for(int n=0; n<mm.size();n++)
    {
        cout << "m["<<n<<"]: str() = "<<mm[n].str() <<endl;
        cout << "m["<<n<<"]: str() = "<<mm.str(n) <<endl;
        cout << "m["<<n<<"]: str() = "<<*(mm.begin()+n) <<endl;
    }
    cout << "m.prefix().str(): "<<mm.prefix().str()<<endl; // prefix is everything in front of matched string
    cout << "m.suffix().str():  "<<mm.suffix().str()<<endl; // suffix is everything is end of matched string

}

#endif /* lesson_13Regular_Expression_II_h */
