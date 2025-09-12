#include <iostream>

#ifndef DIGITALMEDIA_H
#define DIGITALMEDIA_H

using namespace std;

class DigitalMedia {
 public:
  DigitalMedia(char* nTitle, int nYear);
  virtual void printAll();
  char* getTitle();
  int getYear();
 protected:
  char* title;
  int year;
};

#endif
