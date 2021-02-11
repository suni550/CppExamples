#include "VirtualDctor_DeriveClass.h"
#include<iostream>

using namespace std;

VirtualDctor_DeriveClass::VirtualDctor_DeriveClass() {
    cout << "Derived Class Ctor" << endl;
}

VirtualDctor_DeriveClass::~VirtualDctor_DeriveClass() {
    cout << "Derived Class Dctor" << endl;
}

/*
VirtualDctor_BaseClass* VirtualDctor_DeriveClass::get(void) {
  //  VirtualDctor_BaseClass* vdBaseClass  = new VirtualDctor_BaseClass;
    return vdBaseClass;
}
*/
