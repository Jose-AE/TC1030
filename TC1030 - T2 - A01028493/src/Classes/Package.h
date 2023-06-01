#pragma once
#include <cmath>
#include "Shipment.h"

class Package : public Shipment {

  private:
   double length;
   double width;
   double depth;
   double weight;
   double costPerKg;

  public:
   Package(const string& senderName, const string& senderAddress,
           const string& senderCity, const string& senderState,
           const string& senderPostalCode, const string& recipientName,
           const string& recipientAddress, const string& recipientCity,
           const string& recipientState, const string& recipientPostalCode,
           double standardCost, double length, double width, double depth,
           double weight, double costPerKg)
       : Shipment(senderName, senderAddress, senderCity, senderState,
                  senderPostalCode, recipientName, recipientAddress,
                  recipientCity, recipientState, recipientPostalCode,
                  standardCost),
         length(length),
         width(width),
         depth(depth),
         weight(abs(weight)),
         costPerKg(abs(costPerKg)) {}

   double calculateCost() const override {
      double additionalCost = weight * costPerKg;
      return standardCost + additionalCost;
   }
};
