#include"Recursion.h"
#include<string.h>
#include<iostream>

using namespace std;
Recursion::Recursion()
    {
}



int Recursion::recursive(int a) {
    int factorialOfNum;

    if (a < 2) {
        return 1;
    }
    else {
        factorialOfNum = a * recursive(a - 1);
    }

    return factorialOfNum;
}
