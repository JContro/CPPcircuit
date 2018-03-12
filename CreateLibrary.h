#ifndef CREATELIBRARY_H
#define CREATELIBRARY_H

#include "circuit.h"
#include "Components.h"

using namespace std;

class library : public circuit {
    library(); // default constructor
    void add_resistor();
};
        


#endif /* CREATELIBRARY_H */

