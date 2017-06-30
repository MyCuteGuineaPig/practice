#ifndef lesson6Virtual_Destructor_And_Smart_Destructor_h
#define lesson6Virtual_Destructor_And_Smart_Destructor_h
/*
	如果没有virtual在 base destructor, derived destructor will not be called
	if a class is called in polymorphic way, create a derived and cast into bsae class pointer, then base class must have virtual destructor
	实际上建了连个class，但因为destructor 只会call base class destructor

	唯一方法call static function，是use scope operator
	Dogg * pd = DogFactorty::createYellow();

	另外一种方法不用call virtual destructor 是用shared_pointer： shared_ptr
	这种方法尽管不用加virtual，但两个destructor 都会run，而且不用delete， shared_ptr会delete by itself

	unique pointer 没有这个功能


	所有STL class 都没有virtual destructor， 用polymorphism 的话，最好用shared_ptr
*/


#include<iostream>
#include <memory>
using namespace std;

class Dogg{
	public:
		virtual ~Dogg() { cout << "Dog Destoryed" << endl; }
		//virtual void bark();
};


class YellowDog: public Dogg{
	public:
		~YellowDog() { cout << "YellowDog Destoryed" << endl; }
};

class DogFactorty{
	public:
		static Dogg* createYellow() {
			return (new YellowDog());  // create a yellow as dogs pointer
		}
		//如果不想用virtual destructor
		static shared_ptr<Dogg> createYellow1() {
			return shared_ptr<YellowDog>(new YellowDog());
		}
};

void lesson_6() {

	Dogg * pd = DogFactorty::createYellow();

	delete pd;

	shared_ptr<Dogg> pd1 = DogFactorty::createYellow1();
	// pd1 will be deleted by iteself I don't need to run virtual destructor then two destructor will run both
	// if you use unique pointer it won't do the job
	// All classes in STL has no virtual destructor, so be careful inheriting from them


}




#endif
#pragma once
