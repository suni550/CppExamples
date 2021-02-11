#pragma once
#include "DynamicBinding_BaseClass.h"

class DynamicBinding_DerivedClass : public DynamicBinding_BaseClass {
public:
    DynamicBinding_DerivedClass();
    ~DynamicBinding_DerivedClass();
    // NOTES: 
    /* 
   
    */


     virtual int foo(int x);
};

