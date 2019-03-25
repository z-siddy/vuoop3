#include "headers/studs.h"
#include "headers/main.h"
#include "headers/student.h"
#include "headers/timer.h"
#define input "kursiokai.txt"
#define generateNumber 15000

int main() {
    Timer timer;
    timer.startClock();
    Studs A;
    try {
      A.readFileData(input);
    } catch (const char* msg) {
        
        std::cerr << msg << endl;
    }
    timer.endClock("Read data from file");
    timer.startClock();
    A.inputData();
    timer.endClock("Data input");
    timer.startClock();
    A.generateLists(generateNumber);
    timer.endClock("List generation");
    // timer.startClock();
    // A.printResult();
    // timer.endClock("Printing results");
    timer.startClock();
    A.sortByMarks();
    timer.endClock("Output file creation");
    return 0;
}
