#include <algorithm>
#include <ctime>
#include <iostream>
#include <random>

using namespace std;

class Board {
  private:
   char tiles[30];

  public:
   Board() {
      // generate random tiles
      fill_n(tiles, 30, 'N');

      // random seed
      srand(static_cast<unsigned int>(time(nullptr)));

      // generate snakes
      int snakes = 0;
      while (snakes < 3) {
         int selectedTile = rand() % 30;
         if (tiles[selectedTile] == 'N') {
            snakes += 1;
            tiles[selectedTile] = 'S';
         }
      }
      // generate ladders
      int ladders = 0;
      while (ladders < 3) {
         int selectedTile = rand() % 30;
         if (tiles[selectedTile] == 'N') {
            ladders += 1;
            tiles[selectedTile] = 'L';
         }
      }
   };

   void printBoard() { cout << tiles; }
};
