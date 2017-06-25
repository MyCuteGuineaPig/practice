﻿#include <iostream>
#include "lesson1.h"
#include "lesson2.h"
#include "lesson3.h"
#include "lesson4UnorderedContainer.h"
#include "lesson5IteratorsAndAlgorithm.h"
#include "lesson6Functors.h"
#include <string.h>
using namespace std;


template<class T>
class BoVector{
	T arr[1000];
	int size;
	public:
		BoVector():size(0){}
		void push(T x) {arr[size] = x; size++;}
		T get(int i) const {return arr[i];}
		int getSize() const {return size;}
		void print() const {for(int i=0; i<size;i++) {cout<<arr[i]<<endl;}}

};

template <typename T>
BoVector <T> operator* (const BoVector<T> & rhs1, BoVector<T> & rhs2){
	BoVector<T>ret;
	for (int i=0 ; i<rhs1.getSize(); i++)
		ret.push(rhs1.get(i)*rhs2.get(i));
	return ret;
}


template <typename T>
T square(T x){
	return x*x;
}


int main(){ // code bloat
	// function template do not need to tell data type
	//cout << square(5.5)<<endl;
	//cout << square(5)<<endl;
	BoVector<int> bv;
	// class template must be explicitly told what is the type
	bv.push(2);
	bv.push(5);
	bv.push(9);
	
	bv = square(bv); // invoke template operator *
	bv.print();

	// standard template library has algorithm and containers
	// containers contains data, and algorithms run algorithms in containers
	// oo programming is to combine algorithms and containers together into class
	// STL is the opposite of oo programming, it sparate algorithms and data structure, 
	// so we can use one algorithms in different containers and one containers to run different algorithms
	// if i want to one algorithms to run different containers, need to many implementations

	// so iterators solve that program, each containers is require to have a interface which defined by iterater
	// each iterater can iterate each element inside containers, so algorithms can only work toward iterater then go to containers
	cout<<endl << "--------------------lesson 2 Sequence Containers-------------------------------"<<endl;
	lesson_2();


	cout<<endl << "--------------------lesson 3 Associate Containers-------------------------------"<<endl;
	lesson_3();


	cout << endl << "--------------------lesson 4 Unordered Associative Containers-------------------------------" << endl;
	lesson_4();


	/*
		Container Adaptor 
		- Provide a restricted interface to meet special needs
		- Impletmented with fundamental container clases
		1. stack: LIFO push(), pop(), top()
		2. queue: FIFO push(), pop(), front(),back(), push in the front, pop in the end
		3. priority queue: first item alwasy has the greatest priority, push(), pop(), top()
	*/

	/*
		Another way of categorizing containers:
		1.Array based containers vector, deque
		2. Node base containers： list+asscociative containers + unordered containers
		Array baed containers invalidated pointers:
		- Native pointers, iterators, reference;

		vector<int> vec = {1,2,3,4};
		int *p = &vec[2]; // P points to 3
		vec.insert(vec.begin(),0);
		cout << *p <<endl; // 2 (new location )or random number or program will crash, undefined behavior 
		

		everytime you remove something from vector or insert something insert vector
		the pointer previously pointing to the content of vectors may 失效， 所以不能使用pointer
		但是nodes 就没有这个问题， pointer 会remain valid even after you have insert or remove from containers 只能不delete point

	*/

	cout << endl << "--------------------lesson 5 Iterators and Algorithms-------------------------------" << endl;
	lesson_5();


	cout << endl << "--------------------lesson 6 Functors-------------------------------" << endl;
	lesson_6();
}