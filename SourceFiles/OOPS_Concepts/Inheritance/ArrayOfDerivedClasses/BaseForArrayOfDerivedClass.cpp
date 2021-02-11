#include "BaseForArrayOfDerivedClass.h"
#include<iostream>

using namespace std;

BaseForArrayOfDerivedClass::BaseForArrayOfDerivedClass () {
    cout << "BaseForArrayOfDerivedClass, Ctor" << endl;
}

BaseForArrayOfDerivedClass::~BaseForArrayOfDerivedClass () {
    cout << "BaseForArrayOfDerivedClass, Dctor" << endl;
}

void BaseForArrayOfDerivedClass::foo ( void ) {
    cout << "BaseForArrayOfDerivedClass:-> foo" << endl;
}

