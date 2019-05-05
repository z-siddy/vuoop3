#include "Student.h"

#ifndef STUDS_H
#define STUDS_H

class Studs {
private:
    vector<Student > students;
    vector<Student > vargsiukai;
    vector<Student > kietekai;
    int longestName = 12;
    int longestLastName = 12;
public:
    void addStudent(Student student);
    void addKietekas(Student student);
    void addVargsiukas(Student student);
    void checkLongestName(Student &student);
    void sortStudents();
    void readData(const char data[]);
    void inputData();
    void generateLists(int num, int marks);
    void clearStudents();
    void groupStudents();
    void printResult();
    void outputCreate();
    bool stringValidation(const string x);
    Student getRandomStudent();
    //Studs();
};

#endif //STUDS_H