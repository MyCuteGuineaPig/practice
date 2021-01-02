#ifndef lesson2ConstAndFunctions_h
#define lesson2ConstAndFunctions_h
/*
	const should be used to be frequently 


	1. Const as Parameters
	 当parameter 作为const，必须加上&， pass by reference, 不能改变function里面的值，

	  void setAge(const int &a) {
		age = a;}

	  如果不是pass by reference, function的 parameter 只是 caller parameter的copy 版本，const int a所以跟 int a, 一样，因为即使function改了，
	  也只是改的复制的值， 不是真实的对应值，也不会影响外面

	2. return value as const
	当function return value 作为const, 必须加上&， return by reference
	否则没有意思，如果没有&，return 到function外面的只是function return的copy 版本，所以copy前的值只是temporary的，temporary的值是const，没有意义

	3. const Function 
	   const Function 是function 内不会改变任何class 的variable，也不能在function内call 任何不是const function的

		const Function 可以overload
		void printDogName const() const function 会被called 当object 是const
		const Dog d2;
		void printDogName() 会被called 当object 不是const

*/


#include<iostream>
#include <string>
using namespace std;

class Dog {
	int age;
	string name;
	public:
		Dog() { age = 3; name = "dummy"; }
		void setAge(const int &a) {
			/* const parameter
				如果我们用const int a， a 不能改变inside function， 因为a 只是i的copy value，
				void setAge(const int a)  跟 void setAge(int a)两个function Basically the same
				 pass reference 才是真实的pass value */
			age = a;
			//a++; // don't want to i change use const int & a
		} 

		void setAge(int &a) {
			/* const parameter
			如果我们用const int a， a 不能改变inside function， 因为a 只是i的copy value，
			void setAge(const int a)  跟 void setAge(int &a)两个function Basically the same
			pass reference 才是真实的pass value */
			age = a;
			//a++; // don't want to i change use const int & a
		}

		const string & getName() { return name; }// return reference, improve program efficiency 
		// 所以外面的是改变不能value returned
		/*
			如果改变const string & getName() 成
			const string getName()， const is very useless, then function return is the copy of the name, which is temporary
			it doesn't make sense if temporary is const
		
		*/

		// const Function
		void printDogName() const { // 意味着this function will not change any variable in the class
			cout << name << "  const function "<< endl;
			// 如果const function call another not function inside itself 不会compile
			//getName(); 不会compile const function 只能call another const function
		}

		//constness can be used to overload functions
		void printDogName() { 
			cout << getName() << " non- const function " << endl;
		}

		// const Function will be called if dog is const 
		// non const function will be called if dog isn't const

};

void lesson_2() {
	Dog d;
	int i = 9;
	d.setAge(i);
	cout << i << endl;

	const string & n = d.getName();
	cout << " function return value const & " << n << endl;

	/*
		如果 getname 是 const string getName() ， return is temporary constant, copy后的值不是const，所以返回取得值可以不是const
		
		string n = d.getName();
	
	*/
	d.printDogName(); // non const function

	const Dog d2;
	d2.printDogName(); // Const function to print name

}



#endif
#pragma once
