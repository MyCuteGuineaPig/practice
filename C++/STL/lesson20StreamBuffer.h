#ifndef lesson20StreamBuffer_h
#define lesson20StreamBuffer_h

/*
	streambuf *pbuf = cout.rdbuf();  get the pointer to the internal module for stream buffer
	ostream myCout(pbuf); 创建一个ostream 与cout 有一样的stream buffer
	这样的话：
		myCout << 34; 34 就会打印出来

	恢复之前的buffer， assign 不能stream buffer 前，先存入原始的streambuffer
	streambuf *origBuf = cout.rdbuf();
	cout.rdbuf(of.rdbuf()); // assign the stream buffer for of to count

	cout << "Hello " << endl; // MyLog.txt has "Hello" redirect to log file

	// 之后我们可以恢复用 cout.rdbuf(origBuf)
	cout.rdbuf(origBuf);
	cout << "Goodbye" << endl; // stdout: Goodbye

*/


#include <iostream>
#include <fstream>
#include <iomanip> // manipulator
using namespace std;


void lesson_20() {

	// IO operation:
	//formatting data  -- stream class
	// communicating data to external devices -- stream buffer

	cout << 34; // cout is responsible for converting 34 into an appropriate format, then commciating data is stream buffer
	//cout.rdbuf(); // get the pointer to the internal module for stream buffer

	streambuf *pbuf = cout.rdbuf();
	ostream myCout(pbuf); // create another ostream which has the same stream buffer as cout
	myCout << 34; // 34 to stdout;

	myCout.setf(ios::showpos);  // show positive sign as number
	myCout.width(20); // by default the data will right to the right

	myCout << 12 << endl; // will print                   +12;
	cout << 12 << endl; //12
	// this is useful for temporary output for mycout but not change cout

	ofstream of("MyLog.txt");
	streambuf *origBuf = cout.rdbuf();
	//cout.rdbuf();  // will assign different stream buffer to cout
	cout.rdbuf(of.rdbuf()); // assign the stream buffer for of to count

	cout << "Hello " << endl; // MyLog.txt has "Hello" redirect to log file

	// be restore cout as original buffer, you cannot do not that, becuase original stream buffer is lost
	// 之后我们可以恢复用 cout.rdbuf(origBuf)
	cout.rdbuf(origBuf);
	cout << "Goodbye" << endl; // stdout: Goodbye

	/*
	//another to access stream buffer is to use stream buffer iterator
	istreambuf_iterator<char>i(cin);
	ostreambuf_iterator<char>o(cout);
	while (*i != 'x') {
		*o = *i;
		++o;
		++i;
	} // read from input and to standard output until see letter 'x'

	copy(istreambuf_iterator<char>(cin), istreambuf_iterator<char>(), ostreambuf_iterator<char>(cout)); // do the same things 除了不能在x 停止
	*/
}



#endif
#pragma once
