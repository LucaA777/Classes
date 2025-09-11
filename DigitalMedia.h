#include <iostream>

#ifndef DIGITALMEDIA_H
#define DIGITALMEDIA_H

using namespace std;

class DigitalMedia {
 public:
  DigitalMedia(char* nTitle, int nYear);
  void setTitle(char* nTitle);
  void setYear(int nYear);
  int getYear();
  char* getTitle();
 protected:
  char* title;
  int year;
};

#endif
