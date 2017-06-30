#include<iostream>
#include "lesson1const.h"
#include "lesson2ConstAndFunctions.h"
#include "lesson3LogicConstnessAndBitwise.h"
#include "lesson4ComplierGeneratedFunctions.h"
#include "lesson5DisallowFunctions.h"
#include "lesson6Virtual_Destructor_And_Smart_Destructor.h"
#include "lesson7Exceptions_in_Destructors.h"
#include "lesson8Virtual_Function_in_Constructor_or_Destructor.h"
#include "lesson9Assignment_to_self_in_Assignment_Operator.h"
#include "lesson_10_Resource_Acquisition_is_Initialization.h"

using namespace std;

int main() {
	cout << "-----------------------lesson 1 const--------------------------------------" << endl;
	lesson_1();
	
	cout << "-----------------------lesson 2 Const And Functions--------------------------------------" << endl;
	lesson_2();

	cout << "-----------------------lesson 3 Logic Constness And Bitwise Constness--------------------------------------" << endl;
	lesson_3();

	cout <<endl<< "-----------------------lesson 4 Complier generated function--------------------------------------" << endl;
	lesson_4();

	cout << endl << "-----------------------lesson 5 Disallow Function--------------------------------------" << endl;
	lesson_5();

	cout << endl << "-----------------------lesson 6 Virtual Destructor and smart Destructor--------------------------------------" << endl;
	lesson_6();

	cout << endl << "-----------------------lesson 7 Exceptions from leaving Destructors--------------------------------------" << endl;
	lesson_7();

	cout << endl << "-----------------------lesson 8 Virtual Function in Constructor or Destructor--------------------------------------" << endl;
	lesson_8();

	cout << endl << "-----------------------lesson 9 Assignment to self in Assignment Operator--------------------------------------" << endl;
	lesson_9();


	return 0;
}






