//
//  lesson_11Resource_Managing_Class.h
//  Modern C++
//
//  Created by beckswu on 7/8/17.
//  Copyright © 2017 beckswu. All rights reserved.
//

#ifndef lesson_11Resource_Managing_Class_h
#define lesson_11Resource_Managing_Class_h


// 不能定义destructor，因为destructor 不能有move constructor
class Person{
    private:
        //string* pName_;
        unique_ptr<string>pName_;
    public:
        Person(string name): pName_(new string(name)) {}
        //~Person() {delete pName_;}
        //Person(const Person &) = delete; // the copy constructor is deleted
        Person(Person &&) = default;
        ~Person(){}
        void printName(){cout<<*pName_<<endl;}
    
};


void lesson_11(){
    vector<Person> persons;
    //persons.push_back(Person("George")); // construct the object in place ( int he space allocated to the vector)
    //emplace_back这是在那个位置生成，不会有copy
    //persons.emplace_back("George");
    
    Person p("George");
    persons.push_back(move(p)); // 不能用copy，因为用的是unique_ptr
    persons.front().printName();
    
    
    cout<<"Goodbye "<<endl;
    
    /*   C++03 solution 
        1. define copy constructor and copy assignment operator
        2. define copy constructor and copy assignment operator
     
     
     */
}





#endif /* lesson_11Resource_Managing_Class_h */
