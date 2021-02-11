#include "DynamicBinding_DerivedClass.h"
#include<iostream>

using namespace std;
DynamicBinding_DerivedClass::DynamicBinding_DerivedClass() {
 //   cout << "Dynamic Binding Derived Class Ctor" << endl;
}

DynamicBinding_DerivedClass::~DynamicBinding_DerivedClass() {
 //   cout << "Dynamic Binding Derived Class Dctor" << endl;
}

int DynamicBinding_DerivedClass::foo(int x) {
    cout << "DynamicBinding_DerivedClass: foo " << endl;
    if (x > 8) {
        return 8;
    }

    return 0;
}
