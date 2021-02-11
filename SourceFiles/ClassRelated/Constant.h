#pragma once
#include<string.h>

class Constant {
public: 
	Constant(int d); // Ctor

	// This function is invoked for 1. int or 2 int & without const word
	void constantReferenceVariable(int& age);
	// This function is invoked for 1. const int or 2 const int & means with const keyword
	void constantReferenceVariable(const int& age);

	//void nonConstantVariable(int age);
	// Overload the function
	void constantVariable(const int age);
	//void constantVariable(int age); // Overloaded function has no difference with const function so compiler gives an error; 
	                                // From the callers point there is no difference b/w these two functions
									// As its passed by value so the caller function does not care whether called function modifies or not as its a copy 
	
	//   BITWISE constness
	/* Constant Memebr Function: Should not modify any non-static data member variable
	*  Const member functions only call Const Memebr function; they should not call non-const member functions
	*/
	void constantMemberFunction(int age) const;

	// Logical constness 
	int& logicalConstFunction(int index) const;

	// Constant Reference Return Value
	const int& constantReferenceReturn(void);


	int getDogAge(void) const;

	void setDogAge(int age);

	void myString(const int& s);

private:
	int dogAge;
	


	int* intPtr;
};