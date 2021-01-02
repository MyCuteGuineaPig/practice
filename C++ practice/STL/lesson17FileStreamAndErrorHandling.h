#ifndef lesson17FileStreamAndErrorHandling_h
#define lesson17FileStreamAndErrorHandling_h

/*
	ofstream of("Mylog.txt"); 会打开file，清楚所有的东西，然后写入file
	ofstream of("Mylog.txt", ofstream::app); //app 是append 接着以前的写，不会remove file本身的内容，打开file，在结尾接着写

	// 想写在中间，需要read file as well
	ofstream of("Mylog.txt", ofstream::in | ofstream::out);
	of.seekp(10, ios::beg);// 移动output pointer 10个char的长度从文件开始的位置，文件就可以从10这个位置写入  move output pointer 10 chars after begin
	of.seekp(-5, ios::end); // 移动output pointer 5个char的长度从文件结束的位置往前，move output pointer 5 chars before end
	of.seekp(-5, ios::cur); // 移动output pointer 5个char的长度从文件现在的位置往后


	Error Handling
	ifstream inf("Mylog.txt");
	int i;
	inf >> i; 
	//Error Status: goodbit, badbit, failbit, eofbit(end of file)
	inf.good(); 返回true如果一切正常 return true if Everything is ok (goodbit==1)
	inf.bad();  是不能恢复的error Non-recoverable error (badbit==1)
	inf.fail(); 可以修复的error failed stream operation (failbit == 1 and badbit==1), error is recoverable
	inf.eof(); // End of file (eodbit==1)

	inf.clear(); 清楚所有的error status( goodbit, badbit, failbit, eofbit() clear all the error status 如果你想继续 如果括号里面没有其他的，等于clear(ios::goodbit)
	inf.clear(ios::badbit); 清楚除了badbit之外的，所有的error status set a new value to the error flag, badbit == 1, 其他的error 都是0

	inf.rdstate(); 读取现在error status read the current status flag
	inf.clear(inf.rdstate() & ~ios::failbit); // clear only the fail bit, everything else stay the name

	if (inf) // Equivalent if (!inf.fail())
	cout << "Read successfully " << endl;

	if (inf >> i) // input operator inf return reference to stream itself
	cout << "Read successfully ";

	inf.exceptions(ios::badbit | ios::failbit); // Either the badbit or failbit = 1, the exception will be throwned
	//when badbit or failbit set to 1, exception of ios::failure will be throw
	// but if eofbit set to 1, no exception
	inf.exceptions(ios::goodbit); // No exception will be generated

*/




#include <iostream>
#include <fstream>
#include <bitset>
#include <complex>
using namespace std;

void lesson_17() {
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

	{
		//ofstream of("Mylog.txt"); // Open file for write, clear the content of file
		ofstream of("Mylog.txt", ofstream::app); //app 是append 接着以前的写，不会remove file本身的内容
		of << "Honesty is the best policy. " << endl;
	}

	{
		// 想写在中间，需要read file as well
		ofstream of("Mylog.txt", ofstream::in | ofstream::out); 
		of.seekp(10, ios::beg);// move output pointer 10 chars after begin
		of << "12345"; //overwrite 5 chars file 第一行变成 Experience 12345, 
		of.seekp(-5, ios::end); // move output pointer 5 chars before end
		of << "Nothing ventured, nothing gained." << endl;
		of.seekp(-5, ios::cur); // move output pointer 5 chars before current position 
	}

	/*
	ifstream inf("Mylog.txt");
	int i;
	inf >> i; //read one word from file and pass integer and
	// but this not integer, fails operation
	//Error Status: goodbit, badbit, failbit, eofbit(end of file)
	inf.good(); //return true if Everything is ok (goodbit==1)
	inf.bad(); // Non-recoverable error (badbit==1) 
	inf.fail(); // failed stream operation (failbit == 1 and badbit==1), error is recoverable
	inf.eof(); // End of file (eodbit==1)

	inf.clear(); // clear all the error status 如果你想继续 如果括号里面没有其他的，等于clear(ios::goodbit)
	inf.clear(ios::badbit); // set a new value to the error flag, badbit == 1, 其他的error 都是0

	inf.rdstate(); // read the current status flag
	inf.clear(inf.rdstate() & ~ios::failbit); // clear only the fail bit, everything else stay the name 

	if (inf) // Equivalent if (!inf.fail())
		cout << "Read successfully " << endl;

	if (inf >> i) // input operator inf return reference to stream itself
		cout << "Read successfully ";

	inf.exceptions(ios::badbit | ios::failbit); // setting the exception mask. Either the badbit or failbit = 1, the exception will be throwned
	//when badbit or failbit set to 1, exception of ios::failure will be throw
	// but if eofbit set to 1, no exception 
	inf.exceptions(ios::goodbit); // No exception will be generated 
	*/
}

#endif
#pragma once
