//
//  lesson8_Using_Callable_Object.h
//  concurrent programming
//
//  Created by beckswu on 7/9/17.
//  Copyright © 2017 beckswu. All rights reserved.
//

#ifndef lesson8_Using_Callable_Object_h
#define lesson8_Using_Callable_Object_h

/*
    thread run一个class的member function
        thread t6(&A::f,a,8,'w'); // make a copy of a and evoke a.f function: copy_of_a.f(8,'w'); in a different thread
        thread t7(&A::f,&a,8,'w'); // pass a's address, a.f(8,'w') in a different thread
 
        thread t8(std::move(a),8); //在move之后，a不在vaild
    
    thread run一个lambda function
        thread t4([](int x){return x*x; }, 6);
 */


class A{
    public:
        void f(int x, char c){}
        long g(double x) {return 0;}
        int operator()(int N) {return 0;}
};


void lesson_8(){
    A a;
    // method 1
    //thread t1(a,6); // copy_of_a() in a different thread
    //thread t2(ref(a),6); // raise a as a functor in a different thread
    //thread t3((A()),6); // temporary A;
    //thread t4([](int x){return x*x; }, 6);
    
    //create a member function
    //thread t6(&A::f,a,8,'w'); // make a copy of a and evoke a.f function: copy_of_a.f(8,'w'); in a different thread
    //thread t7(&A::f,&a,8,'w'); // pass a's address, a.f(8,'w') in a different thread

    //thread t8(std::move(a),8); //在move之后，a不在vaild
}



#endif /* lesson8_Using_Callable_Object_h */
