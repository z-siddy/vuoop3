#include "main.h"

#ifndef STUDENT_H
#define STUDENT_H

struct Student{

    string firstName;
    string lastName;
    int examScore;
    vector<double > homework;
    double calculateScore();
    double median();
    void setName(string name);
    void setLastName(string lname);
    void setMark(double mark);
    void setExam(double exam);
    struct Comparison{
        bool operator()(Student * lhs, Student * rhs) {return lhs->firstName < rhs->firstName;}
    };
};

#endif //STUDENT_H