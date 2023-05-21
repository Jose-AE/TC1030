#include <algorithm>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <random>
#include <string>
#include "Player.h"

#define BOARD_SIZE 30

using namespace std;

class Board {
  private:
   string tiles[BOARD_SIZE];
   Player p1;
   Player p2;

  public:
   Board() {
      // create players
      p1.setId(1);
      p2.setId(2);

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

      // tiles[5] = "L";
   };

   string getTile(int tile) { return tiles[tile]; }

   int getPlayerTile(int player) {

      return (player == 1 ? p1.getTile() : p2.getTile());
   }

   int movePlayerBy(int tile, int playerId) {

      if (playerId == 0) {
         if (p1.getTile() + tile > BOARD_SIZE - 1) {
            p1.setTile(BOARD_SIZE - 1);
         } else if (tiles[p1.getTile() + tile] == "S") {
            movePlayerBy(tile - 3, 0);
         } else if (tiles[p1.getTile() + tile] == "L") {
            movePlayerBy(tile + 3, 0);
         } else {
            p1.incrementTile(tile);
         }
         return p1.getTile();
      }

      if (playerId == 1) {
         if (p2.getTile() + tile > BOARD_SIZE - 1) {
            p2.setTile(BOARD_SIZE - 1);
         } else if (tiles[p2.getTile() + tile] == "S") {
            movePlayerBy(tile - 3, 1);
         } else if (tiles[p2.getTile() + tile] == "L") {
            movePlayerBy(tile + 3, 1);
         } else {
            p2.incrementTile(tile);
         }
         return p2.getTile();
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

            if (tile == p1.getTile() && tile == p2.getTile()) {
               players += "(P1 P2)";
            } else if (tile == p1.getTile()) {
               players += "  (P1) ";
            } else if (tile == p2.getTile()) {
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
