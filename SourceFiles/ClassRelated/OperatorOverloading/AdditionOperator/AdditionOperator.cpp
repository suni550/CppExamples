#include "AdditionOperator.h"
#include <iostream>

using namespace std;
AdditionOperator::AdditionOperator() : 
  m_length(0), 
  m_width(0),
  m_num1(0),
  m_num2(0),
  m_mulResult() {

}

AdditionOperator::~AdditionOperator() {
}

void AdditionOperator::setLength(int length) {
    m_length = length;
}

void AdditionOperator::setWidth(int width) {
    m_width = width;
}

AdditionOperator AdditionOperator::operator+(const AdditionOperator& rhs) {
    cout << "AdditionOperator::operator+ overloading" << endl;
    AdditionOperator additionalOperator; 
    additionalOperator.m_length = this->m_length + rhs.m_length ;
    additionalOperator.m_width = this->m_width + rhs.m_width;
    return additionalOperator;
}



int AdditionOperator::getLength() {
    return m_length;
}

int AdditionOperator::getWidth(){
    return m_width;
}

int AdditionOperator::calcPerimeter() {
    return (2*(m_length + m_width));
}

void AdditionOperator::setNum1(int x) {
    m_num1 = x;
}

void AdditionOperator::setNum2(int y) {
    m_num2 = y;
}

AdditionOperator AdditionOperator::operator*(const AdditionOperator& rhs) {
    cout << "AdditionOperator::operator* overloading" << endl;
    AdditionOperator additionalOperator;
    additionalOperator.m_mulResult = this->m_num1 * rhs.m_num2;

    return additionalOperator;
}

int AdditionOperator::getResult() {
    return m_mulResult;
}
