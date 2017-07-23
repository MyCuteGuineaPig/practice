#ifndef lesson_25Namespace_and_Keyword_using_h
#define lesson_25Namespace_and_Keyword_using_h

#include <iostream>
using namespace std;

/*
 
 C++ keyword: using 
1. using directive: to bring all namespace members into current scope
    Example
    using namespace std;    //bring every name std under current scope
 
 2. using declaration 可以work for namespace 和class
    a. Bring one specific namespace member to current scope.
    b. Bring a member from base class to current class's scope;
 
 比如using std::cout 
 cout << "hello";
 
 
 using namespace std; // case 1. global scope
 using std::cout;  // case 2.a. global scope
 
 
 class B{
    public:
        void f(int a);
 
 };
 
 class D: private B{ // become private
    public:
        void g(){
            using namespace std; // case 1 local scope
            cout <<"From D";
        }
        using B::f; // case 2.b, class scope
        using std::cout; // illegal
        using namspace std; // illegal
 
 }
 
 假如我们把declaration of class in global scope, illegal
 using B::f // illegal
  假如我们把declaration of namespace in class scope, illegal
 
 
 Anonymous Namespace 
 
 namespace { // can be only called in the same file not from another file
    void h() {std::cout<<"h()\n";} // similar to global static function
 }
 
 static void h() {std::cout<<"h()\n";}
 
 
 int main() {
    h();
 
 }
 
 
 */



void lesson_25() {


}


#endif 
#pragma once
