#pragma once
#include <string>

using namespace std;

class Video {
  protected:
   int id;
   string name;
   string genre;
   float duration;
   int votes = 0;
   float rating = 0;

  public:
   Video(const int& id, const string& name, const string& genre,
         const float& duration);
   virtual bool isMovie() const = 0;
   string getName() const;
   string getGenre() const;
   float getDuration() const;
   float getRating() const;
   void addRating(const float& rate);
   int getId() const;

   void operator++();  // when used it will add a 5 star rating to the video
};
