#ifndef lesson_18Inheritance_Public_Protected_Private_h
#define lesson_18Inheritance_Public_Protected_Private_h

#include <iostream>
using namespace std;

/*
    class B{};
 
    class D_priv: private B{};
    class D_prot: protected B {};
    class D_pub: public B{};
    
    They specifies different access control from the dervied class to the base class
    Access Control:
    1. None of the derived classes can access anything that is private in B:
    没有任何可能性接触B的private class
    2. D_pub inherits public members of B as public and the protected members of B as protected
    3. D_priv inherits the public and protected memebers of B as private 
    4. D_protected inherits the public and protected members of B as protected 
 
 
    Casting:
    1. Anyone can cast a D_pub* to B*. D_pub is a special kind of B
    2. D_priv's members and freiendes can cast a D_priv* to B*
    3. D_prot's members, friends, and children can cast a D_prot to B*
 
 
 
    例子：
    class B{
        public: 
            void f_pub() {cout<<" f_pub is called "<<endl;}
        public:
            void f_prot() {cout<<" f_pub is called "<<endl;}
        private:
            void f_priv() {cout<<" f_pub is called "<<endl;}
 
    }
 
    
    class D_pub: public B{
        public:
            void f(){
                f_pub();     // OK
                f_prot();   // OK
                void f_priv() // Error
            }
    }
 
 
    class D_pub: protected B{
        public:
        using B::f_pub(); // then 可以call f_pub()， 变成public
            void f(){
                f_pub();     // OK become protected function
                f_prot();   // OK become protected function
                void f_priv() // Error
        }
    }
 
    class D_pub: private B{
        public:
            void f(){
                    f_pub();     // OK become private function
                    f_prot();   // OK become private function
                    void f_priv() // Error
            }
    }
 
 
    int main(){
        D_pub D1;
        D1.f_pub(); // f_pub() is a D_pub's public functionf
        D_prot D2;
        D2.f_pub(); // Error f_pub() is D_prot's protected function
 
 
        D *pB = & D1; // OK
        pB = & D2; // Error
 
    }
 
    public inheritane: is-a relation. eg. D_pub is a kind of a B
    private inheritance: similar to has-a relation (与composition 比较像)
 
 
    class ring{
        public:
            void tinkle() {}
 
    }
 
    class dog{
        ring m_ring;
        public:
            void tinkle() {m_ring.tinkle(); } // call forwarding
 
    }
 
    private Inheritance
    class dog:private ring{
        public:
           using ring::tinkle;
 }
    composition prefer private inheritance
    1. composition is better oo structure, 
    2. composition is more flexible  比如dog有两个ring
 
 
    situation private inheritance is more preferable 比如 base class 有virtual function然后function call that
 
 
    class ring{
        virtual tremble();
 
        public:
            void tinkle() {tremble();}
        }
    class dog:private ring{
        virtual tremble();
        public:
            using ring::tinkle;
        }
 
 
 */


void lesson_18() {
    

}


#endif
#pragma once
