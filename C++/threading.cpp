#include <iostream>
#include <thread>
#include <string>
#include <mutex>
#include <future> //future, async
#include <fstream>
#include <condition_variable>
#include <deque>
using namespace std;

std::mutex mu;

class LogFile{
	std::mutex m_mutex;
	ofstream f;

public:
	LogFile() {
		f.open("log.txt");
	}
	void shared_print(string id, int value){
		std::lock_guard<std::mutex>locker(m_mutex);
		cout<<"From "<<id<<" :"<<value<<endl;
	}
	// bad idea 
	//ofstream & getstream() {return f;} // since user have the access f without mutex
	// never pass f as an augument to user provided function
};


class LogFile_4{
	std::mutex m_mutex; //security reason
	std::mutex m_mutex2; //file reason
public:

	void shared_print(string id, int value){
		std::lock(m_mutex,m_mutex2);
		std::lock_guard<std::mutex>locker(m_mutex,std::adopt_lock);
		// adopt_lock tell locker that m_mutex has already locked, adopt the ownership to mutex
		// so that when out of scope to unlock m_mutex
		std::lock_guard<mutex>locker_2(m_mutex2,std::adopt_lock);
		cout<<"From "<<id<<" :"<<value<<endl;
	}

	void shared_print2(string id, int value){
		std::lock(m_mutex,m_mutex2);
		//std::lock_guard<std::mutex>locker_2(m_mutex2);
		//std::lock_guard<mutex>locker(m_mutex);

		std::lock_guard<std::mutex>locker_2(m_mutex,std::adopt_lock);
		std::lock_guard<mutex>locker(m_mutex2,std::adopt_lock);
		cout<<"From "<<id<<" :"<<value<<endl;
	}
};



class LogFile_5{
	std::mutex m_mutex;
	std::mutex _mu_open;
	std::once_flag _flag;
	ofstream _f;

public:
	/*
	void shared_print(string id, int value){
		std::unique_lock<mutex>locker(m_mutex,std::defer_lock);
		if (!_f.is_open()){
			std::unique_lock<mutex> locker(_mu_open); // is not thread safe, thread A go here find file is not open 
			//and at the same time thread B come here and find file is not open
			// so file will be open twice
			_f.open("log.txt");
		}
		locker.lock();
		cout<<"From "<<id<<" :"<<value<<endl;
		locker.unlock(); // unique lock provide fined-lock
		// do something else
		locker.lock();
		locker.unlock(); // can lock and unlock multiple times, this cannot be done with lock_guard
		std::unique_lock<std::mutex>locker2 = std::move(locker);
		// 把ownership transfer 给 locker2
		
	}*/
		
		void shared_print(string id, int value){
		/*{ //every time will check if program file is opened, waste time
			std::unique_lock<std::mutex>locker(_mu_open);//haven't lock yet
			if (!_f.is_open()){
				_f.open("log.txt");
			}	
		}*/

		std::call_once(_flag,[&](){_f.open("log.txt");});

		std::unique_lock<mutex>locker(m_mutex,std::defer_lock);
		cout<<"From "<<id<<" :"<<value<<endl;
		
	}
};




void shared_print(string msg, int id)
{
	// lock mutex
	//mu.lock(); // other thread will not print message
	std::lock_guard<std::mutex>guard(mu); // RAII
	// if guard out of exception, mu will be unlocked, but cout is global variables, another variable can directly use cout
	cout << msg << id << endl; // if this line have error, lock will lock forever
	//mu.unlock();
}

void function_1(){
	cout << "beauty is only skin-deep"<<endl;
}

void function_3(LogFile & log){
	for (int i=0; i>-100;i--)
		log.shared_print( "From t3 ",i);
}

void function_4(LogFile_4 & log){
	for (int i=0; i>-100;i--)
		log.shared_print( "From t3 ",i);
}


std::deque<int>q;
std::condition_variable cond;

void function_61(){
	int count = 10;
	while (count > 0){
		std::unique_lock<mutex>locker(mu);
		q.push_front(count);
		locker.unlock();
		cond.notify_one(); // wake a thread which is waiting for condtion
		//也许有更多thread 都等着wake up， 可以用 cond.notify_all()
		std::this_thread::sleep_for(chrono::seconds(1));
		count --;
	}
}

void function_62(){
	int data = 0;
	while(data!=1){
		std::unique_lock<mutex>locker(mu);
		if (!q.empty()){
			data = q.back();
			q.pop_back();
			locker.unlock();
			cout << "t2 got a value from t1:  "<<data<<endl;
		}
		else{
			locker.unlock();
		}
	
	}

}

void function_622(){
	int data = 0;
	while(data!=1){
		std::unique_lock<mutex>locker(mu);
		// 有locker做为参数原因是：
		// 会unlock locker, then go to sleep, 之后碰到触发，再lock
		cond.wait(locker, [](){return !q.empty();}); // let thread2 in sleep until get notify by thread 1
		// spurious wake, we want to let it sleep again if wake once
		// if q is wake up and find q is empty then go to sleep again 
		data = q.back();
		q.pop_back();
		locker.unlock();
		cout << "t2 got a value from t1:  "<<data<<endl;
	}

}



int factorial_7(int N) {
	int res = 1;
	for (int i = N; i>1; i--)
		res *= 1;
	cout << "Result is: "<<res<<endl;
	return res;
}

int factorial_71(std::future<int> & f){
	int res = 1;
	int N = f.get();// exception: std::future_errc::broken_promise
	for (int i = N; i>1; i--)
		res *= i;
	cout << "Result is: "<<res<<endl;
	return res;}

class A_8{
	public:
		void f(int x, char c){}
		long g(double x) {return 0;}
		int operator()(int N) {return 0;}
};


class Fctor{
	public:
		void operator()(string & msg){ // not copy
			cout << "t1 says: "<<msg<<endl;
			//for (int i=0; i>-100;i--)
			//{
			//	cout << "from t1"<<i<<endl;
			//}
			msg = "Hey change";
		}
};

std::deque<std::packaged_task<int()>> task_q;
std::mutex mu9;
std::condition_variable cond9;
void thread_91(){
	std::packaged_task<int()>t;
	{
		std::unique_lock<mutex>lock(mu9);
		cond.wait(lock,[](){return !task_q.empty();});
		t = std::move(task_q.front());
		task_q.pop_front();
	}
	t(); // it will get a return value
}

int main()
{
	/*
	// to many thread is oversubscription. 
	// many thread running than CPU cost
	// cause to switch back-and worth

	cout << "how many thread can be running "<< thread::hardware_concurrency()<<endl; //hardware_concurrency(), get how many thread can be run CPU run

	cout << "current thread "<<this_thread::get_id() << endl; //get current thread id
	Fctor fct;
	//thread t1(function_1);
	//thread t1(fct);

	string s = "hey becks";
	//thread t1((Fctor()),s); //把参数放后面

	//thread t1((Fctor()),std::ref(s)); 	//想要把string 当成reference传入
	
	thread t1((Fctor()),std::move(s)); // move s from main thread to child thread
	cout << t1.get_id()<<endl;
	//thread t2 = t1; // cannot compile, since thread is not copyied

	thread t2 = move(t1); // move t1 to t2, t1 is empty now;

	t2.join();
	cout << "from main " <<s <<endl;
	
	//using RAII
	//Wrapper w(t1);

	//t1.join(); //main thread waits for t1 to finish
	//now we have two threads, main thread and child thread
	t1.detach(); // t1 will freely on its own -- daemon process 
	// 用detach 运行，就会没有显示print，因为main thread运行太快，还没有等到detach 运行出结果
	// 只能detach 或者 join 一次
	// if detach 和 join 一起run，program 会crash
	if (t1.joinable())
		t1.join();

	// if thread is destory before thread is detached or join, program will terminate


	try{
		for (int i =0; i <100; i++)
			cout << "from main "<<i<<endl;
	}catch(...){
		t1.join();
		throw;
	}	*/

	//t1.join();


	// ---------------------lesson 3--------------------------------
	//lock_guard outof scope, lock will be released with or without exception
	//race condition is not well for our program
	//thread t3(function_3);
	//for (int i = 0 ; i<100; i++)
	//	shared_print("from main ",i);

	//t3.join();
	
	/*
	LogFile log;
	thread t3_1(function_3,std::ref(log));
	for (int i = 0 ; i<100; i++)
		log.shared_print("from main ",i);

	t3_1.join();


	// ---------------------lesson 4- Dead Lock-------------------------------
	LogFile_4 log;
	thread t_41(function_4,std::ref(log));
	for (int i = 0 ; i<100; i++)
		log.shared_print2("from main ",i);

	t_41.join();
	// lock 可以同时lock mu, mu_2, 避免deadlock 
	//prefer locking single mutex at a time
	//avoid locking a mutex and call a user provided function
	//如果想一起lock 两个function，use std::lock() to lokc more than one mutex
	// 4. Lock the mutex in the same order

	//fine-grained lock: protects samll amount of data
	//coarse-grained lock: protects big amount of data
	*/

	// ---------------------lesson 5- Unique Lock and Lazy initialization-------------------------------
	//unique lock更加flexible
	// can lock and unlock multiple times, this cannot be done with lock_guard
	//unique lock 可以move、
	//unique lock 更加heavy， 想要更好的performance，用lock guard


	/*
	// ---------------------lesson 6- Condition Variable-------------------------------
	thread t_61(function_61);
	thread t_62(function_62);
	// thread t_61 is to create data
	// thread t_62 is to consume data, t_62 is always waiting, 也许take nap 可以让program更efficient


	t_61.join();
	t_62.join();
	*/

	/*
	// ---------------------lesson 7- Futures Promise, and async()-------------------------------
	// want to return child thread to parent thread
	// we want to make sure child thread fetch x first, then parent thread get x
	int x;
	//thread t7(factorial_7,4,std::ref(x));

	//std::future<int> fu = std::async(factorial_7,4);
	// future is a channel to get result from child thread
	// future class to is get something in the future
	//async may or may not be get thread; std::future<int> fu = std::async(std::launch::deferred,factorial_7,4);
	//上面的执行直到get function get called
	//当deferred function被called,会在同一个thread 运行，不会create 新的thread， async 会create a new thread
	// it will get another thread std::future<int> fu = std::async(std::launch::async,factorial_7,4); 
	// std::future<int> fu = std::async(std::launch::async | std::launch::deferred,factorial_7,4);
	// wether create a thread or not will determined by the implementation
	//std::launch::async | std::launch::deferred is defualt value for parameter 

	// fu.get() will wait until child thread finish
	//x = fu.get();
	// fu.get() only get once, if run more, get crash()


	// we can aslo pass value from parent thread to child thread
	std::promise<int> p;
	std::future<int> f = p.get_future();
	// cannot pass the same future into all the thread 因为一个future，只能被get 一次
	// 如果想一个future pass 很多个
	//std::shared_future<int>sf = f.share(); 之后pass function 需要pass shared_future<int>

	std::future<int> fu = std::async(std::launch::async,factorial_71,std::ref(f));
	std::future<int> fu2 = std::async(std::launch::async,factorial_71,std::ref(f));
	std::future<int> fu3 = std::async(std::launch::async,factorial_71,std::ref(f));

	// do something else
	std::this_thread::sleep_for(chrono::milliseconds(20));
	p.set_value(4);

	// if I cannot set value, I can set exception
	//p.set_exception(std::make_exception_ptr(runtime_error("To err is human")));
	// promise and future cannot be copied. must be move
	// std::promise<int> p2 = std::move(p);


	x = fu.get();
	cout << "get from" << x << endl;
	//t7.join();
	*/

	/*
	// ---------------------lesson 8- using callable objects-------------------------------

	A_8 a;
	std::thread t_8(a,6); // copy_of_a() in a different thread
	//std::thread t3(A_8(),6);//temp A
	//std::thread t4([](int x) {return x*x;},6) // create a lambda function
	//std::thread t_6(&A_8::f,a,8,'w'); // copy_of_a.f(8,'w') in a different thread
	std::async(std::launch::async,a,6);
	std::bind(a,6);//take a object and argument
	//std::call_once(once_flag,a,6);
	*/

	/*
	// ---------------------lesson 9 packaged_task-------------------------------

	//std::thread t7(factorial_7,6);//thread can be passed different parameters
	// package task argument cannot be passed by constructor
	//std::packaged_task<int(int)>t(factorial_7);
	//std::packaged_task<int()>t(std::bind(factorial_7,6));
	// parameter is bind with factorial function, when task is executed,cannot pass value
	//auto t = std::bind(factorial_7,6); // t is function object
	// the main advantage of package_task is that it can link a callable object to a future

	//factorial_7 is take int and return int
	//int(int) pass integer and return int

	//package can be passed along to different place, function, tasks, object,

	//t(6); // ican be executed n a different context
	//int x = t.get_future().get(); // get return value from factorial function
	thread t9(thread_91);

	std::packaged_task<int()> t(bind(factorial_7,6));
	std::future<int> fu = t.get_future();
	task_q.push_back(std::move(t));
	cond9.notify_one();
	cout <<fu.get()<<endl;
	// 3 ways to get a future
	// promise::get)fture() , package_task::get_future(), async() returns a future
	*/

	/*
	// ---------------------lesson 10 review and time constraint-------------------------------
	//thread 
	std::thread t_101(factorial_7,6);
	std::this_thread::sleep_for(chrono::microseconds(3));
	chrono::steady_clock::time_point tp = chrono::steady_clock::now()+chrono::microseconds(4);
	std::this_thread::sleep_until(tp);

	//mutex
	std::mutex mu10;
	std::lock_guard<mutex>lock(mu10);
	std::unique_lock<mutex>ulock(mu10);
	ulock.try_lock(); //if not successful, immediately return
	ulock.try_lock_for(chrono::nanoseconds(500)); //500 nanosecond pass and ulock cannot lock, function will return
	ulock.try_lock_until(tp); //until some timepoint

	//condition variable 
	std::condition_variable cond;
	cond.wait_for(chrono::microseconds(2));
	cond.wait_until(ulock,tp);

	//future and promise

	std::promise<int> p;
	std::future<int> f = p.get_future();
	f.get();
	f.wait(); // get function internally call wait function
	f.wait_for(chrono::milliseconds(2));
	f.wait_until(tp);

	//async() 
	std::future<int> fu =async(factorial_7, 6);

	//package task
	std::packaged_task<int(int)>t(factorial_7);
	std::future<int> fu2 = t.get_future();
	t(6);
	// add time constraint, to use chrono library
	*/


	return 0;
}