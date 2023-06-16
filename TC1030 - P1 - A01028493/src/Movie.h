#pragma once
#include "Video.h"

class Movie : public Video {
  public:
   Movie(const int& id, const string& name, const string& genre,
         const float& duration);

   bool isMovie() const override;
};
