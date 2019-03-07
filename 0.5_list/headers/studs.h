#include "Student.h"

#ifndef STUDS_H
#define STUDS_H

struct Studs{
    list<Student> students;
    int longestName = 12;
    int longestLastName = 12;
    bool string_is_valid(const string x);
    void readFileData(const char input[]);
    void sortStudents();
    void printResult();
    void inputData();
    void checkLongestNames();
    bool checkFile(const char *filename);
    bool isNumber(const std::string& s);
    void generateLists(int n);
    void sortByMarks();
};

#endif //STUDS_H