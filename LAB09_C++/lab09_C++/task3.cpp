#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student {
private:
    string name;
    vector<int> marks;

public:
    Student(string n) {
        name = n;
    }

    void add_mark(int m) {
        marks.push_back(m);
    }

    void display() const {
        cout << "Name: " << name << endl;
        cout << "Marks: ";
        for (int m : marks)
            cout << m << " ";
        cout << endl;
    }

    friend double calculate_average(const Student& s);
};

// Friend function
double calculate_average(const Student& s) {
    int sum = 0;
    for (int m : s.marks)
        sum += m;
    return (double)sum / s.marks.size();
}

// Custom print function (for function pointer)
void print_student(const Student& s) {
    s.display();
    cout << "Average: " << calculate_average(s) << endl;
    cout << "----------------------\n";
}

int main() {

    vector<Student> students;

    Student s1("Ali");
    s1.add_mark(80);
    s1.add_mark(85);

    Student s2("Sara");
    s2.add_mark(70);
    s2.add_mark(65);

    Student s3("Ahmed");
    s3.add_mark(90);
    s3.add_mark(88);

    students.push_back(s1);
    students.push_back(s2);
    students.push_back(s3);

    // Lambda to filter students with average > 75
    auto filter = [](const Student& s) {
        return calculate_average(s) > 75;
    };

    // Function pointer
    void (*func_ptr)(const Student&) = print_student;

    cout << "Students with Average > 75:\n";

    for (const Student& s : students) {
        if (filter(s)) {
            func_ptr(s);
        }
    }

    return 0;
}
