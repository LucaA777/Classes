#include <iostream>

#ifndef MUSIC_H
#define MUSIC_H
#include "DigitalMedia.h"
#endif

using namespace std;

class Music : public DigitalMedia {
 public:
  Music(char* nTitle, char* nArtist, int nYear, float nDuration, char* nPublisher);
  virtual void printAll();

  //the following three functions aren't used but are required by the assignment
  char* getArtist();
  float getDuration();
  char* getPublisher();
private:
  char* artist;
  float duration;
  char* publisher;

};
