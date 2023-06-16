#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Episode.h"
#include "Movie.h"

using namespace std;

vector<Video*> videos;

void clearConsole() {
   for (int i = 0; i < 100; i++) {
      cout << endl;
   }
}

void printSelectVideo() {
   string index;

   while (true) {
      cout << "Enter the id of the video you want to select [0 to return]\n";
      cin >> index;
      if (index == "0") {
         return;
      }
      try {
         if (stoi(index) > 0 && stoi(index) <= videos.size()) {
            break;
         } else {
            throw "Invalid index";
         }

      } catch (...) {
         cout << "Invalid input\n";
      }
   }

   clearConsole();
   string input;
   cout << "[1]Rate it\n[2]Watch it \n[0]Return\n ";
   cin >> input;
   clearConsole();
   if (input == "1") {
      string score;

      while (true) {
         cout << "Enter rating (1-5)\n";
         cin >> score;
         try {
            if (stof(score) > 0 && stof(score) <= 5) {
               videos[stoi(index)]->addRating(stof(score));

               break;
            } else {
               throw "Invalid rating";
            }

         } catch (...) {
            cout << "Invalid rating\n";
         }
      }
      cout << "Rated the video successfully!\n\n\n";
      system("pause");
      return;

   } else if (input == "2") {
      clearConsole();
      cout << "You watch the video\n\n\n";
      system("pause");
      return;

   } else {
      return;
   }
}

void selectGenre() {
   string input;
   cout << "[1]Action\n[2]Comedy \n[3]Mystery\n[4]Drama\n[0]Return\n ";
   cin >> input;

   string filter =
       input == "1"
           ? "Action"
           : (input == "2" ? "Comedy"
                           : (input == "3" ? "Mystery"
                                           : (input == "4" ? "Drama" : "NA")));
   clearConsole();
   if (filter != "NA") {
      cout << "-----------Filter: " << filter << "---------\n";
      for (auto video : videos) {

         if (video->isMovie() && video->getGenre() == filter) {
            cout << "<" << video->getId() << ">" << endl;
            cout << "[" << video->getName() << "]" << endl;
            cout << "Rating:" << video->getRating() << "/5" << endl;
            cout << "Genre:" << video->getGenre() << endl;
            cout << "Duration:" << video->getDuration() << "m\n\n";
         } else if (video->getGenre() == filter) {
            Episode* episode = dynamic_cast<Episode*>(video);
            cout << "<" << episode->getId() << ">" << endl;
            cout << "[" << episode->getName() << "]";
            cout << "(" << episode->getEpName() << ")" << endl;
            cout << "Rating:" << episode->getRating() << "/5" << endl;
            cout << "Genre:" << episode->getGenre() << endl;
            cout << "Duration:" << episode->getDuration() << "m\n\n";
         }
      }
      printSelectVideo();

   } else {
      return;
   }
}

void selectDuration() {
   string input;
   cout << "[1]More than 120 min\n[2]Less than 120 min\n[0] Return\n ";
   cin >> input;

   string filter = input == "1" ? "more" : (input == "2" ? "less" : "NA");
   clearConsole();
   if (filter != "NA") {
      cout << "-----------Filter: "
           << (filter == "more" ? "More than 120 min" : "Less than 120min")
           << "---------\n";
      for (auto video : videos) {

         if (video->isMovie() &&
             ((filter == "more" && video->getDuration() > 120.0) ||
              (filter == "less" && video->getDuration() < 120.0))) {
            cout << "<" << video->getId() << ">" << endl;
            cout << "[" << video->getName() << "]" << endl;
            cout << "Rating:" << video->getRating() << "/5" << endl;
            cout << "Genre:" << video->getGenre() << endl;
            cout << "Duration:" << video->getDuration() << "m\n\n";
         } else if ((filter == "more" && video->getDuration() > 120.0) ||
                    (filter == "less" && video->getDuration() < 120.0)) {
            Episode* episode = dynamic_cast<Episode*>(video);
            cout << "<" << episode->getId() << ">" << endl;
            cout << "[" << episode->getName() << "]";
            cout << "(" << episode->getEpName() << ")" << endl;
            cout << "Rating:" << episode->getRating() << "/5" << endl;
            cout << "Genre:" << episode->getGenre() << endl;
            cout << "Duration:" << episode->getDuration() << "m\n\n";
         }
      }
      printSelectVideo();

   } else {
      return;
   }
}

void printHome() {
   clearConsole();
   cout << "[1]Filter by genre\n[2]Filter by duration\n[3]Browse all "
           "videos\n[0]Exit\n";
   string input;
   cin >> input;
   if (input == "1") {
      clearConsole();
      selectGenre();

   } else if (input == "2") {
      clearConsole();
      selectDuration();
   } else if (input == "3") {
      clearConsole();
      for (auto& video : videos) {

         if (video->isMovie()) {
            cout << "<" << video->getId() << ">" << endl;
            cout << "[" << video->getName() << "]" << endl;
            cout << "Rating:" << video->getRating() << "/5" << endl;
            cout << "Genre:" << video->getGenre() << endl;
            cout << "Duration:" << video->getDuration() << "m\n\n";
         } else {
            Episode* episode = dynamic_cast<Episode*>(video);
            cout << "<" << episode->getId() << ">" << endl;
            cout << "[" << episode->getName() << "]";
            cout << "(" << episode->getEpName() << ")" << endl;
            cout << "Rating:" << episode->getRating() << "/5" << endl;
            cout << "Genre:" << episode->getGenre() << endl;
            cout << "Duration:" << episode->getDuration() << "m\n\n";
         }
      }

      cout << "\n\n\n\n";

      printSelectVideo();
   } else {
      exit(0);
   }
}

int main() {

   // generate and populate vector
   string line, word;
   fstream file("test.csv", ios::in);
   if (file.is_open()) {

      try {
         while (getline(file, line)) {
            vector<string> columns;
            stringstream str(line);
            while (getline(str, word, ',')) {
               columns.push_back(word);
            }

            if (columns[4] == "NA") {
               videos.push_back(new Movie(stoi(columns[0]), columns[1],
                                          columns[2], stof(columns[3])));
            } else {
               videos.push_back(new Episode(stoi(columns[0]), columns[1],
                                            columns[2], stof(columns[3]),
                                            columns[4]));
            }
         }
         while (true) {
            ++(*videos[0]);  // give the first video a rating of 5 to showcase
                             // ++ overloading
            printHome();
         }

      } catch (...) {
         cout << "-------------------------------------------------------------"
                 "-----------\n";
         cout << "Error reading csv, file might have incorrect format or be "
                 "corrupt\n";
         cout << "Make sure the columns are as follows:\n";
         cout << "[Id(int)][Name][Genre][Duartion(float)][Ep name(NA if "
                 "movie)]\n";
         cout << "-------------------------------------------------------------"
                 "-----------";
      }

   } else {
      cout << "Could not open the file\n";
   }

   return 0;
}
