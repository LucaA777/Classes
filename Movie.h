#include <iostream>

#ifndef MOVIE_H
#define MOVIE_H
#include "DigitalMedia.h"
#endif

using namespace std;

class Movie : public DigitalMedia {
 public:
  Movie(char* nTitle, char* nDirector, int nYear, float nDuration, float nRating);
  virtual void printAll();

 private:
  char* director;
  float duration;
  float rating;
};
