//
//  lesson6_Condition_Variable.h
//  concurrent programming
//
//  Created by beckswu on 7/9/17.
//  Copyright © 2017 beckswu. All rights reserved.
//

#ifndef lesson6_Condition_Variable_h
#define lesson6_Condition_Variable_h

/*
    让thread sleep：
        this_thread::sleep_for(chrono::seconds(1));
    
    让certain thread execute certain hour
    condition_variable cond
    cond.notify_one();
 
    std::unique_lock<mutex>locker(mu);
    cond.wait(locker); //用unique_lock 做为参数的原因是：在sleep前，会unlock,然后再go to sleep
    一旦有condition variable 唤醒它，会继续lock locker，继续剩下的任务
 
    condition_variable 也可以用lambda function来决定是继续还是睡眠，要是符合lambda function就继续，不符合就进入睡眠
    cond.wait([locker,[](){return !q.empty();});

 */


#include <deque>
#include <mutex>
#include <chrono>
#include <condition_variable>
using namespace std;



deque<int>q;
mutex muu;
condition_variable cond;

void function_61(){
    int count = 10;
    while (count > 10){ // 往queue put variable
        std::unique_lock<mutex>lock(muu);
        q.push_front(count);
        lock.unlock();
        cond.notify_one();
        std::this_thread::sleep_for(chrono::seconds(1));
        count -- ;
    }
}

void function_62(){
    int data = 0;
    while (data!=1){
        std::unique_lock<mutex>locker(muu);
        cond.wait(locker,[](){return !q.empty();}); //trhead 2 go to sleep  wait until call by notify_one()
        // 除了被notify_one 唤醒，也可以自己唤醒自己，叫spurious wake, 用lambda function 如果发现符合lambda function的（如果q不是空，就继续，如果q是空，就进入睡眠）
        if (!q.empty()){
            data = q.back();
            q.pop_back();
            locker.unlock();
            cout << "t2 got a value from t1" << data <<endl;
        } else {
            locker.unlock();
        }
    
    }
}




void lesson_6(){


}




#endif /* lesson6_Condition_Variable_h */
