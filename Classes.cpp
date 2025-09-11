#include <iostream>
#include <cstring>
#include <vector>
#include "DigitalMedia.h"
#include "VideoGame.h"

using namespace std;

void addMedia(vector<DigitalMedia*> &d);
void searchMedia(vector<DigitalMedia*> &d);
void cinReset();

int main() {

  vector<DigitalMedia*> media;
  searchMedia(media);
  addMedia(media);
  searchMedia(media);
  
  /*
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
  */
}

void addMedia(vector<DigitalMedia*> &d) {
  char* input = new char[15];
  do {
    cout << "What type of digital media would you like to add (Video game, Music, Movie):" << endl;
    cin.get(input, 15);
    cinReset();
  } while (strcmp(input, "Video game") != 0 && strcmp(input, "Music") != 0 && strcmp(input, "Movie") != 0);

  //get input for video games
  if (strcmp(input, "Video game") == 0) {

    char* title;
    int year;
    char* publisher;
    float rating;

    //get title
    cout << "Enter the title:" << endl;
    title = new char[80];
    cin.get(title, 80);
    cin.get();

    //get year
    do {
      if (cin.fail()) {
	cinReset();
      }
      cout << "Enter the year:" << endl;
      cin >> year;
    } while (cin.fail() || year < 0);

    //get publisher
    cinReset();
    cout << "Enter the publisher:" << endl;
    publisher = new char[80];
    cin.get(publisher, 80);
    cin.get();

    //get rating
    do {
      if (cin.fail()) {
        cinReset();
      }

      cout << "Enter rating:" << endl;
      cin >> rating;
    } while (cin.fail() || rating < 0 || rating > 5);
 

    d.push_back(new VideoGame(title, year, publisher, rating));
  }
}

void searchMedia(vector<DigitalMedia*> &d) {
  if (d.size() <= 0) {
    cout << "There is no media, please add media first." << endl;
    return;
  }

  char* input = new char[10];
  int yearInput = 0;
  
  do {
    if (cin.fail()) {
      cinReset();
    }
    cout << "Search by title or year? (Title, Year):" << endl;
    cin.get(input, 10);
    cin.get();
  } while (strcmp(input, "Title") != 0 && strcmp(input, "Year") != 0);

  bool isTitle = true;
  if (strcmp(input, "Year") == 0) {
    isTitle = false;

    do {
      if (cin.fail()) {
	cinReset();
      }
      cout << "Enter year:" << endl;
      cin >> yearInput;
    } while (cin.fail() || yearInput < 0);
  }
  else {
    cout << "Enter title:" << endl;
    cin.get(input, 80);
    cin.get();
  }
  

  

  vector<DigitalMedia*> matches;
  for (DigitalMedia* m : d) {
    //chooses whether its searching by title or year
    if (isTitle) {
      if (strcmp(m -> getTitle(), input) == 0) {
	matches.push_back(m);
      }
    }
    else {
      if (m -> getYear() == yearInput) {
	matches.push_back(m);
      }
    }
  }

  
}

void cinReset() {
  cin.clear();
  cin.ignore(10000, '\n');
}
