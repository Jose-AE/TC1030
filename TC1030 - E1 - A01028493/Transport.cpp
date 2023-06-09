#include "Transport.h"
#include <iostream>
#include <string>
using namespace std;

Transport::Transport(const float& storedGas) : storedGas(storedGas) {}

Transport Transport::operator+(const Transport* trans) const {

   Transport result(trans->storedGas + storedGas);

   return result;
}

float Transport::getStoredGas() { return storedGas; }
