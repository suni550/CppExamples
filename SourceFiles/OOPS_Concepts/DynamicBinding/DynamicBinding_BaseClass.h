#pragma once
class DynamicBinding_BaseClass {
public:
    // Ctor
    DynamicBinding_BaseClass();

    // Dtor
    ~DynamicBinding_BaseClass();
    
    // NOTES:
    /* 
    * This is an example of ploymorphism Dynamic Binding/Run time/ Late binding
    * For this to happen we need 4 things 
    *   1. Two classes (base and derived); Class is derived publically 
    *   2. Base class should have pure virtual function 
    *   3. Derived class should override the virtual function 
    *   4. Overridden function must be accessed throudh base class pointer pointer or reference

    */
     
    virtual int foo(int x);

};

