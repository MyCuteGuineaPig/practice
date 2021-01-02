//
//  main.cpp
//  concurrent programming
//
//  Created by beckswu on 7/9/17.
//  Copyright © 2017 beckswu. All rights reserved.
//

#include <iostream>
#include <thread>
#include <mutex>
#include "lesson2_Thread_Management.h"
#include "lesson3_Data_Race_And_Mutex.h"
#include "lesson4_Deadlock.h"
#include "lesson5_Unique_Lock_and_Lazy_Initialization.h"
#include "lesson6_Condition_Variable.h"
#include "lesson7_Future_Promise_Async.h"
#include "lesson8_Using_Callable_Object.h"
#include "lesson9_Packaged_task.h"

using namespace std;


/*
 
    multithreading:  thread 1 and thread 2 are communciating with shared memory 
    优点：
        fast to start, low overhead, multiprocessing 需要resource 当开启时managment the process
    缺点：
        difficult to implement, cann't run on distributed system
    
    only join thread/detach only once 
 
 */




/*
    大总结：
        thread t1(function_1) ; 是function_1的copy 在different thread
        thread 可以run lambda function
        thread t4([](int x){return x*x; }, 6);
 
    lesson2:
        如果把一个functor 加入thread,必须加上（），（）是function decoration，否则C++不知道它是functor
 
        如果想pass reference to thread function
            std::thread t1((Fctor()),std::ref(s));  pass value in the function by reference
        把variable 全部移到thread move()
            std::thread t1((Fctor()),std::move(s)); 把variable s 移动到fctor 里面
 
        如果想copy thread，必须用move
        thread t2 = move(t1);
 
        得到thread id
        this_thread::get_id();
        t1.get_id();

    lesson3:
 
        一个mutex，只能lock本地一个lock 范围内的内部的!! 不会干预其他thread运行!!，只让别的位置不call 这个function，但是不会锁住其他function
        mu.lock, mu.unlock 不保险，一旦中间报错，就永远锁住
        解决方法：lock_guard<mutex>guard(mu);
 
    lesson 4:
        std:lock(mu,mu1); 可以lock 多个mutex at the same time
        lock_guard<mutex>lock(mu, std::adopt_lock)// adopt_lock 意思是告诉mutex, 这个mutex mu已经lock了,然后由lock_guard<mutex>lock(mu,std::adopt_lock) 接手这个lock的mutex
 
 
    lesson 5:
        unique_lock<mutex>locker(m_mutex,std::defer_lock); // defer_lock是此刻不lock
        unique_lock可以无限次lock,unlock code
        lock guard, 和 unqiue lock 不能复制，但是unique lock 可以move, transfer ownership
        但是lock guard不能move，但是lock_guard 运行效率最快，unique lock 功能多，要付出代价
 
 
        funciton 只会run 一遍call lambda function, call过一遍，就不会再call 了
        once_flag _flag;
        call_once(_flag,[&](){f.open("log.txt");}); // file will be opened only once by one
 
    lesson 6:
        让thread sleep：this_thread::sleep_for(chrono::seconds(1));
 
        condition_variable cond
        cond.notify_one();
 
        std::unique_lock<mutex>locker(mu);
        cond.wait(locker); //用unique_lock 做为参数的原因是：在sleep前，会unlock,然后再go to sleep
        一旦有condition variable 唤醒它，会继续lock locker，继续剩下的任务
 
        condition_variable 也可以用lambda function来决定是继续还是睡眠，要是符合lambda function就继续，不符合就进入睡眠
        cond.wait([locker,[](){return !q.empty();});
 
    lesson 7:
        注意future or promise是不能copy的，所以pass 到function的parameter 必须要reference
        future 是pass value from child thread to parent thread
        promise 是pass value from parent thread to child thread
 
        想要thread return value
        future<int> fu = async(factorial, 4);
        x = fu.get()  get() will wait until async function finished, 并且只能call Get（）一次
        async 也许创建另一个thread
 
        future<int> fu = async(factorial,4);
        future<int> fu2 = async(std::launch::deferred, factorial,4); not to create a thread 知道有Get（）function call，才产生thread
        future<int> fu2 = async(std::launch::async, factorial,4); 直接产生thread
        future<int> fu2 = async(std::launch::async|std::launch::deferred, factorial,4); 产生thread与否又implementaition 决定
        default value for async
 
 
        promise<int> p;
        std::future<int> f2 = p.get_future();
 
        future<int>fu3 = async(std::launch::async, factorial2, ref(f2)); // 注意需要future的reference，因为future或者promise不能被copy
        this_thread::sleep_for(chrono::milliseconds(20));
 
        p.set_value(4);//如果忘记set_value 会fu3.get() get error, break promise
        p.set_value 必须在future 。get之前，否则会报错
        x = fu3.get(); // tell child thread that we will send him a value but
 
        p.set_exception(std::make_exception_ptr(runtime_error("TO err is human")));//如果知道不会设置，设置exception
 
 
        假如一个promise 用到了很多的function，但是普通的future只能call 一次get
        就可以用shared_future
        promise<int> p;
        std::future<int> f = p.get_future();
        shared_future<int> sf = f.share()
 
        shared_future 是可以复制的，可以call function 用shared future value 而不是reference
    
    
    lesson 8:
        run thread 方法：
            1. thread t1(a, 6);
            2. async(std:launch::async,a,6);
            3. bind(a,6);
            4. call_once(flag,a,6);
        
        thread run一个class的member function
            thread t6(&A::f,a,8,'w'); // make a copy of a and evoke a.f function: copy_of_a.f(8,'w'); in a different thread
            thread t7(&A::f,&a,8,'w'); // pass a's address, a.f(8,'w') in a different thread
 
            thread t8(std::move(a),8); //在move之后，a不在vaild
 
            thread run一个lambda function
            thread t4([](int x){return x*x; }, 6);
 
    lesson 9:
 
        it is a package of task that can be transported to different places and being executed at there
        packaged_task<int(int)>  take integer and return integer
 
        packaged_task<int(int)> t(factorial9);
        运行package_task
        t(6);
        int x = t.get_future().get();得到package_task return值
 
        但是package_task 好处是link callable object to the future that it is very important for threading environment
 
        另一种package_task 初始化的方法：
        packaged_task<int()> t2(bind(factorial9,6)); 把function和参数结合，之后就不能调整参数
        t() 运行function
        future<int>fu = t2.get_future(); 把package_task的return 结果与future 相结合，之后call fu.get() 可以获取值t()
 
    lesson 10:
        chrono::steay_clock::time_point tp = chrono::steady_clock::now() + chono::microseconds(4);
        this_thread::sleep_until(tp);
 
        unique_lock:
            unique_lock<mutex> ulocker(mu)
            ulocker.try_lock();
            ulocker.try_lock_for(chrono::microseconds(4)) 如果4microsec 还没有lock住，就会return
            ulocker.try_lock_until(tp);
 
        condition_variable:
            condition_variable cond
            cond.wait_for(locker, chrono::microseconds(2));
            cond.wait_until(locker, tp);
 
        future:
            promise<int>p;
            future<int> fu = p.get_future();
            除了get function 还有wait function，wait data will be available
            f.get(); // 实际上get internally call wait function
            f.wait();
            f.wait_for( chrono::microseconds(2));
            f.wait_until(locker, tp);
 
 
    3 different way to get future():
        - promise:: get_future()
        - package_task:: get_future()
        - async() returns a future
 
 */


int main(int argc, const char * argv[]) {
    cout<< thread::hardware_concurrency()<<endl;
    
    
    cout << "--------------------------lesson 2 thread management--------------"<<endl;
    lesson_2();
    
    
    cout << "--------------------------lesson 3 Data Race And Mutex--------------"<<endl;
    lesson_3();
    
    cout << "--------------------------lesson 5 Unique Lock and Lazy Initialization--------------"<<endl;
    lesson_5();
    
    
    cout << "--------------------------lesson 6 Condition Variable--------------"<<endl;
    lesson_6();
    
    cout << "--------------------------lesson 7 Future Promise And Async-------------"<<endl;
    lesson_7();
    
    cout << "--------------------------lesson 8 Using Callable Objects-------------"<<endl;
    lesson_8();
    
    cout << "--------------------------lesson 9 Package_task-------------"<<endl;
    lesson_9();
    
    
}

