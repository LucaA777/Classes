#include <iostream>
#include <cstring>
#include <vector>
#include "DigitalMedia.h"
#include "VideoGame.h"
#include "Music.h"

using namespace std;

void addMedia(vector<DigitalMedia*> &d);
void addVideoGame(vector<DigitalMedia*> &d);
void addMusic(vector<DigitalMedia*> &d);
void searchMedia(vector<DigitalMedia*> &d);
void cinReset();

int main() {

  vector<DigitalMedia*> media;
  char* input = new char[80];
  do {

    //proccesses inputs
    if (cin.fail()) {
      cinReset();
    }

    cout << "Enter command (ADD, SEARCH, DELETE, QUIT):" << endl;
    cin.get(input, 80);
    cin.get();

    //checks and runs commands
    if (strcmp(input, "ADD") == 0) {
      addMedia(media);
    }
    else if (strcmp(input, "SEARCH") == 0) {
      searchMedia(media);
    }
    else if (strcmp(input, "DELETE") == 0) {

    }

  } while (cin.fail() || strcmp(input, "QUIT") != 0);
  
  cout << "Quitting program..." << endl;
  
  return 0;
}

void addMedia(vector<DigitalMedia*> &d) {
  char* input = new char[15];
  cout << endl;
  
  do {
    cout << "What type of digital media would you like to add (Video game, Music, Movie):" << endl;
    cin.get(input, 15);
    cinReset();
  } while (strcmp(input, "Video game") != 0 && strcmp(input, "Music") != 0 && strcmp(input, "Movie") != 0);

  //get input for video games
  if (strcmp(input, "Video game") == 0) {
    addVideoGame(d);
  }
  else if (strcmp(input, "Music") == 0) {
    addMusic(d);
  }
}

void addVideoGame(vector<DigitalMedia*> &d) {

    char* title;
    int year;
    char* publisher;
    float rating;

    cout << endl;
    
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

    cout << endl;

    d.push_back(new VideoGame(title, year, publisher, rating));
}

void addMusic(vector<DigitalMedia*> &d) {

    char* title;
    char* artist;
    int year;
    float duration;
    char* publisher;
    

    cout << endl;
    
    //get title
    cout << "Enter the title:" << endl;
    title = new char[80];
    cin.get(title, 80);
    cin.get();

    
    //get artist
    cout << "Enter the artist:" << endl;
    artist = new char[80];
    cin.get(artist, 80);
    cin.get();
    
    //get year
    do {
      if (cin.fail()) {
	cinReset();
      }
      cout << "Enter the year:" << endl;
      cin >> year;
    } while (cin.fail() || year < 0);

    //get duration
    do {
      if (cin.fail()) {
	cinReset();
      }
      cout << "Enter the duration (seconds):" << endl;
      cin >> duration;
    } while (cin.fail() || duration <= 0);

    //get publisher
    cinReset();
    cout << "Enter the publisher:" << endl;
    publisher = new char[80];
    cin.get(publisher, 80);
    cin.get();

   
    cout << endl;

    d.push_back(new Music(title, artist, year, duration, publisher));
}

void searchMedia(vector<DigitalMedia*> &d) {
  cout << endl;
  
  if (d.size() <= 0) {
    cout << "There is no media, please add media first." << endl;
    return;
  }

  char* input = new char[10];
  int yearInput = 0;
  
  do {
    cinReset();
     
    cout << "Search by title or year? (Title, Year):" << endl;
    cin.get(input, 10);
    cin.get();
  } while (strcmp(input, "Title") != 0 && strcmp(input, "Year") != 0);

  bool isTitle = true;

  cout << endl;
  
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

  cout << endl;

  for (DigitalMedia* m : d) {
    //chooses whether its searching by title or year
    if (isTitle) {
      if (strcmp(m -> getTitle(), input) == 0) {
	m -> printAll();
      }
    }
    else {
      if (m -> getYear() == yearInput) {
	m -> printAll();
      }
    }
  }

  cout << endl;

  
}

void cinReset() {
  cin.clear();
  cin.ignore(10000, '\n');
}
