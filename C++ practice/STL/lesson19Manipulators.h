#ifndef lesson19Manipulators_h
#define lesson19Manipulators_h

/*
	cout << ends; // insert end character '\0'
	cout << setw(8) << left << setfill('_') << 99 << endl;   设置宽度为8， 99 alignment to the left, 并把剩下的位置都打印成 underscored
	// output is like 99______;
	cout << hex << showbase << 14; // will show 0xe

*/


#include <iostream>
#include <fstream>
#include <functional>
#include <iomanip> // manipulator
using namespace std;

ostream &endl(ostream & sm) { // take ostream reference and return ostream
	sm.put('\n'); // manipulator
	sm.flush(); 
	return sm; 
}

/*
ostream & ostream::operator<<(ostream& (*func)(ostream&)) { 
	return (*func)(*this); // evoke the function on this ostream then return with return value
} //  this ostream a pointer to a function that has the same signature for nl
// to take a function as parameter
*/
void lesson_19() {
	cout << "hello " << endl; //endl: will send '\n' and flush
	// what is endl? a function 
	// <<(output operator) is the member function of stream that is used to overload different parameter
	
	cout << ends; // insert end character '\0'
	cout << flush;
	//cin >> ws; //read and discard white spaces

	cout << setw(8) << left << setfill('_') << 99 << endl;   //设置宽度为8 set width as 8 and fill empty space with _， set alignment from left
	// output is like 99______; 
	cout << hex << showbase << 14; // will show 0xe
}

#endif
#pragma once
