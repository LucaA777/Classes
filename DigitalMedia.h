#include <iostream>

using namespace std;

class DigitalMedia {
 public:
  DigitalMedia();
  void setTitle(char* newTitle);
  void setYear(int newYear);
  int getYear();
  char* getTitle();
 protected:
  char* title;
  int year;
};
