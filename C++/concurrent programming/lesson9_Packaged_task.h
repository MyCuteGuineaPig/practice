//
//  lesson9_Packaged_task.h
//  concurrent programming
//
//  Created by beckswu on 7/10/17.
//  Copyright © 2017 beckswu. All rights reserved.
//

#ifndef lesson9_Packaged_task_h
#define lesson9_Packaged_task_h


/*
    it is a package of task that can be transported to different places and being executed at there
    packaged_task<int(int)>  take integer and return integer
    
    packaged_task<int(int)> t(factorial9); 
    运行package_task
    t()6;
 
    得到package_task return值
    int x = t.get_future().get();
 
     但是package_task 好处是link callable object to the future that it is very important for threading environment
 
    另一种package_task 初始化的方法：
        packaged_task<int()> t2(bind(factorial9,6)); 把function和参数结合，之后就不能调整参数
        t() 运行function
        future<int>fu = t2.get_future(); 把package_task的return 结果与future 相结合，之后call fu.get() 可以获取值t()
 
 
 */
#include <deque>
#include <functional>
using namespace std;

int factorial9(int N){
    int res=1;
    for(int i = N; i>1; i--)
        res *= i;
    cout << "Result is:  "<<res<<endl;
    return res;
}

deque<packaged_task<int()>> task_q;
mutex mu9; // 因为要share task_q 在不同的thread，所以要lock
condition_variable cond9;

void thread_1(){
    std::packaged_task<int()>t;
    {
        unique_lock<mutex>locker(mu9);
        cond.wait(locker,[](){return !task_q.empty();});
        t = move(task_q.front());
        task_q.pop_front();
    
    }
        t(); // when t() generate return value
}

void lesson_9(){
    thread t1(thread_1);
    
    
    //packaged_task<int(int)> t(factorial9); // t is a task being packaged up
    // package can be pass to different places, different function object, thread,
    
    // it is a package of task that can be transported to different places and being executed at there
    //packaged_task<int(int)>  take integer and return integer
    
    // 在特殊的时间，task is executed in a different context
    //t(6); // In a different context
    
    //不能用 int x = t(6); 因为t的return是void
    //int x = t.get_future().get();
    
    
    packaged_task<int()> t2(bind(factorial9,6));// 用bind create function object with function and parameter

    /*
        Do we need package_task
        auto t = std::bind(factorial9, 6);
        it seems like we don't need it
        但是package_task 好处是link callable object to the future that it is very important for threading environment
     
     */
    future<int>fu = t2.get_future();
    // 因为有bind，这个package_task不能再有parameter了，所以就remove int parameter,
    
    {
        lock_guard<mutex>locker(mu9);
        
        task_q.push_back(move(t2));// main thread create a task and push to task_q
        // t2 no longer used in main thread 所以可以加上move
        
    }
    cond.notify_one();

    
    cout<<" the value of packaged task: " << fu.get();
    t1.join();
}


#endif /* lesson9_Packaged_task_h */
