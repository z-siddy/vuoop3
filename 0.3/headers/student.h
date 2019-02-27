#include "main.h"

#ifndef STUDENT_H
#define STUDENT_H

struct Student{

    string firstName;
    string lastName;
    double examScore;
    vector<double > homework;

    double calculateScore();
    double median();
    void setName(string name);
    void setLastName(string lname);
    void setMark(double mark);
    void setExam(double exam);

};

#endif //STUDENT_H