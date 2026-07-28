// //design a programme to convert a precedural implementation of a student record system into an object oriented approach using class and object.
// #include <iostream>
// #include <vector>
// #include <string>
// #include <iomanip>

// using namespace std;

// class Student {
// private:
//     int rollNo;
//     string name;
//     int marks[5];
//     float percentage;
//     char grade;

//     void calculatePercentage() {
//         int total = 0;
//         for (int i = 0; i < 5; i++) {
//             total += marks[i];
//         }
//         percentage = total / 5.0;
//     }

//     void calculateGrade() {
//         if (percentage >= 90)
//             grade = 'A';
//         else if (percentage >= 80)
//             grade = 'B';
//         else if (percentage >= 70)
//             grade = 'C';
//         else if (percentage >= 60)
//             grade = 'D';
//         else
//             grade = 'F';
//     }

// public:
//     Student(int rNo, string sName, int m[]) {
//         rollNo = rNo;
//         name = sName;

//         for (int i = 0; i < 5; i++) {
//             marks[i] = m[i];
//         }

//         calculatePercentage();
//         calculateGrade();
//     }

//     int getRollNo() const {
//         return rollNo;
//     }

//     void display() const {
//         cout << "\n-----------------------------------\n";
//         cout << "Roll No    : " << rollNo << endl;
//         cout << "Name       : " << name << endl;

//         cout << "Marks      : ";
//         for (int i = 0; i < 5; i++)
//             cout << marks[i] << " ";

//         cout << endl;
//         cout << fixed << setprecision(2);
//         cout << "Percentage : " << percentage << "%" << endl;
//         cout << "Grade      : " << grade << endl;
//         cout << "-----------------------------------\n";
//     }
// };

// class StudentRecordSystem {
// private:
//     vector<Student> students;

// public:
//     void addStudent(int rollNo, string name, int marks[]) {
//         students.push_back(Student(rollNo, name, marks));
//         cout << "\nStudent Record Added Successfully!\n";
//     }

//     void displayAllStudents() const {
//         if (students.empty()) {
//             cout << "\nNo Student Records Found.\n";
//             return;
//         }

//         cout << "\n========== Student Records ==========\n";

//         for (const auto &student : students)
//             student.display();
//     }

//     void searchStudent(int rollNo) const {
//         for (const auto &student : students) {
//             if (student.getRollNo() == rollNo) {
//                 cout << "\nStudent Found!\n";
//                 student.display();
//                 return;
//             }
//         }

//         cout << "\nStudent with Roll No " << rollNo << " not found.\n";
//     }
// };

// int main() {
//     StudentRecordSystem system;
//     int choice;

//     do {
//         cout << "\n========= Student Record System =========\n";
//         cout << "1. Add Student\n";
//         cout << "2. Display All Students\n";
//         cout << "3. Search Student by Roll No\n";
//         cout << "4. Exit\n";
//         cout << "Enter Choice: ";
//         cin >> choice;

//         switch (choice) {
//         case 1: {
//             int rollNo;
//             string name;
//             int marks[5];

//             cout << "Enter Roll No: ";
//             cin >> rollNo;

//             cin.ignore();

//             cout << "Enter Student Name: ";
//             getline(cin, name);

//             cout << "\nEnter Marks for 5 Subjects\n";

//             for (int i = 0; i < 5; i++) {
//                 cout << "Subject " << i + 1 << ": ";
//                 cin >> marks[i];
//             }

//             system.addStudent(rollNo, name, marks);
//             break;
//         }

//         case 2:
//             system.displayAllStudents();
//             break;

//         case 3: {
//             int rollNo;
//             cout << "Enter Roll No to Search: ";
//             cin >> rollNo;
//             system.searchStudent(rollNo);
//             break;
//         }

//         case 4:
//             cout << "\nThank You! Exiting Program...\n";
//             break;

//         default:
//             cout << "\nInvalid Choice! Try Again.\n";
//         }

//     } while (choice != 4);

//     return 0;
// }
// Design a program to convert a procedural implementation of a Student Record System
// into an Object-Oriented approach using Classes and Objects.

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class Student {
private:
    int rollNo;
    string name;
    int marks[5];
    float percentage;
    char grade;

    void calculatePercentage() {
        int total = 0;
        for (int i = 0; i < 5; i++) {
            total += marks[i];
        }
        percentage = total / 5.0;
    }

    void calculateGrade() {
        if (percentage >= 90)
            grade = 'A';
        else if (percentage >= 80)
            grade = 'B';
        else if (percentage >= 70)
            grade = 'C';
        else if (percentage >= 60)
            grade = 'D';
        else
            grade = 'F';
    }

public:
    Student(int rNo, string sName, int m[]) {
        rollNo = rNo;
        name = sName;

        for (int i = 0; i < 5; i++) {
            marks[i] = m[i];
        }

        calculatePercentage();
        calculateGrade();
    }

    int getRollNo() const {
        return rollNo;
    }

    void display() const {
        cout << "\n-----------------------------------\n";
        cout << "Roll No    : " << rollNo << endl;
        cout << "Name       : " << name << endl;

        cout << "Marks      : ";
        for (int i = 0; i < 5; i++) {
            cout << marks[i] << " ";
        }
        cout << endl;

        cout << fixed << setprecision(2);
        cout << "Percentage : " << percentage << "%" << endl;
        cout << "Grade      : " << grade << endl;
        cout << "-----------------------------------\n";
    }
};

class StudentRecordSystem {
private:
    vector<Student> students;

public:
    void addStudent(int rollNo, string name, int marks[]) {
        if (!students.empty()) {
            cout << "\nOnly one student record is allowed.\n";
            return;
        }

        students.push_back(Student(rollNo, name, marks));
        cout << "\nStudent Record Added Successfully!\n";
    }

    void displayAllStudents() const {
        if (students.empty()) {
            cout << "\nNo Student Records Found.\n";
            return;
        }

        cout << "\n========== Student Record ==========\n";

        for (const auto &student : students) {
            student.display();
        }
    }

    void searchStudent(int rollNo) const {
        for (const auto &student : students) {
            if (student.getRollNo() == rollNo) {
                cout << "\nStudent Found!\n";
                student.display();
                return;
            }
        }

        cout << "\nStudent with Roll No " << rollNo << " not found.\n";
    }
};

int main() {
    StudentRecordSystem system;
    int choice;

    do {
        cout << "\n========== Student Record System ==========\n";
        cout << "1. Add Student\n";
        cout << "2. Display Student Record\n";
        cout << "3. Search Student by Roll No\n";
        cout << "4. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {

        case 1: {
            int rollNo;
            string name;
            int marks[5];

            cout << "Enter Roll No: ";
            cin >> rollNo;
            cin.ignore();

            cout << "Enter Student Name: ";
            getline(cin, name);

            cout << "\nEnter Marks for 5 Subjects\n";
            for (int i = 0; i < 5; i++) {
                cout << "Subject " << i + 1 << ": ";
                cin >> marks[i];
            }

            system.addStudent(rollNo, name, marks);
            break;
        }

        case 2:
            system.displayAllStudents();
            break;

        case 3: {
            int rollNo;
            cout << "Enter Roll No to Search: ";
            cin >> rollNo;
            system.searchStudent(rollNo);
            break;
        }

        case 4:
            cout << "\nThank You! Exiting Program...\n";
            break;

        default:
            cout << "\nInvalid Choice! Please Try Again.\n";
        }

    } while (choice != 4);

    return 0;
}