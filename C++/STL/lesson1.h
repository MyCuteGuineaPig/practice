#ifndef LESSON1_H
#define LESSON1_H


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void lesson_1(){
	// vector is created dynamically allocated and size is not fixed. it is created on heap
	vector<int>vec;
	vec.push_back(4);
	vec.push_back(1);
	vec.push_back(8);

	vector<int>::iterator itr1 = vec.begin(); // half-open, being end
	vector<int>::iterator itr2 = vec.end(); 

	// begin will point to the first element
	// end will point to the end element
	// iterater behaves like a pointer

	// end is defined at the end of the vector, cannot use vec.end()

	for (vector<int>::iterator itr = itr1; itr!=itr2;++itr)
		cout << * itr << " ";

	sort(itr1,itr2);
	// algorithm must work as iterator

	/*Reasons to use C++ standard library
	  1. code reuse, no need to re-invet the wheel
	  2. Efficiency (fast and use less resources), Modern C++ compliers are usually tuned to optimize C++ standard library code
	  3. Accurate, less buggy
	  4. Terse, readable code; reduced control flow
	  5. Standardization, guarenteed availability
	  6. A role model of writing library
	  7. Good knowledge of data structure and algorithm

	*/
}

#endif