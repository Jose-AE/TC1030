#include <iostream>
#include <typeinfo>
#include <vector>
#include "Episode.h"
#include "Movie.h"
#include "Series.h"

using namespace std;

void clearConsole() {
   for (int i = 0; i < 100; i++) {
      cout << endl;
   }
}

int main() {

   vector<Series*> series{
       new Series(5, "Bob Serie", "Action", 1, 5,
                  vector<Episode*>{new Episode("Ep Name", 2.5, 3),
                                   new Episode("Ep 2", 3.0, 4),
                                   new Episode("Ep 3", 2.8, 3),
                                   new Episode("Ep 4", 3.2, 4),
                                   new Episode("Ep 5", 2.7, 3)}),
       new Series(7, "Sci-Fi Show", "Sci-Fi", 2, 4.5,
                  vector<Episode*>{new Episode("Pilot", 1.5, 4),
                                   new Episode("Episode 2", 1.7, 4),
                                   new Episode("Episode 3", 1.8, 4),
                                   new Episode("Episode 4", 2.0, 4),
                                   new Episode("Season Finale", 1.9, 4)}),
       new Series(3, "Drama Series", "Drama", 1.5, 4.2,
                  vector<Episode*>{new Episode("Episode 1", 1.5, 4),
                                   new Episode("Episode 2", 1.6, 4),
                                   new Episode("Episode 3", 1.7, 4),
                                   new Episode("Episode 4", 1.8, 4),
                                   new Episode("Episode 5", 1.9, 4)})};

   vector<Movie*> movies{new Movie(5, "Bob Movie", "Action", 1.5, 5),
                         new Movie(2, "Comedy Film", "Comedy", 2.0, 4.2),
                         new Movie(8, "Thriller Movie", "Thriller", 1.8, 4.5),
                         new Movie(4, "Romantic Movie", "Romance", 1.7, 4.3),
                         new Movie(6, "Sci-Fi Movie", "Sci-Fi", 2.5, 4.7)};

   while (true) {
      clearConsole();
      cout << "[1]-Show all videos (Movies & Episodes)\n[2]-Show episodes of "
              "specific "
              "series\n[3]-Show "
              "movies\n";
      string input;
      cin >> input;

      if (input == "1") {
         clearConsole();
         // Mostrar los videos en general con sus calificaciones

         cout << "--------------Movies------------\n";
         for (auto& movie : movies) {

            cout << "[" << movie->getName() << "]" << endl;
            cout << "Rating:" << movie->getRating() << "*" << endl;
            cout << "Genre:" << movie->getGenre() << endl;
            cout << "Duration:" << movie->getDuration() << "h\n\n";
         }

         cout << "--------------Episodes------------\n";
         for (auto& series : series) {
            for (auto& episode : series->getEpisodes()) {
               cout << "[" << series->getName() << "]"
                    << "(" << episode->getName() << ")" << endl;
               cout << "Rating:" << episode->getRating() << "*" << endl;
               cout << "Duration:" << episode->getDuration() << "h\n\n";
            }
         }
         cout << "\n\n\n\n";
         system("pause");

      } else if (input == "2") {

         int index;

         while (true) {
            clearConsole();
            cout << "Input series index\n";
            for (int i = 0; i < series.size(); i++) {
               cout << "[" << i << "] " << series[i]->getName() << endl;
            }

            try {

               cin >> input;
               index = stoi(input);

               if (index <= series.size() && index >= 0) {
                  break;
               }

            } catch (invalid_argument e1) {
            }
         }
         clearConsole();
         cout << "-------------" << series[index]->getName() << "'s Episodes"
              << "-------------\n";
         for (auto& episode : series[index]->getEpisodes()) {

            cout << "[" << episode->getName() << "]" << endl;
            cout << "Rating:" << episode->getRating() << "*" << endl;
            cout << "Duration:" << episode->getDuration() << "h\n\n";
         }

         cout << "\n\n\n\n";
         system("pause");

      } else if (input == "3") {
         clearConsole();
         cout << "--------------Movies------------\n";
         for (auto& movie : movies) {
            cout << "[" << movie->getName() << "]" << endl;
            cout << "Rating:" << movie->getRating() << "*" << endl;
            cout << "Genre:" << movie->getGenre() << endl;
            cout << "Duration:" << movie->getDuration() << "h\n\n";
         }

         cout << "\n\n\n\n";
         system("pause");
      }
   }

   return 0;
}
