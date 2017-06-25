#ifndef  LESSON4UNORDERDCONTAINER_H
#define  LESSON4UNORDERDCONTAINER_H

#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
	properties of unordered containers:
	1. fastes search/insert at any place O(1)
		associative Container takes O(log(n))
		vector, deque takes O(n)
		list takes O(1) to insert, O(n) to search 

	2. unordered set/multiset: element value cannot be changed
	   unordered map/ multimap: element key cannot be changed

*/


void lesson_4() {
	/*
		unordered set or Multiset:
		unordered map or mutlmap

		the order of map/set is not defined, they may change with time

		unordered container is implemented with hash table which is array with linked list
		array 也叫 buckets, linked list 叫entry

		each elements is used by hash function to calculate value, based that value element is inserted into its own place in the entry
		the biggest advantage of this structure if you have a fastest and effective hash function, find elements in the table is very fast
		it only tasks constant time, 最快的among all containers

	*/

	unordered_set<string>myset = { "red","green","blue" };
	unordered_set<string>::const_iterator itr = myset.find("green"); // O(1)
	if (itr != myset.end()) // important check 
		cout << *itr << endl;
	myset.insert("yellow"); // O(1)



	vector<string>vec = {"purple","pink"};
	myset.insert(vec.begin(), vec.end());

	//Hash table specifixc APIs:
	cout << "Load_factor =  " << myset.load_factor() << endl; // load_factor return the total number of elements and total number of buckets
	string x = "red";
	cout << x << " is in bucket # " << myset.bucket(x) << endl; // bucket tells me which bucket that x is stored at  
	cout << "Total bucket # " << myset.bucket_count() << endl; // total number of buckets

	/*
		unordered mutliset: unordered set that allows duplicated elements
		unordered map: unordered set of pairs
		unordered multimap: unordered map that allows duplicated keys
		
		hash collision => performance degrade, it means many items are inserted into the same buckets
		最糟糕的情况是所有item 都存在一个items， 变成array， search time 从O(1) 到 O(n)
	*/

	/*associative Array - map and unordered map*/

	unordered_map<char, string>day = { {'S',"Sunday"},{'M',"Monday"} };
	cout << day['S'] << endl; // No range check
	cout << day.at('S') << endl;// has range check 

	vector<int> vecc = { 1,2,3 };
	//vec[5] = 5; has complie error

	day['W'] = "Wednesday"; // Inserting {'W',"Wednesday"}
	day.insert(make_pair('F', "Friday")); //Inserting {'F',"Friday"}

	//day.insert(make_pair('M', "MONDAY")); // insert function not be used to modify. Fail to modify, it's an unordered_map
	day['M'] = "MONDAY";

	// 当complier see day["M"], it is assumed to write to day["M"], so fail to run cout << M['S'] << endl; 当 function传入const unorderedmap
	// 如果想打印，有const unorderedmap, auto itr = m.find("S"), if (itr!=m.end()) cout<<*itr<<endl;

	/*
	Associative Array
	1. Search time: unordered_map, O(1); map, O(log(n))
	2. unordered_map may degrade to O(n) linear time, map can guarantee Log(n) time search
	3. can't use multimap and unordered_multimap. they don't have [] operator
		
	*/

}













#endif // ! LESSON4UNORDERDCONTAINER_H