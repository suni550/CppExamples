#include"InlineClass.h"
#include<iostream>


using namespace std;

InlineClass::InlineClass() {

}

InlineClass::~InlineClass() {

}

inline int InlineClass::foo(int a) {
    return a*a;
}

int InlineClass::fooTest(int a) {

    return foo(a);
}
