#ifndef lesson14NonmemberFunctions_h
#define lesson14NonmemberFunctions_h

/*
	getline(cin, s1); 读取输入值，然后传给s1,以换行分割“\n”
	getline(cin,s1,";") 读取输入值，然后传给s1,以分号分割

	to_string(8); convert to string
	s1 = to_string(2.3e7); // s1 = 23000000.000000
	s1 = to_string(0xa4); // 16 进制，s1 = 164
	s1 = to_string(034); // 8进制 s1 = 28


	stoi（） 可以一个参数，也可以两个参数；也可以是宪哥参数
	int i = stoi(s1, &pos); 
		-- 返回值，convert 的string， 
		-- 第一个参数是想convert 的string， 
		-- 第二个参数pass the reference size_t,是convert 到哪里停止了， 比如 s1 = "190 monkey", 到第三个位置，空格停止了
		-- 第三个参数是转化的方式，默认方式是10，可以是16， 8


	//stol, convert to long
	//stod convert to double
	//stof convert to float,
	//however they only does simple string conversion
*/

#include <iostream>
#include <string>
using namespace std;

void lesson_14() {
	// cout << s1 << endl;
	// cin >> s1； //input
	string s1;
	//getline(cin, s1);//read line from standard input default delimeter of "\n"
	//getline(cin, s1, ";") //delimeter is ";"
	s1 = to_string(2.3e7); // s1 = 23000000.000000
	s1 = to_string(0xa4); // 16 进制，s1 = 164
	s1 = to_string(034); // 8进制 s1 = 28

	//convert a string into a number 
	s1 = "190";
	int i = stoi(s1); //i: 190
	s1 = "190 Monkeys";
	size_t pos;
	i = stoi(s1, &pos); // i: 190, pos is the index of character, where string stop passing number
	// pos equal to three, the space 空格时候停止pass

	s1 = "a monkey";
	// i = stoi(s1, &pos); //exception of invalid_argument, becuase the function fails to find string s1
	i = stoi(s1, &pos, 16); //pass 16 进制的数字，发现a 是16进制的，get i == 10
	//stoi function convert a string into a integer

	//stol, convert to long
	//stod convert to double
	//stof convert to float, 
	//however they only does simple string conversion 

	// if you want more complex data formating 
	//stringstream 

	//lexical_cast<>
}

#endif
#pragma once
