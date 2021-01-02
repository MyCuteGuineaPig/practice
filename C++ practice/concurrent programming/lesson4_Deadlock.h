//
//  lesson4_Deadlock.h
//  concurrent programming
//
//  Created by beckswu on 7/9/17.
//  Copyright © 2017 beckswu. All rights reserved.
//

#ifndef lesson4_Deadlock_h
#define lesson4_Deadlock_h


/*
    std:lock(mu,mu1); 可以lock 多个mutex at the same time 
    lock_guard<mutex>lock(mu, std::adopt_lock)// adopt_lock 意思是告诉mutex, 这个mutex mu已经lock了,然后由lock_guard<mutex>lock(mu,std::adopt_lock) 接手这个lock的mutex
 
 

    try to lock a single mutex at a time
    比如
    {
        std;:lock_guard<mutex>lock1(mu);
 
    }
    {
        std::lock_guard<mutex>lock2(mu2);
 
    }
    
    lock 较小范围（适中）的data 越好
    Fine-grainedLock: protects small amount of data 
    Coarse-grained_lock: protects big amount of data
 
 */


#endif /* lesson4_Deadlock_h */
