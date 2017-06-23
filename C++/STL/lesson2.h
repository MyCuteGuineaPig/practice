#ifndef LESSON2_H
#define LESSON2_H

/* 1. sequence containers(array and linked list)
	-vector, deque, list, forward list, arrary

	2. Associate containers // typically run the binary tree
		- set, multiset, 
		- map, multimap
	
	3. unordered Containers(hash table)
	  - unordered set / multiset
	  - unordered map/ multimap
*/

#include <vector> 
#include <deque>
#include <list> 
#include <set> // set and multiset
#include <map> // map and multimap
#include <unordered_set> // unordered set// multiset
#include <unordered_map> // unordered map// mutlimap
#include <iterator>
#include <algorithm>
#include <numeric> // some numeric algorithm
#include <functional>
#include <iostream>
#include <array>

void lesson_2(){
	vector<int>vec; // initial vector size = 0
	vec.push_back(4);
	vec.push_back(1);
	vec.push_back(8);


	cout <<vec[2] << endl; // 8 no range check
	cout << vec.at(2)<<endl; // 8 throw range_error exception of out of range

	//traverse vector
	for (int i=0; i<vec.size();i++)
		cout << vec[i] << " ";

	for (vector<int>::iterator itr = vec.begin(); itr!=vec.end(); itr++)
		cout << * itr << endl; // this way is faster than vec[i], aslo this is the universal way to choose container

	//for (it:vec) C++ 11
	//	cout << it << endl;
	//vector is a dynamically allocated contiguous array in memory
	// none of other container is contiguous array in memory

	int *p = &vec[0]; p[2] =6;
	// so we can use p just as regular array p[2] =6

	if (vec.empty()) {cout<<"vector size is 0 "<<endl;}
	cout <<"vec size "<<vec.size()<<endl; // 3

	vector<int>vec2(vec); // copy constructor vec2, {4,1,8}
	vec.clear(); //remove all items in vec, vec.size() == 0

	vec2.swap(vec); // v2 becomes empty, vec hs 3 items 
	// Notes; No penalty of abstraction, very efficient 

	/* 
		property of vector 
		1. fast insert/remove at the end O(1)
		2. slow insert/remove at the beginning or in the middle O(n)
		要把insert 之后的往后推一位
		3. slow search O(n)


	*/

	cout<<"-------------------------------DEQUE-----------------------"<<endl;
	// vector can only grow in the end and deque can grow in the end and in the beginning 
	//deque<int> deq = {4,5,7};
	deque<int>deq;
	deq.push_front(2); // {2,4,5,7}
	deq.push_front(3); // {2,4,6,7,3}

	// Deque has the same interface as vector
	cout << deq[1]<<endl;; // 4

	/* Properties 
	1. fast insert/remove at the beginning and the end
	2. slow insert/ remove in the middle
	3. slow search O(n);


	*/

	//list is double linked list

	//fast remove and replace in the place 

	//list<int>mylist = {5,2,9};
	list<int>mylist;
	mylist.push_back(5);
	mylist.push_back(2);
	mylist.push_back(9);
	mylist.push_back(6);
	mylist.push_front(4); // {4,5,2,9,6}
	
	list<int>::iterator itr = find(mylist.begin(),mylist.end(),2); //itr-->2
	mylist.insert(itr, 8); //{4,5,8,2,9,6}, 在这个iterator 前面insert

	//insertation O(1), faster than vector/deque
	itr++; // itr->9;
	mylist.erase(itr); // {4,8,5,2,6} // O(1) very fast

	/*
	1. fast insert/remove at any place O(1)
	2.slow search O(n) slower than vector,
	// vector is contiguous allocated, each elements in the list is stored at different place
	3. no random access, no [] opearator

	list has two more pointers than elements, so list will use much more memory

	mylist1.splice(itr,mylist2, itr_a,itr_b), itr_a and itr_b is iterator defined for list2

	so I can cut the function from list2 itr_a to itr_b insert to list1 O(1), 
	 no other vector can take advantage of that
		*/

	/*forward list

	you can only traverse from the beginning to end, only one way
	not from end to beginning

	*/

	/*Array
	  Array container if I have a array and do begin, end, size, swap
	  disadvantage 1. cannot change size,
	  2. different type 
	  array<int,3> a = {3,4,5};
	  array<int,4> b = {3,4,5};
	  A function if take a cannot take b, because they are two different types

	*/
	//int a[3] = {3,4,5}
	array<int,3> a = {3,4,5}; // size is 3

	a.begin();


}






#endif