#include<iostream>
#include<stdio.h>

// Project includes
#include<memory>

// CLASS related concepts
#include"ClassRelated/Constant.h"
#include "ClassRelated/CompilerGenFunctions.h"
#include "ClassRelated/Inline/InlineClass.h"
#include "ClassRelated/OperatorOverloading/PrefixAndPostfixOperator/PrefixAndPostfixOperator.h"
#include "ClassRelated/StaticMember/ObjectsInHeap.h"
#include "ClassRelated/StaticMember/StaticMember.h"
#include "ClassRelated/OperatorOverloading/AdditionOperator/AdditionOperator.h"
#include "ClassRelated/OperatorOverloading/Multiplication/MutliplicationOperator.h"
#include "ClassRelated/Recursion/Recursion.h"

// STL 
#include "STL/Stl.h"

// OOPS_Concepts related includes
#include "OOPS_Concepts/VirtualDestructor/VirtualDctor_BaseClass.h"
#include "OOPS_Concepts/VirtualDestructor/VirtualDctor_DeriveClass.h"
#include "OOPS_Concepts/DynamicBinding/DynamicBinding_BaseClass.h"
#include "OOPS_Concepts/DynamicBinding/DynamicBinding_DerivedClass.h"

#include"OOPS_Concepts\Inheritance\ArrayOfDerivedClasses\BaseForArrayOfDerivedClass.h"
#include"OOPS_Concepts\Inheritance\ArrayOfDerivedClasses\ArrayOfDerivedClasses.h"

using namespace std;
/////////////////////////////////////////

void TestStl(void ) {
    Stl m_Stl; 
    m_Stl.VectorDemo();
    m_Stl.SetDemo();
    m_Stl.Mapdemo();
}

class OpenFile {
public:
    OpenFile(string fileName) { 
        cout << "File Name = " << fileName<<endl;
    }
};


//2. Calling Constant Class 
void CallConstantClass(void) {
    int aa = 9;
    int& ref = aa;
    int bb = 88;

    ref = bb;
    cout << "aa = " << aa << ", bb = " << bb << endl;

    Constant C1(1);
    int a = 3;
    // Callling Non-constant ReferenceVariable Function
    C1.constantReferenceVariable(a);
    cout << "NonConst.Ref Value = " << a << endl;

    a = 33;
    const int& constRef = a;

    // Callling ConstantReferenceVariable Function
    C1.constantReferenceVariable(constRef);

    const int b = C1.constantReferenceReturn();
}
// 3.CallCompilerGenFunctions
void CallCompilerGenFunctions(void) {
    CompilerGenFunctions C1,C2;
    //CompilerGenFunctions C2;
    C2 = C1; // Copy assignment constructor will be called
  //  CompilerGenFunctions C3 = C2; // Copy constructor will be called
}
    // 4. Calling Virtual Dctor
void callVirtualDctor(void) {
    VirtualDctor_BaseClass* VDBase = new VirtualDctor_DeriveClass();
    delete VDBase;
}

void TestDynamicBinding1(DynamicBinding_BaseClass b) {
    b.foo(4);
}

void TestDynamicBinding2(DynamicBinding_BaseClass& b) {
    b.foo(9);
}

void TestDynamicBinding3(DynamicBinding_BaseClass* b) {
    b->foo(8);
}
// 5. Calling Dynamic Binding
void DynamicBinding(void) {
    DynamicBinding_BaseClass b;
    DynamicBinding_DerivedClass d;

    // Case 1
    cout << "%%%%% Call TestDynamicBinding1 %%%%%" << endl;
    TestDynamicBinding1(b);
    TestDynamicBinding1(d);
    cout << endl;
    // Case 2
    cout << "+++++ Call TestDynamicBinding2 +++++" << endl;
    TestDynamicBinding2(b);
    TestDynamicBinding2(d);
    cout << endl;
    // Case 3
    cout << "***** Call TestDynamicBinding3 *****" << endl;
    TestDynamicBinding3(&b);
    TestDynamicBinding3(&d);
    cout << endl;
}

// 6.TestInline feature 
void TestInlineFeature(void) {
    InlineClass iCObj;
    int retVal = iCObj.fooTest(4);
    cout << "Inline Fun retVal = " << retVal << endl;
}


void TestPrefixAndPostfixOperator(void) {
    Check obj;
    Check obj1;
    obj.Display();
    obj1.Display();

    // Operator function is called, only then value of obj is assigned to obj1
    obj1 = ++obj;
    obj.Display();
    obj1.Display();

    // Assigns value of obj to obj1, only then operator function is called.
    obj1 = obj++;
    obj.Display();
    obj1.Display();
}
// 7. TestOperatorOverloading
void TestOperatorOverloading() {
    TestPrefixAndPostfixOperator();
}

// 8. TestStaticMember and ObjectsInHeap
void TestStaticMemberAndObjectsInHeap(void) {
   // StaticMember stMemObj;
    ObjectsInHeap* StaticMemberObj = new ObjectsInHeap( );
    if (NULL != StaticMemberObj) {
        delete StaticMemberObj;
    }

   // cout<<"Static Member no.of objects created = "<<stMemObj.getNumber()<<endl;
}

void sampleTest ( BaseForArrayOfDerivedClass* b ) {
 //   b->foo ( );
    cout << "b[0].f \n";
    b[0].foo ( );

  //  cout << "b[1].f \n";
  //  b[1].foo ( );  //System crash. since b[1] may not point to d[1]. b[1] may point to somewhere in the middle of d[0]
}

// 9. Testing Array of Derived classes, new delete and new[] and delete[]
void TestArrayOfDerivedClasses ( void ) {
    ArrayOfDerivedClasses ArrayOfD[5];
    cout << "instances/objects for ArraOfDerivedClassesCreated"<<endl<<endl;
    cout << "NowCallingMethods\n";
    sampleTest(ArrayOfD);

    // Array of Base Classes 
    // Done use pointer arithmetic on polymorphic objects 
    // https://wiki.sei.cmu.edu/confluence/display/cplusplus/CTR56-CPP.+Do+not+use+pointer+arithmetic+on+polymorphic+objects
    BaseForArrayOfDerivedClass** pBaseForArrayOfDerivedClass = new BaseForArrayOfDerivedClass*[2];
    pBaseForArrayOfDerivedClass[0] = new ArrayOfDerivedClasses;
    sampleTest (pBaseForArrayOfDerivedClass[0]);


    ArrayOfDerivedClasses* obj = new ArrayOfDerivedClasses();  // obj holds the address which is on the 'stack' memory
    cout << (obj) << endl;
    delete obj;

    ArrayOfDerivedClasses* ptr = new ArrayOfDerivedClasses[2];
     delete[] ptr;
}

// 10. Testing recursive function
void TestRecursion() {
    Recursion m_recursion;
    int recResult = m_recursion.recursive(8);
    cout << "Recursion of 8 = " << recResult << endl;
}
class Test {
public:
    Test() {}
    Test(const Test& t) {
        cout << "Copy constructor called " << endl;
    }

    Test& operator = (const Test& t) {
        cout << "Assignment operator called " << endl;
        return *this;
    }
};



namespace first {
    int nameSpaceVar = 600;
}

int nameSpaceVar = 400; 

void TestNameSpaceVarName() {
    int nameSpaceVar = 200;
    //using first::nameSpaceVar; // using- declaration causes a multiple declaration of 'nameSpacevar'

    //  can access the first nameSpaceVar 
    cout << "first::nameSpaceVar = " << first::nameSpaceVar << endl;

    cout << "GloablVar::nameSpaceVar = " << ::nameSpaceVar << endl;

    cout << "Local nameSpaceVar = " << nameSpaceVar << endl;

    return;
}

namespace FirstNameSpace {
    class Kumar {
    public:
        void foo() {
            cout << "I am in FirstNameSpace, class Kumar" << endl;
        };
    };
}

namespace SecondNameSpace {
    class Kumar {
    public:
        void foo() {
            cout << "I am in SecondNameSpace, class Kumar" << endl;
        }
    };
}

void TestingNameSpaceClassName() {

    // Accessing the names inside namespaces 1st method
    FirstNameSpace::Kumar firstKumarobj;
    SecondNameSpace::Kumar secondKumarobj;
    firstKumarobj.foo();
    secondKumarobj.foo();

    // Accessing the names inside namespaces 2nd method
  //  using namespace FirstNameSpace;   
  //  Kumar kumarObj;

  //  using SecondNameSpace::Kumar;
  //  Kumar kumar2Obj;


}
// Diamond problem
class A
{
    int x;
public:
    A(int i) { x = i; }
   // void setX(int i) { x = i; }
    void print() { cout << x; }
};

class B : virtual public A
{
public:
    B():A(10) { //setX(10);
    }
};

class C : virtual public A
{
public:
    C():A(20) { //setX(20); 
    }
};

class D : public B, public C {
public:
    D() : A(100), B(), C() {}
};

// Functionoid
void TestFunctionoid() {
    StaticMember m_staticMemberObj;
    int retVal;
    retVal = m_staticMemberObj.next();
    cout << "1st.retVal = " << retVal << endl;
    retVal = m_staticMemberObj.next();
    cout << "2nd.retVal = " << retVal << endl;
    retVal = m_staticMemberObj.next();
    cout << "3rd.retVal = " << retVal << endl;

    StaticMember m_staticMemberObj2;
    int retVal2;
    retVal2 = m_staticMemberObj2.operator()();
    cout << "1st.retVal2 = " << retVal2 << endl;
    retVal2 = m_staticMemberObj2.operator()();
    cout << "1st.retVal2 = " << retVal2 << endl;
    retVal2 = m_staticMemberObj2.operator()();
    cout << "1st.retVal2 = " << retVal2 << endl;

    retVal = m_staticMemberObj.next();
    cout << "4th.retVal = " << retVal << endl;
}

int* foo(void) {
    int k = 3;
    k++;
    return &k;
}

class Wilma {
public: 
    Wilma() { cout << "Wilma Ctor" << endl; }
    void f() { cout << "Wilma is used\n"; }
};

class Fred {
public:
    Fred() {
        cout << "Fred Ctor \n";
        m_wilma().f();
    }

protected:
    static Wilma& m_wilma();
};

Fred m_fred;
// Static member function definition
Wilma& Fred::m_wilma() {
    static Wilma* ptr = new Wilma();
    return *ptr;
}

void swapTwoNumbers(int& x, int& y) {
    int temp; 
    temp = y; 
    y = x;
    x = temp;
}

void sample() {
    int a; 
    int b; 
    a = 45;
    b = 65;
    int* ptr = new int(5);
    *ptr = 42; 
  //  *(ptr + 4) = 45;
  //  *(ptr + 5) = 55;
  //  *ptr = 99;

   // cout << "*ptr = " << *ptr  <<endl;
//    cout << "*(ptr + 4) = " << *(ptr + 4) <<endl;
  //  cout << "*(ptr + 5) = " << *(ptr + 5) <<endl;

    delete ptr;

}

int main() {
    // 1. Test STL Libraries
    //  TestStl();
    // 2. Calling ConstantClass
    //  CallConstantClass();

    // 3. Calling Compiler Gen Functions
    //   CallCompilerGenFunctions();

    // 4. Call to Virtual Dcotr 
    // callVirtualDctor();

    // 5. Call to Dynamic Binding
    // DynamicBinding();
 
    // 6.TestInline feature 
    // TestInlineFeature();
   
    // 7. TestOperator Overloading
    // TestOperatorOverloading();
    
    // 8. TestStaticMemberandObjectsInHeap
    // TestStaticMemberAndObjectsInHeap();

    // 9. Testing Array of Derived classes
     TestArrayOfDerivedClasses ( );

    // 10. Testing recursive function
    // TestRecursion();

    // Testing namespace  - 1
    //  TestNameSpaceVarName();

    // Testing namespace  - 2
 //   TestingNameSpaceClassName();

    // Testing Diamond problem 
  //  D d;
  //  d.print();
 

    // Testing StaticMember (or) functionoid
  //  TestFunctionoid();

 
    sample();
/*
    AdditionOperator m_AdditionOperator1;
    m_AdditionOperator1.setLength(6);
    m_AdditionOperator1.setWidth(3);
    cout << "Perimeter of 1 = " << m_AdditionOperator1.calcPerimeter() << endl;

    AdditionOperator m_AdditionOperator2;
    m_AdditionOperator2.setLength(8);
    m_AdditionOperator2.setWidth(5);
    cout << "Perimeter of 2 = " << m_AdditionOperator2.calcPerimeter() << endl;
    AdditionOperator m_AdditionOperatorResult;
    m_AdditionOperatorResult = m_AdditionOperator1 + m_AdditionOperator2;

    cout << "m_AdditionOperatorResult.getLength = " << m_AdditionOperatorResult.getLength() << endl;
    cout << "m_AdditionOperatorResult.getWidth = " << m_AdditionOperatorResult.getWidth() << endl;

    cout << "Perimeter of m_AdditionOperatorResult = " << m_AdditionOperatorResult.calcPerimeter() << endl;
    */

    AdditionOperator m_Mul1, m_Mul2, m_Result;
    m_Mul1.setNum1(8);
    m_Mul2.setNum2(7);
    m_Result = m_Mul1 * m_Mul2;
    cout << "Product of 2 numbers = " << m_Result.getResult() << endl;
    return 0;
 }
