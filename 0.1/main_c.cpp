#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <iomanip>
#include <cstdio>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::left;
using std::string;
using std::setprecision;
using std::fixed;

struct student{
    string firstName;
    string lastName;
    int arrSize=1;
    int lastIndex=0;
    double examScore;
    double finalScore;
    double *homework = new double[arrSize];
    //functions
    double calculateScore(){
        double sum = 0;
        for(int i=0;i<lastIndex;i++){
            sum += homework[i];
        }
        finalScore = (0.4*(sum/lastIndex)) + (0.6*examScore);
    };
    double median() {
        sortMarks();
        if(lastIndex%2 == 0)
            return (0.4*(homework[lastIndex/2] + homework[(lastIndex/2)-1])/2)+(examScore*0.6);
        return (0.4*homework[lastIndex / 2])+(examScore*0.6);
    }
    void setName(string name){
        firstName = name;
    }
    void setLastName(string lname){
        lastName = lname;
    }
    void setMark(double mark){
        if (lastIndex+1 == arrSize)
            expandArr();
        homework[lastIndex] = mark;
        lastIndex++;
    }
    void setExam(double exam){
        examScore = exam;
    }
    void sortMarks() {
        int count = lastIndex;
        double temp;
        bool swap;
        while(count > 1) {
            swap = false;
            for(int i = 0; i < count - 1; i++) {
                if(homework[i] > homework[i + 1]) {
                    swap = true;
                    temp = homework[i];
                    homework[i] = homework[i + 1];
                    homework[i + 1] = temp;
                }
            }
            if(!swap)
                break;
            count--;
        }
    }
    void expandArr() {
        arrSize *= 2;
        auto *newArr = new double[arrSize];
        for (int i = 0; i < lastIndex; i++)
            newArr[i] = homework[i];
        delete [] homework;
        homework = newArr;
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
        for(int i=0;i<number;i++){
            cout << "Įveskite studento namų darbų rezultatą: " << endl;
            cin >> mark;
            A[lastIndex].setMark(mark);
        }
        cout << "Įveskite studento egzamino rezultatą: " << endl;
        cin >> number;
        A[lastIndex].setExam(number);

        while(true) {
            cout << "Pridėti dar vieną studentą? 1 - yes | 0 - no: ";
            cin >> choice;
            if (choice == 0 || choice == 1)
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
            A[i].calculateScore();
            cout << left << setw(12) << A[i].firstName << setw(12) << A[i].lastName << setw(12) << fixed << setprecision(2) << A[i].finalScore << endl;
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
