#include <iostream>
#include <cstring>
#include "DigitalMedia.h"

using namespace std;

DigitalMedia::DigitalMedia(char* nTitle, int nYear) {
  title = new char[80];
  strcpy(title, nTitle);
  year = nYear;
}

void DigitalMedia::setTitle(char* nTitle) {
  title = new char[80];
  strcpy(title, nTitle);
}

void DigitalMedia::setYear(int nYear) {
  year = nYear;
}

char* DigitalMedia::getTitle() {
  return title;
}

int DigitalMedia::getYear() {
  return year;
}
