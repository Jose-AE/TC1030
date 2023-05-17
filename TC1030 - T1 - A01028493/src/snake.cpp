#include "Classes/Board.h"

class MyGame {
  private:
   Board GameBoard;

  public:
   void start() { GameBoard = new Board }
};

int main() {

   MyGame Game;
   Game.start();
   return 0;
}
