#ifndef lesson15StringAndAlgorithms_h
#define lesson15StringAndAlgorithms_h

/*
	An Advantage of string is can pass algorithm to string just as pass to vector

	count, 数string 中有几个
	count_if 可以自己设置lambda function

	string::iterator itr = search_n(s1.begin(), s1.begin() + 20, 2, 's');
	search_n 找到第一个连续出现n的位置
		-- 返回值是iterator, point to 出现的位置
		-- 第一个，第二个参数，是找出现的位置，
		-- 第三个参数是n， 连续出现几回
		-- 第四个参数是单个的pattern


	s1.insert(itr, 3, 'x'); //insert 在itr 前面
	s1.replace(itr, itr + 3, 3, 'y'); 
	-- 第一个第二个参数指的是s1 被replace的范围，第三个参数是重复几回，第四个参数是插入的数

	is_permutation(s1.begin(), s1.end(), s2.begin()); this test if s1 is a permutaion of s2

	remember the algorithm function replace and member function replace
	member function 替换 substring (s1.replace) 替换位置的元素
	algorithm replace is to replace character (replace) 找到元素并替换


	transform() 
	-- 根据operation 转换string 并存到另一个string
		--	第一个第二个参数代表像转换string的起始点
		-- 第三个参数表示保存的string 的起点
		-- 第四个参数是lambda function 表示所对应的operation

	rotate(s1.begin(), s1.begin() + 3, s1.end());
	让string的第四个element 变成第一个元素，第五个是第二个，然后随后排队，展开，之前的第一个排到之前最后一个的后面

	string 的其他形式
	u16string s1; // string char16_t; char 16 bits character
	u32string s2; // string char32_t；
	wstring s0; // wstring wchar_t(wide character)

	// one exception
	//to_wstring(); which is specific defined for wstring()
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void lesson_15() {
	string s1 = "Variety is the spice of life";
	// we want to count how many times e appear in this sentence

	int num = count(s1.begin(), s1.end(), 'e'); // return 4
	num = count_if(s1.begin(), s1.end(), [](char x) {return (x <= 'e' && x >= 'a'); }); // return 6

	s1 = "Goodness is bettern than beauty";
	string::iterator itr = search_n(s1.begin(), s1.begin() + 20, 2, 's'); // search
	// search两个连续的s 在string s1 中第一次出现的位置
	

	s1.erase(itr, itr + 5);
	s1.insert(itr, 3, 'x');
	s1.replace(itr, itr + 3, 3, 'y'); // member function replace substring

	// is_permutation(s1.begin(), s1.end(), s2.begin()); this test if s1 is a permutaion of s2
	
	replace(s1.begin(), s1.end(), 'e', ' '); // replace 'e' with space
	cout << 12 << endl;
	//remember the algorithm function replace and member function replace
	//algorithm replace is to replace character

	s1 = "Goodness is bettern than beauty";
	string s2="                                               ";
	transform(s1.begin(), s1.end(), s2.begin(),
		[](char c) {
		if (c < 'n')
			return 'a';
		else
			return 'z';
	}); //replace the char which is less than n with a , and replace the char bigger than n with z, and save to s2
	cout << 12 << endl;
	s1 = "abcdefg";
	rotate(s1.begin(), s1.begin() + 3, s1.end()); // s1: defgabd

	u16string s4; // string char16_t; char 16 bits character
	u32string s; // string char32_t；  
	wstring s0; // wstring wchar_t(wide character)

	// one exception
	//to_wstring(); which is specific defined for wstring()
}
#endif
#pragma once
