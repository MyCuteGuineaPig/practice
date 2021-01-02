#ifndef lesson22EnableStringForYourOwnClass_h
#define lesson22EnableStringForYourOwnClass_h


#include <iostream>
#include <fstream>
#include <string>
using namespace std;


//create stream-enabled class
struct Dog{
	int age_;
	string name_;
};

ostream & operator<< (ostream& sm, const Dog& d) {
	sm << "My name is " << d.name_ << "  and My age is " << d.age_ << endl;
	return sm;
}

istream & operator>>  (istream & sm, Dog&d) {
	sm >> d.age_;
	sm >> d.name_;
	return sm;
}

void lesson_22() {
	Dog d{ 2,"Bob" };
	cout << d;

	cin >> d;
	cout << d;
}

#endif
#pragma once
