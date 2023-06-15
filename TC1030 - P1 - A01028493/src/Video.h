#pragma once
#include <string>

using namespace std;

class Video {
  protected:
   int id;
   string name;
   string genre;  // drama, acción, misterio).
   float duration;
   int votes = 0;

   float rating = 0;  // rating +new rate/votes

  public:
   Video(const int& id, const string& name, const string& genre,
         const float& duration, const int& rating);

   string getName() const;
   string getGenre() const;
   float getDuration() const;
   float getRating() const;
};
