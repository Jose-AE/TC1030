#include <cmath>
#include "Shipment.h"

class Envelope : public Shipment {

  private:
   double length;
   double width;
   double additionalCharge = 5.0;

  public:
   Envelope(const string& senderName, const string& senderAddress,
            const string& senderCity, const string& senderState,
            const string& senderPostalCode, const string& recipientName,
            const string& recipientAddress, const string& recipientCity,
            const string& recipientState, const string& recipientPostalCode,
            double standardCost, double length, double width)
       : Shipment(senderName, senderAddress, senderCity, senderState,
                  senderPostalCode, recipientName, recipientAddress,
                  recipientCity, recipientState, recipientPostalCode,
                  standardCost),
         length(length),
         width(width) {}

   double calculateCost() const override {
      return (length > 25 || width > 30) ? standardCost + additionalCharge
                                         : standardCost;
   }
};