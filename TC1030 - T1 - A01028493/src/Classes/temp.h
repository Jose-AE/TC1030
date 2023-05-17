#include <algorithm>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <random>

#define BOARD_SIZE 30

using namespace std;

class Board {
  private:
   char tiles[BOARD_SIZE];

  public:
   Board() {
      // generate random tiles
      fill_n(tiles, BOARD_SIZE, 'N');

      // random seed
      srand(static_cast<unsigned int>(time(nullptr)));

      // generate snakes
      int snakes = 0;
      while (snakes < 3) {
         int selectedTile = rand() % BOARD_SIZE;
         if (tiles[selectedTile] == 'N') {
            snakes += 1;
            tiles[selectedTile] = 'S';
         }
      }
      // generate ladders
      int ladders = 0;
      while (ladders < 3) {
         int selectedTile = rand() % BOARD_SIZE;
         if (tiles[selectedTile] == 'N') {
            ladders += 1;
            tiles[selectedTile] = 'L';
         }
      }
   };

   void print() {
      const int COLUMNS = 6;
      const int ROWS = 5;

      cout << tiles << endl;

      for (int row = 0; row < ROWS; row++) {

         for (int col = 0; col < COLUMNS; col++) {
            cout << " _______ ";
         }
         cout << endl;

         for (int col = 0; col < COLUMNS; col++) {
            int tile = abs(BOARD_SIZE - (row * COLUMNS + col));
            cout << "|  [" << tile << (tile ? "] " : "] ") << " |";
         }
         cout << endl;
         for (int col = 0; col < COLUMNS; col++) {

            cout << "|   " << tiles[abs(BOARD_SIZE - (row * COLUMNS + col)) - 1]
                 << "   |";
         }
         cout << endl;
         for (int col = 0; col < COLUMNS; col++) {

            tiles[row * COLUMNS + col];

            cout << "|_______|";
         }
         cout << endl;
      }
   }
};
