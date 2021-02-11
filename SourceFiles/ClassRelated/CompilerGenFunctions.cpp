#include "CompilerGenFunctions.h"
#include<iostream>

using namespace std;

CompilerGenFunctions::CompilerGenFunctions() {
  //  cout << "constructor"<<endl;
}


CompilerGenFunctions::~CompilerGenFunctions() {
 //   cout << "Destructor"<<endl;
}

CompilerGenFunctions::CompilerGenFunctions(const CompilerGenFunctions& obj) {
    cout << "copy constructor"<<endl;
}

CompilerGenFunctions& CompilerGenFunctions::operator=(const CompilerGenFunctions& obj) {
    cout << "copy assignment operator"<<endl;
    // TODO: insert return statement here
    const CompilerGenFunctions refObj = obj;
   // CompilerGenFunctions& refObj2 = refObj;
    return *this;
}
