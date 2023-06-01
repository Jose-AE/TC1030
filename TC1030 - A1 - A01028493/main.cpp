#include <iostream>
#include "Polar.h"
#include "Rect.h"

using namespace std;

int main() {

   Rect r1(0.1, 0.2);
   Rect r2(1, 2);
   Rect r3;

   r3 = r1 + r2;

   Polar p1(60, 5);
   Polar p2(30, 3);
   Polar p3;

   p3 = p1 + p2;

   r3.print();
   p3.print();

   return 0;
}
