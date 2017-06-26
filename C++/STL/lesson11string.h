#ifndef LESSON11STRING_H
#define LESSON11STRING_H


/*
	string constructor 可以copy cstring, 然后可以说从开始copy几个，
	也可以copy string，注意第一个数字是哪个地方开始，如果没有第二个数字，意味着copy到结束，如果有第二个数字，代表着copy几个
	如果数字出现在第一位，之后是一个char，代表重复那个char 几遍
	string 也可以initialized from char *
	string s3(s1.begin(), s1.begin() + 3); //s3 = "Goo" 也可以construct from iterator

	size(), length() 的功能一样
	capacity() 返回目前有一个size of storage space allocated to s1, 
	capacity 必须大于size capacity might be changed
	s1. reserve() // reserve 多少个character space 到这个string
	如果reserve 的比string size小了，不会改变string content， reserve 不会改变content， 也不会改变size

	s1.shrink_to_fit(); shrink the capacity to hold the content; 也相当于call reserve function to smallest number
	s1.resize(); 会改变size， content,
	s1.resize(100,'x'); 会padded character 如果resize 比之前的大了，会在后面填上x

	reserve 不会改变size, content of string 但是resize会
}

*/
#include <iostream>
#include <string>
using namespace std;

void lesson_11() {
	//Constructor
	string s1("Hello"); // constructed from cstring
	string s2("Hello", 3); //3代表size, constructed from cstring s2= "Hel"
	string s3(s1,2); // 2代表从哪里开始， copy constructor, s3="llo", 

	string s4(s1, 2, 2);// starting from 2, size is 2, s4 = "ll"
	string s5(5, 'a'); // 数字放前面代表几个， 有5个

	string s6({ 'a','b','c' }); //string constructed from initialized list
	// this is very useful when u have individual variables stored in the char array
	//s6 = "abc"


	//SIZE
	s1 = "Goodbye";
	//s1.size(); s1.length(), Synonymous, both returns 7 功能一样
	s1.capacity(); // size of storage space currently alllocated to s1, 
	//capacity must bigger than size

	s1.reserve(100); // 会reserve 100个character space 到string 1
	s1.reserve(5); // 也可以减少size, s1: Goodbye, s1.size() == 7, reserve 不会改变content， 也不会改变size， it only work for capacity

	s1.shrink_to_fit(); // shrink the capacity to hold the content; 也相当于call reserve function to smallest number
	s1.resize(9); // s1: Goodbye\0\0
	s1.resize(12, 'x'); // s1:Doodbye\0\0xxx padd with different character 
	s1.resize(3); // s1:Goo
}




#endif
#pragma once
