#include <iostream>
#include "header.h"
#include <fstream> //file input and outfile
#include <string>
#include <cstdlib> // random
#include <ctime>
using namespace std;


void passByValue(int x){
	x = 99;
}

void passByReference(int *x){ // pointer store the address
	*x = 66;
}


int main(){

	cout << "operator overload "<<endl;
	OVERLOAD a(34);
	OVERLOAD b(21);
	OVERLOAD c;

	c = a + b; // ever if know the plus sign means +
	cout << c.num << endl;

	cout <<endl<< "-------------------inheritance -------------------------\n";
	//inheritance_mother mom;
	//mom.sayName();

	inheritance_daugther tina;
	tina.sayName();

	// 当call inheritance_daughter, the first program do is to invoke base class of the constructor, 最后在run base destructor
	// 因为要setup base class in order to run derived class; 所以base class constructor run first


	cout <<endl<< "-------------------polymorphism -------------------------\n";
	polymorphism_ninja n;
	polymorphism_monster m;
	polymorphism_Enemy *enemy1 = &n; // save pointer to address of ninja, because ninja is a enemy
	polymorphism_Enemy *enemy2 = &m;
	enemy1->setattackpower(29); // use pointer should use ->
	enemy2->setattackpower(99); 
	// use the generation to set attack power
	n.attack(); // we have to use ninja, monster to call attack coz enemy don't have attack power
	m.attack();


	cout <<endl<< "-------------------virtual  function -------------------------\n";
	// overwrite the function in the base class
	// 如果derived clas 没有virtual function, 会call base virtual function
	virtual_ninja nn;
	virtual_monster mm;
	virtual_Enemy *enemy11 = & nn;
	virtual_Enemy *enemy12 = & mm;
	enemy11->attack(); // call the same function but different results based on what address it points to
	enemy12->attack();

	// pure virtual function do not have option to inheritance from base class
	// pure virtual function 不能直接call base class function,pure virtual function 的derived class必须overwrite the base class function
	// pure virtual function 没有body， 存在意义是check 每一个derived class 必须要有that function

	cout <<endl<< "------------------- function template-------------------------\n";
	float x = 43.7;
	float y = 7;
	float z = add_t(x,y);
	cout << z<<endl;

	int xx = 89;
	double yy = 56.78;
	cout << smaller(xx,yy)<<endl;

	cout <<endl<< "------------------- class template-------------------------\n";
	// 每一个function build outside class, require proceed function template, need <>for the generic data type
	//当建立 object， 需要说明object的type，int
	Bucky <int>bo(69,105); // we need to tell what type of data need for the template for class
	cout<<bo.bigger()<<endl;

	//一个template可以handle 所有的type，另一个单独的handle character

	Spunky<int> obj1(7);
	Spunky<double> obj2(8.76);
	Spunky<char> obj3('x');

	cout <<endl<< "------------------- error handling-------------------------\n";

	try{
		int monsAge = 30;
		int sonsAage = 34;

		if (sonsAage>monsAge){
			throw  99;// throw a exception, just throw a number. check 20 different types error
		}
	}
	catch (int yy){
		cout << "son cannot be older than mom error number :" <<yy<<endl;
	}

	// 如果有error，就会break try statement

	try{
		int num1 = 30;
		int num2 = 20;

		if (num2 == 0){
			throw  99;// throw a exception, just throw a number. check 20 different types error
		}
		cout << (float)num1/num2 << endl;
	}
	catch (...){ // ... means any error message. if any error message error, default catch
		cout << "you cannot divid by zero "<<endl;
	}





	cout <<endl<< "------------------- work with files-------------------------\n";

	ofstream buckyfile; // need to build object, then associate this object to file
	buckyfile.open("C:\\Jichen Project\\practice\\tuna.txt"); // if not exit, create a file for u, buckyfile 就是tuna.txt

	buckyfile << "I love tunna and tunna love me!\n"; //把这个output 到这个file
	//最后要close file
	buckyfile.close();

	ofstream buckyfile1 ("C:\\Jichen Project\\practice\\beef.txt"); //easy way to associate file
	// isopen check if object is associated with file
	if (buckyfile1.is_open())
	{
		cout<<"file is open "<<endl;
	}
	else{
		cout<<"you measssed up"<<endl;
	}
	buckyfile1 << "oh I love the beef\n";
	buckyfile1.close();

	// custom output file format
	ofstream thefile("C:\\Jichen Project\\practice\\players.txt");
	//cout << " Enters players ID, Name, and Money"<<endl;
	cout << "press Ctrl+Z to quit\n"<<endl;
	int idNumber;
	string Name;
	double money;

	/*
	while(cin >> idNumber >> Name>>money) // 每个输入间有空格
	{
		thefile << idNumber << Name << money<<endl;
	}*/
	idNumber = 0;
	Name = "Sarah";
	money = 65.80;
	thefile << idNumber <<" " << Name <<" "<< money<<endl;
	thefile << 1 <<" " << "Mike" <<" "<< 109.87<<endl;


	//custom input file format
	ifstream thefile1("C:\\Jichen Project\\practice\\players.txt"); 
	//run the ifstream object and get eof pointer, the deconstructor will run automatically and the file close automatically;
	// 所以对于ifstream 不用写file.close()
	int id1;
	string name1; 
	double money1;

	// every file has a file end of file marker, C++ run the program and get end of file marker, it will return the null pointer
	// file pointer will find the those info, eof pointer will return false
	while (thefile1>>id1>>name1>>money1){
		cout << "id: "<<id1 << " name: "<< name1 << " money: "<<money1<<endl;
	
	}



	// rand get the same random is the same
	srand(time(0)); //srand to pass seed to get different random number 

	cout <<endl<< "-------------------random number generater -------------------------\n";
	cout << time(0)<<endl;
	// in order to get rand() % 6, so get 0,1,2,3,4,5
	for(int i = 0; i<5; i++)
		cout << i << "  " << 1+(rand()%6) << endl;



	cout <<endl<< "-------------------pointer-------------------------\n";
	//a pointer contain memory of variables, & called address operator
	int fish = 5;
	cout << "the address is: "<< &fish << endl; 
	int *fishpointer;

	fishpointer = &fish; // assign memory address

	cout << "the address of fish is: "<< fishpointer << endl; // print out the fish address

	// pass by reference, two different way to pass into function 
	//1. pass by value(copy variable make copy to function) 2. pass by reference(pass by address)
	// pass by value cannot change that value, // pass by reference will change that variable
	int betty = 13;
	int sandy = 13;
	passByValue(betty);
	passByReference(&sandy);
	cout << "pass by value "<<betty<<endl<<"pass by reference "<<sandy<<endl;

	int bucky[5];
	int *bp0 = &bucky[0]; //store the address first number in the array
	int *bp1 = &bucky[1]; 
	int *bp2 = &bucky[2];
	cout << "the memory of 1 element : "<<bp0 << endl;
	cout << "the memory of 2 element : "<<bp1 << endl;
	cout << "the memory of 3 element : "<<bp2 << endl;

	bp0 += 2;
	cout << "the memory of 1 element : "<<bp0 << endl; // now the address of first number is the third number


	cout <<endl<< "-------------------sizeof-------------------------\n"; //find how many elements in an array
	//sizeof array, length, into bytes
	char c1;
	cout <<"the size of charactor in bytes: "<<sizeof(c1)<<endl; //1
	int cc;
	cout <<"the size of integer in bytes: "<<sizeof(cc)<<endl; //2,or 4, or 8
	double c2;
	cout <<"the size of double in bytes: "<<sizeof(c2)<<endl; // 8
	// the more precise, the more memory it takes of 
	double bucky1[10];
	cout <<"the size of double array of length in bytes: " <<sizeof(bucky1)<<endl; // 80, 每一个double是10
	cout << "the size of array : "<< (int) sizeof(bucky1) / sizeof(bucky1[0]) <<endl;

	return 0;
}