#ifndef LESSON7NONMODIFYALGORITHM
#define LESSON7NONMODIFYALGORITHM


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*	 STL Algorithm Walkthrought:
Non-modifying alorithms
count, min and max, compare, linear search, attribute
*/

bool lessThan10(int x) {
	return x < 10;
}

void lesson_7() {
	vector<int>vec = { 9,60,90,8,45,87,90,69,69,55,7 };
	vector<int>vec2 = { 9,60,70,8,45,87 };
	// C++ lambda Function
	//num = count_if(vec.begin(), vec.end(), [](int x) {return x < 10; }); // lambda function is a function without name
	vector<int>::iterator itr, itr2;
	pair<vector<int>::iterator, vector<int>::iterator>pair_of_itr;

	
	// 1. Counting 
	// Algorithm           Data       Operation 
	//algorithm 都符合这个顺序，数据， 处理
	int n = count(vec.begin(), vec.end(), 69);//count data equal to 69 // 有两个69， 所以结果是69， count 只能assign number，因为它用的是default operation equal
	// or int n = count(vec.begin(), vec.end(), [](int x){return x==69;});/
	//int n = count(vec.begin()+2, vec.end(), 69);vec.begin()+2, 就把开始的地方从90 开始算
	//algorithm run through iterator 
	int m = count_if(vec.begin(), vec.end(), [](int x) {return x < 10; }); // 数几个小于10， 有3个
	// count_if allow the condition defined ，


	//2 Min and Max
	itr = max_element(vec.begin()+2, vec.end());//
	// return first max elements which has the 最后一个digit 最大的， use the default comparison less than
	itr = max_element(vec.begin(), vec.end(), [](int x, int y) {return (x % 10) < (y % 10); }); // 9
	/*
	 most algorithm will the return the first elements match, but some returns last match
	 most algorithm use default comparison function or default computation operation(less than)
	 generalized form provide u to input function such as lambda function
		有时候 generalized or simple form 命名不一样，比如count 和 count if
		有时候一样， 比如max_element
	*/  

	itr = min_element(vec.begin(), vec.end());//7  find the first smallest element in the data range
	//generalized form: min_element()

	pair_of_itr = minmax_element(vec.begin(), vec.end(), [](int x, int y) {return (x % 10) < (y % 10); });
	// minmax_element, 返回iterator 指出 第一个最小的和最后一个最大的, min返回值跟min_element 返回值，last_of max 跟max_element 不一样（因为max_element,返回第一个最大）

	//3 Linear Search Only used when data is unsorted, 如果data is sorted, use binary search, faster
	//returns the first match
	itr = find(vec.begin(), vec.end(), 55);//返回第一个等于55的
	itr = find_if(vec.begin(), vec.end(), [](int x) {return x > 80; });
	itr = find_if_not(vec.begin(), vec.end(), [](int x) {return x > 80; });//返回第一个不大于80的
	itr = search_n(vec.begin(), vec.end(), 2, 69); // search_n, 找到特殊的pattern，consecutive 2 items of 69
	

	//search subrange
	vector<int>sub = { 45,87,90 }; // first design a pattern
	itr = search(vec.begin(), vec.end(), sub.begin(), sub.end());// 找到第一个满足这个pattern
	//search first subrange
	itr = find_end(vec.begin(), vec.end(), sub.begin(), sub.end());// 找到最后一个满足这个pattern
	//search last subrange
	//gemeralized form: search(), find_end() 两个funciton 是complement of each others, but have different names

	//search_any_of
	vector<int> items = { 87,69 };
	itr = find_first_of(vec.begin(), vec.end(), items.begin(), items.end()); // search any one of the item in items
	//generalized version
	itr = find_first_of(vec.begin(), vec.end(), items.begin(), items.end(),
		[](int x, int y) {return x == y * 4; });//search any of the item in items that satisfy: x==y*4

	//search adjacent
	itr = adjacent_find(vec.begin(), vec.end()); // 找到第一个相邻的item 是一样的
	itr = adjacent_find(vec.begin(), vec.end(), [](int x, int y) {return x == y * 4; }); // find two adjacent items that 满足 x==y*4

	// 4. Comparing Ranges

	/*
	if (equal(vec.begin(), vec.end(), vec2.begin())) { // check if vec and vec 2 are the same
		cout << "vec and vec2 are the same" << endl;
	}
	cout << "4" << endl;
	if (is_permutation(vec.begin(), vec.end(), vec2.begin()))
	{
		cout << "vec and vec2 have the same ittems but in different order " << endl;
	}
	*/
	//pair_of_itr = mismatch(vec.begin(), vec.end(), vec2.begin()); // find the first place of first different

	// pair_of_itr.first is an iterator of vec
	// pair_of_itr.second is an iterator of vec2
	
	lexicographical_compare(vec.begin(), vec.end(), vec2.begin(), vec2.end());
	// one-by-ne comparison with "less than", 从第一个开始知道第一个difference find，then compare which one is less by compare item difference
	// {1,2,3,5} < {1,2,4,5}
	// {1,2} < {1,2,3}

	//generalized forms:
	// equal(), is_permutation(), mismatch(), lexicographical_compare()

	//5 Check Attributes
	is_sorted(vec.begin(), vec.end()); // check if vec is sorted 
	itr = is_sorted_until(vec.begin(), vec.end()); // itr points to first place to where elements are no longer sorted 
	// generalized forms: is_sorted(), is_sorted_until()

	is_partitioned(vec.begin(), vec.end(), [](int x) {return x > 80; }); // check if vec is partitioned according to x>80
	
	is_heap(vec.begin(), vec.end());//check if vec is a heap
	itr = is_heap_until(vec.begin(), vec.end());//find the first palce where it is no longer a heap
	//generalized forms: is_heap(), is_heap_until()

	//All, any, noe
	all_of(vec.begin(), vec.end(), [](int x) {return x > 80; });
	// If all of vec is bigger than 80

	any_of(vec.begin(), vec.end(), [](int x) {return x > 80; });
	none_of(vec.begin(), vec.end(), [](int x) {return x > 80; }); // If none of vec is bigger than 80

}

#endif
#pragma once
