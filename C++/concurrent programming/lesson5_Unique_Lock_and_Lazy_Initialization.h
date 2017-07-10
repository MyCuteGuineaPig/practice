//
//  lesson5_Unique_Lock_and_Lazy_Initialization.h
//  concurrent programming
//
//  Created by beckswu on 7/9/17.
//  Copyright © 2017 beckswu. All rights reserved.
//

#ifndef lesson5_Unique_Lock_and_Lazy_Initialization_h
#define lesson5_Unique_Lock_and_Lazy_Initialization_h

/*
    unique lock 提供了更多lock的选择
 
    unique_lock<mutex>locker(m_mutex,std::defer_lock); // defer_lock是此刻不lock
 
    unique_lock可以无限次lock,unlock code
    lock guard, 和 unqiue lock 不能复制，但是unique lock 可以move, transfer ownership
    但是unique_lock不能move
 
    once_flag _flag;
    funciton 只会run 一遍call lambda function, call过一遍，就不会再call 了
    call_once(_flag,[&](){f.open("log.txt");}); // file will be opened only once by one
 */




class LogFile5{
    mutex m_mutex;
    ofstream f;
    once_flag _flag;
public:
    LogFile5() {f.open("log.txt");}
    void shared_print(string id, int value){
        unique_lock<mutex>locker(m_mutex,std::defer_lock);
        locker.lock();
        f << "From "<<id << " : "<<value << endl;
        locker.unlock();
        // then do something else
        
        locker.lock();//
        
        unique_lock<mutex> locker2 = move(locker);
    }
    
    void shared_print2(string id, int value){
        call_once(_flag,[&](){f.open("log.txt");}); // file will be opened only once by one
        unique_lock<mutex>locker(m_mutex);
        locker.lock();
        f << "From "<<id << " : "<<value << endl;
    }

};


void lesson_5(){

}



#endif /* lesson5_Unique_Lock_and_Lazy_Initialization_h */
