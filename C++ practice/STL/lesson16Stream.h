#ifndef lesson16Stream_h
#define lesson16Stream_h

/*	
	cout : a global object of ostream which is in std namespace
	ostream (typedef basic_ostream<char>ostream)
	<< : (ostream& ostream:: operator << (string v))  left shift operator:  it is a member function of ostream
	<< takes string 并返回到ostream and return a reference with the same ostream
	这是原因，当你send some data into ostream, you can change it with another output operation

	endl: let just assume '\n' + flush (flush operation)
	cout is a ostream which is a type of stream

	what is stream? Serial IO Interface, which handle IO data one by one
	to external device, file, stdin/stdout, network, etc

	What does Serial mean?
	string s("Hello"); //random access interface
	s[3] = 't' // Random access
	but you cannot use cout[3] = 't' in Serial Interface;  Error

	Some stream provide random access like File stream 
	file stream 不用写打开或者close 写在一个block 里面，出了block，自己就会关了

	ofstream of("Mylog.txt"); //Create a new file 如果这个file 不存在
	of << "Experience is the mother of wisdom" << endl;// this is
	left operator is overloaded function 把string 作为parameter
	// this stream not only overloaded for string parameters, it is overloaded for all fundamental data types


	IO Operation:
		formatting the data <----> communicating the data with external devices(txt)
		it doesn't matter you use file, stdin/stdout, you always use the same API to format the data

		formate 和交流的module 要离得尽可能远
		 this trigger software Engineering principal: low coupling, we have one module for format data and one module to communicate data
		and those two module are decoupled from each other as much as possible,
		low coupling: resuability, the same APi used for formatting data are reused for IO operations.


*/

#include <iostream>
#include <fstream>
#include <bitset>
#include <complex>
using namespace std;

//C++ Input and Output Library -- Stream

void lesson_16() {
	cout << "Hello " << endl;
	// cout : a global object of ostream

	//we don't need to open and close file, as long as we limit the code into certain scope
	// then the file is open when the file is contructed, it will be closed when ostream go out of scope
	{
		ofstream of("Mylog.txt"); //Create a new file for write if the file didn't exist
		of << "Experience is the mother of wisdom" << endl;// this is 
		// left operator is overloaded function that take string as parameter,
		// this stream not only overloaded for string parameters, it is overloaded for all fundamental data types
		of << 234 << endl;
		of << 2.3 << endl;
		of << bitset<8>(14) << endl; // this will write 00001110 into file
		of << complex<int>(2, 3) << endl;// this will write (2,3)

		//  with the stream, we can handle the data conveniently when exchange the data external devices
	} //RAII 

	//IO Operation:
	//formatting the data <----> communicating the data with external devices(txt)
	//it doesn't matter you use file, stdin/stdout, you always use the same API to format the data
	

	// this trigger software Engineering principal: low coupling, we have one module for format data and one module to communicate data
	// and those two module are decoupled from each other as much as possible, 
	// low coupling: resuability, the same APi used for formatting data are reused for IO operations.
}


#endif
#pragma once
