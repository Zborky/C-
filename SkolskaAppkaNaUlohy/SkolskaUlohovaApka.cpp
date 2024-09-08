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
     * Kon�truktor pre triedu HomeWork.
     *
     * @param homeworkID ID dom�cej �lohy.
     * @param title N�zov dom�cej �lohy.
     * @param description Popis dom�cej �lohy.
     * @param dueDate D�tum odovzdania dom�cej �lohy.
     * @param courseID ID kurzu.
     */
    HomeWork(int homeworkID, string title, string description, string dueDate, int courseID)
        : homeworkID(homeworkID), title(title), description(description), dueDate(dueDate), courseID(courseID) {}

    /**
     * Zobraz� inform�cie o dom�cej �lohe.
     */
    void displayHomeWork() const {
        cout << "HomeWorkID: " << homeworkID << "\nTitle: " << title << "\nDescription: " << description
            << "\nDue Date: " << dueDate << "\nCourseID: " << courseID << endl;
    }

    /**
     * Ulo�� dom�cu �lohu do s�boru.
     *
     * @param outFile V�stupn� s�borov� pr�d.
     */
    void saveToFile(ofstream& outFile) const {
        outFile << homeworkID << "\n" << title << "\n" << description << "\n" << dueDate << "\n" << courseID << "\n";
    }

    /**
     * Na��ta dom�cu �lohu zo s�boru.
     *
     * @param inFile Vstupn� s�borov� pr�d.
     * @return Na��tan� dom�ca �loha.
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
     * Kon�truktor pre triedu Student.
     *
     * @param id ID �tudenta.
     * @param n Meno �tudenta.
     * @param e E-mail �tudenta.
     */
    Student(int id, string n, string e)
        : studentID(id), name(n), email(e) {}

    /**
     * Odovzd� dom�cu �lohu.
     *
     * @param homeworkID ID dom�cej �lohy.
     * @param filePath Cesta k s�boru.
     */
    void submitHomework(int homeworkID, string filePath) const {
        cout << "Odovzd�vam dom�cu �lohu s ID: " << homeworkID << " od " << name
            << "\nCesta k s�boru: " << filePath << endl;
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
     * Kon�truktor pre triedu Submission.
     *
     * @param subID ID odovzdania.
     * @param hwID ID dom�cej �lohy.
     * @param studID ID �tudenta.
     * @param path Cesta k s�boru.
     * @param date D�tum odovzdania.
     * @param grd Zn�mka.
     */
    Submission(int subID, int hwID, int studID, string path, string date, string grd)
        : submissionID(subID), homeworkID(hwID), studentID(studID), filePath(path), submissionDate(date), grade(grd) {}

    /**
     * Ulo�� odovzdanie do s�boru.
     *
     * @param outFile V�stupn� s�borov� pr�d.
     */
    void saveToFile(ofstream& outFile) const {
        outFile << submissionID << "\n" << homeworkID << "\n" << studentID << "\n"
            << filePath << "\n" << submissionDate << "\n" << grade << "\n";
    }

    /**
     * Na��ta odovzdanie zo s�boru.
     *
     * @param inFile Vstupn� s�borov� pr�d.
     * @return Na��tan� odovzdanie.
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

// Funkcie na ulo�enie a na��tanie dom�cich �loh
/**
 * Ulo�� zoznam dom�cich �loh do s�boru.
 *
 * @param homeworks Vektor dom�cich �loh.
 */
void saveHomeworks(const vector<HomeWork>& homeworks) {
    ofstream outFile("homeworks.txt");
    for (const auto& hw : homeworks) {
        hw.saveToFile(outFile);
    }
    outFile.close();
}

/**
 * Na��ta zoznam dom�cich �loh zo s�boru.
 *
 * @return Vektor na��tan�ch dom�cich �loh.
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

// Funkcie na ulo�enie a na��tanie odovzdan�ch dom�cich �loh
/**
 * Ulo�� zoznam odovzdan�ch dom�cich �loh do s�boru.
 *
 * @param submissions Vektor odovzdan�ch dom�cich �loh.
 */
void saveSubmissions(const vector<Submission>& submissions) {
    ofstream outFile("submissions.txt");
    for (const auto& sub : submissions) {
        sub.saveToFile(outFile);
    }
    outFile.close();
}

/**
 * Na��ta zoznam odovzdan�ch dom�cich �loh zo s�boru.
 *
 * @return Vektor na��tan�ch odovzdan�ch dom�cich �loh.
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
        cout << "Syst�m na spr�vu dom�cich �loh\n";
        cout << "1. Prida� dom�cu �lohu\n";
        cout << "2. Zobrazi� dom�ce �lohy\n";
        cout << "3. Odovzda� dom�cu �lohu\n";
        cout << "4. Ukon�i�\n";
        cout << "Zadajte svoju vo�bu: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int id, courseID;
            string title, description, dueDate;
            cout << "Zadajte ID dom�cej �lohy: ";
            cin >> id;
            cout << "Zadajte n�zov: ";
            cin.ignore();
            getline(cin, title);
            cout << "Zadajte popis: ";
            getline(cin, description);
            cout << "Zadajte d�tum odovzdania: ";
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
            cout << "Zadajte ID �tudenta: ";
            cin >> studentID;
            cout << "Zadajte ID dom�cej �lohy: ";
            cin >> homeworkID;
            cout << "Zadajte cestu k s�boru: ";
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
                    cout << "Dom�ca �loha nebola n�jden�.\n";
                }
            }
            else {
                cout << "�tudent nebol n�jden�.\n";
            }
            break;
        }
        case 4:
            cout << "Ukon�ujem...\n";
            break;
        default:
            cout << "Neplatn� vo�ba. Sk�ste znova.\n";
            break;
        }
    } while (choice != 4);

    return 0;
}