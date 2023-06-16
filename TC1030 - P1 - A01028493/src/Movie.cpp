#include "Movie.h"

Movie::Movie(const int& id, const string& name, const string& genre,
             const float& duration)
    : Video(id, name, genre, duration) {}

bool Movie::isMovie() const { return true; }