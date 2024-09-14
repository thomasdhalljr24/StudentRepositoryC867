#include <iostream>
#include "Roster.h"
#include <sstream>
#include <vector>

using namespace std;
//Adding student data to the roster
void Roster::add(string studentID, string firstName, string lastName, string email, int age, int days1, int days2, int days3, DegreeProgram degree) {
  int numberDays[] = {days1, days2, days3};
  classRoster[++ind] = new Student(studentID, firstName,lastName, email, age, numberDays, degree);
}
//Parsing the class roster based on the array in main
  void Roster::parseClass(string studentsList) {
    vector<string> tokens;
    DegreeProgram degree;
      stringstream ss(studentsList);

      while(ss.good()){
        string tempVal;
        getline(ss,tempVal,',');
        tokens.push_back(tempVal);
      }; 
      if(tokens.at(8) == "SOFTWARE"){
        degree = DegreeProgram::SOFTWARE;
      }
      if(tokens.at(8) == "NETWORK"){
        degree = DegreeProgram::NETWORK;
      }
      if(tokens.at(8) == "SECURITY"){
        degree = DegreeProgram::SECURITY;
      }
      if(tokens.at(8) == "UNDECIDED"){
          degree = DegreeProgram::UNDECIDED;
      }
      Roster::add(tokens.at(0),tokens.at(1),tokens.at(2),tokens.at(3),stoi(tokens.at(4)),stoi(tokens.at(5)),stoi(tokens.at(6)),stoi(tokens.at(7)), degree);
    } 
void Roster::printAll() {
  for (int i = 0; i < 5; ++i) {
    if (classRoster[i] != nullptr) {
      classRoster[i]->Student::print();
      cout << "\n";
    }
  }
}

void Roster::remove(string studentID) {
    bool found = false;

    cout << BLUE << "\nRemoving student record with student ID: " << RESET << studentID << endl;

    for (int k = 0; k < 5; ++k) {
        if (classRoster[k] == nullptr) {
            continue; // Skip to the next iteration if the slot is empty
        }

        if (studentID == classRoster[k]->Student::getId()) {
            delete classRoster[k]; // Deallocate memory if dynamically allocated
            classRoster[k] = nullptr;
            found = true;

            // Shift remaining students up
            for (int j = k; j < 4; ++j) { // Note: Loop runs till 4 to avoid out-of-bounds
                classRoster[j] = classRoster[j + 1];
            }
            classRoster[4] = nullptr; // Set the last element to nullptr
            std::cout << "Student removal successful \n" << std::endl;
            break; // Exit the function after successful removal
        }
    }

    if (!found) {
        cout << BLUE << "\n\nOh no! Student with ID " << RESET << studentID << BLUE << " was not located.\n" << RESET << std::endl;
    }
}
void Roster::printInvalidEmails(){
  for(int m = 0; m < 5; ++m) {
    if (classRoster[m] == nullptr) {
        continue; // Skip to the next iteration if the slot is empty
    }
    
    bool atSign = false;
    bool space = false;
    bool period = false;
    string studentEmail;
    
    studentEmail = classRoster[m]->Student::getEmail();
    for(char &charAt : studentEmail) {
      if(charAt == '@') {atSign = true;}
      if(charAt == ' '){space = true;}
      if(charAt == '.'){period = true;}
    } 
    if(atSign == false || space == true || period == false){
      cout << GREEN << "\nInvalid email: " << RESET << classRoster[m]->Student::getEmail();}
  }
}
string Roster::degreeToString(DegreeProgram degree) {
    switch(degree) {
        case SECURITY: return "SECURITY";
        case NETWORK: return "NETWORK";
        case SOFTWARE: return "SOFTWARE";
        default: return "UNDECIDED";
    }
}

void Roster::printByDegreeProgram(DegreeProgram degree) {
  cout << GREEN << "\n\nStudents with " << RESET << degreeToString(degree) << GREEN << " degree programs: " << RESET << endl;
  for (int i = 0; i < 5; ++i) {
    if (classRoster[i] != nullptr) {
      if (degree == classRoster[i]->Student::getDegree()) {
        classRoster[i]->Student::print();
      }
    }
  }
  std::cout << std::endl;
}

void Roster::printAverageDaysInCourse(string studentID) {
    bool found = false;
    cout << "Searching for student ID: " << studentID << endl;

    for(int f = 0; f < 5; ++f) {
        if (classRoster[f] == nullptr) {
            cout << "Slot " << f << " is empty" << endl;
            continue;
        }

        if(studentID == classRoster[f]->Student::getId()) {
            int* daysList = classRoster[f]->Student::getCourseDayArray();
            int avg = (daysList[0] + daysList[1] + daysList[2]) / 3;
            cout << GREEN << "Average days in course for student " << RESET << studentID << GREEN << ": " << RESET << avg << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student with ID " << studentID << " not found." << endl;
    }
}
Roster::~Roster() {
    cout << "Destructor called!" << std::endl << std::flush;
    for (int i = 0; i < 5; i++) {
        if (classRoster[i] != nullptr) {
            cout << "Deleting student #" << i + 1 << std::endl;
            delete classRoster[i];
            classRoster[i] = nullptr;
        }
    }
    cout << "Destructor finished!" << std::endl << std::flush;
}
