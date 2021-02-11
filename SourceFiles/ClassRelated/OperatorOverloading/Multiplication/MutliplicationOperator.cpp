#include "MutliplicationOperator.h"
#include <iostream>

using namespace std;
MutliplicationOperator::MutliplicationOperator() : 
 
  m_num1(0),
  m_num2(0),
  m_mulResult() {

}

MutliplicationOperator::~MutliplicationOperator() {
}

void MutliplicationOperator::setNum1(int x) {
    m_num1 = x;
}

void MutliplicationOperator::setNum2(int y) {
    m_num2 = y;
}

MutliplicationOperator MutliplicationOperator::operator*(const MutliplicationOperator& rhs) {
    cout << "MutliplicationOperator::operator* overloading" << endl;
    MutliplicationOperator additionalOperator;
    additionalOperator.m_mulResult = this->m_num1 * rhs.m_num2;

    return additionalOperator;
}

int MutliplicationOperator::getResult() {
    return m_mulResult;
}
