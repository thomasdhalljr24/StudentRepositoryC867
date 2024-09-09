#include <iostream>

#include "student.h"
#include "Roster.h"

using namespace std;

int main() { 

  cout << "Scripting and Programming - Applications – C867" << endl;
  cout << "Language: C++" << endl;
  cout << "Thomas Hall - 011171933 \n\n " << endl;
  
  const string studentData[] = {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Thomas,Hall,thal579@wgu.edu,24,10,5,25,SOFTWARE"};

  Roster classRoster;

  for (int i = 0; i < 5; ++i) {
    classRoster.parseClass(studentData[i]);
  }

  classRoster.printAll();

  cout << "INVALID EMAILS: ";
  classRoster.printInvalidEmails();

  classRoster.printByDegreeProgram(SOFTWARE);

  classRoster.remove("A3");

  classRoster.printAll();

  classRoster.remove("A3");

  classRoster.~Roster();
}