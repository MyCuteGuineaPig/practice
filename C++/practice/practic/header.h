#ifndef HEADER_H
#define HEADER_H

#include<iostream>
using namespace std;

class OVERLOAD
{
	public:
		int num;
		OVERLOAD() {};
		OVERLOAD(int a);
		
		// return this OVERLOAD object
		OVERLOAD operator+ (OVERLOAD);// operator must be added, use + operator
};
OVERLOAD::OVERLOAD(int a): num(a){}

OVERLOAD OVERLOAD::operator+ (OVERLOAD aso) // 第一个OVERLOAD 是return type
{
	OVERLOAD brandnew;
	brandnew.num = num + aso.num; // return 是 brandew，自带的是num，传入OVERLOAD function 的object 叫asm
	return brandnew;
}

// inhertiance only inherit base class public and protected
class inheritance_mother
{
	public:
		inheritance_mother(){cout<<"I am monther constructor"<<endl;}
		void sayName(){
			cout<< "I am a Mother"<<endl;
		}
		~inheritance_mother(){ cout<<"I am Mother deconstructor"<<endl;}
};


class inheritance_daugther: public inheritance_mother // include all the stuff(all variables and functions) from mother
{
	public:
		inheritance_daugther(){cout<<"I am daughter constructor"<<endl;}
		~ inheritance_daugther () {	cout<<"I am daugther deconstructor"<<endl;}
};



class polymorphism_Enemy{
	protected:
		int attackpower;
	public: 
		void setattackpower(int a){
			attackpower = a;
		}
};

class polymorphism_ninja: public polymorphism_Enemy
{
	public:
		void attack()
		{
			cout << "I am a ninja, ninja chop!! - "<<attackpower <<endl;
		}

};

class polymorphism_monster: public polymorphism_Enemy
{
	public:
		void attack()
		{
			cout << "monster will eat you!!! - "<<attackpower <<endl;
		}

};

class virtual_Enemy{
	public: 
		virtual void attack()= 0;  // use function as virtual, it means that make function polymorphicialy
};

class virtual_ninja: public virtual_Enemy
{
	public:
		void attack()
		{
			cout << "I am a ninja, ninja chop!! - "<<endl;
		}

};

class virtual_monster: public virtual_Enemy
{
	public:
		void attack()
		{
			cout << "monster will eat you!!! - "<<endl;
		}

};


class pure_virtual_Enemy{
	public: 
		virtual void attack() = 0;

};


// template
template <class bucky> //bucky is the generic type of data
bucky add_t(bucky a, bucky b)
{
	return a+b;
}

template <class first, class second> // generic type is the type of data
first smaller(first a, second b)
{
	return (a<b?a:b);
}

// class template
template <class T>
class Bucky
{
	T first, second;
	public:
		Bucky(T a, T b): first(a), second(b){};
		T bigger();
};

template <class T> // for every single function outside declaration outside class, we awalys need the template definition again 
T Bucky<T>::bigger() //function template <T> : need to tell function template is the same one that is the same as using for class
{
	return (first>second ? first:second);
}




template <class T>
class Spunky{
	public:
		Spunky(T x){
			cout << x << " is not a character"<<endl;
		}


};

//template specialization empty <>
template<>
class Spunky<char>{ //only hanlder char
	public:
		Spunky(char x){
			cout << x << " is indeed a string"<<endl; 
		}

};


#endif
