#include <chrono>
#include <thread>
#include "Classes/Board.h"
#include "Classes/Dice.h"

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

      int turn = 0;
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
            int prevTile = GameBoard.getPlayerTile(turn % 2 == 0 ? 1 : 2);
            turn += 1;
            int roll = GameDice.roll();
            int tile = GameBoard.movePlayerBy(roll, turn % 2 == 0 ? 1 : 0);
            this_thread::sleep_for(chrono::seconds(1));
            clearConsole();

            if (tile == BOARD_SIZE - 1) {
               cout << "-- GAME OVER --" << endl;
               cout << (turn % 2 == 0 ? "Player 2 is the winner!!!"
                                      : "Player 1 is the winner!!!");
               break;
            }

            cout << "Turn: " << turn << endl;
            cout << "Player: " << (turn % 2 == 0 ? 2 : 1) << endl;
            cout << "Was in tile: " << prevTile + 1 << endl;
            cout << "Dice rolled: " << roll << endl;
            cout << "Got to a tiile with: "
                 << GameBoard.getTile(prevTile + roll) << endl;
            cout << "Ended up in tile: " << tile + 1 << endl;

            cout << "Turn abbreviation: " << turn << (turn % 2 == 0 ? 2 : 1)
                 << prevTile + 1 << roll << GameBoard.getTile(prevTile + roll)
                 << tile + 1 << endl;

         } else {
            clearConsole();
            break;
         }
      }
      cout << "\nThanks for playing!!!";
      string temp;
      cin >> temp;
   }
};

int main() {

   MyGame Game;
   Game.start();
   return 0;
}
