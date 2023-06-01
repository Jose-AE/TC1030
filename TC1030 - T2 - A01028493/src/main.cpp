#include <iostream>
#include "Classes/Envelope.h"
#include "Classes/Package.h"

using namespace std;

int main() {
   Package package("Sender", "123 Main Street", "City", "State", "12345",
                   "Recipient", "456 Elm Street", "City", "State", "67890",
                   10.0, 35, 30, 20, 90, 5);

   Envelope envelope("Sender", "123 Main Street", "City", "State", "12345",
                     "Recipient", "456 Elm Street", "City", "State", "67890",
                     10.0, 20, 20);

   cout << "Package cost: $" << package.calculateCost() << endl;
   cout << "Package cost: $" << envelope.calculateCost() << endl;

   return 0;
}
