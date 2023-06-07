#pragma once
#include <vector>
#include "Episode.h"
#include "Video.h"
using namespace std;

class Series : public Video {
  private:
   vector<Episode*> episodes;

  public:
   Series(const int& id, const string& name, const string& genre,
          const float& duration, const int& rating,
          const vector<Episode*> episodes)
       : Video(id, name, genre, duration, rating), episodes(episodes) {}

   vector<Episode*> getEpisodes() { return episodes; }
};
