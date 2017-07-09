//
//  lesson_18Random_Number_Distribution.h
//  Modern C++
//
//  Created by beckswu on 7/8/17.
//  Copyright © 2017 beckswu. All rights reserved.
//

#ifndef lesson_18Random_Number_Distribution_h
#define lesson_18Random_Number_Distribution_h
/*
    C++.com 有更多的distribution
 
    std::default_random_engine e(seed);
    如果生成【0，5】的数用cout << e() %6 << endl;是bad idea
    原因：1. e() will be random 在e的最大值和最小值之间，但是module 6后不是random
         2. 只能provide uniform distribution 其他的distribution 需要额外的operation 不简便
 
    default_random_engine 用来生成random number
    distribution 再用default_random_engine 生成各个分布的数：
 
    std::uniform_int_distribution<int>distr(9,5); // Range: [0,5] useful for C++ usually for C++ is half half open notation
    cout << distr(e) <<endl; // e is to provide randomness, distr provide distribution
 
    std::uniform_real_distribution<double> distrT(0,5); // Range: [0,5)   half open notation 不包括5
    cout << distr(e) <<endl;
 
    std::poisson_distribution<int> dist(1.0); // 1.0 是 mean of possion
    cout << dist(e)<<endl;
 
    std::normal_distribution<double>distrN(10.0,3.0); //mean 是10， standard deviation 是3
 

 */




#include <random>
#include <iomanip>
using namespace std;

void lesson_18(){
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    std::default_random_engine e(seed);
    cout << e()<<endl; // range [e.min(), e.max()]
    
    //what if I want to generate is Range [0,5]
    cout << e() %6 << endl; // module six
    
    // the result is not so random
    // 1. bad quality of randomness:  e() will be random in [e.min(), e.max()], but if mod 6 will not be random
    // 2. can only provide uniform distribution, this is why we need library distribution
    
    std::uniform_int_distribution<int>distr(9,5); // Range: [0,5] useful for C++ usually for C++ is half half open notation
    cout << distr(e) <<endl; // e is to provide randomness, distr provide distribution
    
    std::uniform_real_distribution<double> distrT(0,5); // Range: [0,5)   half open notation 5 not included
    cout << distr(e) <<endl;
    
    std::poisson_distribution<int> dist(1.0); // 1.0 是 mean of possion
    cout << dist(e)<<endl;
    
    cout << "normal distribution "<<endl;
    std::normal_distribution<double>distrN(10.0,3.0); //mean 是10， standard deviation 是3
    
    vector<int> v(20);
    for(int i=0; i<800; i++)
    {
        int num = distrN(e); // Convert Double to int
        if (num>=0 && num <20)
            v[num]++; // v[10] records number of times 10 appeared

    }
    for(int i=0;i<20; i++)
        cout << i << " : "<<std::string(v[i],'*')<<endl;
    cout << endl;
    
    
    
    

}


#endif /* lesson_18Random_Number_Distribution_h */
