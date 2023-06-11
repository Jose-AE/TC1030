#pragma once
#include <string>

using namespace std;

class Video {
  protected:
   int id;
   string name;
   string genre;  // drama, acción, misterio).
   float duration;
   float rating = 0;

  public:
   Video(const int& id, const string& name, const string& genre,
         const float& duration, const int& rating)
       : id(id), name(name), genre(genre), duration(duration), rating(rating) {}

   string getName() const { return name; }

   string getGenre() const { return genre; }

   float getDuration() const { return duration; }

   float getRating() const { return rating; }
};
