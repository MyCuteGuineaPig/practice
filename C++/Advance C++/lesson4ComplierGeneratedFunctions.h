#ifndef lesson4ComplierGeneratedFunctions_h
#define lesson4ComplierGeneratedFunctions_h

/*
	Compiler silently writes 4 functions if they are not explicitly declared:
	1. copy constructor
	2. copy assignment Operater
	3. Destructor
	4. Default constructor(only if there is no constructor declare
	default constructor: constructor is a constructor can work without any parameter
	错误default constructor 定义：a constructor is a constructor that has no parameter

	如果class 没有constructor， compiler 会自己run default constructor,然后会call data member constructor
	如果class 没有default， compiler 会自己run destructor

	1. Compiler Generated Function is public and inline
	2. They are generated only if they are inline
	// if 他们没有被called，他们不会generated，even if compiler are able to generated

	一定注意class 有没有reference variable 
	----因为reference varibale 必须initialized 
	----因为referenc, const 都不能copy
	C++ 11
	class dog{
		public:
			dog() = default;
			dog(string name) {};
	}
*/


#include<iostream>
#include <string>
using namespace std;


// clas dog{}； 根下面的一样
class dog {
	// complier generated function
	public:
		dog(const dog& rhs) {}; // Member by Member initilization

		dog & operator = (const dog&rhs) {}; // member by member copy
		// what if function fails to do their jobs, rem

		dog() {}; /// 1. call base class's default constructror;
				//2. Call data Member's default constructor

		// what if default base class doesn't have constructor

		~dog() {}; // call base class's destructor
		//每一个class 都有destructor，but what if destructor is private,
};

class dog1 {
	public:
		string  m_name;
		// suppose we change string  m_name to string & m_name, this code will no longer compiler
		// 因为dog 有refernce 不会compiler
		// 有了reference 也不能用于container， 因为container需要containee copy and assignable

		dog1(string name = "Bob") { 
			m_name = name; cout << name << " is born." << endl; 
		}
		~dog1() { cout << m_name << " is destroyed " << endl; }
};

/*
	class collar {
		public:
			collar(string color ) {std:: cout<< "colar is born";}
	};

	class dog {
		collar m_collar
	};

	call dog dog1, fail to compile 
	原因： 
		dog会run default constructor （complier default constructor 会call data member default constructor, which is collar）
		compiler cannot generate default constuctor for collar, so compiler cannot generate default constructor for dogs
		所以会run copy constructor

		如果remove string color, complier 会run 成功
*/

void lesson_4() {
	const int i = 0;
	int ii = i;

	dog1 dog11("Henry");
	dog1 dog2;
	dog2 = dog11;

	/* Output
		Henry is born.
		Bob is born.
		Henry is destroyed
		Henry is destroyed
	
		1. copy constructor is not generated
		2. copy Assignment Operator:  - yes (dog2 = dog11; 因为dog 没有copy assignment defined,所以会generated)
		3. Destructor:   not generated, class has destructor defined
		4. default constructor:  - no, (because we have default constructor)
		default constructor: constructor is a constructor can work without any parameter
		错误default constructor 定义：a constructor is a constructor that has no parameter
		reference 都要intialized 

	*/
}




#endif
#pragma once
