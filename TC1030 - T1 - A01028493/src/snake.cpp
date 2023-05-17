#include "Classes/Board.h"

class MyGame {

  public:
   void start() {
      Board MyBoard;
      MyBoard.print();
   }
};

int main() {

   MyGame Game;
   Game.start();
   return 0;
}
