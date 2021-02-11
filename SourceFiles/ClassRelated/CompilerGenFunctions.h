#pragma once
class CompilerGenFunctions {

public:
    // Ctor
    CompilerGenFunctions();
    // Dtor
    ~CompilerGenFunctions();

    // Copy Ctor
    CompilerGenFunctions(const CompilerGenFunctions& obj);

    // Copy Assignment operator
    // Is called when already created class assigned 
    CompilerGenFunctions& operator = (const CompilerGenFunctions& obj);
};

