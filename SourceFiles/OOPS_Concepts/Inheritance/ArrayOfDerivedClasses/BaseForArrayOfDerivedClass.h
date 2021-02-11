#pragma once
#include "BaseForArrayOfDerivedClass.h"

class BaseForArrayOfDerivedClass {
public:
    BaseForArrayOfDerivedClass ();
    ~BaseForArrayOfDerivedClass ();

    virtual void foo(void);// = 0; // pure virtual 
};

