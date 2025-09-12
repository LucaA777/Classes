#include <iostream>
#include <cstring>
#include "Music.h"

using namespace std;

Music::Music(char* nTitle, char* nArtist, int nYear, float nDuration, char* nPublisher):DigitalMedia(nTitle, nYear) {
  title = new char[80];
  strcpy(title, nTitle);

  artist = new char[80];
  strcpy(artist, nArtist);

  year = nYear;

  duration = nDuration;

  publisher = new char[80];
  strcpy(publisher, nPublisher);
}

void Music::printAll() {
  cout << title << ", " << artist << ", " << year << ", " << duration << ", " << publisher << "." << endl;
}

