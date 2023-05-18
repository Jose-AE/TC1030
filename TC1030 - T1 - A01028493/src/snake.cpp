#include "Classes/Board.h"
#include "Classes/Player.h"

class MyGame {

  public:
   void start() {
      Board MyBoard;
      Player players[2];

      bool firstTurn = true;
      while (true) {

         string input;
         cout << (firstTurn
                      ? "Press C to continue next turn, or E to end the game:"
                      : ":");
         cin >> input;

         cout << input;
         if (input != "c" || input != "C" || input != "e" || input != "E") {
            cout << "Invalid option, please press C to continue next turn or E "
                    "to end the game"
                 << endl;
         }
      }

      MyBoard.print();
   }
};

int main() {

   MyGame Game;
   Game.start();
   return 0;
}
