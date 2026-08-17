#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
----------------------------------------------------------
Student Class
Stores student information and calculates average
----------------------------------------------------------
*/
class Student {
public:
    string name;
    int rollNumber;
    vector<int> marks;

    // Calculate average dynamically
    double calculateAverage() const {
        if (marks.empty()) return 0;

        double sum = 0;
        for (int m : marks)
            sum += m;

        return sum / marks.size();
    }

    void display() const {
        cout << "Name: " << name
             << ", Roll: " << rollNumber
             << ", Average: " << calculateAverage()
             << endl;
    }
};

// Function prototypes
void addStudent(vector<Student> &students);
void displayStudents(const vector<Student> &students);
void searchStudent(const vector<Student> &students);
void updateMarks(vector<Student> &students);
void sortStudents(vector<Student> &students);

int main() {

    vector<Student> students;
    int choice;

    do {
        cout << "\nStudent Record Management System\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Marks\n";
        cout << "5. Sort by Average\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: addStudent(students); break;
            case 2: displayStudents(students); break;
            case 3: searchStudent(students); break;
            case 4: updateMarks(students); break;
            case 5: sortStudents(students); break;
        }

    } while(choice != 6);

    return 0;
}

// Add Student
void addStudent(vector<Student> &students) {
    Student s;
    cout << "Enter Name: ";
    cin >> s.name;
    cout << "Enter Roll Number: ";
    cin >> s.rollNumber;

    int subjects;
    cout << "Number of subjects: ";
    cin >> subjects;

    for(int i = 0; i < subjects; i++) {
        int mark;
        cout << "Enter mark " << i+1 << ": ";
        cin >> mark;
        s.marks.push_back(mark);
    }

    students.push_back(s);
}

// Display Students
void displayStudents(const vector<Student> &students) {
    for(auto it = students.begin(); it != students.end(); ++it)
        it->display();
}

// Search Student
void searchStudent(const vector<Student> &students) {
    int roll;
    cout << "Enter Roll Number: ";
    cin >> roll;

    for(const auto &s : students)
        if(s.rollNumber == roll)
            s.display();
}

// Update Marks
void updateMarks(vector<Student> &students) {
    int roll;
    cout << "Enter Roll Number: ";
    cin >> roll;

    for(auto &s : students) {
        if(s.rollNumber == roll) {
            s.marks.clear();
            int subjects;
            cout << "Enter number of subjects: ";
            cin >> subjects;

            for(int i = 0; i < subjects; i++) {
                int mark;
                cin >> mark;
                s.marks.push_back(mark);
            }
        }
    }
}

// Sort Students
void sortStudents(vector<Student> &students) {
    sort(students.begin(), students.end(),
        [](Student a, Student b) {
            return a.calculateAverage() >
                   b.calculateAverage();
        });
}
