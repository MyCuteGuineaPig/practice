//
//  lesson7_Future_Promise_Async.h
//  concurrent programming
//
//  Created by beckswu on 7/9/17.
//  Copyright © 2017 beckswu. All rights reserved.
//

#ifndef lesson7_Future_Promise_Async_h
#define lesson7_Future_Promise_Async_h

/*
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
    x = fu3.get(); // tell child thread that we will send him a value but
    
    p.set_exception(std::make_exception_ptr(runtime_error("TO err is human")));//如果知道不会设置，设置exception
 
 
    假如一个promise 用到了很多的function，但是普通的future只能call 一次get
    就可以用shared_future
    promise<int> p;
    std::future<int> f = p.get_future();
    shared_future<int> sf = f.share()

    hared_future 是可以复制的，可以call function 用shared future value 而不是reference
 */



#include <future>
using namespace std;



int factorial(int N){
    int res = 1;
    for(int i = N;i>1; i--)
        res *=i;
    cout <<"Result is "<<res<<endl;
    return res;

}


int factorial2(future<int>& fu){
    int res = 1;
    int N = fu.get();
    for(int i = N;i>1; i--)
        res *=i;
    cout <<"Result is "<<res<<endl;
    return res;
    
}

void lesson_7(){
    int x; // 我们想要thread function return 结果
    
    
    //thread t7(factorial,4);
    
    future<int> fu = async(factorial,4);
    future<int> fu2 = async(std::launch::deferred, factorial,4);
    // not to create a thread 知道有Get（）function call，才产生thread
    //future<int> fu2 = async(std::launch::async, factorial,4); 产生thread
    //future<int> fu2 = async(std::launch::async|std::launch::deferred, factorial,4); 产生thread与否又implementaition 决定
    //default value

    x = fu.get();
    //t7.join();
    
    promise<int> p;
    //promise <int> p2 = move(p);
    std::future<int> f2 = p.get_future();
    
    future<int>fu3 = async(std::launch::async, factorial2, ref(f2)); // 注意需要future的reference，因为future或者promise不能被copy
    this_thread::sleep_for(chrono::milliseconds(20));

    p.set_value(4);//如果忘记set_value 会fu3.get() get error, break promise
    
    //p.set_exception(std::make_exception_ptr(runtime_error("TO err is human")));//如果知道不会设置，设置exception
    x = fu3.get(); // tell child thread that we will send him a value but
    
    
    cout << "Get child value "<< x << endl;
    
    
    /*
        suppose do the function many time
     
        promise<int> p;
        std::future<int> f2 = p.get_future();
     
        future<int>fu = async(std::launch::async, factorial2, ref(f2));
        future<int>fu2 = async(std::launch::async, factorial2, ref(f2));
        future<int>fu3 = async(std::launch::async, factorial2, ref(f2));
        future<int>fu4 = async(std::launch::async, factorial2, ref(f2));
        因为每个future 只能call 一次get，
        
        所以我只能call 10次get 如果有10个async
     
        解决方法 shared_future<int> sf = f.share();
        shared_future 是可以复制的，可以call function 用shared future value 而不是reference
        当set value,所有的function内的 get() 都可以get 到
     
        promise<int> p;
        std::future<int> f = p.get_future();
        shared_future<int> sf = f.share()
     
        future<int>fu = async(std::launch::async, factorial2, f2);
        future<int>fu2 = async(std::launch::async, factorial2, f2);
        future<int>fu3 = async(std::launch::async, factorial2, f2);
        future<int>fu4 = async(std::launch::async, factorial2, f2);
     */
    
}





#endif /* lesson7_Future_Promise_Async_h */
