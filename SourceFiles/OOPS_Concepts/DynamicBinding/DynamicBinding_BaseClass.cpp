#include "DynamicBinding_BaseClass.h"
#include<iostream>

using namespace std;
DynamicBinding_BaseClass::DynamicBinding_BaseClass() {
   // cout << "Dynamic Binding Base Class Ctor" << endl;
}

DynamicBinding_BaseClass::~DynamicBinding_BaseClass() {
  //  cout << "Dynamic Binding Base Class Dctor" << endl;
}

int DynamicBinding_BaseClass::foo(int x) {
    cout << "DynamicBinding_BaseClass: foo " << endl;
    if (x % 2 == 0) {
        return x + 1;
    }
    return 0;
}
