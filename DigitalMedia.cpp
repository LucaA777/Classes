#include <iostream>
#include <cstring>
#include "DigitalMedia.h"

using namespace std;

DigitalMedia::DigitalMedia() {
  title = new char[80];
  year = 0;
}

void DigitalMedia::setTitle(char* newTitle) {
  title = new char[80];
  strcpy(title, newTitle);
}

void DigitalMedia::setYear(int newYear) {
  year = newYear;
}

char* DigitalMedia::getTitle() {
  return title;
}

int DigitalMedia::getYear() {
  return year;
}
