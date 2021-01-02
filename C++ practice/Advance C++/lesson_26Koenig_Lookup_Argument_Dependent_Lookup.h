#ifndef lesson_26Koenig_Lookup_Argument_Dependent_Lookup_h
#define lesson_26Koenig_Lookup_Argument_Dependent_Lookup_h

#include <iostream>
using namespace std;



/*
    koening Lookup

    example 
    
    namespace A{
        struct X{};
        void g(x) {cout <<"caling A::g()";}
    }
 
 
    int main(){
        A::X x1;
        g(x1); // will work
        //koeing Lookup or agrument dependent lookup(ADL)
    }
 
    it turns out when compiler come to that function, it not only search in current scope and global scope
    C++ 也搜索scope where parameter is defined,g(x1); x1 is defined in namespace A();
    但是假如有两个function，有一样的parameter，不会compile
 
    koeing Lookup 只会work for namespace not for class
 
 
    
 
 
 
 
 */




void lesson_26() {


}


#endif 
#pragma once
