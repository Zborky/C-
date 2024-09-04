#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Trieda Course predstavuje kurz.
 */
class Course {
private:
    int kredits; // Počet kreditov kurzu
    string profesor; // Meno profesora, ktorý vyučuje kurz
    string course_name; // Názov kurzu
    string course_end; // Čas konca kurzu
    string course_start; // Čas začiatku kurzu
    vector<string> meeting_days; // Dni, kedy sa kurz koná

public:
    /**
     * Konštruktor triedy Course.
     * @param kredits Počet kreditov kurzu.
     * @param profesor Meno profesora.
     * @param course_name Názov kurzu.
     * @param course_end Čas konca kurzu.
     * @param course_start Čas začiatku kurzu.
     * @param meeting_days Dni konania kurzu.
     */
    Course(int kredits, string profesor, string course_name, string course_end, string course_start, vector<string> meeting_days) {
        this->kredits = kredits;
        this->profesor = profesor;
        this->course_name = course_name;
        this->course_end = course_end;
        this->course_start = course_start;
        this->meeting_days = meeting_days;
    }

    /**
     * Získa počet kreditov kurzu.
     * @return Počet kreditov.
     */
    int getKredits() const {
        return this->kredits;
    }

    /**
     * Získa meno profesora.
     * @return Meno profesora.
     */
    string getProfesor() const {
        return this->profesor;
    }

    /**
     * Získa názov kurzu.
     * @return Názov kurzu.
     */
    string getCourse_Name() const {
        return this->course_name;
    }

    /**
     * Získa čas začiatku kurzu.
     * @return Čas začiatku kurzu.
     */
    string getCourse_Start() const {
        return this->course_start;
    }

    /**
     * Získa čas konca kurzu.
     * @return Čas konca kurzu.
     */
    string getCourse_End() const {
        return this->course_end;
    }

    /**
     * Získa dni konania kurzu.
     * @return Vektor dní konania kurzu.
     */
    const vector<string>& getMeeting_Days() const {
        return meeting_days;
    }

    /**
     * Nastaví počet kreditov kurzu.
     * @param kredits Počet kreditov.
     */
    void setKredits(int kredits) {
        this->kredits = kredits;
    }

    /**
     * Nastaví meno profesora.
     * @param profesor Meno profesora.
     */
    void setProfesor(string profesor) {
        this->profesor = profesor;
    }

    /**
     * Nastaví názov kurzu.
     * @param name Názov kurzu.
     */
    void setCourse_Name(string name) {
        this->course_name = name;
    }

    /**
     * Nastaví čas konca kurzu.
     * @param time Čas konca kurzu.
     */
    void setCourse_End(string time) {
        this->course_end = time;
    }

    /**
     * Nastaví čas začiatku kurzu.
     * @param time Čas začiatku kurzu.
     */
    void setCourse_Start(string time) {
        this->course_start = time;
    }
};

/**
 * Trieda Schedule predstavuje rozvrh kurzov.
 */
class Schedule {
private:
    vector<Course*> courses; // Vektor kurzov v rozvrhu
    int number_of_courses; // Počet kurzov v rozvrhu

public:
    /**
     * Konštruktor triedy Schedule.
     * @param number_of_courses Počet kurzov (počiatočne 0).
     */
    Schedule(int number_of_courses) {
        this->number_of_courses = 0;
    }

    /**
     * Pridá kurz do rozvrhu.
     * @param course Ukazovateľ na kurz, ktorý sa má pridať.
     */
    void addCourse(Course* course) {
        courses.push_back(course);
        this->number_of_courses++;
    }

    /**
     * Odstráni kurz z rozvrhu na základe názvu kurzu.
     * @param course_name Názov kurzu, ktorý sa má odstrániť.
     */
    void remove_Course(string course_name) {
        for (int i = 0; i < number_of_courses; i++) {
            if (courses[i]->getCourse_Name() == course_name) {
                delete courses[i]; // Uvoľnenie pamäte, ktorá bola dynamicky alokovaná
                courses.erase(courses.begin() + i);
                this->number_of_courses--;
                break; // Ukončíme slučku po odstránení kurzu
            }
        }
    }

    /**
     * Vytlačí všetky kurzy v rozvrhu.
     */
    void printSchedule() const {
        for (const Course* course : courses) {
            cout << "Course: " << course->getCourse_Name() << endl;
            cout << "Days: ";
            for (const string& day : course->getMeeting_Days()) {
                cout << day << " ";
            }
            cout << endl;
            cout << "Time: " << course->getCourse_Start() << " - " << course->getCourse_End() << endl;
            cout << "Professor: " << course->getProfesor() << endl << endl;
        }
    }

    /**
     * Skontroluje konflikt medzi dvoma kurzami na základe dní konania kurzu.
     * @param course1 Ukazovateľ na prvý kurz.
     * @param course2 Ukazovateľ na druhý kurz.
     * @return True, ak existuje konflikt (t.j. kurzy sa konajú v rovnaký deň), inak False.
     */
    bool checkConflikt(const Course* course1, const Course* course2) {
        for (const string& day1 : course1->getMeeting_Days()) {
            for (const string& day2 : course2->getMeeting_Days()) {
                if (day1 == day2) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    // Vytvorenie objektu rozvrhu
    Schedule schedule(0);

    // Vytvorenie objektov kurzov
    Course* course1 = new Course(3, "Prof. A", "Math", "10:00", "09:00", {"Mon", "Wed", "Fri"});
    Course* course2 = new Course(4, "Prof. B", "Science", "11:00", "10:00", {"Tue", "Thu"});
    Course* course3 = new Course(3, "Prof. C", "English", "09:00", "08:00", {"Mon", "Wed"});

    // Pridanie kurzov do rozvrhu
    schedule.addCourse(course1);
    schedule.addCourse(course2);
    schedule.addCourse(course3);

    // Vytlačenie rozvrhu
    cout << "Initial Schedule:" << endl;
    schedule.printSchedule();
    cout << endl;

    // Kontrola konfliktov medzi kurzami
    if (schedule.checkConflikt(course1, course2)) {
        cout << "There is a conflict between " << course1->getCourse_Name() << " and " << course2->getCourse_Name() << endl;
    } else {
        cout << "No conflict between " << course1->getCourse_Name() << " and " << course2->getCourse_Name() << endl;
    }

    if (schedule.checkConflikt(course1, course3)) {
        cout << "There is a conflict between " << course1->getCourse_Name() << " and " << course3->getCourse_Name() << endl;
    } else {
        cout << "No conflict between " << course1->getCourse_Name() << " and " << course3->getCourse_Name() << endl;
    }

    // Odstránenie kurzu z rozvrhu
    schedule.remove_Course("Math");
    cout << endl << "Schedule after removing Math course:" << endl;
    schedule.printSchedule();

    // Uvoľnenie dynamicky alokovanej pamäte
    delete course1;
    delete course2;
    delete course3;

    return 0;
}