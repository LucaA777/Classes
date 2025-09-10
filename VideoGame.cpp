#include <iostream>
#include <cstring>
#include "VideoGame.h"

using namespace std;


VideoGame::VideoGame(char* nTitle, int nYear, char* nPublisher, float nRating):DigitalMedia() {
  title = new char[80];
  strcpy(title, nTitle);

  year = nYear;

  publisher = new char[80];
  strcpy(publisher, nPublisher);

  rating = nRating;
}

char* VideoGame::getPublisher() {
  return publisher;
}

float VideoGame::getRating() {
  return rating;
}
