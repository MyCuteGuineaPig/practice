#ifndef lesson8Virtual_Function_in_Constructor_or_Destructor_h
#define lesson8Virtual_Function_in_Constructor_or_Destructor_h

#include<iostream>
using namespace std;

/*
	当inistaniate a object,
	YellowDog8 d; 
	d.seeCat(); 即使seeCat function来自base(Dog) class, 但seeCat function call virtual function, 会call YellowDog, 因为program 会认清这个object的对象

	但是要避免constructor or destructor call virtual function
	因为这样只会call base class function 

	Constuctor:
		YellowDog8 d;  先会叫base class constructor，但constructor里有virtual function
		,但发现virtual function不能run，因为derived class还没有initialized， 所以就会call 第二选择，自己virtual function

	Destructor:
		YellowDog8 d; 
		先摧毁derived class,然后run base class, 发现base class destructor 有virtual function但是derived class已经毁了
		所以只能call第二个选择,自己的virtualfunciton

	所以constructor 和destructor 尽可能简短，不用fancy function/ virtual function

*/


class Dog8 {
public:
	Dog8() { cout << "Dog born." << endl; bark(); }//even if we evoke a yellow dog, it still call dog bark function
	// because before yellow dog initiated, dog is initiated, so yellow dog bark function is not executed yet,所以call nonvirtual function
	// yellow dog is not constructed 除非是static function,
	//avoid call virtual/fancy function inside constructor is not recommended. the same idea is for destructor
	virtual void bark() { cout << "I am just a Dog." << endl; }
	void seeCat() { bark(); }
	~Dog8() {
		//bark(); // will call dog bark because derived object is destoryed, cannot call function if its member is destoryed
	}
};


class YellowDog8 : public Dog8 {
public:
	YellowDog8() { cout << "Yellow Dog born." << endl; }
	virtual void bark() { cout << "I am a Yellow Dog." << endl; }
};

void lesson_8() {
	YellowDog8 d; // call dog constructor and call yellow dog constructor
	d.seeCat(); // when run seeCat function evoke bark function and realize its yellowdog then run yellowdog bark
	// 即使yellowdog 没有seeCat function 也会run YellowDog virtual function
	//dynamics binds, as long as d is yellow dog, it always call yellow dog virtual function
	



}




#endif
#pragma once
