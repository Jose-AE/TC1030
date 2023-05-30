#include <string>

using namespace std;

class Envio {
  protected:
   string name;
   string adress;
   string city;
   string state;
   string zip;
   string recipient;
   string destiny;
   float cost = 60;

  public:
   virtual double calculaCosto(return cost) {}
};
