#ifndef lesson3LogicConstnessAndBitwise_h
#define lesson3LogicConstnessAndBitwise_h


/*
	Logic Constness: do not change variable that you think is import
	如果const function改变了一些次要的varible， 
	两个方法解决：
		1. mutable int a; 在次要的variable 加mutable
		2. const_cast<BigArray*>(this)->accessCounter++; 不提倡，cast constness

	const int * const fun(const int * const & p) const;
	A cosnt function that doesn't mdify its data members and only calls other const member functions.

	1. return value of fun is a const pointer pointing t o a constant integer value
	2. the parameter of fun is aference of a const pointer pointer to a const integer

	the reference cannot refer to a different pointer (naturre of reference)
	the referred pointer cannot point to a different value

*/


#include<iostream>
#include <vector>
using namespace std;

class BigArray {
	vector<int>v;//huge vector
	//mutable int accessCounter; // keep track of how many times v has been accessed, logic constness
    int accessCounter;
	// add mutable variable, the variable can be changed in the const function
	int *v2;

	public:
		int getItem(int index) const {
			//accessCounter++; // as long as variable is inside function cannot be const function
			// it conflict with bitwise constness

			// or
			const_cast<BigArray*>(this)->accessCounter++; // const cast this object
			return v[index];
		}

		void setV2Item(int index, int x) const {
			*(v2 + index) = x; //set item in v2 at position index as x
			// it did not change memeber directly, maintain member directly
		}
		//quiz
		//const int * const fun(const int * const & p) const;

};

void lesson_3() {
	BigArray b;




}




#endif




#pragma once
