#pragma once
#include <string>
#include "Vehicle.h"

using namespace std;

class Boat : public Vehicle {
  private:
   string mobilityType;

  public:
   Boat(const float&, const string&, const string&);
   void mobility() override;
};
