//Student functions---------------------------------------------------------------------------------------

#include "student.h"

    double Student::calculateScore(){
        double sum = 0;
        for(double mark : homework)
            sum += mark;
        return (0.4*(sum/homework.size())) + (0.6*examScore);
    };
    double Student::median() {
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
    void Student::setName(string name){
        firstName = name;
    }
    void Student::setLastName(string lname){
        lastName = lname;
    }
    void Student::setMark(double mark){
        homework.push_back(mark);
    }
    void Student::setExam(double exam){
        examScore = exam;
    }

//Studs FUNCTIONS ---------------------------------------------------------------------------------

#include "studs.h"

bool Studs::checkFile(const char *fileName){
    std::ifstream infile(fileName);
    return infile.good();
}

bool Studs::stringValidation(const string x) {
    string spec_char = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_";
    if (x.find_first_not_of(spec_char) != string::npos)
        return false;
    return true;
}

void Studs::inputData(){
    std::default_random_engine gen;
    std::uniform_int_distribution<int> dist(0, 10);
    string text;
    int number, choice,mark;
    while(true){
        Student temp;

        cout << "Iveskite studento varda: " << endl;
        cin >> text;
        while(!stringValidation(text)) {
            cout << "KLAIDA! Iveskite nauja varda:";
            cin.clear();
            cin.ignore(256, '\n');
            cin >> text;
        }
        temp.setName(text);

        cout << "Iveskite studento pavarde: " << endl;
        cin >> text;
        while(!stringValidation(text)) {
            cout << "KLAIDA! Iveskite nauja pavarde:";
            cin.clear();
            cin.ignore(256, '\n');
            cin >> text;
        }
        temp.setLastName(text);

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
                temp.setMark(dist(gen));
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
                temp.setMark(mark);
            }

        }

        cout << "Iveskite studento egzamino rezultata: " << endl;
        cin >> number;
        while (cin.fail()) {
            cout << "KLAIDA! Iveskite nauja ivertinima:";
            cin.clear();
            cin.ignore(256, '\n');
            cin >> number;
        }
        temp.setExam(number);

        cout << "Prideti dar viena studenta? (0/1) ";
        cin >> choice;
        while(!((!cin.fail()) && (choice == 0) || (choice == 1))) {
            cout << "KLAIDA! Iveskite nauja pasirinkima (0/1):";
            cin.clear();
            cin.ignore(256, '\n');
            cin >> choice;
        }

        students.push_back(temp);
        if(choice==0)
            return;

    }
}

void Studs::checkLongestNames(){
    int fname=longestName,lname=longestLastName;
    for (const auto &el : students){
        if(el.firstName.length() > fname)
            fname = el.firstName.length();
        if(el.lastName.length() > lname)
            lname = el.lastName.length();
    }
    longestName = fname;
    longestLastName = lname;
}

void Studs::readFileData(const char input[]){
    if(!checkFile(input))
    {
        throw "Nuskaitymo failas neegzistuoja!";
    }
    string text;
    int number,mark;
    std::ifstream x(input);
    while(true){
        Student temp;

        if(x.eof())
            break;

        x >> text;
        if(x.fail() || !stringValidation(text)) {
            x.clear();
            x.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            continue;
        }
        temp.setName(text);

        x >> text;
        if(x.fail() || !stringValidation(text)) {
            x.clear();
            x.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            continue;
        }
        temp.setLastName(text);

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
            temp.setMark(mark);
        }

        x >> number;
        if(!((!x.fail())&&(number <= 10)&&(number >= 1))) {
            x.clear();
            x.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            continue;
        }
        temp.setExam(number);

        students.push_back(temp);

    }
}


void Studs::printResult(){
    checkLongestNames();
    sortStudents();
        cout << left << setw(longestName+1) << "Vardas" << setw(longestLastName+1) << "Pavarde" << setw(20) << "Galutinis (Vid.)" << setw(15) << "Galutinis (Med.)" << endl;
        cout << "---------------------------------------------------------------" << endl;
        for(auto student:students){
            cout << left << setw(longestName+1) << student.firstName << setw(longestLastName+1) << student.lastName << setw(20) << fixed << setprecision(2) << student.calculateScore() << setw(15) << fixed << setprecision(2) << student.median() << endl;
        }
}

void Studs::sortStudents() {
    std::sort(students.begin(), students.end(),
              [](Student& lhs, Student& rhs) {
                  return lhs.firstName > rhs.firstName;
              });
}

void Studs::generateLists(int n){
    std::ofstream out("generatedList.txt");
    Student temp;
    int number,mark;
    srand(0);
    for(int i=1;i<=n;i++){
        temp.firstName = "Vardas" + std::to_string(i);
        out << temp.firstName << " ";
        temp.lastName = "Pavarde" + std::to_string(i);
        out << temp.lastName << " ";
        number = 1+(double)rand()/RAND_MAX*9;
        out << number << " ";
        for(int j=0;j<number;j++){
            mark = 1+(double)rand()/RAND_MAX*9;
            temp.setMark(mark);
            out << mark << " ";
        }
        temp.examScore = 1+(double)rand()/RAND_MAX*9;
        out << temp.examScore << endl;
        students.push_back(temp);
    }
    out.close();
}

void Studs::sortByMarks(){
    std::ofstream out1("vargsiukai.txt");
    std::ofstream out2("kietekai.txt");
    //std::size_t it=0;
    for(auto student:students){
        if(student.calculateScore() < 5.0){
            vargsiukai.push_back(student);
            out1 << student.firstName << " " << student.lastName << " " << fixed << setprecision(2) << student.calculateScore() << endl;
            //students.erase(students.begin() + it);
        }
        else{
            kietekai.push_back(student);
            out2 << student.firstName << " " << student.lastName << " " << fixed << setprecision(2) << student.calculateScore() << endl;
        }
        //it++;
    }
    out1.close();
    out2.close();
}

//Timer functions
#include "timer.h"

void Timer::startClock() {
    start = std::chrono::high_resolution_clock::now();
}

void Timer::endClock(string opName) {
    end = std::chrono::high_resolution_clock::now();
    duration = end-start;
    cout << opName <<  " : " << duration.count() << " s" << std::endl;

}