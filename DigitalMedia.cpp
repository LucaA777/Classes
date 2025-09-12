#include <iostream>
#include <cstring>
#include "DigitalMedia.h"

using namespace std;

DigitalMedia::DigitalMedia(char* nTitle, int nYear) {
  title = new char[80];
  strcpy(title, nTitle);
  year = nYear;
}

void DigitalMedia::printAll() {
  cout << title << ", " << year << "." << endl;
}

char* DigitalMedia::getTitle() {
  return title;
}

int DigitalMedia::getYear() {
  return year;
}
