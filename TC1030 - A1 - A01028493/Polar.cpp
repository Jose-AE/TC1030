#include "Polar.h"
#include <cmath>
#include <iostream>
#include "Rect.h"

using namespace std;

Polar::Polar() {}
Polar::Polar(float theta, float mag) : theta(theta), mag(mag) {}

float Polar::getTheta() const { return theta; }
float Polar::getMag() const { return mag; }

// polar + polar
Polar Polar::operator+(const Polar& polar) const {

   Rect temp1(polar.getMag() * cos(polar.getTheta()),
              polar.getMag() * sin(polar.getTheta()));
   Rect temp2(mag * cos(theta), mag * sin(theta));

   float sumX = temp1.getX() + temp2.getX();
   float sumY = temp1.getY() + temp2.getY();

   cout << sumX << endl;
   cout << sumY << endl;

   Polar result(sqrt(pow(sumX, 2) + pow(sumY, 2)), atan(sumY / sumX));

   return result;
}

// polar + rect
Polar Polar::operator+(const Rect& rect) const {
   Polar temp;
   // temp.x = x + polar.x;
   // temp.y = y + polar.y;
   return temp;
}

void Polar::print() const {
   cout << "(" << theta << " Deg," << mag << ")" << endl;
}