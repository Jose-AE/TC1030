#pragma once
#include <string>
#include "Boat.h"
#include "Car.h"
#include "Vehicle.h"

using namespace std;

class Transport {
  private:
   float storedGas = 0;
   Vehicle* vehicles[6] = {
       new Car(5.5, "Race", 15.5),       new Car(5.5, "Gokart", 15.5),
       new Car(5.5, "General", 15.5),    new Boat(5.5, "Fisher", "Paddle"),
       new Boat(5.5, "Cruise", "Motor"), new Boat(5.5, "Cargo", "Sail"),
   };

  public:
   Transport(const float&);
   Transport operator+(const Transport*) const;
   float getStoredGas();
};
