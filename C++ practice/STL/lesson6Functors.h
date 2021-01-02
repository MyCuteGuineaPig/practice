#ifndef LESSON6FUNCTORS_H
#define LESSON6FUNCTORS_H

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <functional>
using namespace std;

class X {
public:
	void operator()(string str) {
		cout << "Calling functor X with parameter: " << str << endl;
	}
	X(int i) {}
	operator string () const { 
		cout << "type conversion " << endl;
		return "x"; } //  type conversion function
	// type conversion put type before operator 
	// functor put type after operator
};

// can do paraameterized function 
/* benefits of functor:
	1. smart function: capabilities beyond operator(), 
		so you can two different functors that behave different each other
	   It can remember state
	2. It can have its own type. Two functor can have different types even if they have the exactly same signiature
*/

void add2(int i) {
	cout << i + 1 << endl;
}
template<int val>
void addVal(int i) {
	cout << val + i << endl;
}

void add3(int i, int val) {
	cout << i + val << endl;
}

class addvalue {
	int val; 
	public:
		addvalue(int j) :val(j) {}
		void operator() (int i) {
			cout << i + val << endl;
		}
};

double Pow(double x, double y) {
	return pow(x, y);
}

// 因为set 第二个不能是function，或者pointer， 因为有type
/*
bool lsb_less(int x, int y) {
	return (x%1) 

}*/

class Lsb_less {
public:
	bool operator()(int x, int y) {
		return (x % 10) < (y % 10);
	}

};

class NeedCopy_1 {
public:
	bool operator()(int x) {
		return (x > 20) || (x < 5);
	}
};

//use a instance as a function.  functor behaves like saying like a function but it is a class
void lesson_6() {
	X foo(6);
	foo("Hi"); // calling functor X with parameter Hi
	foo.operator string();

	X(8)("Hola"); // lokes like a function with parameterized with eight and invoked a regular parameters high
	//why we need that 

	vector<int>vec = { 2,3,4,5 };
	//for_each(vec.begin(), vec.end(), add2);// add 2 will be invoked for each function in vec {4,5,6,7}
	for_each(vec.begin(), vec.end(), addVal<2>);// template variable is resolved at compiled time, it has to be compiled time constant
	// if I have int x = 2, then for_each(vec.begin(), vec.end(), addVal<x>); it will not compiled
	// 另一种方法是 functor 
	int xx = 2;
	for_each(vec.begin(), vec.end(), addvalue(xx));
	 
	//STL has itself some built in functors
	/*	 Built in Functors
	less greater greater_equal less_equal  not_equal_to
	logical_and  logical_not  logical_or
	multiplies minus plus divide modulus negate
	*/

	int x = multiplies<int>()(3, 4); //x= 3*4

	if (not_equal_to<int>()(x, 10)) // if (x!=10)
		cout << x << endl;

	/*
	parameter binding */
	set <int> myset1 = {2,3,4,5};
	vector <int>vec1;

	int x1 = multiplies<int>()(3, 4); // x = 3*4

	// multiply myset's elements by 10 and save in vec
	transform(myset1.begin(), myset1.end(), // source
		back_inserter(vec1), //destination 
		bind(multiplies<int>(), placeholders::_1, 10));// functor
	// first parameter of multiples <int>(0 is substitued with myset's elements
	// transform 只能pass 四个变量，multiplies<int> 有两个变量，所以只能用bind
	// placeholders _1 的意思是，第一个multiplies 参数会用myset 的参数替换， multiplies 第二个参数是10

	// 第二种方法
	for_each(vec1.begin(), vec1.end(), bind(add3, placeholders::_1, 2));
	// bind is only for C++, 其他version 可以用bind1st, bind2nd

	set<int>myset2 = { 3,1,25,7,12 };
	deque<int>d2;
	auto f2 = function<double (double,double)>(Pow); // use stl function to convert standard function into functor
	// 可以用function convert function 到functor
	transform(myset2.begin(), myset2.end(), back_inserter(d2), bind(f2, placeholders::_1, 2));


	set<int> myset3 = { 3,1,25,7,12 };
	//when (x>20||x<5) copy from myset to d
	deque<int>d3;

	transform(myset3.begin(), myset3.end(), back_inserter(d3),
		bind(logical_or<bool>(),
			bind(greater<int>(), placeholders::_1, 20),
			bind(less<int>(), placeholders::_1, 5))
	);

	// 或者 lambda function
	transform(myset3.begin(),myset3.end(),back_inserter(d3),
		[](int x) {return (x > 5 || x < 20); } // I don't need to create a separate function in different place 
	);
	//lambda function works well in stl

	set<int>myset4 = { 3,1,25,7,12 }; //set has 5 integers myset = {1,3,7,12,25}, auto sorted 
	// set可以传入两个变量， 一是数据类型，另外一个是function used for sorting,
	//same as 
	set <int, less<int>>myset5 = { 3,1,25,7,12 }; // default sorting
	set<int, Lsb_less> myset6 = { 3,1,25,7,12 }; // want to sort it in least significant digit {1,12,3,25,7}
	// STL without STL cannot work

	/*
		Predicate 
		A Functor or function that 
		1. returns a boolean
		2. des not modify data
		Predicate is used for compairson or condition check 
	*/ 
	vector<int>myset7 = { 1,20,18,5 };
	deque<int>d7;
	transform(myset7.begin(), myset7.end(), back_inserter(d7), NeedCopy_1()); 
	// You cann't assume predicate is only invoked once per elements during execution of algorithm, 
	// It is recommanded predicate is a pure function which means the return value is purely based on input value ,
	// has nothing to do how many times the predicate is being invoked

}	

#endif
#pragma once
