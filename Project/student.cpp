#include <iostream>
#include <iomanip>
#include <vector>

#include "student.h"

#define BOLDRED "\033[1;31m"
#define RESET "\033[0m"


using namespace std;

//Setter defintions
void Student::setId(string id){
  id = student_id;
};
void Student::setFirstName(string first){
  first_name = first;
};
void Student::setLastName(string last){
  last_name = last;
};
void Student::setAge(int age){
  student_age = age;
};
void Student::setEmail(string email){
  email_address = email;
};
void Student::setDaysToComplete(int days_left_courses[]){
  for(int i = 0; i < DAYS_NUM_VECTOR; ++i){
    days_to_complete_courses[i] = days_left_courses[i];
  }
};
void Student::setDegreeProgram(DegreeProgram degreeProgram){
    degreeProgram = degree_program;
};

//Getter defintions
string Student::getId() const{
  return student_id;
};
string Student::getFirstName() const{
  return first_name;
};
string Student::getLastName() const{
  return last_name;
};
int Student::getAge()const{
  return student_age;
};
string Student::getEmail() const{
  return email_address;
};
int Student::getDaysInClass1() const{
  return days_to_complete_courses[0];
};
int Student::getDaysInClass2() const{
  return days_to_complete_courses[1];
};
int Student::getDaysInClass3() const{
  return days_to_complete_courses[2];
};
DegreeProgram Student::getDegree()const{
  return degree_program;
};

int* Student::getCourseDayArray() const {
    int* list = new int[3];  // Dynamically allocate an array of 3 integers
    for(int i = 0; i < 3; ++i) {
        list[i] = days_to_complete_courses[i];  // Copy values from the original array
    }
    return list;  // Return the pointer to the array
}

//Constructor
Student::Student(string id, string first, string last, string email, int age, int daysInClasses[], DegreeProgram degree){
  student_id = id;
  first_name = first;
  last_name = last;
  student_age = age;
  email_address = email;
  for(int i = 0; i < DAYS_NUM_VECTOR; ++i){
    days_to_complete_courses[i] = daysInClasses[i];
  }
  degree_program = degree;
};

//Print All Function
void Student::print(){
    cout << getId() << "\t" << BOLDRED << "First Name: " << RESET << getFirstName() << "\t" << BOLDRED << " Last Name: " << RESET << getLastName() << "\t" << BOLDRED << " Age: " << RESET << getAge() << "\t" <<  BOLDRED <<" Email Address: " << RESET << getEmail() << "\t" << BOLDRED << " daysInCourse: " << RESET << "{" << getDaysInClass1() <<", " << getDaysInClass2() << ", " << getDaysInClass3() << "}";  
      
  string degreeString = "";
      switch (degree_program) {
        case DegreeProgram::SECURITY:
          degreeString = "SECURITY";
          break;
        case DegreeProgram::NETWORK:
          degreeString = "NETWORK";
          break;
        case DegreeProgram::SOFTWARE:
          degreeString = "SOFTWARE";
          break;
          case DegreeProgram::UNDECIDED:
          degreeString = "UNDECIDED";
          break;
      };
  
    cout << "\t" <<  BOLDRED << " Degree Program: " << RESET << degreeString << endl;
};

//Printing individual attributes
void Student::printFirst(){
  cout << first_name << endl;
};
void Student::printLast(){
  cout << last_name << endl;
};
void Student::printAge(){
  cout << student_age << endl;
};
void Student::printEmail(){
  cout << email_address << endl;
};
void Student::printsDaysInClasses(){
  for(int i = 0; i < DAYS_NUM_VECTOR; ++i){
    cout << days_to_complete_courses[i] << endl;
  }
};
void Student::printDegree(){
  cout << degree_program << endl;
};

//Destructor
Student::~Student(){
  cout << "\nStudent deleted\n\n";
}
