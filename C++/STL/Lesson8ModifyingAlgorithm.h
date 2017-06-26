#ifndef LESSON8MODIFYINGALGORITHM_H
#define LESSON8MODIFYINGALGORITHM_H

/*
	Algorithm Walkthrough:
	Value-changing Algorithm - Changes the element values
	copy, 复制数据两个都有
	move,  从一个复制到另一个， 开始的那个最后没有了
	transform, 从一个做一些处理，复制到另一个
	swap, swap_ranges  two way copying
	fill, 给vector 赋值，generate 用function 产生值，然后fill
	replace, 用新的值 replace 固定的值，replace_if 可以用lambda function来设置条件
	replace_copy, 用老的值，operation 再copy到新的vector, replace_copy_if
	remove(remove vector 所有满足条件的值), remove_if, remove_copy, remove_copy_if
	unique remove 所有不一样的，也是generalized form, unique_copy(simple && generalized form)
	

	Order-changing Algorithm
	--reverse, rotate, permute, shuffle
	reverse: reverse 从特质位置reverse reverse_copy
	rotate, 从特定位置开始，让它做第一个元素，然后之前的元素成为结尾之后，按顺序排，rotate_copy

	lexicographically smallest 从小到大排序
	lexicographically greatest 从大到小排序
	next_permutation: lexicographically nex greater permutation 由小到大排序的permutation
	prev_permutation: lexicographically nex smaller permutation 由大到小排序的permutation
	They changes the order of elements in containrer, but not necessarily the elements themselves
	generation form: prev_permutation,next_permutation

	shuffle: random_shuffle
	shuffle: better random generation

*/
#include<iostream>
#include <vector>
#include <string>
#include <random>
#include <algorithm>

void lesson_8() {
	vector<int> vec = { 9,60,70,8,45,87,90 };// 7 items
	vector<int> vec2 = { 0,0,0,0,0,0,0,0,0,0,0 }; // 11 items
	vector<int>::iterator itr, itr2;
	pair<vector<int>::iterator, vector<int>::iterator>pair_of_itr;
	//1. copy, you have to make sure vec2 is as big as vec1
	copy(vec.begin(), vec.end(), // source
		vec2.begin()); // Destination 

	copy_if(vec.begin(), vec.end(),//
		vec2.begin(), [](int x) {return x > 80; });
	//vec2:{87,90,0,0,0,0,0,0,0,0,0}

	copy_n(vec.begin(), 4, vec2.begin());// 从 vec的开始起，前四个复制到vec begin

	copy_backward(vec.begin(), vec.end(),//source
		vec2.end() //Destination
	); // 把vec 复制到vec2的后面，相当于一个一个push_back，{0,0,0,0,9,60,70,8,45,87,90}


	//2. Move 
	vector<string>vec3 = { "apple","orange","pear","grape" }; // 4 items
	vector<string>vec4 = { "","","","","","" }; // 6 items

	move(vec3.begin(), vec3.end(), vec4.begin());
	/* move items from one place to another 
	move 之后  vec:{"","","",""} undefined ， vec2={ "apple","orange","pear","grape","",""}; 
	If mnove semantics are defined for the element type, elements are moved over,
	otherwise they are copied over with copy constructor, just like copy()
	如果vec, 或者vec2 只是integer， then move function just worked like copy function 
	*/

	move_backward(vec3.begin(), vec3.end(), vec4.end());//vec2={"","", "apple","orange","pear","grape"};

	//3. transform, it transform data with certain operation and save data in different place 
	vector<int>vec5 = { 9,60,70,8,45,87,90 }; // 7 items
	vector<int>vec6 = { 9,60,70,8,45,87,90 };
	vector<int>vec7 = { 0,0,0,0,0,0,0,0,0,0,0 }; // 11 items
	transform(vec5.begin(),vec5.end(),//source
		vec7.begin(), //destination
		[](int x) {return x - 1; } // operation
	);
	//transform can take two inputs of data
	transform(vec5.begin(), vec5.end(), //source 1
		vec6.begin(), // source 2
		vec7.begin(), //Destination
		[](int x, int y) {return x + y; });

	//4 Swap two way copying
	swap_ranges(vec5.begin(), vec5.end(), vec7.begin());



	//5 Fill fill the data with certain value
	vector<int>vec8 = { 0,0,0,0,0 };
	fill(vec.begin(), vec.end(), 9); // vec: {9,9,9,9,9} 从开始到结尾都fill 9
	fill_n(vec.begin(), 3, 9); // vec: {9,9,9,0,0}
	generate(vec.begin(), vec.end(), rand); // generate take the value generating function 然后再fill
	generate_n(vec.begin(), 3, rand); // 从begin 开始只赋给3个值

	//6 replace 用新的值 replace 固定的值
	replace(vec.begin(), vec.end(),//Data Range
		6, //old value condition
		9 // new value
	);

	replace_if(vec.begin(), vec.end(),//Data Range
		[](int x) {return x > 80; }, 9
	); // 可以用lambda function 来赋值

	replace_copy(vec.begin(), vec.end(), vec7.begin(), // Source, Destination
		6, //old value
		9// new value
		);
	//generalized form replace_copy_if

	//7 Remove
	remove(vec.begin(), vec.end(), 3); // Remove all 3's
	remove_if(vec.begin(), vec.end(), [](int x) {return x > 80; }); //remove items bigger than 80

	remove_copy(vec.begin(), vec.end(), // Source
		vec7.begin(), // Destination
		6 // Condition
	);// Remove all 6's and copy the remain items to vec2 
	//generalized form remove_copy_if

	unique(vec.begin(), vec.end()); //remove consecutive equal elements
	unique(vec.begin(), vec.end(), less<int>()); //remove elements whose previous element is less than itself
	unique_copy(vec.begin(), vec.end(),vec7.begin()); // remove consecutive equal elements, and then copy the uniquified items to vec7
	//generalized form unique_copy


	//1. Reverse
	vector<int>vec9 = { 9,60,70,8,45,87,90 };// 7 items
	vector<int>vec10 = { 0,0,0,0,0,0,0 }; // 7 items

	reverse(vec9.begin() + 1, vec9.end() - 1); // vec{9,87,45,8,70,60,90} // 7 items
	reverse_copy(vec9.begin() + 1, vec9.end() - 1, vec10.begin());
	//vec10:{87,45,8,70,60}

	//2 Rotate  变换顺序
	rotate(vec9.begin(), vec9.begin() + 3, vec9.end()); //从第一个开始到最后结束，  让第四个位置成为第一个
	//vec9: {8,45,87,90,9,60,70}
	

	rotate_copy(vec9.begin(), vec9.begin() + 3, vec9.end(),//source
		vec10.begin()); // Destination, vec9 is unchanged
	//permute 

	next_permutation(vec9.begin(), vec9.end()); // lexicographically next greater permutation 
	prev_permutation(vec9.begin(), vec9.end());//lexicographically next smaller permutation 

	/*{1,2,3,5} < {1,2,4,4}
	{1,2} < {1,2,3}
		
		sored in ascending order:{8,9,45,60,70,87,90} lexicographically smalles
		sorteed in descending order: {90,87,70,60,45,9,8} lexicographically greatest
		generalized form:next_permutation(), pre_permutation

	*/
	//4 shuffle
	//Rearrange the elements randomly 
	//swap each element with a ranomly selected element
	random_shuffle(vec9.begin(), vec9.end());
	//random_shuffle(vec9.begin(), vec9.end(), rand); 可以自己写rand function generation

	// C++ 11
	shuffle(vec9.begin(), vec9.end(), default_random_engine()); //better random number generation 
}



#endif
#pragma once
 