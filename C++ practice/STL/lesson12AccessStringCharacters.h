#ifndef lesson12AccessStringCharacters_h
#define lesson12AccessStringCharacters_h
/*
	s1[2] and s1.at(2) is not identical, s1.at(200) will throw out of range exception whereas s1[200] will be undefined behavior
	
	s1.front() //返回第一个char in string
	s1.back() //返回最后一个char in string
	s1.push_back() // 往string 后面append char
	s1.pop_back() // 删掉最后一个string

	s1.begin()
	s1.end() 
	like vector, string doesn't have push_front() and pop_front()


	assign function 有点像string constructor 
	s1.assign()
	    -- 当第一个参数是cstring, 第二个参数代表length，从cstring的头开始，截取多少
		-- 当第一个参数是string, 第二个参数代表起始位置，第三个参数代表长度（必须要有第三个，跟constructor有点不一样）
		-- 当一个参数是数字，第二个是char，代表重复这个char 多少遍
		-- 当参数是char * or char [], 直接变成string

	s1.append(" def"); 在末尾append string
	s1.insert()
		-- 第一个参数是s1 insert 开始的位置，第二个参数插入的string， 第三个参数是选取插入string的长度
	s1.replace(2, 5, s2, 3, 3); 
		-- 第一个参数是s1 准备replace 的起点，第二参数是s1从起点开始replace的长度
		第三个string 是准备replace的string，第四个参数是，s2 起始的位置，第五个参数是s2 replace 的长度

	s1.erase(1, 4); 
		-- 第一个参数是s1 erase的起点，第二个参数是erease 的长度
	s2.substr(2, 4);
		-- 第一个参数是substring 的起点,第二个是长度

	s1 = "abc";
	s1.c_str(); // "abc\0" convert string to cstring
	s1.data(); // convert to cstring without \0 termination but in C++ 11, it aslo return termination 
	s1.swap(s2); // swap two strings

*/

#include <iostream>
#include <string>
using namespace std;

void lesson_12() {
	//sting Element Access
	string s1 = "Goodbye";
	cout << s1[2] << endl; // 'o'
	s1[2] = 'x'; //Goxbye
	s1.at(2) = 'y'; //Goybye
	//s1[2] and s1.at(2) are not identical, s1.at(200) will throw exception 
	//whereas s1[200] will not throw exception will be undefined behavior

	s1.front(); // 'o'
	s1.back();//'e'
	s1.push_back('z');//append the character in the end of string
	s1.pop_back(); // pop out of the last character
	s1.begin(); //will return a iterator which point the beginning of string
	s1.end(); // will return a iterator pointing the end of string

	//string like vector don't have push_front(), pop_front()
	string s3(s1.begin(), s1.begin() + 3); //s3 = "Goo"

	//Ranged Access 
	//Assign, append, insert, replace 

	string s2 = "Dragon Land";
	s1.assign(s2); // s1 = s2 assign is more flexible
	s1.assign(s2, 2, 4);// s1 take portion of s2, length of 4 starting at 2 s1 = "agon"
	s1.assign("Wisdom"); // cstream
	s1.assign("wisdom", 3); //S1:Wis when first is cstring, second parameter is size
	//s1.assign(s2, 3);// Error won't complie
	s1.assign(3, 'x'); //s1 = "xxx"
	s1.assign({ 'a','b','c' }); //s1='abc'


	//append()
	s1.append(" def"); //s1 = "abc def"
	s1.insert(2, "mountain", 4); // 2是s1 的起始位置，4是截图mountain的长度， moun  s1="abmounc def"
	s1.replace(2, 5, s2, 3, 3); // starting at s1 position 2, size 5, replace s2 starting at position 3, size is 3
	// s1 = "abgon def", looks like s1.assign(s2, 2, 4);

	//s1.erase(1, 4); //s1 erase starting from 1, size is 4, a = "def"
	s2.substr(2, 4); // s1 starting at position 2, position is 4 return // agon

	s1 = "abc";
	s1.c_str(); // "abc\0" convert string to cstring
	s1.data(); // convert to cstring without \0 termination but in C++ 11, it aslo return termination 
	s1.swap(s2); // swap two strings
}


#endif
#pragma once
