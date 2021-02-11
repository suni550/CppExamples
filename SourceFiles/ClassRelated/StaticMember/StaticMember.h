#pragma once
/// <summary>
/// FAQ: 16.12: function holding its states between function calls.
/// FAQ: 16.13: Functionoid a class with single major function; often uses function call operator "operator() ()" 
/// </summary>


class StaticMember {
public:
    // Ctor
    StaticMember(int initialValue = 0);

    // Dtor
    ~StaticMember();
    // Example for FAQ 16.12 
    int next();

    // Example for FAQ 16.13 
    int operator()();

    // Example for FAQ 16.14 Is it safe to be ignore the order of static initialization?


private:
    // Copy Ctor 
    StaticMember(const StaticMember& obj);

    // Copu Assignement
    StaticMember&  operator = (const StaticMember& obj);
    int current;
    int m_operatorCurrent;

};

