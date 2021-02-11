#include "VirtualDctor_BaseClass.h"
#include<iostream>

using namespace std;
VirtualDctor_BaseClass::VirtualDctor_BaseClass() {
    cout << "Base Class Ctor" << endl;
}

VirtualDctor_BaseClass::~VirtualDctor_BaseClass() {
    cout << "Base Class Dctor" << endl;
}
