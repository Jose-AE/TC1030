
#include "Episode.h"
using namespace std;

Episode::Episode(const int& id, const string& name, const string& genre,
                 const float& duration, const string& epName)
    : Video(id, name, genre, duration), epName(epName) {}

bool Episode::isMovie() const { return false; }

string Episode::getEpName() const { return epName; }