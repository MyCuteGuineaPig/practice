//
//  lesson8Shared_PointerII.h
//  Modern C++
//
//  Created by beckswu on 7/8/17.
//  Copyright © 2017 beckswu. All rights reserved.
//

#ifndef lesson8Shared_PointerII_h
#define lesson8Shared_PointerII_h

/*
    shared_ptr<Dog7> p = make_shared<Dog7>("Gunner"); 这是preferred way
    
    但是有时候用 custome deleter
    shared_ptr<Dog7>p2 = shared_ptr<Dog7>(new Dog7("Tankk2"), // 建一个deleter function
                        [](Dog7 *p){cout<<"Customer deleteing "; delete p;} );
 
    比如建一个shared pointer 从一个array 里建立shared_ptr 实际上shared_ptr只连接了pointer array中的第一个，
    要是不做处理删除，剩下的array会memory leak，所以要件deleter
    shared_ptr<Dog7> p3(new Dog7[3],[](Dog* p){delete []p;});
 
    p1.get() 是获取原来的pointer，但是避免使用

 */


#include <iostream>
#include <string>
#include <memory>
using namespace std;

void foo8(){
    shared_ptr<Dog7> p1 = make_shared<Dog7>("Gunner2");
    // when out of scope call some delete function to delete gunner
    // delete function 叫做deleter using default deleter: operatr delete
    shared_ptr<Dog7>p2 = shared_ptr<Dog7>(new Dog7("Tankk2"), // 建一个deleter function
                                          [](Dog7 *p){cout<<"Customer deleteing "; delete p;}
                                          );
    
    cout << "let us see"<<endl;
    // 需要customer deleter时候
    //shared_ptr<Dog7> p3(new Dog7[3]); // will create a array of dog 但是p3 仅仅指向第一个dog
    // 所以当out of  scope 时候只有first dog deleted, other two dogs are memory leak（dog[1],dog[2]）
    
    //shared_ptr<Dog7> p3(new Dog7[3],[](Dog* p){delete []p;});
    
    //Dog * dd = p1.get(): // returns the raw pointer, avoid raw pointer
    // 如果delete dd, dog Gunner 将会被deleted 但是当p1 out of scope, Gunner将会再次被删除
    
}

void lesson_8(){
    shared_ptr<Dog7>p1 = make_shared<Dog7>("Gunner1");
    shared_ptr<Dog7>p2 = make_shared<Dog7>("Tank1");
    // 因为share_ptr 存在Stack， LIFO, 所以p2 Tank 会先被delete
    p2 = p1; // p2, p1 both to Tank, GUnner 此刻被删除
    p1 = nullptr; // GUnner 先会被删除
    p1.reset(); // GUnner 被删除
    foo8();
    // 虽然make_shared是最prefered 建立pointer 的方法 是custom deleter

}


#endif /* lesson8Shared_PointerII_h */
