#include "Student.h"

#ifndef STUDS_H
#define STUDS_H

struct Studs{
    vector<Student > students;
    vector<Student > vargsiukai;
    vector<Student > kietekai;
    int longestName = 12;
    int longestLastName = 12;
    void readFileData(const char input[]);
    bool stringValidation(const string x);
    void sortStudents();
    void printResult();
    void inputData();
    void checkLongestNames();
    bool checkFile(const char *filename);
    void generateLists(int n);
    void sortByMarks();
};

#endif //STUDS_H