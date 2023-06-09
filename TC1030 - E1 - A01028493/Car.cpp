#include "Car.h"
#include <iostream>
#include <string>
using namespace std;

Car::Car(const float& gas, const string& type, const float& maxSpeed)
    : Vehicle(gas, type), maxSpeed(maxSpeed) {}

void Car::mobility() {

   if (type == "Race") {
      cout << "Used in racetracks\n"
           << "Car type: " << type << "\nMax Speed:" << maxSpeed << endl;
   } else if (type == "Gokart") {
      cout << "Used in gokart tracks\n"
           << "Car type: " << type << "\nMax Speed:" << maxSpeed << endl;
   } else if (type == "General") {
      cout << "Used in roads\n"
           << "Car type: " << type << "\nMax Speed:" << maxSpeed << endl;
   }
}
