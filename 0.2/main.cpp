#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <random>
#include <algorithm>

#define input "kursiokai.txt"

using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::left;
using std::string;
using std::setprecision;
using std::fixed;
using std::vector;
using std::sort;

struct Student{

    string firstName;
    string lastName;
    double examScore;
    vector<double > homework;

    //functions
    double calculateScore(){
        double sum = 0;
        for(double mark : homework)
            sum += mark;
        return (0.4*(sum/homework.size())) + (0.6*examScore);
    };
    double median() {
        double m;
        sort(homework.begin(),homework.end());
        if(homework.size()%2 == 0){
            m = (homework[homework.size()/2]+homework[(homework.size()/2)-1])/2.0;
        }
        else{
            m = homework[homework.size()/2];
        }
        return (m*0.4) + (0.6*examScore);
    }
    void setName(string name){
        firstName = name;
    }
    void setLastName(string lname){
        lastName = lname;
    }
    void setMark(double mark){
        homework.push_back(mark);
    }
    void setExam(double exam){
        examScore = exam;
    }

};

void sortStudents(Student A[], int lastIndex) {
    std::sort(A, A+lastIndex, [] (Student a, Student b) -> bool { return (a.firstName < b.firstName); });
}

void inputData(Student A[], int &lastIndex){
    string text;
    int number, choice,mark;
    while(true){

        cout << "Įveskite studento vardą: " << endl;
        cin >> text;
        A[lastIndex].setName(text);

        cout << "Įveskite studento pavardę: " << endl;
        cin >> text;
        A[lastIndex].setLastName(text);

        cout << "Įveskite studento namų darbų užduočių skaičių: " << endl;
        cin >> number;

        cout << "Ar norite generuoti atsitiktinius pažymius? (1/0)" << endl;
        cin >> choice;

        if(choice == 1){
            srand(0);
            for(int i=0;i<number;i++){
                A[lastIndex].setMark(1+(double)rand()/RAND_MAX*9);
            }
            cout << "Sugeneruota!" << endl;

        }
        else{

            for(int i=0;i<number;i++){
                cout << "Įveskite studento namų darbų rezultatą: " << endl;
                cin >> mark;
                A[lastIndex].setMark(mark);
            }

        }

        cout << "Įveskite studento egzamino rezultatą: " << endl;
        cin >> number;
        A[lastIndex].setExam(number);

        while(true) {

            cout << "Pridėti dar vieną studentą? (1/0) ";
            cin >> choice;
            if(choice == 0 || choice == 1)
                break;

        }

        lastIndex += 1;
        if(choice==0)
            return;

    }
}

void readFileData(Student A[], int &lastIndex){
    string text;
    int number, choice,mark;
    std::ifstream x(input);
    while(true){

        if(x.eof())
            break;

        x >> text;
        A[lastIndex].setName(text);

        x >> text;
        A[lastIndex].setLastName(text);

        x >> number;

        for(int i=0;i<number;i++){
            x >> mark;
            A[lastIndex].setMark(mark);
        }

        x >> number;
        A[lastIndex].setExam(number);

        lastIndex += 1;

    }
}


void printResult(Student A[], int lastIndex){
        cout << left << setw(12) << "Vardas" << setw(12) << "Pavardė" << setw(20) << "Galutinis (Vid.)" << setw(15) << "Galutinis (Med.)" << endl;
        cout << "---------------------------------------------------------------" << endl;
        for(int i=0;i<lastIndex;i++){
            cout << left << setw(12) << A[i].firstName << setw(12) << A[i].lastName << setw(20) << fixed << setprecision(2) << A[i].calculateScore() << setw(15) << fixed << setprecision(2) << A[i].median() << endl;
        }
}

int main() {

    int lastIndex = 0;
    Student A[50];
    readFileData(A,lastIndex);
    inputData(A,lastIndex);
    sortStudents(A,lastIndex);
    printResult(A,lastIndex);

    return 0;
}
