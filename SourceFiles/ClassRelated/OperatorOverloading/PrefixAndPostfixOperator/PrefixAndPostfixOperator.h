#pragma once
#include<string.h>
#include<iostream>

using namespace std;

class Check {
/*public: 
	PrefixAndPostfixOperator();
	~PrefixAndPostfixOperator();

	PrefixAndPostfixOperator(const PrefixAndPostfixOperator& obj);
	
	// Prefix increment
	PrefixAndPostfixOperator operator ++();

	// Postfix increment
	PrefixAndPostfixOperator operator ++(int);

	// Display the output
	void Display(void);
	*/

public:
    Check(); // : i(0) {  }
    ~Check(){}

    Check(const Check& obj);

    // Prefix operator overloading
    Check operator ++ () {
        Check temp;
        temp.i = ++i;
        return temp;
    }

    // Notice int inside barcket which indicates postfix increment.
    // Postfix operator overloading
    Check operator ++ (int) {
        Check temp;
        temp.i = i++;
        return temp;
    }

    void Display() {
        cout << "i = " << i << endl;
    }

private:
	int number;
    int i;

};