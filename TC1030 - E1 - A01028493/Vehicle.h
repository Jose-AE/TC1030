#pragma once
#include <string>

using namespace std;

class Vehicle {
  protected:
   float gas;
   string type;

  public:
   float getGas();
   string getType();
   Vehicle(const float&, const string&);
   virtual void mobility() = 0;
};
