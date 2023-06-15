#include "Video.h"

Video::Video::Video(const int& id, const string& name, const string& genre,
                    const float& duration, const int& rating)
    : id(id), name(name), genre(genre), duration(duration), rating(rating) {}

string Video::getName() const { return name; }
string Video::getGenre() const { return genre; }
float Video::getDuration() const { return duration; }
float Video::getRating() const { return rating; }