#include "Rect.h"
#include <cmath>
#include <iostream>
#include "Polar.h"

using namespace std;

Rect::Rect() {
   x = 0;
   y = 0;
}
Rect::Rect(float x, float y) : x(x), y(y) {}

float Rect::getX() const { return x; }
float Rect::getY() const { return y; }

// rect + rect
Rect Rect::operator+(const Rect& rect) const {
   Rect temp;
   temp.x = x + rect.x;
   temp.y = y + rect.y;
   return temp;
}

// rect + polar
Rect Rect::operator+(const Polar& polar) const {
   Rect temp;
   temp.x = polar.getMag() * cos(polar.getTheta());
   temp.y = polar.getMag() * sin(polar.getTheta());
   return temp;
}

void Rect::print() const { cout << "(" << x << "," << y << ")" << endl; }