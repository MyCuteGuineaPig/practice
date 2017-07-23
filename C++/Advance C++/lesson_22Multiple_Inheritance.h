#ifndef lesson_11Static_Initialization_Fiacso_h
#define lesson_11Static_Initialization_Fiacso_h

#include <iostream>
using namespace std;

/*
    Summary:
    1. multiple inheritance is an important technique: e.g, ISP (Interface Segregation Principle)
    2. Derive only from Pure Abstract clas when using multiple inheritance
 
 
    Multiple Inheritance 有时候difficult to use, 
    but why we use it?
    
    Interface Segregation Principle:
        Split large interfaces into smaller and more specific ones so that clients only need to know about the methods
        are interest to them
 
 
 
    clas InputFile{
        public:
            void read();
        private:
            void open();
    };
 
    class OutputFile{
        public:
            void write();
            void open();
    };
 
    class IOFile: public InputFile, public OutputFile {
 
 
    };
 
 
    int main(){
        IOFile f;
        f.open(); // cannot complie 因为IOFIle 有两个instance call open
        f.OutputFile::open();// 会compile
 
    }
 
    C++ 会说before complier see accessiablity of function, it must said which function is the best mathcing function called
    所以在看见private前，会说哪个open最好
 */





/*
               File
            /       \
        InputFile   OutputFile
            \        /
               IOFIle
 
 class File{
    public: 
        string name;
        void open();
 
 };
 
 class InputFile: virtual public File{
    public:
        void read();
    private:
        void open();
 };
 
 class OutputFile: virtual public File{
    public:
        void write();
        void open();
        } ;
 
 class IOFile: public InputFile, public OutputFile {
 
 };

 IOFfile f;
 会有两个string 对于一个IOFile
 f.InputFile::name = "File";
 f.OutputFile::name = "File2"
 
 */





/*      initialization
 /*
              File
            /       \
        InputFile   OutputFile
            \        /
            IOFIle
 all the problem will be gone if we inherit from pure abstract class, no problem with multiple implementation and initialization
 
 
 class File{
        public:
            string name;
            void open();
            File(string fname);
 };
 
 class InputFile: virtual public File{
        public:
            void read();
            InputFile(string fname) : File(fname){};
        private:
            void open();
 };
 
 class OutputFile: virtual public File{
        public:
            void write();
            void open();
            OutputFile(string fname) : File(fname){};
 } ;
 
 class IOFile: public InputFile, public OutputFile {
         IOFile(string fname): OutputFile(fname), InputFile(string fname), File(fname){};
 };
如果OutputFile class 和inputFile 的名字不一样，会有两个file name

C++ rule: the initialization of virtual base class will be respond by the most derived class, IO file 是most derived class
 

 
 why use multiple Inheritance?
 class Engineer {
    public:
        ...; // 40 APIs
 
 
 }
 
 class Son {
 public:
 ...; // 50 APIs
 
 
 }
 
 
 
 class Andy: public Engineer, Son{ // If I am andy co-worker, I only need Engineer API
    public: // complicated person
    ... // 500 APIs
 
 };
 
 if you a class which has many API, it is good to segregrate class
 
 

 
 Abstract: A class has one or more pure virtual functions
 Pure Abstract Classes: 只有virtual functions
    1. no data,
    2. no concrete functions
 
 class OutputFile{
    public:
        void write() = 0;
        void open() = 0;
 
 }
 
 */

void lesson_22() {


}


#endif
#pragma once