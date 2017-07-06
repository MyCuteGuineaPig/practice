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
#include "lesson_10Resource_Acquisition_is_Initialization.h"
#include "lesson_11Static_Initialization_Fiacso.h"
#include "lesson_22Multiple_Inheritance.h"
#include "lesson_12Struct_Class.h"
#include "lesson_13Resource_Managing_Class.h"
#include "lesson_14Virtual_Constructor_Clone_Function.h"
#include "lesson_14Virtual_Constructor_Clone_Function.h"
#include "lesson_15Define_Implicit_Type_Conversion.h"
#include "lesson_16All_Casting_Considered_I.h"
#include "lesson_17All_Casting_Considered_II.h"
#include "lesson_18Inheritance_Public_Protected_Private.h"
#include "lesson_19Maintain_is_a_realtion_for_Public_Inheritance.h"
#include "lesson_20Understanding_rvalue_and_lvalue.h"
#include "lesson_21Static_Polymorphism.h"
#include "lesson_23Pulic_Inheritance_Interface_and_Implementation.h"
#include "lesson_24Code_Reuse_Inheritance_Composition.h"
#include "lesson_25Namespace_and_Keyword_using.h"
#include "lesson_26Koenig_Lookup_Argument_Dependent_Lookup.h"
#include "lesson_27Koenig_Lookup_and_Namespace_Design.h"
#include "lesson_28Demystifying_Operator_New_Delete.h"
#include "lesson_29How_to_Define_new_Handler.h"





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

	cout << endl << "-----------------------lesson 10 RAII--------------------------------------" << endl;
	lesson_10();

    cout << endl << "-----------------------lesson 11 Static Initialization Fiasco--------------------------------------" << endl;
    lesson_11();
    
    
    cout << endl << "-----------------------lesson 12 Struct vs Class--------------------------------------" << endl;
    lesson_12();

    
    cout << endl << "-----------------------lesson 13 Resource Managing Class--------------------------------------" << endl;
    lesson_13();
    
    cout << endl << "-----------------------lesson 15 Define Implicit Type Conversion--------------------------------------" << endl;
    lesson_15();
    
	return 0;
}






