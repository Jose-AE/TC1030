#include <iostream>
#include <vector>
#include "Classes/Envelope.h"
#include "Classes/Package.h"
#include "Classes/Shipment.h"

using namespace std;

int main() {

   vector<Shipment*> shipments;

   shipments.push_back(new Package(
       "Sender", "123 Main Street", "City", "State", "12345", "Recipient",
       "456 Elm Street", "City", "State", "67890", 10.0, 35, 30, 20, 90, 5));

   shipments.push_back(new Envelope(
       "Sender", "123 Main Street", "City", "State", "12345", "Recipient",
       "456 Elm Street", "City", "State", "67890", 10.0, 20, 20));

   double totalCost = 0.0;

   // Iterar sobre el vector de envíos
   for (auto shipment : shipments) {
      // Obtener la información de las direcciones del remitente y destinatario

      // Imprimir las direcciones en las etiquetas de correo
      cout << "Recipients adress: " << shipment->getRecipientAddress() << endl;
      cout << "Sender adress: " << shipment->getSenderAddress() << endl;

      // Calcular el costo de envío y mostrarlo
      cout << "Shipment cost: $" << shipment->calculateCost() << endl;

      // Actualizar el costo total de envío
      totalCost += shipment->calculateCost();
   }

   // Mostrar el costo total de envío para todos los envíos
   cout << "Total shipment cost: $" << totalCost << endl;

   return 0;
}
