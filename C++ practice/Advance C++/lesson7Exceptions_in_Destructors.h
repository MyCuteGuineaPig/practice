#ifndef lesson7Exceptions_in_Destructors_h
#define lesson7Exceptions_in_Destructors_h

/*
	Destructor like any part of code, they may throw exceptions
	You need to very careful if destructor throw exception, they are contained inside destructor, they should not out of destructor

	如果outside class，假如你用polymorphism，然后两个class都有throw exception，C++ 不喜欢这样，program crash
	SOLUTION 1
		catch exception in destructor
		~dog7(){
			try{
				// Enclose all the exception prone code here
			} catch(MYEXECEPTION e){ 
			或者 catch(...) 
			// this prevent any other unknown exception,  但是必须小心，not useful, dangerous, 也许会给你any error message
				//catch exception
			}
		}
		downside: dog object will not get that exception, only destructor get exception

	SOLUTION 2
	Move the exception-prone code to a different function
	void prepareTODestructor() { throw 20; }; // now destructor is exception free

	downside 需要function 去call

	决定用哪个是 取决于who handle the exception, 
	if dog itself hanlde, use solution 1
	if dog instance, use solution 2
*/


#include<iostream>
#include <string>
using namespace std;

class dog7 {
	public:
		string m_name;
		dog7(string name) { m_name = m_name; cout << name << "is_born. " << endl; }
		~dog7() { cout << m_name << "is destroyed." << endl;
		///throw 21; // program will crash
		} 
		void prepareTODestructor() { throw 20; }; // now destructor is exception free

		void bark() {};
};


void lesson_7() {
	try {
		dog7 dog1("Henry");
		dog7 dog2("Bob");
		//throw 20;
		dog1.bark();
		dog2.bark();
		/*
			all local varible is destroyed
			output:
			Henry is born
			Bob is born
			Bob is destroyed
			Henry is destroyed
			20 is caught
			这样顺序因为object 存在stack上，last in first out

			program crash, 
			因为program out of try block, local variable will be destroyed
			bob 先destory，发现有exception 
			因为要出block henry 需要destory，也会throw exception
			因此会有两个exception pending at the same time C++ 不愿意同时有两个exception
		*/
		dog1.prepareTODestructor(); // program will not longer crash
		dog2.prepareTODestructor();
		//dog instance will get exception and can handle exception
	}
	catch (int e) {
		cout << e << "  is caught" << endl;
	}




}




#endif


#pragma once
