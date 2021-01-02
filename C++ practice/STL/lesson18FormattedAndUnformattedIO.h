#ifndef lesson18FormattedAndUnformattedIO_h
#define lesson18FormattedAndUnformattedIO_h

/*
	the purpose of stream class is to format the data
	cout.setf(ios::oct,ios::basefield) 设置输出为8进制
	cout.setf(ios::hex, ios::basefield); 设置输出为16进制
	cout.setf(ios::dec, ios::basefield);改变format 成为decimal format
	cout.setf(ios::showbase);  会输入数字的base 
	cout.unsetf(ios::showbase);  会隐藏base

	cout.width(10); 会让output 变成10 characters
	cout.setf(ios::left, ios::adjustfield); 取消设置宽度到默认值
	cout.setf(ios::scientific, ios::floatfield);  "340.1 会打印成 3.401000e+002" 

	cout.setf(ios::fixed, ios::floatfield); "340.1 会打印成340.100000"
	cout.precision(3); //  设置精度为3

	cout.flags(); 可以返回现在output 的设置
	ios::fmtflags f = cout.flags();
	cout.flags(ios::oct | ios::showbase); // 将设置output为这个值.  now ios has 8进制，还会show base number


	//Member functions for unformatted IO hanldes for raw text
	ifstream inf("MyLog.txt");
	char buf[80];

	inf.get(buf,80);   读取inf中 80 个char,并存到buf 中
	inf.getline(buf,80);  读取inf中 80 个char 或者 直到下一行开启，然后存入buf 中

	inf.read(buf, 20); 读取20个char，存入buf中
	inf.ignore(3);  忽略接下来3个character 
	inf.peek();  返回stream 第一个char
	inf.unget(); 存入下一个char 到sream，下次用 inf.get(), note that unget 没有parameter，get（）每次读取char 都会一样 如果用unget()
	

	inf.putback('z'); 可以存入任意一个char 到stream 中
	inf.gcount(); 返回上一次stream 读取char 的个数, will return 1, 因为之前只读了一个char

	//output
	ofstream of("MyLog.txt");
	of.put('c'); //will put one character into stream
	of.write(buf, 6); 会将buf的前六个char 写入stream
	of.flush(); // flush the output


*/


#include <iostream>
#include <fstream>
using namespace std;

void lesson_18() {
	cout << 34 << endl; //34
	cout.setf(ios::oct, ios::basefield); // set cout to 8进制
	cout << 34 << " 8进制，会打出42" << endl;
	cout.setf(ios::showbase);
	cout << 34 << "  show base" << endl; // 会打出042
	cout.setf(ios::hex, ios::basefield); // set cout to 16 进制
	cout << 34 << " 16 进制的0x22" << endl;

	cout.unsetf(ios::showbase); // 会隐藏base infomation
	cout << 34 << "  会隐藏base 22" << endl; //
	cout.setf(ios::dec, ios::basefield);//改变format 成为decimal format

	cout.width(10); // 会让output 变成10 characters
	cout << 26 << endl;  // 显示        26            要保持宽度为10，10是default alignment 

	cout.setf(ios::left, ios::adjustfield);//26 变回原来的ouput

	//floating point value
	cout.setf(ios::scientific, ios::floatfield);
	cout << 340.1 << " 会打印成 3.401000e+002" << endl;

	cout.setf(ios::fixed, ios::floatfield);
	cout << 340.1 << " 会打印成340.100000" << endl;
	cout.precision(3);
	cout << 340.1 << " 会打印成340.100" << endl;


	int i;
	//cin.setf(ios::hex, ios::basefield);  // cin 会转变成8 进制
	//cin >> i; 输入12 变成18

	cout.flags(); //can return current setting for formate
	ios::fmtflags f = cout.flags();
	cout.flags(ios::oct | ios::showbase); // will set formate to this value.  now ios has 8进制，还会show base number

	//Member functions for unformatted IO hanldes for raw text

	ifstream inf("MyLog.txt");
	char buf[80];

	inf.get(buf, 80);//read inf up to 80 characters and save to buf
	inf.getline(buf,80); // read up to 80 characters or encounter a new line

	inf.read(buf, 20); // read 20 chars
	inf.ignore(3); // ignore next 3 characters
	inf.peek(); //return character on top of the stream
	inf.unget(); // return a char to the strem 下次用 inf.get(), note that unget 没有parameter，get（）只能读取一眼的char 如果用unget()
	//将read one character that you'll get character return back

	inf.putback('z'); // put a different char back to stream for next read
	inf.gcount(); // return number of chars being read by last unformatted read, will return 1, 因为之前只读了一个char

	//output
	ofstream of("MyLog.txt");
	of.put('c'); //will put one character into stream
	of.write(buf, 6); //write first 6 chars of buf into the stream
	of.flush(); // flush the output 

}


#endif
#pragma once
