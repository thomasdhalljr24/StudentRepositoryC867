#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <vector>

#include "degree.h"
using namespace std;

class Student {
  public:
    const int DAYS_NUM_VECTOR = 3;

    //Setters
    void setId(string id);
    void setFirstName(string first);
    void setLastName(string last);
    void setAge(int age);
    void setEmail(string email);
    void setDaysToComplete(int days_left_courses[]);
    void setDegreeProgram(DegreeProgram degreeProgram);
    
    //Getters
    string getId() const;
    string getFirstName() const;
    string getLastName() const;
    int getAge() const;
    string getEmail() const;
    int getDaysInClass1() const;
    int getDaysInClass2() const;
    int getDaysInClass3() const;
    DegreeProgram getDegree() const;
    int* getCourseDayArray() const;
    
    //Constructor
    Student(string id, string first, string last, string email, int age, int daysInClasses[], DegreeProgram degree);

    //Print functions
    void print();
    void printFirst();
    void printLast();
    void printAge();
    void printEmail();
    void printsDaysInClasses();
    void printDegree();
    void printMyName();

    //Destructor
    ~Student();

  //Private variables & Default constructor
  private:
    string student_id = "";
    string first_name = "Unknown";
    string last_name = "Unknown";
    int student_age = 2000;
    string email_address = "123@noemail.com";
    int days_to_complete_courses[3] = {-1,-1,-1};
    DegreeProgram degree_program = UNDECIDED;
    




};
#endif