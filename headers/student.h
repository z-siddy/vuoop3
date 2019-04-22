#include "main.h"

#ifndef STUDENT_H
#define STUDENT_H


class Student {
private:
  std::string firstName_;
  std::string lastName_;
  int examScore_;
  std::vector<double> homework_;
public:
  Student() : examScore_(0) { }
  Student(std::istream& is);
  inline std::string getName() const { return firstName_; }
  inline std::string getLastName() const { return lastName_; }
  int getExamScore() const { return examScore_; }
  double calculateScore() const;
  std::istream& readStudent(std::istream&);
  void setName(string name);
  void setLastName(string lname);
  void setMark(double mark);
  void setExam(double exam);
  double median();
};

bool compare(const Student&, const Student&);
bool compareByLastName(const Student&, const Student&);
bool compareByScore(const Student&, const Student&);

#endif //STUDENT_H