#ifndef lesson13StringMemberFunction_h
#define lesson13StringMemberFunction_h

/*
	member function algorithm, copy, find, compare


	copy function is the only exception in the string class where 第二个参数是长度，第三个参数是起始的位置
	size_t len = s1.copy(buf,4,2); // 复制s1 从第二个位置开始，长度为4，返回值是真实被copy的长度

	find,
	size_t found = s1.find("doing well", 0, 5); 
	-- 参数可以是一个，两个或者三个，返回值是找到这个目标string的s1开始的位置
		-- 第一个参数是在s1 中出现的string
		-- 第二个参数是从s1 的什么位置开始
		-- 第三个参数是找目标string 的长度，"doing well" 的前5位，“doing” 找s1 中“doing”的位置

	found = s1.find_first_of("doing", 10, 1); 
	-- 寻找目标string 中的char 在目标string 中的， 就是找s1第一个位置出现d, 或 o 或 i 或 n 或g的位置
	-- 参数可以是一个，两个或者三个，返回值是找到这个目标string的s1开始的位置
		-- 第二参数是s1 开始的位置
		-- 第三个参数是第一个参数cstring 的截取值，比如1,代表只去s1中寻找d的值，

	find_last_of // 找到最后一个在cstring中的char
	find_first_not_of //找到第一个不是目标string 的char
	find_last_not_of //找到最后一个不是目标string的char
	跟上面的find_first_of 一样

	compare
	s1.compare(3,2, s2);
	// 如果s1>s2 返回值是positive, 如果s1<s2, 返回值是negative, 如果s1==s2, 返回值是0
	// 可以有一个参数，两个，或者三个，
	//最后一个是比的对象，

*/

#include <iostream>
#include <string>
using namespace std;

void lesson_13() {
	string s1 = "abcdefg";
	char buf[20];
	size_t len = s1.copy(buf, 3);// it will copy three characters from s1 to buf
	//return is number of character that is indeed copy, 
	//buf="abc"  len == 3 note buf is not terminated
	len = s1.copy(buf, 4, 2); // this will copy portional s1 to buf, s1 starting position 2 and size is 4
	//buf: cdef, len==4
	

	s1 = "If a job is worth doing, it's worth doing well";
	size_t found = s1.find("doing");//this will find the string doing in string one, found is the position that it is found
	// found = 17, 17是doing 中d 的位置
	found = s1.find("doing", 20); // this will starting searching at position 20//found ==35
	found = s1.find("doing well", 0); // found = 35
	found = s1.find("doing well", 0, 5); //found will starting from 0 and only look at 5 character in "doing well", found == 17

	found = s1.find_first_of("doing"); // this will search the first character is s1 in appear in "doing",只找第一个d,o,i,n,g出线位置
	//found = 6
	found = s1.find_first_of("doing", 10); // will start searching at position 10, found = 12, worth 中的o
	found = s1.find_first_of("doing", 10, 1);//只会找从s1 第10个位置开始，doing 中第一个元素d，第一次出现的位置

	found = s1.find_last_of("doing"); //found = 939 doing well 的g
	found = s1.find_first_not_of("doing"); // found = 0
	found = s1.find_last_not_of("doing"); // 最后一个位置， found = 44;

	string s2("If a job is worth doing");
	s1.compare(s2);//return positive if s1>s2, negative if (s1<s2), 0 if )(s1 == s2)
	// if(s1>s2){} // if s1.compare(s2) >0 
	//compare can compare portion of string
	s1.compare(3, 2, s2);//this will start the comparison at position 3 and only compare 2 characters

	string ss = s1 + s2; // concatenate, this might give ur illusion, this operation is cheap
	// this opeartion is very expensive when string size is very big
}



#endif
#pragma once
