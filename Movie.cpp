#include <iostream>
#include <cstring>
#include "Movie.h"

using namespace std;

Movie::Movie(char* nTitle, char* nDirector, int nYear, float nDuration, float nRating):DigitalMedia(nTitle, nYear) {
  title = new char[80];
  strcpy(title, nTitle);

  director = new char[80];
  strcpy(director, nDirector);

  year = nYear;

  duration = nDuration;

  rating = nRating;
}

void Movie::printAll() {
  cout << title << ", " << director << ", " << year << ", " << duration << ", " << rating << "." << endl;
}

char* Movie::getDirector() {
  return director;
}

float Movie::getDuration() {
  return duration;
}

float Movie::getRating() {
  return rating;
}
