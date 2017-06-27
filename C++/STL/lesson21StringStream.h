#ifndef lesson21StringStream_h
#define lesson21StringStream_h

/*
	如果想work both input and output 用stringstream, 否则用ostringstream(output) or istringstream (input)
	better safty and make your code 更加readable

	ss << 89 << " Hex:  " << hex << 89 << " Oct :  " << oct << 89 << endl; 往stringstream 传入数
	cout << ss.str() << endl;  89 Hex: 59 Oct: 131; 打印

	ss >> hex >> a;  从stringstram 中传出数，读取第一个word, 读取的数由8进制转化为10进制，word由 space, tabs, newlines 分割


*/

#include <iostream>
#include <fstream>
using namespace std;


void lesson_21() {
	//String Stream doesn't do IO operations
	//used for read and write string, treating string as treating file
	// purpose to reuse format function stream to process string
	stringstream ss;
	ss << 89 << " Hex:  " << hex << 89 << " Oct :  " << oct << 89 << endl;
	cout << ss.str() << endl; // 89 Hex: 59 Oct: 131; 

	int a, b, c;
	string s1;
	ss >> hex >> a;  // it will read first word and read as Hex number and save to ; Formatted input works token by token.
	// tokens are separated by space, tabs, newlines, 
	// 第一个是89， 最后a=137

	ss >> s1; // s1: "Hex:" second token is interpret as string

	ss >> dec >> b; // b is saved as decimal number b = 59
	ss.ignore(6); // ignore next 6 characters in the stream
	ss >> oct >> c; // c = 89 (131 被当成16进制的)

	//stringstream is powerful for formating string and extract from string

	//ostringstream -- formatted output
	//istringstream -- formatted input
	// 如果想work for input and output, use stringstream, 其他情况下， prefer to use ostringstream or istringstream
	// ostringstream or istringstream： provide more safyty, they are better at communicating intent your code, more readable 
	
}


#endif
#pragma once
