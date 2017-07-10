//
//  lesson2_Thread_Management.h
//  concurrent programming
//
//  Created by beckswu on 7/9/17.
//  Copyright © 2017 beckswu. All rights reserved.
//


/*
    如果把一个functor 加入thread,必须加上（），（）是function decoration，否则C++不知道它是functor
    
    如果想pass reference to thread function
 
    string s ="where is no trust";
    std::thread t1((Fctor()),std::ref(s));  pass value in the function by reference
    或者：
    std::thread t1((Fctor()),std::move(s)); 把variable s 移动到fctor 里面
 
    如果想copy thread，必须用move
    thread t2 = move(t1);
 
    得到parent thread id
    this_thread::get_id();
 
    得到child thread id
    t1.get_id(); 
 
 */


#ifndef lesson2_Thread_Management_h
#define lesson2_Thread_Management_h

using namespace std;

void function_1(){
    std::cout << "Beauty is only skin-deep "<<endl;
}

class Fctor{
    public:
    void operator()() {
        for(int i=0; i>-30; i--)
            cout << "from t1 "<< i <<endl;
    }
    void operator()(string  & msg) {
        for(int i=0; i>-30; i--)
            cout << "from t1 "<< i <<endl;
        msg = "Trust is the mother of deceit";
    }

};

void lesson_2(){
    
    Fctor fct;
    
    //thread t1(function_1);
    
    //thread t1(fct); // t1 是declare function with name t1 and point to another function
    thread t1((Fctor())); // 必须加Functor 外面加上（），因为t1 point to anthor function but it is functor
    // 如果没有括号，C++就不把它做为function decoration, 但实际上它是functor 不是function，所以必须加括号
    // using RAII
    //Wrapper w(t1)
    
    string s = "where is no truct";
    
    
    try{
        //for(int i=0; i<30; i++)  // 如果这有错，t1就不会join， 用try catch
        //    cout << "from main "<<i<<endl;
        
        cout << "from main:  "<<s<<endl;
    } catch(...){
        t1.join();
        throw;
    }
    
    t1.join();
}




#endif /* lesson2_Thread_Management_h */
