#pragma once
#include <vector>
#include "Episode.h"
#include "Video.h"
using namespace std;

class Episode : public Video {
  private:
   string epName;

  public:
   Episode(const int& id, const string& name, const string& genre,
           const float& duration, const string& epName);

   bool isMovie() const override;

   string getEpName() const;
};
