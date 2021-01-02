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


/* 
	associated come from map

	value is associated with key

	where set and multiset can be considered of special map where key of each elements is the same of values
*/

/*associate containter is designed for binary tree
	when insert items in binary tree, it will appear in the appropriate tree
	when delete that items, then tree will be arranged. 

	So No push_back(), push_front()
	logitharism search time is advantage of assciate containers

*/


void lesson_3(){
	cout << "-----------------SET--------------"<<endl;
	// set do not have duplicated items
	set<int>myset;
	myset.insert(3);
	myset.insert(1);
	myset.insert(7); // Insert time O(log(n))


	//find mush faster than O(log(n))
	//
	set<int>::iterator it;
	it = myset.find(7); // O(log(n)), it points to 7
	// sequence containers don't even have find() memeber function

	pair<set<int>::iterator, bool> ret;
	ret = myset.insert(3); //now new element is inserted, insert can return pair, second is whether insert true or not 

	if(ret.second = false)
		it = ret.first; // it now points to element 3,

	myset.insert(it,9); // myset:{1,3,7,9} O(log(n)) => O(1), if you provide 一个好的提示，insert time 可以变成O(1)
	//the value of inserted cannot be decided by iterator, it can only decide by value
	// where it is the iterator used as hint to find location where 9 is inserted
		//it points to 3

	myset.erase(it); // {1,7,9}

	myset.erase(7); // erase 可以是value 或者iterator {1,9}
	// none of sequence containers provide this kind of erase

	cout << "-----------------MULTISET--------------" << endl;
	/* multiset is a set that allows duplicated items
	set/multiset value of the elements cannot be modified read only

	if modified multiset， 会改变data structure, elements 不能被sort

	properties: 
	1. fast search O(log(n))
	2. Traversing is slow (compared to vector & deque)
	3. No random access, no[] operator
	
	*/
	multiset<int>myset2;
	//*it = 10; // read only cannot do that 


	cout << "-----------------Map--------------" << endl;
	/* map no duplicated key*/
	map<char, int>mymap;
	mymap.insert(pair<char, int>('a', 100));
	mymap.insert(make_pair('z', 200));

	map<char, int>::iterator itt = mymap.begin();
	mymap.insert(itt, pair<char, int>('b', 300)); // 'it' is a hint

	itt = mymap.find('z');
	// show contents
	for (itt = mymap.begin(); itt != mymap.end(); itt++)
		cout << (*itt).first << "=> " << (*itt).second << endl;

	cout << "-----------------Multi Map--------------" << endl;
	// multimap is a map that allows duplicated keys
	multimap<char, int>mymaps;
	// map/multimap, key 不能修改
	// type of *it： pair<const char, int>
	//(*)it.first = 'd'; //Error

}















#endif