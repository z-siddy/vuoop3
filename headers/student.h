#include "main.h"
#include "Human.h"

#ifndef STUDENT_H
#define STUDENT_H


class Student : public Human {
private:
  int examScore_;
  std::vector<double> homework_;
public:
  void getTitle() { cout  << "Studentas"; };
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
        a.setName(text);

        cout << "Iveskite studento pavarde: " << endl;
        x >> text;
        a.setLastname(text);

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
  Student(string fname, string lname): Human(fname, lname){};
};


#endif //STUDENT_H