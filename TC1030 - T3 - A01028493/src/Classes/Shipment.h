#include <string>
#pragma once
using namespace std;

class Shipment {
  protected:
   string senderName;
   string senderAddress;
   string senderCity;
   string senderState;
   string senderPostalCode;
   string recipientName;
   string recipientAddress;
   string recipientCity;
   string recipientState;
   string recipientPostalCode;
   double standardCost;

  public:
   Shipment(const string& senderName, const string& senderAddress,
            const string& senderCity, const string& senderState,
            const string& senderPostalCode, const string& recipientName,
            const string& recipientAddress, const string& recipientCity,
            const string& recipientState, const string& recipientPostalCode,
            double standardCost)
       : senderName(senderName),
         senderAddress(senderAddress),
         senderCity(senderCity),
         senderState(senderState),
         senderPostalCode(senderPostalCode),
         recipientName(recipientName),
         recipientAddress(recipientAddress),
         recipientCity(recipientCity),
         recipientState(recipientState),
         recipientPostalCode(recipientPostalCode),
         standardCost(standardCost) {}

   string getSenderAddress() { return senderAddress; }
   string getRecipientAddress() { return recipientAddress; }

   virtual double calculateCost() const { return standardCost; }
};
