#include <cmath>
#include "Classes/Envio.h"

class Package : Envio {
  private:
   float length;
   float width;
   float depht;
   float weight;
   float cost_kg;

   Package(float length, float width, float depht, float weight,
           float cost_kg) {
      this->width = width;
      this->depht = depht;
      this->weight = abs(weight);
      this->cost_kg = abs(cost_kg);
   }

   double calculaCosto() override {}
};