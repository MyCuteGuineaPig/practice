#ifndef LESSON5ITERATORSANDALGORITHM_H
#define LESSON5ITERATORSANDALGORITHM_H

#include<vector>
#include <iostream>
#include <list>
#include <set>
#include <iterator>
#include <algorithm>
using namespace std;

bool isOdd(int i) {
	return i % 2;
}

void lesson_5() {

	/*iterator*/
	// 1 Random Access Iterator: vector, deque, array
	/*
	vector<int> itr;
	itr = itr + 5; // advance itr by 5
	itr = itr - 4; 
	if (itr2 > itr1) ... which one is front which one is in the back
	++itr;
	--itr;*/

	// 2 Bidirectional Iterator: list+ asscoiative container: set/multiset, map/multimap
	/*
	list<int>itr;
	++itr;
	--itr;
	*/

	//3 Forward Iterator: foward_list
	/*
	forward_list<int>itr;
	++itr; 只能++， 不能--
	*/

	// unordered containers provide "At Least" foward iterators， they have option to have bidirectional Iterator

	//4 Input Iterator: read and process values while iterating foward
	// int x = * itr; you can read and deference from iterators but cannot write to it不能改变它，可以输出它

	//5. Ouput Iterator: Ouput values while iterating forward
	//*itr = 100;
	//Both Input and Output Iterator 只能move foward， 只能++， 不能--


	// Every container has a iterator and a const_iterator
	set<int>::iterator it;
	set<int>::const_iterator citr; // read_only access to container elements

	set<int>myset = { 2,4,5,1,9 };
	for (citr = myset.begin(); citr != myset.end(); ++citr)
		cout << *citr << endl;
	// *citr = 3; 会报错

	//for_each(myset.cbeing(),myset.cend(),MyFunction) //only in C++11, apply iterator to algorithm function
	
	//Iterator Functions;
	//advance(itr, 5); // Move itr forward 5 spots,. for random access iterator itr+= 5
	//distance(itr,itr2)// Measure the distance between itr1 and itr2 for non random access iterator

	/*	Iterator Adaptor (Prefdfined Iterator), special designed iterator do more than iteratoring 
	-- A spcial, more powerful iterator
	1. insert iterator
	2. stream iterator
	3. reverse iterator 
	3. move iterator (C++ 11)
	
	
	*/
	// Insert iterator;

	vector<int>vec1 = { 4,5 };
	vector<int>vec2 = { 12,14,16,18 };
	vector<int>::iterator it22 = find(vec2.begin(), vec2.end(), 16);
	insert_iterator<vector<int>>i_itr(vec2, it22); // points to vec2, poistion as it

	copy(vec1.begin(), vec1.end(),//source , copy everything in vec 1 to i_itr
		i_itr); // destination
	//vec2: {12,14,4,5,16,18} other insert iterators: back_insert_iterator(insert in the back), front_insert_iterator(insert in the front)

	//2. stream Iterator:
	//vector<string>vec4;
	//copy(istream_iterator<string>(cin),  // get data from cin input stream
	//	istream_iterator<string>(), //default constructor of istream_iterator represents the end of stream
	//	back_inserter(vec4)); //back_inserter is a function return to back_insert_iterator
	//copy  standard input and back_insert into vec4
	//copy(vec4.begin(), vec4.end(), ostream_iterator<string>(cout, "")); // copy everything inside vec 4 to o stream iterator to cout
	// so everything in vec4 will be printed out as standard out and each element is separated by space 

	//Combine two statements into one statement
	//copy(istream_iterator<string>(cin), istream_iterator<string>(), ostream_iterator<string>(cout, " "));

	//reverse iterator
	vector<int> vec3 = { 4,5,6,7 };
	reverse_iterator<vector<int>::iterator> ritr;
	for (ritr = vec3.rbegin(); ritr != vec3.rend(); ritr++)
		cout << *ritr << ' '; // print:7,6,5,4
	cout << endl;


	cout << "---------------algorithm----------" << endl;
	// make ur code efficient, less buggy
	vector<int>vec4 = { 4,2,5,1,3,9 };
	vector<int>::iterator itr4 = min_element(vec4.begin(), vec4.end()); //itr --> 1
	//Note 1: algorithm always process ranges in a hal-open way: [begin, end)
	//include the first item 4, not include the last item (itr-->1)
	sort(vec4.begin(), itr4); //{2,4,5,1,3,9}, 
	reverse(itr4,vec4.end()); // {2,4,5,9,3,1} itr => 9
	// pointer point to code location
	//vec4.end() is the item after the last item in the vector

	// Note 2:
	vector<int> vec5(3); // copy to other function 
	copy(itr4, vec4.end(),//Source copy vector from iterator to vec4 end (包括了{9,3,1})
		vec5.begin()); // destination 
		// vec5 needs to have at leat space for 3 elements 否则result is undefined behavior

	//Note 3 back_insert is not safe
	vector<int> vec6;
	copy(itr4, vec4.end(), back_inserter(vec6)); // inserting instead of overwriting
	// back_insert_iterator not efficient

	vec6.insert(vec6.end(), itr4, vec4.end()); // Efficient and safe 在vec6.end(), insert vec 的itr4位置到end

	//Note 4 Algorithm with function
	vector<int>vec7 = { 2,4,5,9,2 };
	vector<int>::iterator itr7 = find_if(vec7.begin(), vec7.end(), isOdd); // itr7 --> 5

	//Note 5 Algorithm can even work for native C++ array
	int arr[4] = { 6,3,7,4 };
	sort(arr, arr + 4);
	// A pointer can be think of iterator
}



#endif
#pragma once
