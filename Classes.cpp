#include <iostream>
#include <cstring>
#include "DigitalMedia.h"
#include "VideoGame.h"

using namespace std;

int main() {
  char* newTitle = new char[80];
  strcpy(newTitle, "TITLE");

  char* newPublisher = new char[80];
  strcpy(newPublisher, "Gregarious Games");
  
  VideoGame* d = new VideoGame(newTitle, 2025, newPublisher, 4.5f);

 


  cout << d -> getTitle() << endl;
  cout << d -> getYear() << endl;
  cout << d -> getPublisher() << endl;
  cout << d -> getRating() << endl;
  return 0;
}
