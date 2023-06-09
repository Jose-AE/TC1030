#include <iostream>
#include <vector>
#include "Classes/Envelope.h"
#include "Classes/Package.h"
#include "Classes/Shipment.h"

using namespace std;

int main() {

   vector<Shipment*> shipments{
       new Package("Sender", "123 Main Street", "City", "State", "12345",
                   "Recipient", "456 Elm Street", "City", "State", "67890",
                   10.0, 35, 30, 20, 90, 5),
       new Envelope("Sender", "123 Main Street", "City", "State", "12345",
                    "Recipient", "456 Elm Street", "City", "State", "67890",
                    10.0, 20, 20)};

   double totalCost = 0.0;

   for (auto shipment : shipments) {

      cout << "----------------" << endl;
      cout << "From: " << shipment->getRecipientAddress() << endl;
      cout << "To: " << shipment->getSenderAddress() << endl;
      cout << "Cost: $" << shipment->calculateCost() << endl;

      totalCost += shipment->calculateCost();
   }

   cout << "----------------" << endl;
   cout << "[Total shipment cost: $" << totalCost << "]" << endl;

   return 0;
}
