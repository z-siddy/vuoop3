#include "headers/studs.h"
#include "headers/main.h"
#include "headers/student.h"
#define input "kursiokai.txt"

int main() {

    Studs A;
    try {
      A.readFileData(input);
    } catch (const char* msg) {
        
        std::cerr <<  "\x1B[31m" << msg << "\033[0m\t\t" << endl;
    }
    A.inputData();
    A.printResult();
    return 0;
}
