#include "StaticMember.h"
#include<iostream>

using namespace std;

StaticMember::StaticMember(int initialValue) :
    current(initialValue),
    m_operatorCurrent(initialValue) {
    cout << "StaticMember:: Ctor" << endl;
}

StaticMember::~StaticMember() {
    cout << "StaticMember:: Dtor" << endl;
}

int StaticMember::next() {
    current = current + 2;
    return current;
}

int StaticMember::operator()() {
    m_operatorCurrent = m_operatorCurrent + 5;
    return m_operatorCurrent;
}
