#include "ArrayOfDerivedClasses.h"
#include<iostream>

using namespace std;

ArrayOfDerivedClasses::ArrayOfDerivedClasses ( ):
    BaseForArrayOfDerivedClass (),
    i(){
    cout << "ArrayOfDerivedClasses, Ctor" << endl;
}


ArrayOfDerivedClasses::~ArrayOfDerivedClasses ( ) {
    cout << "ArrayOfDerivedClasses, Dtor" << endl;
}

void ArrayOfDerivedClasses::foo ( void ) {
    cout << "ArrayOfDerivedClasses, foo()" << endl;
}
