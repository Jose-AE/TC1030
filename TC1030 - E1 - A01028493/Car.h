#pragma once
#include <string>
#include "Vehicle.h"

using namespace std;

class Car : public Vehicle {
  private:
   float maxSpeed;

  public:
   Car(const float&, const string& type, const float&);

   void mobility() override;
};
