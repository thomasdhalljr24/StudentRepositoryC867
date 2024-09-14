#ifndef roster_h
#define roster_h

#define GREEN "\033[1;32m"
#define RESET "\033[0m"
#define BLUE "\033[1;34m"

#include <iostream>
#include "student.h"

using namespace std;

class Roster{
  public:
  Student* classRoster[5] = {nullptr, nullptr, nullptr, nullptr, nullptr};
  void add(string studentID, string firstName, string lastName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
  void remove(string studentID);
  void printAll();
  void printAverageDaysInCourse(string studentID);
  void printInvalidEmails();
  void printByDegreeProgram(DegreeProgram degreeProgram);
  void parseClass(string students);

  //Helper function
string degreeToString(DegreeProgram degree);

  int ind = -1;

  //Destructor
  ~Roster();
};
#endif
