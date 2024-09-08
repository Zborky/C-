#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

// Trieda HomeWork
class HomeWork {
private:
    int homeworkID;
    string title;
    string description;
    string dueDate;
    int courseID;

public:
    /**
     * Konštruktor pre triedu HomeWork.
     *
     * @param homeworkID ID domácej úlohy.
     * @param title Názov domácej úlohy.
     * @param description Popis domácej úlohy.
     * @param dueDate Dátum odovzdania domácej úlohy.
     * @param courseID ID kurzu.
     */
    HomeWork(int homeworkID, string title, string description, string dueDate, int courseID)
        : homeworkID(homeworkID), title(title), description(description), dueDate(dueDate), courseID(courseID) {}

    /**
     * Zobrazí informácie o domácej úlohe.
     */
    void displayHomeWork() const {
        cout << "HomeWorkID: " << homeworkID << "\nTitle: " << title << "\nDescription: " << description
            << "\nDue Date: " << dueDate << "\nCourseID: " << courseID << endl;
    }

    /**
     * Uloží domácu úlohu do súboru.
     *
     * @param outFile Výstupný súborový prúd.
     */
    void saveToFile(ofstream& outFile) const {
        outFile << homeworkID << "\n" << title << "\n" << description << "\n" << dueDate << "\n" << courseID << "\n";
    }

    /**
     * Naèíta domácu úlohu zo súboru.
     *
     * @param inFile Vstupný súborový prúd.
     * @return Naèítaná domáca úloha.
     */
    static HomeWork loadFromFile(ifstream& inFile) {
        int id, cID;
        string t, d, date;
        inFile >> id;
        inFile.ignore();
        getline(inFile, t);
        getline(inFile, d);
        getline(inFile, date);
        inFile >> cID;
        inFile.ignore();
        return HomeWork(id, t, d, date, cID);
    }

    int getHomeworkID() const { return homeworkID; }
    const string& getTitle() const { return title; }
    const string& getDescription() const { return description; }
    const string& getDueDate() const { return dueDate; }
    int getCourseID() const { return courseID; }
};

// Trieda Student
class Student {
private:
    int studentID;
    string name;
    string email;

public:
    /**
     * Konštruktor pre triedu Student.
     *
     * @param id ID študenta.
     * @param n Meno študenta.
     * @param e E-mail študenta.
     */
    Student(int id, string n, string e)
        : studentID(id), name(n), email(e) {}

    /**
     * Odovzdá domácu úlohu.
     *
     * @param homeworkID ID domácej úlohy.
     * @param filePath Cesta k súboru.
     */
    void submitHomework(int homeworkID, string filePath) const {
        cout << "Odovzdávam domácu úlohu s ID: " << homeworkID << " od " << name
            << "\nCesta k súboru: " << filePath << endl;
    }

    int getStudentID() const { return studentID; }
    const string& getName() const { return name; }
    const string& getEmail() const { return email; }
};

// Trieda Submission
class Submission {
private:
    int submissionID;
    int homeworkID;
    int studentID;
    string filePath;
    string submissionDate;
    string grade;

public:
    /**
     * Konštruktor pre triedu Submission.
     *
     * @param subID ID odovzdania.
     * @param hwID ID domácej úlohy.
     * @param studID ID študenta.
     * @param path Cesta k súboru.
     * @param date Dátum odovzdania.
     * @param grd Známka.
     */
    Submission(int subID, int hwID, int studID, string path, string date, string grd)
        : submissionID(subID), homeworkID(hwID), studentID(studID), filePath(path), submissionDate(date), grade(grd) {}

    /**
     * Uloží odovzdanie do súboru.
     *
     * @param outFile Výstupný súborový prúd.
     */
    void saveToFile(ofstream& outFile) const {
        outFile << submissionID << "\n" << homeworkID << "\n" << studentID << "\n"
            << filePath << "\n" << submissionDate << "\n" << grade << "\n";
    }

    /**
     * Naèíta odovzdanie zo súboru.
     *
     * @param inFile Vstupný súborový prúd.
     * @return Naèítané odovzdanie.
     */
    static Submission loadFromFile(ifstream& inFile) {
        int subID, hwID, studID;
        string path, date, grd;

        inFile >> subID >> hwID >> studID;
        inFile.ignore();
        getline(inFile, path);
        getline(inFile, date);
        getline(inFile, grd);

        return Submission(subID, hwID, studID, path, date, grd);
    }

    int getSubmissionID() const { return submissionID; }
    int getHomeworkID() const { return homeworkID; }
    int getStudentID() const { return studentID; }
    const string& getFilePath() const { return filePath; }
    const string& getSubmissionDate() const { return submissionDate; }
    const string& getGrade() const { return grade; }
};

// Funkcie na uloženie a naèítanie domácich úloh
/**
 * Uloží zoznam domácich úloh do súboru.
 *
 * @param homeworks Vektor domácich úloh.
 */
void saveHomeworks(const vector<HomeWork>& homeworks) {
    ofstream outFile("homeworks.txt");
    for (const auto& hw : homeworks) {
        hw.saveToFile(outFile);
    }
    outFile.close();
}

/**
 * Naèíta zoznam domácich úloh zo súboru.
 *
 * @return Vektor naèítaných domácich úloh.
 */
vector<HomeWork> loadHomeworks() {
    vector<HomeWork> homeworks;
    ifstream inFile("homeworks.txt");
    while (inFile.peek() != EOF) {
        homeworks.push_back(HomeWork::loadFromFile(inFile));
    }
    inFile.close();
    return homeworks;
}

// Funkcie na uloženie a naèítanie odovzdaných domácich úloh
/**
 * Uloží zoznam odovzdaných domácich úloh do súboru.
 *
 * @param submissions Vektor odovzdaných domácich úloh.
 */
void saveSubmissions(const vector<Submission>& submissions) {
    ofstream outFile("submissions.txt");
    for (const auto& sub : submissions) {
        sub.saveToFile(outFile);
    }
    outFile.close();
}

/**
 * Naèíta zoznam odovzdaných domácich úloh zo súboru.
 *
 * @return Vektor naèítaných odovzdaných domácich úloh.
 */
vector<Submission> loadSubmissions() {
    vector<Submission> submissions;
    ifstream inFile("submissions.txt");
    while (inFile.peek() != EOF) {
        submissions.push_back(Submission::loadFromFile(inFile));
    }
    inFile.close();
    return submissions;
}

int main() {
    vector<HomeWork> homeworks = loadHomeworks();
    vector<Student> students;
    vector<Submission> submissions = loadSubmissions();

    students.push_back(Student(1, "John Doe", "john@example.com"));

    int choice;
    do {
        cout << "Systém na správu domácich úloh\n";
        cout << "1. Prida domácu úlohu\n";
        cout << "2. Zobrazi domáce úlohy\n";
        cout << "3. Odovzda domácu úlohu\n";
        cout << "4. Ukonèi\n";
        cout << "Zadajte svoju vo¾bu: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int id, courseID;
            string title, description, dueDate;
            cout << "Zadajte ID domácej úlohy: ";
            cin >> id;
            cout << "Zadajte názov: ";
            cin.ignore();
            getline(cin, title);
            cout << "Zadajte popis: ";
            getline(cin, description);
            cout << "Zadajte dátum odovzdania: ";
            getline(cin, dueDate);
            cout << "Zadajte ID kurzu: ";
            cin >> courseID;
            homeworks.push_back(HomeWork(id, title, description, dueDate, courseID));
            saveHomeworks(homeworks);
            break;
        }
        case 2: {
            for (const auto& hw : homeworks) {
                hw.displayHomeWork();
                cout << endl;
            }
            break;
        }
        case 3: {
            int studentID, homeworkID;
            string filePath;
            cout << "Zadajte ID študenta: ";
            cin >> studentID;
            cout << "Zadajte ID domácej úlohy: ";
            cin >> homeworkID;
            cout << "Zadajte cestu k súboru: ";
            cin.ignore();
            getline(cin, filePath);

            auto it = find_if(students.begin(), students.end(), [studentID](const Student& s) {
                return s.getStudentID() == studentID;
                });

            if (it != students.end()) {
                auto hw_it = find_if(homeworks.begin(), homeworks.end(), [homeworkID](const HomeWork& hw) {
                    return hw.getHomeworkID() == homeworkID;
                    });

                if (hw_it != homeworks.end()) {
                    it->submitHomework(homeworkID, filePath);
                    submissions.push_back(Submission(submissions.size() + 1, homeworkID, studentID, filePath, "2024-07-20", "N/A"));
                    saveSubmissions(submissions);
                }
                else {
                    cout << "Domáca úloha nebola nájdená.\n";
                }
            }
            else {
                cout << "Študent nebol nájdený.\n";
            }
            break;
        }
        case 4:
            cout << "Ukonèujem...\n";
            break;
        default:
            cout << "Neplatná vo¾ba. Skúste znova.\n";
            break;
        }
    } while (choice != 4);

    return 0;
}