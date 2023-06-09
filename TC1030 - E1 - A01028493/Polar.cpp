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

   Rect temp1(polar.getMag() * cosf(polar.getTheta()),
              polar.getMag() * sinf(polar.getTheta()));
   Rect temp2(mag * cosf(theta), mag * sinf(theta));

   float sumX = temp1.getX() + temp2.getX();
   float sumY = temp1.getY() + temp2.getY();

   Polar result(atanf(sumY / sumX), sqrt(pow(sumX, 2) + pow(sumY, 2)));

   return result;
}

// polar + rect
Polar Polar::operator+(const Rect& rect) const {

   Rect temp(mag * cosf(theta), mag * sinf(theta));

   float sumX = temp.getX() + rect.getX();
   float sumY = temp.getY() + rect.getY();

   Polar result(atanf(sumY / sumX), sqrt(pow(sumX, 2) + pow(sumY, 2)));

   return result;
}

// polar * polar
Polar Polar::operator*(const Polar& polar) const {

   Polar result(polar.getTheta() + theta, polar.getMag() * mag);

   return result;
}

// polar * rect
Polar Polar::operator*(const Rect& rect) const {

   Polar temp(atanf(rect.getY() / rect.getX()),
              sqrt(pow(rect.getX(), 2) + pow(rect.getY(), 2)));

   Polar result(temp.getTheta() + theta, temp.getMag() * mag);

   return result;
}

// polar / polar
Polar Polar::operator/(const Polar& polar) const {

   Polar result(theta - polar.getTheta(), mag / polar.getMag());

   return result;
}

// polar / rect
Polar Polar::operator/(const Rect& rect) const {

   Polar temp(atanf(rect.getY() / rect.getX()),
              sqrt(pow(rect.getX(), 2) + pow(rect.getY(), 2)));

   Polar result(theta - temp.getTheta(), mag / temp.getMag());

   return result;
}

void Polar::print() const {
   cout << "(" << theta << " Rad," << mag << ")" << endl;
}