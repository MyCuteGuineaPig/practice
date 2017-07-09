//
//  lesson_17Random_Number_Engine.h
//  Modern C++
//
//  Created by beckswu on 7/8/17.
//  Copyright © 2017 beckswu. All rights reserved.
//

#ifndef lesson_17Random_Number_Engine_h
#define lesson_17Random_Number_Engine_h

#include <sstream>
#include <random>
#include <chrono>
#include <vector>
#include <algorithm>
using namespace std;

/*
    Random Engine
    stateful generator that generateds random values within predefined min and max
    不能改变generated 的值得最大最小值
    Not truely random -- pseudorandom
 
    初始化random engine 
    std::default_random_engine eng;
    eng.min() 可以显示 random engine 显示出的最小值
    eng,max() 可以显示 random engine 的最大值
 
    初始化random engine with seed
    unsigned seed = chrono::steady_clock::now().time_since_epoch().count(); // every time get different seed
    std::default_random_engine e3(seed);
 
    std::stringstream state; 存储现在状态的engine
    state << eng; // Save the current state
    state >> eng; // 恢复之前存储的engine

    如果random engine 有一样的seed，将打印一样的value
    shuffle(d.begin(),d.end(),std::default_random_engine()); random engine 用于shuffle vector
 */

void printrandom(std::default_random_engine e){
    for(int i=0; i<10; i++)
        cout << e() << " ";
    cout << endl;
}

void lesson_17(){
    std::default_random_engine eng;
    cout << "Min : "<<eng.min() <<endl;
    cout << "Max : "<<eng.max()<<endl;
    //cout << "Random value : "<<eng() <<endl;
    //cout << "Random value : "<< eng() <<endl;
    
    std::stringstream state;
    state << eng; // Save the current state
    cout << "Random value : "<<eng() <<endl;
    cout << "Random value : "<< eng() <<endl;
    
    state >> eng; // restore the state 就会和刚才产生的value 一样
    cout << "Random value : "<<eng() <<endl;
    cout << "Random value : "<< eng() <<endl;
    
    std::default_random_engine e1;
    std::default_random_engine e2;
    printrandom(e1); // 这两个打印出来的数都是一样的
    printrandom(e2);
    
    unsigned seed = chrono::steady_clock::now().time_since_epoch().count(); // every time get different seed
    std::default_random_engine e3(seed); //
    
    e3.seed(); // reset engine e to initial state
    e3.seed(109); // set engine e to a state according to seed 109
    e2.seed(109);
    if (e3==e2)
        cout << "e3 and e2 have the same state "<<endl;
    
    //seed also can be used for shuffle vector and deque
    vector<int>d = {1,2,3,4,5,6,7,8,9};
    shuffle(d.begin(),d.end(),std::default_random_engine());
    // C++ has 16 random engine to use, default random engine with reasonable good quality, performance and size for casual usuage
}



#endif /* lesson_17Random_Number_Engine_h */
