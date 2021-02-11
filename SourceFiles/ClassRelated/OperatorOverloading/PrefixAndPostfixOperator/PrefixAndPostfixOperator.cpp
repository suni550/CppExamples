#include "PrefixAndPostfixOperator.h"
#include<iostream>

using namespace std;
Check::Check():
	i(0) {
	cout << "Ctor:-> " << endl;
}

Check::Check(const Check& obj) {
	i = obj.i;
}






