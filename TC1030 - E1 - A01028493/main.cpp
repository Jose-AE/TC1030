#include <iostream>
#include "Polar.h"
#include "Rect.h"

using namespace std;

int main() {

   Rect r1(0.1, 0.2);
   Rect r2(1, 2);
   Rect r3;
   Polar p1(60, 5);
   Polar p2(30, 3);
   Polar p3;

   r3 = r1 + r2;
   r3.print();
   r3 = r1 + p1;
   r3.print();
   r3 = r1 - r2;
   r3.print();
   r3 = r1 - p1;
   r3.print();

   p3 = p1 + p2;
   p3.print();
   p3 = p1 + r1;
   p3.print();

   p3 = p1 * p2;
   p3.print();
   p3 = p1 * r1;
   p3.print();

   p3 = p1 / p2;
   p3.print();
   p3 = p1 / r1;
   p3.print();

   return 0;
}
