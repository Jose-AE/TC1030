#include <chrono>
#include <thread>
#include "Classes/Board.h"
#include "Classes/Dice.h"
#include "Classes/Player.h"

using namespace std;

class MyGame {

   void clearConsole() {
      for (int i = 0; i < 100; i++) {
         cout << endl;
      }
   }

  public:
   void start() {
      Dice GameDice;
      Board GameBoard;
      Player players[2];

      int turn = 44;
      bool firstTurn = true;

      while (true) {

         if (turn > 50) {
            cout << "The maximum number of turns has been reached...";
            break;
         }

         GameBoard.print();

         string input;
         while (true) {

            cout
                << (firstTurn
                        ? "Press C to continue next turn, or E to end the game:"
                        : ((turn + 1) % 2 == 0 ? "P2 turn: " : "P1 turn: "));

            cin >> input;

            if (input != "c" && input != "C" && input != "e" && input != "E") {
               cout << "Invalid option, please press C to continue next turn "
                       "or E "
                       "to end the game"
                    << endl;
               continue;
            } else {
               firstTurn = false;
               break;
            }
         }
         if (input == "C" || input == "c") {
            clearConsole();
            turn += 1;
            int roll = GameDice.roll();
            int tile = GameBoard.movePlayerBy(roll, turn % 2 == 0 ? 1 : 0);
            this_thread::sleep_for(chrono::seconds(1));
            clearConsole();

            if (tile == BOARD_SIZE - 1) {
               cout << "-- GAME OVER --";
               cout << (turn % 2 == 0 ? "P2 WINS!" : "P1 WINS!");
               break;
            }

         } else {
            clearConsole();
            break;
         }
      }
      cout << "Thanks for playing!!!";
   }
};

int main() {

   MyGame Game;
   Game.start();
   return 0;
}
