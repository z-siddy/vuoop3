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
  double calculateScore() const;
  double median();

  //operatoriai
  friend bool operator == (const Student &a, const Student &b) { return a.calculateScore() == b.calculateScore(); }
  friend bool operator != (const Student &a, const Student &b) { return a.calculateScore() != b.calculateScore(); }
  friend bool operator < (const Student &a, const Student &b) { return a.calculateScore() < b.calculateScore(); }
  friend bool operator > (const Student &a, const Student &b) { return a.calculateScore() > b.calculateScore(); }
  friend std::istream &operator >> (std::istream &x, Student &a) {
        std::default_random_engine gen;
        std::uniform_int_distribution<int> dist(0, 10);
        string text,fname,lname;
        int number, choice,mark;
        cout << "Iveskite studento varda: " << endl;
        x >> text;
        a.firstName_ = text;

        cout << "Iveskite studento pavarde: " << endl;
        x >> text;
        a.lastName_ = text;

        cout << "Iveskite studento namu darbu uzduociu skaiciu: " << endl;
        x >> number;

        cout << "Ar norite generuoti atsitiktinius pazymius? (0/1)" << endl;
        x >> choice;

        if(choice == 1){
            for(int i=0;i<number;i++){
                a.setMark(dist(gen));
            }
            cout << "Sugeneruota!" << endl;

        }
        else{

            for(int i=0;i<number;i++){
                cout << "Iveskite studento namu darbu rezultata: " << endl;
                x >> mark;
                a.setMark(mark);
            }

        }

        cout << "Iveskite studento egzamino rezultata: " << endl;
        x >> number;
        a.setExam(number);
        return x;
  }
  friend std::ostream & operator << (std::ostream &o, const Student stud) {
        o << "Studento informacija:" << endl;
        o << "Vardas: " << stud.getName() << endl;
        o << "Pavarde: " << stud.getLastName() << endl;
        o << "Galutinis bal.: " << stud.calculateScore() << endl;
        return o;
  }
  Student () {};
  Student(string fname, string lname): firstName_(std::move(fname)), lastName_(std::move(lname)) {};
};


#endif //STUDENT_H