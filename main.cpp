#include "headers/studs.h"
#include "headers/main.h"
#include "headers/student.h"
#include "headers/timer.h"
#define input "kursiokai.txt"
#define generateNumber 10000
#define markNumber 10

int main() {
    Studs A;
    Timer timer;
//    timer.startClock();
//    try {
//      A.readData(input);
//    } catch (const char* msg) {
//
//        std::cerr << msg << endl;
//    }
//    timer.endClock("Read data from file");
    timer.startClock();
    try {
        A.generateLists(generateNumber, markNumber);
    } catch (const char* e) {
        std::cerr << e << endl;
    }
    timer.endClock("List generation");
    timer.startClock();
    A.sortStudents();
    timer.endClock("Sorting students");
    // timer.startClock();
    // A.printResult();
    // timer.endClock("Printing results");
    Student a = A.getRandomStudent();
    timer.startClock();
    A.groupStudents();
    timer.endClock("Grouping students");
    timer.startClock();
    A.outputCreate();
    timer.endClock("Outputting students to files");

    
    Student b = A.getRandomStudent();

    cout << a << endl;
    cout << b << endl;

    if (a > b)
        cout << "A didesnis\n";
    else if (a < b)
        cout << "B didesnis\n";
    if (a == b)
        cout << "Lygus\n";
    else if (a != b)
        cout << "Nelygus\n";

    Student c;
    cin >> c;
    cout << c;

    return 0;
}
