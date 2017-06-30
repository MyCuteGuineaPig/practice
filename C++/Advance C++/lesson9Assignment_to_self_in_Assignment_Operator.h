#ifndef lesson9Assignment_to_self_in_Assignment_Operator_h
#define lesson9Assignment_to_self_in_Assignment_Operator_h

/*
	handle self-assignment in operator
	Operator Overload: exploite people's intuition and reduce their learning curve

	dog dd;
	dd = dd; looks silly

	dogs[i] = dogs[j] looks less silly.  self assignment 

*/
#include<iostream>
using namespace std;

/*
class collar;

class dog9 {
	collar * pCollar;
	dog & operator = (const dog& rhs) {
		if (this == &rhs) // ifstatement cost some run time cost
			return *this; // 如果一样，直接return

		collar * pOrigCollar = pCollar;
		pCollar = new collar(*rhs.pCollar);
		// what if throw exception, it means dog delete its pCollar but fail to get pCollar， then pCollar is null / undefined solution change order
		delete pCollar; // 即使建立新的报错了，也可以返回原来的
		
		return *this; // problem *this dog and rhs are the same dog self assignment
		// if this is the case when I delete pCollar, I also delete rhs dog
	}
};


class god91 {
	collar* pCollar;
	dog & operator = (const dog & rhs) {
		*pCollar = *rhs.pCollar; // member by member copying of collars or call collar's operator
		return *this; // I don't necessary to check if this dog is equal to rhs 
		// if rhs 和 this 一样，只会引起runtime cost, no big deal
	}

};
*/
void lesson_9() {





}




#endif
#pragma once


#pragma once
