#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * The Course class represents a course.
 */
class Course {
private:
    int kredits; // Number of credits for the course
    string profesor; // Name of the professor teaching the course
    string course_name; // Name of the course
    string course_end; // End time of the course
    string course_start; // Start time of the course
    vector<string> meeting_days; // Days the course is held

public:
    /**
     * Constructor for the Course class.
     * @param kredits Number of credits for the course.
     * @param profesor Name of the professor.
     * @param course_name Name of the course.
     * @param course_end End time of the course.
     * @param course_start Start time of the course.
     * @param meeting_days Days the course is held.
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
     * Gets the number of credits for the course.
     * @return The number of credits.
     */
    int getKredits() const {
        return this->kredits;
    }

    /**
     * Gets the name of the professor.
     * @return The name of the professor.
     */
    string getProfesor() const {
        return this->profesor;
    }

    /**
     * Gets the name of the course.
     * @return The name of the course.
     */
    string getCourse_Name() const {
        return this->course_name;
    }

    /**
     * Gets the start time of the course.
     * @return The start time of the course.
     */
    string getCourse_Start() const {
        return this->course_start;
    }

    /**
     * Gets the end time of the course.
     * @return The end time of the course.
     */
    string getCourse_End() const {
        return this->course_end;
    }

    /**
     * Gets the days the course is held.
     * @return A vector of meeting days.
     */
    const vector<string>& getMeeting_Days() const {
        return meeting_days;
    }

    /**
     * Sets the number of credits for the course.
     * @param kredits The number of credits.
     */
    void setKredits(int kredits) {
        this->kredits = kredits;
    }

    /**
     * Sets the name of the professor.
     * @param profesor The name of the professor.
     */
    void setProfesor(string profesor) {
        this->profesor = profesor;
    }

    /**
     * Sets the name of the course.
     * @param name The name of the course.
     */
    void setCourse_Name(string name) {
        this->course_name = name;
    }

    /**
     * Sets the end time of the course.
     * @param time The end time of the course.
     */
    void setCourse_End(string time) {
        this->course_end = time;
    }

    /**
     * Sets the start time of the course.
     * @param time The start time of the course.
     */
    void setCourse_Start(string time) {
        this->course_start = time;
    }
};

/**
 * The Schedule class represents a schedule of courses.
 */
class Schedule {
private:
    vector<Course*> courses; // Vector of courses in the schedule
    int number_of_courses; // Number of courses in the schedule

public:
    /**
     * Constructor for the Schedule class.
     * @param number_of_courses Number of courses (initially 0).
     */
    Schedule(int number_of_courses) {
        this->number_of_courses = 0;
    }

    /**
     * Adds a course to the schedule.
     * @param course Pointer to the course to be added.
     */
    void addCourse(Course* course) {
        courses.push_back(course); // Add course to the vector
        this->number_of_courses++; // Increment course count
    }

    /**
     * Removes a course from the schedule by course name.
     * @param course_name The name of the course to remove.
     */
    void remove_Course(string course_name) {
        for (int i = 0; i < number_of_courses; i++) {
            if (courses[i]->getCourse_Name() == course_name) {
                delete courses[i]; // Free dynamically allocated memory
                courses.erase(courses.begin() + i); // Remove course from vector
                this->number_of_courses--; // Decrement course count
                break; // Exit loop after removing the course
            }
        }
    }

    /**
     * Prints all the courses in the schedule.
     */
    void printSchedule() const {
        for (const Course* course : courses) {
            // Print course details
            cout << "Course: " << course->getCourse_Name() << endl;
            cout << "Days: ";
            // Print meeting days
            for (const string& day : course->getMeeting_Days()) {
                cout << day << " ";
            }
            cout << endl;
            // Print course times and professor
            cout << "Time: " << course->getCourse_Start() << " - " << course->getCourse_End() << endl;
            cout << "Professor: " << course->getProfesor() << endl << endl;
        }
    }

    /**
     * Checks for conflicts between two courses based on meeting days.
     * @param course1 Pointer to the first course.
     * @param course2 Pointer to the second course.
     * @return True if there is a conflict (courses held on the same day), otherwise False.
     */
    bool checkConflikt(const Course* course1, const Course* course2) {
        // Check if any meeting day overlaps
        for (const string& day1 : course1->getMeeting_Days()) {
            for (const string& day2 : course2->getMeeting_Days()) {
                if (day1 == day2) {
                    return true; // Conflict found
                }
            }
        }
        return false; // No conflict
    }
};

int main() {
    // Create a schedule object
    Schedule schedule(0);

    // Create course objects dynamically
    Course* course1 = new Course(3, "Prof. A", "Math", "10:00", "09:00", {"Mon", "Wed", "Fri"});
    Course* course2 = new Course(4, "Prof. B", "Science", "11:00", "10:00", {"Tue", "Thu"});
    Course* course3 = new Course(3, "Prof. C", "English", "09:00", "08:00", {"Mon", "Wed"});

    // Add courses to the schedule
    schedule.addCourse(course1);
    schedule.addCourse(course2);
    schedule.addCourse(course3);

    // Print the initial schedule
    cout << "Initial Schedule:" << endl;
    schedule.printSchedule();
    cout << endl;

    // Check for conflicts between courses
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

    // Remove a course from the schedule
    schedule.remove_Course("Math");
    cout << endl << "Schedule after removing Math course:" << endl;
    schedule.printSchedule();

    // Free dynamically allocated memory
    delete course1;
    delete course2;
    delete course3;

    return 0;
}
