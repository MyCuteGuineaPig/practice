#ifndef lesson_10_Resource_Acquisition_is_Initialization_h
#define lesson_10_Resource_Acquisition_is_Initialization_h

/*
	Resource Acquisition is Initialization(RAII)

	use objects to manage resources:
		memory, hardware device, network handle

		Conclusion:
		The only code that can be guaranteed to executed after exception
		is throw are te destructor of ojects residing on the stack

		Resource management therefore needs to be tied to the lifespan of suitable objects in order to gain automatic
		deallocation and reclamation

		
	
*/


#include<iostream>
#include <mutex>
using namespace std;

/* Note 1
Mutex_t = MUTEX_INITIALIZAWR;

void functionA(){
	Mutex_lock (&mu);
	// Do a bunch of things
	Mutex_unlock(&mu); 
}

problem with the code is statement of Mutex_unlock may not be executed, because doing a bunch of thing 
也许会throw exception

solution:

class Lock{
	private:
		Mutext_t * m_pm;
	public:
		explicit Lock(Mutex_t *pm){Mutex_lock(pm);m_pm = pm'}
		~Lock {Mutex_unlock(m_pm);}

};

void function!A (){
	Lock mylock(&mu);
	// the mutex will always be released when mylock is destroied from stack 
	// destructor invoked
}

*/




/*	Conclusion:
The only code that can be guaranteed to executed after exception
is throw are te destructor of ojects residing on the stack

Resource management therefore needs to be tied to the lifespan of suitable objects in order to gain automatic
deallocation and reclamation

*/

/*	Conclusion:
Another good example of RAII: tr1:shared_ptr

int function_A(){
	strd::tr1::shared_ptr<dog>pd(new dog());
} // The dog is destructed when pd goes out of scope ( no more pointer points to pd)
在scope 以外， pointer 会指向pd
shared_ptr is a smart pointer when reference decrease to 1, pointer will be destroyed 
shared_ptr: smart pointer

*/
//Another example:

/*
	class dog;
	class Trick;

	void train(tr1::shared_ptr<dog>pd, Trick dogtrick);
	Trick getTrick(); // return trick

	int main(){
		train(shared_ptr<dog>pd(new dog()),getTrick());
	}

	what happens in train()'s parameter passing:
	1. new dog();
	2. getTrick();
	3. construct tr1::shared_ptr<dog>
	The order of these operations are determined by complier
	GetTrick() may throw exception, then create a new dog which 没有存到shared_ptr net, memory of new dog will be leaked

	Don't combine storing objects in shared pointer with other statement

	所以正确方式是：
	int main(){
		tr1::shared_ptr<dog>pd(new dog());
		train(pd, getTrick());
	}
*/



/*	Note 3:
	what happens when resource managment object is copied 

	Lock L1(&mu);
	Lock L2(L1);

	Solution 1:
		Prohibit copying. disallow copy constructor and copy assignment operator from being used

	Solution 2:
		reference - count the underlying resource by using tr1::shared_ptr

	We need to make sure all resources are released appropriately when we done with it


	template <class other, class D> shared_ptr(other * ptr, D deleter)
	shared pointer takes first parameter and store at the stack
	shared pointer takes second parameter as delete
	// The default value for deleter is operator delete

	The default value for D is delete. e.g: 
		std::tr1::shared_ptr<dog> pd (new dog()); 
		
		
	deleter can be custimized to any function you like


	class Lock{
	private:
		std::tr1::shared_ptr<Mutex_t>pMutex;
	public:
		explicit Lock(Mutex_t *pm): pMutex(p,Mutex_unlock){ // second parameter
			Mutex_lock(pm);
		}
		// when constructed, create Mutex_lock, 
		when no more pointer points to p_mutex, mutex will be un_lock
	};


	Example:

	Lock L1(&mu);
	Lock L2(L1);
	reference count will be two, 
	by the time both L1 and L2 out of scope, the number of pointer points to p_mutex will be zero
	mutex will be unlock

	保证了mutex will be unlock，


*/



void lesson_10() {





}




#endif
#pragma once


#pragma once
