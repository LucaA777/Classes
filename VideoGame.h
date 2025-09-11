#include <iostream>

#ifndef VIDEOGAME_H
#define VIDEOGAME_H
#include "DigitalMedia.h"
#endif

using namespace std;

class VideoGame : public DigitalMedia{
 public:
  VideoGame(char* nTitle, int nYear, char* nPublisher, float nRating);
  char* getPublisher();
  float getRating();
 private:
  char* publisher;
  float rating;
};
