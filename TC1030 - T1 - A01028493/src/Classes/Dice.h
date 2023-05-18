#include <algorithm>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <random>
#include <string>

using namespace std;

class Dice {
  private:
   /* data */
  public:
   int roll() {
      srand(static_cast<unsigned int>(time(nullptr)));
      int rng = rand() % 6 + 1;

      if (rng == 1) {
         cout << "   +---------+" << endl;
         cout << "  /         /|" << endl;
         cout << " +---------+ |" << endl;
         cout << " |         | |" << endl;
         cout << " |    *    | +" << endl;
         cout << " |         |/" << endl;
         cout << " +---------+ " << endl;

      } else if (rng == 2) {
         cout << "   +---------+" << endl;
         cout << "  /         /|" << endl;
         cout << " +---------+ |" << endl;
         cout << " | *       | |" << endl;
         cout << " |         | +" << endl;
         cout << " |       * |/" << endl;
         cout << " +---------+ " << endl;

      } else if (rng == 3) {
         cout << "   +---------+" << endl;
         cout << "  /         /|" << endl;
         cout << " +---------+ |" << endl;
         cout << " | *       | |" << endl;
         cout << " |    *    | +" << endl;
         cout << " |       * |/" << endl;
         cout << " +---------+ " << endl;

      } else if (rng == 4) {
         cout << "   +---------+" << endl;
         cout << "  /         /|" << endl;
         cout << " +---------+ |" << endl;
         cout << " | *     * | |" << endl;
         cout << " |         | +" << endl;
         cout << " | *     * |/" << endl;
         cout << " +---------+ " << endl;

      } else if (rng == 5) {
         cout << "   +---------+" << endl;
         cout << "  /         /|" << endl;
         cout << " +---------+ |" << endl;
         cout << " | *     * | |" << endl;
         cout << " |    *    | +" << endl;
         cout << " | *     * |/" << endl;
         cout << " +---------+ " << endl;

      } else if (rng == 6) {
         cout << "   +---------+" << endl;
         cout << "  /         /|" << endl;
         cout << " +---------+ |" << endl;
         cout << " | *    *  | |" << endl;
         cout << " | *    *  | +" << endl;
         cout << " | *    *  |/" << endl;
         cout << " +---------+ " << endl;
      }

      return rng;
   }
};
