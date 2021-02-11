#pragma once
class VirtualDctor_BaseClass {
public:
    VirtualDctor_BaseClass();
    // NOTES: 
    /* 
    *** if we dont use virtual, when the following is called from Main()
    VirtualDctor_BaseClass* VDBase = new VirtualDctor_DeriveClass();
    delete VDBase;
    the output will be: 
            --> Base Class Ctor
            --> Derived Class Ctor     
                                    // Here Derived calss destructor is not being called thus causing the resource leakage problem.
            --> Base Class Dctor
     *** if we use virtual keayword for the base class Dctor 
     * the output will be 
            --> Base Class Ctor
            --> Derived Class Ctor
            --> Derived Class Dctor // Here Derived calss destructor is being called thus NO problem
            --> Base Class Dctor
    */
    virtual ~VirtualDctor_BaseClass();
};

