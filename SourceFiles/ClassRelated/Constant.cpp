#include"Constant.h"
#include<string.h>
#include<iostream>

using namespace std;
Constant::Constant(int d):
	dogAge(d),
	intPtr(nullptr){
	cout << "Ctor:-> dogAge = " << dogAge << endl;
}

void Constant::constantReferenceVariable(int& age) {
	dogAge = age;
	age = 99;
	cout << "Overloaded NON_CONST Non-ConstantReferenceVariable() = " << dogAge << endl;
}

void Constant::constantReferenceVariable(const int& age) {
	dogAge = age;
//	age++;
	cout << "Overloaded CONST constantReferenceVariable() = " << dogAge << endl;
}

void Constant::constantVariable(const int age) {
	dogAge = age;
}
/*
void Constant::constantVariable(float age) {
	dogAge = age;
	
}
*/

// Bitwise constness
void Constant::constantMemberFunction(int age) const {
	//dogAge = age; // const member function should not modify any data member
	int tmp = getDogAge();
	// setDogAge(tmp); // Const member function should not call a member function which modifies the data member
	cout << "Member:->constantMemberFunction() = " << dogAge << endl;

	//mutableMember = 9;
	//const_cast<int&>(testVar) = 99;
}


// Logical constness
int& Constant::logicalConstFunction(int index) const {

	return intPtr[index];
}




const int & Constant::constantReferenceReturn(void) {
	return dogAge;
}

int Constant::getDogAge(void) const {
	return dogAge;
}

void Constant::setDogAge(int age) {
	dogAge = age;

}

void Constant::myString(const int& s) {

}
