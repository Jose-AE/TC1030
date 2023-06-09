#include "Boat.h"
#include <iostream>
#include <string>
using namespace std;

Boat::Boat(const float& gas, const string& type, const string& mobilityType)
    : Vehicle(gas, type), mobilityType(mobilityType) {}

void Boat::mobility() {
   if (type == "Fisher") {
      cout << "Used in Lakes\n"
           << "Boat type: " << type << "\nMobility Type:" << mobilityType
           << endl;
   } else if (type == "Cruise") {
      cout << "Used in Seas\n"
           << "Boat type: " << type << "\nMobility Type:" << mobilityType
           << endl;
   } else if (type == "Cargo") {
      cout << "Used in Seas\n"
           << "Boat type: " << type << "\nMobility Type:" << mobilityType
           << endl;
   }
}
