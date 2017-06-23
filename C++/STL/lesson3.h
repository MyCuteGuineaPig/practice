#ifndef LESSON3_H
#define LESSON3_H

#include <vector> 
#include <deque>
#include <list> 
#include <set> // set and multiset
#include <map> // map and multimap
#include <unordered_set> // unordered set// multiset
#include <unordered_map> // unordered map// mutlimap
#include <iterator>
#include <algorithm>
#include <numeric> // some numeric algorithm
#include <functional>
#include <iostream>
#include <array>


/*associate containter is designed for binary tree
	when insert items in binary tree, it will appear in the appropriate tree
	when delete that items, then tree will be arranged. 

	So No push_back(), push_front()

*/


void lesson_3(){
	cout << "-----------------SET--------------"<<endl;
	// set do not have duplicated items
	set<int>myset;
	myset.insert(3);
	myset.insert(1);
	myset.insert(7);

	set<int>::iterator it;
	it = myset.find(7); // O(log(n)), it points to 7
	// sequence containers don't even have find() memeber function

	pair<set<int>::iterator, bool> ret;
	ret = myset.insert(3); //now new element is inserted

	if(ret.second = false)
		it = ret.first; // it now points to element 3

	myset.insert(it,9); // myset:{1,3,7,9} O(log(n)) => O(1)
		//it points to 3

	myset.erase(it);


}















#endif