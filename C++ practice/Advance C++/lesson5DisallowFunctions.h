#ifndef lesson5DisallowFunctions_h
#define lesson5DisallowFunctions_h

#include<iostream>
using namespace std;

/*
	disallow complier generated function
	1. copy constructor: 
		C++ 11, OpenFile(OpenFile &rhs) = delete;
		C++ 03, make it private  do not need to declare function: OpenFIle(OpenFile &rhs) 

		也许说可以通过private function access copy constructor 但是member function 没有return type， 因为private copy constructor 没有body


	2. copy assignment operator:
		put it into private
		OpenFile & operator= (const OpenFile & rhs);//

		还可以通过private disable function


	3. Destructor
		尽管我们turn off by adding into private 
		但是不要用，不好，object must be destructed by one way or another or memory/resource will be leaked 
		存在stack上的，不run destructor 有error


	4. default Constructor:
		建一个constructor 有参数的就把default constructor turned of

	有private destructor 用heap
*/

class OpenFile {
	// disallow default constructor
	// in order not to run default constructor, define constructor and pass some value
	public:
		//OpenFile() = default;
		OpenFile(string filename) { cout << "open a file " << filename << endl; } // compiler will not generate default constructor for me
	
		// C++ 11
		OpenFile(OpenFile &rhs) = delete; // do not allow copy constructor
		void DestroyMe() { delete this; }
		// C++03 make OpenFile(OpenFile &rhs) as private
	private:
		//OpenFile(OpenFile &rhs); 
		OpenFile & operator= (const OpenFile & rhs);// disable copy operator
		//void writeLine(string str); say openfile has a inherited functon called witeLine
		~OpenFile() { cout << "Open destructed " << endl; };//Nobody can use destructor any more but we don't define it. Do 
};




void lesson_5() {
	//OpenFile f(string("Bo_file"));//因为没有default constructor
	// 有private destructor, program will be failed 因为f存在stack上，out of scope f会被destroyed, 因为function没有destructor了，fail to complie
	
	//f.DestroyMe(); // 因为f 存在stack上，在destroyme 之后 f会destroy again
	//reference counting share pointer: count the number of pointer to itself. 一旦count =0, 会自杀

	//OpenFile f2(f); // copy constructor from f, call compiler copy consturctor// write file at the time same
	
	OpenFile *f = new OpenFile(string("Bo_file")); // store f on stack
	f->DestroyMe(); // delete nothing for class coz delete this is to delete heap not stack

}




#endif#pragma once
