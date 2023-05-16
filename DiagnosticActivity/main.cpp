#include "Classes/Fraccion.h"
#include <iostream>
using namespace std;

int main() {

    Fraccion fraccion(3,5);
    Fraccion temp(5,6);

    fraccion.sum(temp);
    
    fraccion.print();




    return 0;
}