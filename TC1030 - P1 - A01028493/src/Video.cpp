#include "Video.h"

Video::Video::Video(const int& id, const string& name, const string& genre,
                    const float& duration)
    : id(id), name(name), genre(genre), duration(duration), rating(rating) {}

string Video::getName() const { return name; }
string Video::getGenre() const { return genre; }
float Video::getDuration() const { return duration; }
float Video::getRating() const { return rating; }

void Video::addRating(const float& rate) {
   votes += 1;
   rating += rate / votes;
}

int Video::getId() const { return id; }

void Video::operator++() {
   votes += 1;
   rating += 5 / votes;
}