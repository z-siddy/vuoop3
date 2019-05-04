//Student functions---------------------------------------------------------------------------------------

#include "student.h"
#include "timer.h"
#include "studs.h"

double Student::calculateScore() {
    double sum = 0;
    for(double mark : homework_)
        sum += mark;
    if (homework_.empty()) throw "Dalyba iš 0";
    return (sum / homework_.size()) * 0.4 + 0.6 * examScore_;
}
double Student::median() {
    std::sort(homework_.begin(), homework_.end());
    double m;
    if(homework_.size() % 2 == 0)
        m = (homework_[homework_.size() / 2] + homework_[(homework_.size() / 2) - 1]) / 2.;
    else
        m = homework_[homework_.size() / 2];
    return m * 0.4 + 0.6 * examScore_;
}


//Studs FUNCTIONS ---------------------------------------------------------------------------------


bool Studs::stringValidation(const string x) {
    string spec_char = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_";
    if (x.find_first_not_of(spec_char) != string::npos)
        return false;
    return true;
}

void Studs::addStudent(Student student) {
    checkLongestName(student);
    students.push_back(student);
}

void Studs::addKietekas(Student student) {
    checkLongestName(student);
    kietekai.push_back(student);
}

void Studs::addVargsiukas(Student student) {
    checkLongestName(student);
    vargsiukai.push_back(student);
}

void Studs::clearStudents() {
    students.clear();
}

void Studs::inputData(){
    std::default_random_engine gen;
    std::uniform_int_distribution<int> dist(0, 10);
    string text,fname,lname;
    int number, choice,mark;
    while(true){

        cout << "Iveskite studento varda: " << endl;
        cin >> text;
        while(!stringValidation(text)) {
            cout << "KLAIDA! Iveskite nauja varda:";
            cin.clear();
            cin.ignore(256, '\n');
            cin >> text;
        }
        fname = text;

        cout << "Iveskite studento pavarde: " << endl;
        cin >> text;
        while(!stringValidation(text)) {
            cout << "KLAIDA! Iveskite nauja pavarde:";
            cin.clear();
            cin.ignore(256, '\n');
            cin >> text;
        }
        lname = text;

        Student student = Student(fname,lname);

        cout << "Iveskite studento namu darbu uzduociu skaiciu: " << endl;
        cin >> number;
        while (cin.fail()) {
            cout << "KLAIDA! Iveskite nauja skaiciu:";
            cin.clear();
            cin.ignore(256, '\n');
            cin >> number;
        }

        cout << "Ar norite generuoti atsitiktinius pazymius? (0/1)" << endl;
        cin >> choice;
        while(!((!cin.fail()) && (choice == 0) || (choice == 1)))
        {
            cout << "KLAIDA! Iveskite tinkama pasirinkima (0/1):";
            cin.clear();
            cin.ignore(256, '\n');
            cin >> choice;
        }

        if(choice == 1){
            for(int i=0;i<number;i++){
                student.setMark(dist(gen));
            }
            cout << "Sugeneruota!" << endl;

        }
        else{

            for(int i=0;i<number;i++){
                cout << "Iveskite studento namu darbu rezultata: " << endl;
                cin >> mark;
                while (!((!cin.fail()) && (mark <= 10) && (mark >= 1))) {
                    cout << "KLAIDA! Iveskite nauja ivertinima(1-10):";
                    cin.clear();
                    cin.ignore(256, '\n');
                    cin >> mark;
                }
                student.setMark(mark);
            }

        }

        cout << "Iveskite studento egzamino rezultata: " << endl;
        cin >> number;
        while (!((!cin.fail()) && (number <= 10) && (number >= 1))) {
            cout << "KLAIDA! Iveskite nauja ivertinima:";
            cin.clear();
            cin.ignore(256, '\n');
            cin >> number;
        }
        student.setExam(number);

        cout << "Prideti dar viena studenta? (0/1) ";
        cin >> choice;
        while(!((!cin.fail()) && (choice == 0) || (choice == 1))) {
            cout << "KLAIDA! Iveskite nauja pasirinkima (0/1):";
            cin.clear();
            cin.ignore(256, '\n');
            cin >> choice;
        }

        students.push_back(student);
        if(choice==0)
            return;

    }
}

void Studs::checkLongestName(Student &student){
    string n = student.getName();
    string ln = student.getLastName();
    const int lon = n.length();
    const int lol = ln.length();
    if (lon > longestName)
        longestName = lon;
    if (lol > longestLastName)
        longestLastName = lol;
}

void Studs::readData(const char input[]){
    string fname,lname;
    std::ifstream x(input);
    if (x.fail())
        throw "Tekstinis duomenu failas nerastas!";

    string text;
    int number,mark;
    while(true){
        if(x.eof())
            break;

        x >> text;
        if(x.fail() || !stringValidation(text)) {
            x.clear();
            x.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            continue;
        }
        fname = text;

        x >> text;
        if(x.fail() || !stringValidation(text)) {
            x.clear();
            x.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            continue;
        }
        lname = text;

        Student student = Student(fname,lname);

        x >> number;
        if(x.fail()) {
            x.clear();
            x.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            continue;
        }

        for(int i=0;i<number;i++){
            x >> mark;
            if(x.fail()) {
                x.clear();
                x.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                continue;
            }
            student.setMark(mark);
        }

        x >> number;
        if(!((!x.fail())&&(number <= 10)&&(number >= 1))) {
            x.clear();
            x.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            continue;
        }
        student.setExam(number);

        students.push_back(student);

    }
    x.close();
}


void Studs::printResult(){
        cout << left << setw(longestName+1) << "Vardas" << setw(longestLastName+1) << "Pavarde" << setw(20) << "Galutinis (Vid.)" << setw(15) << "Galutinis (Med.)" << endl;
        cout << "---------------------------------------------------------------" << endl;
        for(auto student:students){
            cout << left << setw(longestName+1) << student.getName() << setw(longestLastName+1) << student.getLastName() << setw(20) << fixed << setprecision(2) << student.calculateScore() << setw(15) << fixed << setprecision(2) << student.median() << endl;
        }
}

void Studs::sortStudents() {
    std::sort(students.begin(), students.end(),
              [](Student& lhs, Student& rhs) {
                  return lhs.getName() > rhs.getName();
              });
}

void Studs::generateLists(int num, int marks) {
    string name, lname;
    std::default_random_engine gen;
    std::uniform_int_distribution<int> dist(0, 10);
    for(int i = 0; i < num; i++) {
        name = "Vardas" + std::to_string(i + 1);
        lname = "Pavarde" + std::to_string(i + 1);
        Student student = Student(name, lname);
        for(int j = 0; j < marks; j++) {
            student.setMark(dist(gen));
        }
        student.setExam(dist(gen));
        addStudent(student);
    }
}

void Studs::groupStudents() {
    double fin;
    size_t cnt = 0;
    auto i = students.begin();
    while(i != students.end()) {
        try {
            fin = i->calculateScore();
        } catch (const char* e) {
            i++;
            continue;
        }
        if(fin != 0 && fin < 5) {
            addVargsiukas(*(i));
        } else {
            std::rotate(students.begin(), i, std::next(i));
            i++;
            cnt++;
        }
        i++;
    }
    students.resize(cnt, Student("", ""));
    students.shrink_to_fit();
}

void Studs::outputCreate(){
    std::ofstream out1("vargsiukai.txt");
    std::ofstream out2("kietekai.txt");
    //std::size_t it=0;
    for(auto student:students){
        out2 << student.getName() << " " << student.getLastName() << " " << fixed << setprecision(2) << student.calculateScore() << endl;
    }
    for(auto student:vargsiukai){
        out1 << student.getName() << " " << student.getLastName() << " " << fixed << setprecision(2) << student.calculateScore() << endl;
    }
    out1.close();
    out2.close();
}

//Timer functions

void Timer::startClock() {
    start = std::chrono::high_resolution_clock::now();
}

void Timer::endClock(string opName) {
    end = std::chrono::high_resolution_clock::now();
    duration = end-start;
    cout << opName <<  " : " << duration.count() << " s" << std::endl;

}