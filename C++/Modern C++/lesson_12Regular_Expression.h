//
//  lesson_12Regular_Expression.h
//  Modern C++
//
//  Created by beckswu on 7/8/17.
//  Copyright © 2017 beckswu. All rights reserved.
//


/*
 
 Regular Expression: A regular  expression is a specfic pattern that provides concise and flexible means to match strings of 
 text, such as particular characters, word, or patterns of charaters - wikipedia
 
 
 . means any character except newline
 regex e("abc.",regex_constants::icase); // match any string starting with abc and then follow by one character
 abcc matched, 但是aabcc 不行
 
 ？zero or 1 preceding character(最后一个character出现1遍或者两遍)
 regex e("abc?"); 这里c是preceding character
 abc, matched, ab matched,
 
regex e(“abc*”) * 是zero or more predecing character (最后一个character出现很多次或者不出现)
abc, abcccc, ab all matched, 但是aab 不行
 
 regex e(“abc+”) + one or more preceding character
 abc, abcccc matched 但是ab不match
 
 regex e("ab[cd]*"); [] Any character inside the square brakets, 只要是ab后面跟着c,or d, or 没有 出现就matched
 abc, ab, abcd, abccccdddd   matched  abbcc not matched(因为多了个b)
 
 regex e("ab[^cd]*"); [^] Any character not inside the bracket matched（只要不出线c,d就match）
 abe, abefg ab  match 但是 abc not matched
 
 regex e("ab[cd]{3}") {3} exact three appearing for preceding character
 abddd, abdcd, abccc matched 但是abcdcd 不匹配
 
regex e("ab[cd]{3, }") {3, } three or more appearing for preceding character
abcccc, abcdcdcd matched, 但是abcc不matched
 
regex e("ab[cd]{3,5}") {3,5} 代表区间preceding character只能出现3，4，5次
 
regex e("abc|de[fg]") | 代表前面或者后面成立 ，【】中的只出现一个
 abc, def, deg match, defg 不match
 
 regex e("abc|de[\]fg]")   matched afbc or  de] or def or deg
 
 regex e("(abc)de + \\1") () was used to define a group \\1 means sub match will appear here again 第一个\ 是escape \ 
 abcdeeabc matched 
 
 regex e("(ab)c(de+)\\2\\\1") 2个group
 abcdeeedeeab matched 
 
 [[:w:]] word character 包括了digit, number or underscore
 
 
 regex e_email("[[:w:]]+@[[:w:]]+\.edu"); // \. means 就是。而不是means any character
 
 Cplusplus.com 有更多的regular expression
 class                     description                             equivalent (with regex_traits, default locale
 [:alnum:]         alpha numerical character                         isalnum
 [:alpha:]         alphabetic character                              isalpha
 [:blank:]         blank    character           
 [:cntrl]          control character                                 iscntrl
 [:digit:]         decimal digit character                           isdigit
 [:graph:]         character with graphical representation           isgraph
 [:lower:]         lowercase letter                                  islower
 [:print:]         printable character                               isprint
 [:punct:]         punctuation mark character                        ispunct
 [:space:]         whitespace character                              isspace
 [:upper:]         uppercase letter                                  isupper
 [:xdigit:]        hexadecimal digit character                       isxdigit
 [:d:]             decimal digit character                           isdigit
 [:s:]             whitespace character                              isspace

 
 regex e("abc.")
 bool match = regex_match(str,e); // 要整个string match regex e
 
 bool match1 = regex_search(str,e); // search whether substring match it
 aaaaaabce,    aaabcde matched
 
 regex e("^abc.") 只能是beginning of string,只能在开始位置，不能在中间或结束的位置
  bool match1 = regex_search(str,e);
 abcd matched, 但是aaabcd 不match
 
 regex e("abc.$") $ 只能是end of string,只能在结束的位置
 bool match1 = regex_search(str,e);
 aaaaabcd matched, 但是aaabcde 不match

 
 
 */

#ifndef lesson_12Regular_Expression_h
#define lesson_12Regular_Expression_h


#include <regex>
using namespace std;

void lesson_12(){
    string str = "jwu@illinois.edu";
    
    
    //cin >> str;
    //regex e("abc");
    //regex ee("abc.",regex_constants::icase); // ignore the cast
    regex e("abc|de[fg]");
    
    regex e_email("[[:w:]]+@[[:w:]]+\.edu"); // \. means 就是。而不是means any character
    
    
    bool match = regex_match(str,e_email); // 只可以match string 小写 abc
    
    bool match1 = regex_search(str,e); // search whether substring match it
    cout << (match? "Matched ":"Not matched")<<endl;

}





















#endif /* lesson_12Regular_Expression_h */
