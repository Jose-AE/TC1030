#pragma once
#include <string>

using namespace std;

class Episode {
  private:
   int rating = 0;
   string name;
   float duration;

  public:
   Episode(const string& name, const float& duration, const int& rating)
       : name(name), duration(duration), rating(rating) {}

   string getName() { return name; }
   int getRating() { return rating; }
   int getDuration() { return duration; }
};
