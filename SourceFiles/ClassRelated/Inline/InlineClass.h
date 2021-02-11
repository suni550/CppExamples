#pragma once
#include<string.h>

class InlineClass {
public: 
	// Ctor
	InlineClass();

	// Dtor
	~InlineClass();
	
	inline int foo(int a);
	int fooTest(int a);
private:


};