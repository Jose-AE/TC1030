#include "Vehicle.h"
#include <string>

using namespace std;

Vehicle::Vehicle(const float& gas, const string& type) : gas(gas), type(type) {}

float Vehicle::getGas() { return gas; }
string Vehicle::getType() { return type; }
