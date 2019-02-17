#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <random>
#include <algorithm>

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

struct student{

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

void inputData(student A[], int &lastIndex){
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


void printResult(student A[], int lastIndex, int choice){
    if(choice == 1){
        cout << left << setw(12) << "Vardas" << setw(12) << "Pavardė" << setw(12) << "Galutinis (Vid.)" << endl;
        cout << "--------------------------------------------------" << endl;
        for(int i=0;i<lastIndex;i++){
            cout << left << setw(12) << A[i].firstName << setw(12) << A[i].lastName << setw(12) << fixed << setprecision(2) << A[i].calculateScore() << endl;
        }
    }
    else{
        cout << left << setw(12) << "Vardas" << setw(12) << "Pavardė" << setw(12) << "Galutinis (Med.)" << endl;
        cout << "--------------------------------------------------" << endl;
        for(int i=0;i<lastIndex;i++){
            cout << left << setw(12) << A[i].firstName << setw(12) << A[i].lastName << setw(12) << fixed << setprecision(2) << A[i].median() << endl;
        }
    }
}

int main() {

    int lastIndex = 0;
    student A[50];
    int choice;
    inputData(A,lastIndex);
    cout << "Jeigu norite matyti vidurkio rezultatą, įveskite 1. Priešingu atveju matysite medianos rezultatą: " << endl;
    cin >> choice;
    printResult(A,lastIndex,choice);

    return 0;
}
