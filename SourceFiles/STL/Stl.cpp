
#include <string>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<set>
#include<map>

#include "Stl.h"

using namespace std;

void Stl::VectorDemo() {

    vector<string> StringList;
    StringList.push_back("Hello ");

    vector<int> A = { 1, 55, 34, 200, 2 };

    cout << "A.size() = " << A.size() << endl;

    A.push_back(100);
    A.push_back(100);
    A.push_back(100);
    A.push_back(100);
    A.push_back(123);

    sort(A.begin(), A.end()); // A = 1,2,34,55,100,100,100,100,123,200
    vector<int>::iterator it = lower_bound(A.begin(), A.end(), 50); // 1st element which is !< 100 = A[4] = 100
    vector<int>::iterator it2 = upper_bound(A.begin(), A.end(), 50); // 1st element which is > 100 = A[8] = 123

    cout << "*it =" << *it << "  " << "it =" << it - A.begin() << endl;
    cout << "*it2 =" << *it2 << "  " << "it2 =" << it2 - A.begin() << endl;
    cout << "it2-it =" << it2 - it << endl;


    A.push_back(13);
    A.push_back(33);
    // sort(A.begin(), A.end(), comp);

    for (int i = 0; i < 12; ++i) {
        cout << "A[" << i << "] = " << A[i] << endl;
    }

}

void Stl::SetDemo(void) {
    /*
       any time an element is inserted into sets, they are already sorted out.
       Unlike vector which requires sorting sets done require sorting.
     */
    std::cout << "*********  setDemo Enter **********\n";

    set<int> S;

    //// 1. Insert an element of into a set
    S.insert(2);
    S.insert(4);
    S.insert(21);
    S.insert(0);
    S.insert(22);
    std::cout << "S.size() = " << S.size() << endl;

    //// 2. Delete an element from set
    S.erase(22);
    std::cout << "S.size() = " << S.size() << endl;

    //// 3. Iterator on set
    // 3 ways of iterators 
    set<int>::iterator it;
    for (it = S.begin(); it != S.end(); it++) {
        std::cout << "*it = " << *it << endl;
    }

    for (auto iterator = S.begin(); iterator != S.end(); iterator++) {
        std::cout << "*iterator = " << *iterator << endl;
    }

    for (int x : S) {
        std::cout << "x = " << x << endl;
    }

    //// 4. Find an element in a set 
    set<int>::iterator it2 = S.find(4);
    if (it2 == S.end()) {
        std::cout << "Element is not present \n";
    }
    else {
        std::cout << "Element is Present \n";
    }
    std::cout << "*it2 = " << *it2 << endl;

    //// Upper bound and Lower bound on set
    auto it3 = S.lower_bound(1);
    auto it4 = S.upper_bound(0);
    std::cout << "lower bound of 1:-> *it3 = " << *it3 << "  " << "upper bound of 0:-> *it4 = " << *it4 << endl;

    std::cout << "\n\n*********  setDemo Exit **********\n";
}


void Stl::Mapdemo(void) {
    map<int, int> gquiz1;

    // insert elements in random order 
    gquiz1.insert(pair<int, int>(1, 40));
    gquiz1.insert(pair<int, int>(2, 30));
    gquiz1.insert(pair<int, int>(3, 60));
    gquiz1.insert(pair<int, int>(4, 22));
    gquiz1.insert(pair<int, int>(4, 20));

    gquiz1.insert(pair<int, int>(5, 50));
    gquiz1.insert(pair<int, int>(6, 50));
    gquiz1.insert(pair<int, int>(7, 10));

    // Printing map gquiz1
    map<int, int>::iterator itr;
    for (itr = gquiz1.begin(); itr != gquiz1.end(); itr++) {
        cout << "key = " << itr->first << "  " << "Value = " << itr->second << endl;
    }
    cout << "gquiz1.size() = " << gquiz1.size() << endl;

    // coping from one map to another map 
    map<int, int> gquiz2(gquiz1.begin(), gquiz1.end());
    cout << "\n\ngquiz2 elements " << endl;
    for (itr = gquiz2.begin(); itr != gquiz2.end(); itr++) {
        cout << "key = " << itr->first << "  " << "Value = " << itr->second << endl;
    }
    cout << "gquiz2.size() = " << gquiz2.size() << endl;

    // Remove elements upto key = 3
    gquiz2.erase(gquiz2.begin(), gquiz2.find(3));
    cout << "\n gquiz2 after deleting elements upto key 3\n";
    for (itr = gquiz2.begin(); itr != gquiz2.end(); itr++) {
        cout << "key = " << itr->first << "  " << "Value = " << itr->second << endl;
    }

    // remove all elements with key = 4
    gquiz2.erase(4);
    cout << "\n gquiz2 after deleting elements with key 4\n";
    for (itr = gquiz2.begin(); itr != gquiz2.end(); itr++) {
        cout << "key = " << itr->first << "  " << "Value = " << itr->second << endl;
    }
}