#ifndef lesson1const_h
#define lesson1const_h
/*
	Const:
		A compile time constraint that an object cannot be modified

	
	Const Pointer 三种类型

	const i = 0;
	1. data is const, pointer is not const
		const int * p = &i;  
		int const * p = &i; 这种pointer指的对象是const，但自己pointer 不是const
		*p = 6; 不行， 因为 指的对象是const， 不能改变指的对象的值
		p++; 可以，可以改变自己pointer 的值

	int ii = 0;
	2. data is not const, pointer is const
		int * const p = &ii;  可以改变point 对象的值，不能改变自己的值
		指向一个variable后就不能改变，要一直指向它
		int j = 0;  p = &jj 会报错
		但可以 *p = 101; 

	3. data is const, pointer is const
	const int * const p = &i; 既不能改变指向的对象（poiner的值），也不能改变指向对象的值（pointe to 的 int value的值）

	暂时取消const 
	const_cast<int &>(i3) == 6;
	暂时让不是const 变成const
	static_cast<const int&>(j)

	尽可能不用cast


	Why use Const
	 1. Guard against inadvertent write to the variable
	 2. self documenting
	 3. enable compiler to do more optimization, making code tigher 可以让code提速
	 4. const means the variable can be put in ROM (read only memory)

	 As professonial C++ programmer, use const proactively

*/
#include<iostream>
using namespace std;

void lesson_1(){
	const int i = 9; // constriant that is enforced in the compile time
	//i = 6;failed to compile


	const int *p1 = &i;  // data is const, p1 point to的对象是const（int是const），pointer 不是const，
	//离谁近，谁是const
	//*p1 = 5;  不能compile 因为read only location,改变*p1 as 5, 会改变i，是错误的
	p1++; // modified p1 itself, then complied,而不是改变p1 point的值

	int ii = 10;
	int j = 12;
	int *const p2 = &ii; // opposite of p1, p2 itself as const, but data it points to not const
	// pointer is const, data is not, 不能改变pointer 自身的值，但可以改变point value 的值
	// 只能point to 一个value, 如果 p2++, 会报错,但是可以改变point to value 的值
	*p2 = 101;
	
	const int * const p3 = &i; // data and pointer are both const;
	
	int const * p4 = &i; // const int * p4 这两个是一回事
	// Rule: If const is on the left of *, data is const
	// If const is on the right of *, pointer is const

	const int i3 = 9;
	//say I really want to change data
	const_cast<int &>(i3) = 6; // const_cast can cast the way of i
	//cast we can cast away the const of data

	cout << i3 << endl;

	// at certain point, change j to const
	static_cast<const int&>(j); // aslo I can cast data into const
	j = 10;
	//avoid away cast as much as possible 

}




#endif
#pragma once
