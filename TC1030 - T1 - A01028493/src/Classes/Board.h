#include <algorithm>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <random>
#include <string>

#define BOARD_SIZE 30

using namespace std;

class Board {
  private:
   string tiles[BOARD_SIZE];
   int p1 = 0;
   int p2 = 0;

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
      // tiles[4] = "L";
   };

   int movePlayerBy(int tile, int playerId) {

      if (playerId == 0) {
         if (p1 + tile > BOARD_SIZE - 1) {
            p1 = BOARD_SIZE - 1;
         } else if (tiles[p1 + tile] == "S") {
            p1 += tile - 3;
         } else if (tiles[p1 + tile] == "L") {
            p1 += tile + 3;
         } else {
            p1 += tile;
         }
         return p1;
      }

      if (playerId == 1) {
         if (p2 + tile > BOARD_SIZE - 1) {
            p2 = BOARD_SIZE - 1;
            cout << "-------------------------";
         } else if (tiles[p2 + tile] == "S") {
            p2 += tile - 3;
         } else if (tiles[p2 + tile] == "L") {
            p2 += tile + 3;
         } else {
            p2 += tile;
         }
         return p2;
      }

      return 0;
   }

   void print() {
      const int COLUMNS = 6;
      const int ROWS = 5;

      if (false) {
         for (int i = 0; i < BOARD_SIZE; i++) {
            cout << tiles[i];
         }
         cout << endl;
      }

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

            string players = "|";

            if (tile == p1 && tile == p2) {
               players += "(P1 P2)";
            } else if (tile == p1) {
               players += "  (P1) ";
            } else if (tile == p2) {
               players += "  (P2) ";
            } else {
               players += "       ";
            }

            cout << players << "|";
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
