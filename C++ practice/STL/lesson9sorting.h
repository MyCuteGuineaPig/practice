#ifndef LESSON9SORTING_H
#define LESSON9SORTING_H
/*
	sorting in STL
	sorting algorithm requires random access iterators:
		vector, deque, container array, native array
	list and unordered container cannot be sorted, associative doesn't need to sort 

	sort
	partial_sort(vec1.begin(), vec1.begin() + 5, vec1.end()); 从vector开始到末尾选出5个最小的，放在最前面， 除了前五个，后面是无须的
	nth_element选出5个最小（大）的element，放在前面，不管前面n个element 顺序，也不管后面element 的顺序

	partition: first group/second group 根据方程分类，两个group 都是无序的，不是sorted
	stable_partition 分成两组unsorted， 但不是无序的，保留之前数据中的order


	Heap Algorithm
	Heap: 
	1. First element is always the largest (priority queue also has the property that first element is largest)
	2. Add.remove takes O(log(n)) times

	Heap Algorithm often implement priority queue
*/
#include<iostream>
#include <vector>
#include <string>
#include <random>
#include <algorithm>

using namespace std;

bool lsb_less(int x, int y) {
	return (x % 10) < (y % 10);
}

bool LessThan10(int i) {
	return i < 10;
}


void lesson_9() {
	vector<int>vec = { 9,1,10,2,45,3,90,4,9,5,8 };
	sort(vec.begin(), vec.end()); // sort with operator <
	//vec: 1 2 3 4 5 8 9 9 10 45 90
	sort(vec.begin(), vec.end(), lsb_less); // 对比最后一位
	// 10 90 1 2 3 4 45 5 8 9 9

	//sometime we don;t need complete sorting 
	//problem #1 finding top 5 students according to their test scoes


	vector<int>vec1 = { 9,60,70,8,45,87,90,69,69,55,7 };
	partial_sort(vec1.begin(), vec1.begin() + 5, vec1.end(), greater<int>());
	//从vector开始到末尾选出5个最大的
	//top 5 instudent is sorted in front of vector, vector 其他的部分是unsorted
	// 90,87,70,69,69,   8,9,45,60,55,7
	partial_sort(vec1.begin(), vec1.begin() + 5, vec1.end());
	//7,8,9,45,55  90,60,87,70,69,69 //从vector开始到末尾选出5个最小的，放在最前面
	//partial

	//problem #2 finding top 5 students according to their test scoes but I don't care their order

	vector<int>vec2 = { 9,60,70,8,45,87,90,69,69,55,7 };

	nth_element(vec2.begin(), vec2.begin() + 5, vec2.end(), greater<int>());
	//选出5个最大的放在前面，不用管这5个顺序
	// vec： 69,87,70,90,69，  60,55,45,9,8,7

	//Move the students whose score is less than 10 to the front
	partition(vec2.begin(), vec2.end(), LessThan10); // will separate vector into 2 groups,
	// one group contains the number is less than 10, second group contains the rest
	// group one 8 7 9;  90 69 60 55 45 70 87 69
	
	//to preserserve originial order within each partition
	stable_partition(vec2.begin(), vec2.end(), LessThan10);
	//vec: 9 8 7; 60 70 45 87 90 69 69 55

	// heap algorithm
	vector<int>vec3 = { 9,1,10,2,45,3,90,4,9,5,8 };
	make_heap(vec3.begin(), vec3.end());
	//90 45 10 9 8 3 9 4 2 5 1
}



#endif
#pragma once
