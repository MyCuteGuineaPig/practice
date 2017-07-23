#ifndef lesson_21Static_Polymorphism_h
#define lesson_21Static_Polymorphism_h

#include <iostream>
using namespace std;

//Dynamic polymorphism

/*
 
 
 struct TreeNode {TreeNode *left, TreeNode *right};
 
 class Generic_parser{
    public:
        void parse_preorder(TreeNode *node)
        {
            if(node){
                process_node(node);
                parse_preorder(node->left);
                parse_preorder(node->right);
            }
 
        }
    private:
        virtual void process_node(TreeNode * node)
 
 }
 
 class EmployeeChar_Parser: public Generic_parser{
    private:
        void process_node(TreeNode *node){
            cout << "Customized process_node () for EmploymeeChart "<<endl;
        }
 
 }
 
 EmployeeChar_Parser ep;
 ep.parse_preorder(root);
 
        
        polymorphism is not for free. come to price to pay
        1. memory cost to virtual table   // 需要memory cost给virtual table
        2. runtime cost to dynamic binding  要runtime结合到function
        the cost is small
 
    要inheritance 需要考虑的信息
    1. is-a relationship between base class and derived class
    2. Base class defines a "Generic" algorithm that's used by derived class
    3. The generic algorithm is customized by the drived class
 
 
    不想用runtime 结合
    
    solution:
    TMP: template Metaprogramming: do the function from runtime to compile time, 把computation 到compile time
    改进program的efficiency，improve
 
    template<typename T> class Generic_Parser { // become a template
        public:
            void parse_preorder(TreeNode * node){
                if(b){
                    process_node(node);
                    parse_preorder(node->left);
                    parse_preorder(node->right);
                }
            void process_node(TreeNode * node){
                static_cast<T*> (this)->process_node(node); // cast object into T
                会把this cast to T‘s object
                当被叫的时候会把T的process_node call
            }
    }
 
    class EmployeeChar_Parser: public Generic_parser<EmployeeChart_Parser>{
            private:
                void process_node(TreeNode *node){
                cout << "Customized process_node () for EmploymeeChart "<<endl;
                }
 
            }
 
    也可以叫
    EmployeeChar_Parser ep;
    ep.parse_preorder(root);
 
    这种pattern叫做：Curiously recurring template pattern(static polymorphism, simulated polymorphism)
    通常被用在library code
    
    Generic_Parser<EmployeeChart_Parser>, 和Generic_Parser<MilitaryChart_Parser>, 是totally different type pattern,
    take different memory
 
    tradeoff is between memory and execution time
 
    当people talk about static polymorphism, they talk about template itselft compile time
    template<typename T>
    T max(vector<T> v){
        T max = v[0];
        for (typename std::vector<T?::iterator it = v.begin(); it!=v.end();++it){
            if(*it > max){
                max = *it;
            }
        }
        return max;
 
    }
 
 */












void lesson_21() {


}


#endif
#pragma once
