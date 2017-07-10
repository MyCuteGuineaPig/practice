//
//  lesson3_Data_Race_And_Mutex.h
//  concurrent programming
//
//  Created by beckswu on 7/9/17.
//  Copyright © 2017 beckswu. All rights reserved.
//

#ifndef lesson3_Data_Race_And_Mutex_h
#define lesson3_Data_Race_And_Mutex_h


/*
    Race Condition: outcome of program depends for the relative order of execution of one or more thread
    Race Condition not good, need to avoid 
 
    一个mutex，只能lock本地一个方程的内部的，让别的位置不call 这个function，但是不会锁住其他function
 
    mu.lock, mu.unlock 不保险，一旦中间报错，就永远锁住
    
    解决方法：lock_guard<mutex>guard(mu);
 
 */
#include <mutex>
#include <string>
#include <fstream>
using namespace std;


mutex mu;
void shared_print(string msg, int id){ // 只要call shared_print 就不会同时call shared_print() at the same time
    //mu.lock();
    lock_guard<mutex>guard(mu); // 还有个问题，因为cout是global variable,假如其他位置有cout，还会有同时打印
    cout << msg << id <<endl;
    //mu.unlock();
}

//Solution to solve 避免 cout at the same time
class LogFile {
    mutex m_mutex;
    ofstream f;
    public:
        LogFile() {f.open("log.txt");}
        void shared_print(string id, int value){
            lock_guard<mutex>locker(m_mutex);
            f << "From "<<id << " : "<<value << endl;
            // 没有人可以get access to f without get into logfile
            }
        //Never return f to the ourside word, 不能以ofstream & getStream() {return f;} bad idea
        // 因为user get access to f without using mutex
        //也不要把pass f as an argument to user provided function
};



mutex mu1;
void shared_print2(string msg, int id){
    mu1.lock();
    cout << msg << id <<endl;
    mu1.unlock();
}

void function_3(){
    for(int i=0; i>-50; i--) // this thread and lesson 3 compete each other for cout
        //cout << "From function t3 "<<i <<endl;
        shared_print(string("From function t "), i);
}

void lesson_3(){
    std::thread t1(function_3);
    for(int i = 0; i<=50; i++)
        //cout <<"from lesson 3 main "<<i<<endl;
        shared_print(string("from lesson 3 main "), i);
        
    t1.join();

}



#endif /* lesson3_Data_Race_And_Mutex_h */
