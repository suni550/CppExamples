#pragma once
#include<string.h>
#include<iostream>

using namespace std;
/*
* This class description about 
*   1. How many objects are created (heap + stack) 
*   2. How many objects are in heap memory
*   3. 
*/

class ObjectsInHeap {
public:
    ObjectsInHeap();
    ~ObjectsInHeap();

    ObjectsInHeap(const ObjectsInHeap& obj);

    // new Operator Overload 
    void* operator new(size_t size);

    // delete operator overload 
    void operator delete(void* ptr);

    static int getNumber();

   
private:
    static int totalNumberOfObjects;
    static int m_objectInHeap;
    int nonStaticDataMember;
};
