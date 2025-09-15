/*
This program allows a user to create a database of various types of digital media.
They can add video games, music, and movies, each with their own attributes. The user
can then search the database for exact matches as well as delete items from the database.
  
Author: Luca Ardanaz
Last updated: 9/15/2025
 */


#include <iostream>
#include <cstring>
#include <vector>
#include "DigitalMedia.h"
#include "VideoGame.h"
#include "Music.h"
#include "Movie.h"

using namespace std;

//declares functions
void addMedia(vector<DigitalMedia*> &d);
void addVideoGame(vector<DigitalMedia*> &d);
void addMusic(vector<DigitalMedia*> &d);
void addMovie(vector<DigitalMedia*> &d);
vector<DigitalMedia*> searchMedia(vector<DigitalMedia*> &d);
void deleteMedia(vector<DigitalMedia*> &d);
void cinReset();

int main() {

  vector<DigitalMedia*> media;
  char* input = new char[80];

  //input loop. Asks for commands and processes them 
  do {
    cout << endl;
    
    //clears input errors
    if (cin.fail()) {
      cinReset();
    }

    //asks for command
    cout << "Enter command (ADD, SEARCH, DELETE, QUIT):" << endl;
    cin.get(input, 80);
    cin.get();

    //checks and runs commands
    if (strcmp(input, "ADD") == 0) {
      addMedia(media);
    }
    else if (strcmp(input, "SEARCH") == 0) {
      vector<DigitalMedia*> tempMedia = searchMedia(media);
    }
    else if (strcmp(input, "DELETE") == 0) {
      deleteMedia(media);
    }

  } while (cin.fail() || strcmp(input, "QUIT") != 0);
  
  cout << "Quitting program..." << endl;
  
  return 0;
}

void addMedia(vector<DigitalMedia*> &d) {
  char* input = new char[15];
  cout << endl;

  //asks for which kind of digital media to add.
  do {
    
    cout << "What type of digital media would you like to add (Video game, Music, Movie):" << endl;
    cin.get(input, 15);
    cinReset();
    
  } while (strcmp(input, "Video game") != 0 && strcmp(input, "Music") != 0 && strcmp(input, "Movie") != 0);

  //get input for video games
  if (strcmp(input, "Video game") == 0) {
    addVideoGame(d);
  }
  //get input for music
  else if (strcmp(input, "Music") == 0) {
    addMusic(d);
  }
  //get input for movies
  else if (strcmp(input, "Movie") == 0) {
    addMovie(d);
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
    
    cout << "Enter rating (0-5):" << endl;
    cin >> rating;
  } while (cin.fail() || rating < 0 || rating > 5);

  cin.get();
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

void addMovie(vector<DigitalMedia*> &d) {
  char* title;
  char* director;
  int year;
  float duration;
  int rating;
  
  
  cout << endl;
  
  //get title
  cout << "Enter the title:" << endl;
  title = new char[80];
  cin.get(title, 80);
  cin.get();
  
  
  //get director
  cout << "Enter the director:" << endl;
  director = new char[80];
  cin.get(director, 80);
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
    cout << "Enter the duration (minutes):" << endl;
    cin >> duration;
  } while (cin.fail() || duration <= 0);

  //get rating
  do {
    if (cin.fail()) {
      cinReset();
    }
    
    cout << "Enter rating (0-5):" << endl;
    cin >> rating;
  } while (cin.fail() || rating < 0 || rating > 5);
  
  cin.get();
  cout << endl;
  
  d.push_back(new Movie(title, director, year, duration, rating));
}

vector<DigitalMedia*> searchMedia(vector<DigitalMedia*> &d) {
  vector<DigitalMedia*> results;
  
  cout << endl;

  //if there isn't any media, return to main commands
  if (d.size() <= 0) {
    cout << "There is no media, please add media first." << endl;
    return results;
  }

  char* input = new char[10];
  int yearInput = 0;

  //ask whether the user wants to search by title or year
  do {
    if (cin.fail()) {
      cinReset();
    }
     
    cout << "Search by title or year? (Title, Year):" << endl;
    cin.get(input, 10);
    cin.get();
  } while (strcmp(input, "Title") != 0 && strcmp(input, "Year") != 0);

  bool isTitle = true;

  cout << endl;

  //gets the year (if they're searching by year)
  if (strcmp(input, "Year") == 0) {
    isTitle = false;

    do {
      if (cin.fail()) {
	cinReset();
      }
      cout << "Enter year:" << endl;
      cin >> yearInput;
    } while (cin.fail() || yearInput < 0);
    cin.get();
  }
  //gets the title (if they're searching by title)
  else {
    cout << "Enter title:" << endl;
    cin.get(input, 80);
    cin.get();
  }

  cout << endl;

 
  //prints all media that matches the search
  for (DigitalMedia* m : d) {
    //chooses whether its searching by title or year
    if (isTitle) {
      if (strcmp(m -> getTitle(), input) == 0) {
	m -> printAll();
	results.push_back(m);
      }
    }
    else {
      if (m -> getYear() == yearInput) {
	m -> printAll();
	results.push_back(m);
      }
    }
  }

  //if there are no results, tell the user
  if (results.size() < 1) {
    cout << "No stored media matched the search." << endl;
  }

  cout << endl;

  return results;

  
}

void deleteMedia(vector<DigitalMedia*> &d) {
  //search for all the results
  vector<DigitalMedia*> discardedMedia = searchMedia(d);

  //if there aren't any results, return to main commands
  if (discardedMedia.size() < 1) {
    return;
  }

  
  char* input = new char[2];
  //ask if the user wants to delete the media
  do {
    if (cin.fail()) {
      cinReset();
    }
    cout << "Are you sure you want to delete these? (y/n):" << endl;
    cin.get(input, 2);
    cin.get();
  } while (cin.fail() || (strcmp(input, "y") != 0 && strcmp(input, "n") != 0));

  //if they do, go through each item in the list to be discarded, remove it from the main vector and delete it
  if (strcmp(input, "y") == 0) {
    //for each discarded media, find it in the original vector and delete it
    for (int i = 0; i < discardedMedia.size(); i++) {
      for (int j = 0; j < d.size(); j++) {
	if (discardedMedia.at(i) == d.at(j)) {
	  delete d.at(j);
	  d.erase(d.begin() + j);
	  break;
	}
      }
      
    }

    cout << "Media deleted." << endl;
    return;
  }
  
  cout << "Cancelling deletion..." << endl;
}

void cinReset() {
  cin.clear();
  cin.ignore(10000, '\n');
}
