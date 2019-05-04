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
  inline std::string getName() const { return firstName_; }
  inline std::string getLastName() const { return lastName_; }
  void setMark(int mark) { homework_.push_back(mark); };
  void setExam(int exam) { examScore_ = exam; };
  double calculateScore();
  double median();
  Student(string fname, string lname): firstName_(std::move(fname)), lastName_(std::move(lname)) {};
};


#endif //STUDENT_H