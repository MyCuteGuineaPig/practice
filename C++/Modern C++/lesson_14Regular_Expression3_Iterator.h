//
//  lesson_14Regular_Expression3_Iterator.h
//  Modern C++
//
//  Created by beckswu on 7/8/17.
//  Copyright © 2017 beckswu. All rights reserved.
//

/*
    regex e("([[:w:]]+)@([[:w:]]+)\.com");
    1. Regex Iterator
    可以找到subgroup 的方法用iterator 初始化Regex Iterator: sregex_iterator pos(str.cbegin(),str.cend(),e);
    sregex_iterator pos(str.cbegin(),str.cend(),e);
    sregex_iterator end;
    for(;pos!=end; pos++){
            cout << "Matched: "<<pos->str(0)<<endl; // 0是match的
            cout << "Username "<<pos->str(1)<<endl; // 1是subgroup 1
            cout << "Domain "<<pos->str(2)<<endl; // 2是subgroup 2
    }
 

    2. Regex Token Iterator
    sregex_token_iterator poss(str.begin(),str.cend(),e,0);
    //token iterator 可以选择额外的paratmeter，如果不设置默认是0，0代表满足的结果，不会显示subgroup
    //如果是1， 只要subgroup 1, 只显示sub group 1
    //如果是2， 只要subgroup 2, 只显示sub group 2
    //如果parameter是 -1, 只有不match regular expression 被extracted
 
    sregex_token_iterator endd;
    for(; poss!=endd; poss++)
        cout << "Match (Token Iterator )"<<poss->str()<<endl; // extract every email

 
    3. Regex_replace
       cout << regex_replace(str, e, "$1 is on $2",regex_constants::format_no_copy)<<endl;
     //用strin "$1 is on $2" 代替 match string subgroup 1 and subgroup 2
    // $1 match first sub match, $2 matches second sub match
    // 还可以显示另一个parameter,regex_constants::format_no_copy: 意思是没有match的string不会被copy到新string
    // regex_constants::format_first_only 只显示第一个match的，only first one is considered as match and everything else 不会认为是matched
 
 */


#ifndef lesson_14Regular_Expression3_Iterator_h
#define lesson_14Regular_Expression3_Iterator_h


#include <regex>
using namespace std;


void lesson_14(){
    string str ="boq@gmail.com;  boqian@hotmail.com;;  bo_qian2000@163.com";
    
    regex e("([[:w:]]+)@([[:w:]]+)\.com");
    
    smatch m;
    
    /* 只打出了第一个email address
    bool found = regex_search(str,m,e);
    for(int n=0; n<m.size();n++)
    {
        cout<<"m["<<n<<"]:str()="<<m[n].str()<<endl;
    
    }*/
    
    
    //*************************Regex Iterator *****************************
    // apply regex_iterater to apply target string
    sregex_iterator pos(str.cbegin(),str.cend(),e);
    sregex_iterator end;
    for(;pos!=end; pos++){
        cout << "Matched: "<<pos->str(0)<<endl;
        cout << "Username "<<pos->str(1)<<endl;
        cout << "Domain "<<pos->str(2)<<endl;
        cout << endl;
    }
    
    //*************************Regex Token Iterator *****************************
    // every match只能match 一个result
    sregex_token_iterator poss(str.begin(),str.cend(),e,0);
    //token iterator can take one extra parameter which is how to extract result
    // defautl is 0, 如果是1， 只要subgroup 1, 就是username extract, 如果是2， 是domain extracted
    // parameter is -1, 只有不match regular expression 被extracted
    
    sregex_token_iterator endd;
    for(; poss!=endd; poss++){
        cout << "Match (Token Iterator )"<<poss->str()<<endl; // extract every email
    }
    
    //*************************Regex replace*****************************
    cout << regex_replace(str, e, "$1 is on $2",regex_constants::format_no_copy)<<endl;
    //cout << regex_replace(str, e, "$1 is on $2",regex_constants::format_no_copy|regex_constants::format_first_only)<<endl;
    // replace match string group 1 and group 2 with string as "$1 is on $2"
    // $1 match first sub match, $2 matches second sub match
    // 还可以显示另一个parameter,regex_constants::format_no_copy: 意思是没有match的string不会被copy到新string
    // regex_constants::format_first_only 只显示第一个match的，only first one is considered as match and everything else 不会认为是matched
}






#endif /* lesson_14Regular_Expression3_Iterator_h */
