#include"BaseForArrayOfDerivedClass.h"

class ArrayOfDerivedClasses : public BaseForArrayOfDerivedClass {

public:
    ArrayOfDerivedClasses ( );

    ~ArrayOfDerivedClasses ( );

    void foo ( void ); 

protected:
    int i;

};

