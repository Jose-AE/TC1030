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
   string tiles[BOARD_SIZE];

  public:
   Board() {
      // generate random tiles
      fill_n(tiles, BOARD_SIZE, "N");

      // random seed
      srand(static_cast<unsigned int>(time(nullptr)));

      // generate snakes
      int snakes = 0;
      while (snakes < 3) {
         int selectedTile = rand() % BOARD_SIZE;
         if (tiles[selectedTile] == "N" &&
             tiles[max(0, selectedTile - 3)] != "L" &&
             selectedTile < (BOARD_SIZE - 1) && selectedTile > 2) {
            snakes += 1;
            tiles[selectedTile] = "S";
         }
      }
      // generate ladders
      int ladders = 0;
      while (ladders < 3) {
         int selectedTile = rand() % BOARD_SIZE;
         if (tiles[selectedTile] == "N" &&
             tiles[max(0, selectedTile + 3)] != "S" &&
             selectedTile < (BOARD_SIZE - 3) && selectedTile > 0) {
            ladders += 1;
            tiles[selectedTile] = "L";
         }
      }
   };

   void print() {
      const int COLUMNS = 6;
      const int ROWS = 5;

      for (int i = 0; i < BOARD_SIZE; i++) {
         cout << tiles[i];
      }
      cout << endl;

      for (int row = 0; row < ROWS; row++) {

         for (int col = 0; col < COLUMNS; col++) {
            cout << " _______ ";
         }
         cout << endl;

         for (int col = 0; col < COLUMNS; col++) {
            int tile = (BOARD_SIZE) - (row * COLUMNS + col);

            cout << "|  [" << tile << (tile < 10 ? "] " : "]") << " |";
         }
         cout << endl;
         for (int col = 0; col < COLUMNS; col++) {
            cout << "|   " << tiles[(BOARD_SIZE - 1) - (row * COLUMNS + col)][0]
                 << "   |";
         }
         cout << endl;
         for (int col = 0; col < COLUMNS; col++) {
            int tile = (BOARD_SIZE) - (row * COLUMNS + col) - 1;

            if (tiles[tile].length() == 1) {
               cout << "|       |";
            } else {

               string players = "|";

               for (int i = 1; i <= tiles[tile].length(); i++) {
                  players +=
                      tiles[tile][i] +
                      (i < tiles[tile].length() - 1 ? string(" ") : string(""));
               }

               for (int i = 0; i < 8 - ((tiles[tile].length() - 1) * 2); i++) {
                  players += " ";
               }

               cout << players << "|";
            };
         }
         cout << endl;
         for (int col = 0; col < COLUMNS; col++) {

            tiles[row * COLUMNS + col];

            cout << "|_______|";  // 7 under
         }
         cout << endl;
      }
   }
};
