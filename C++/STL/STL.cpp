#include <iostream>
#include "lesson1.h"
#include "lesson2.h"
#include "lesson3.h"
#include <string.h>
#include <stdio.h>
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
}