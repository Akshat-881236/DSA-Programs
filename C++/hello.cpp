#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    string name;
    int age;
};

class Student : public Person {
public:
    int rollno;
    string course;
    float cgpa;
};

class Teacher : public Person {
protected:
    int salary;
public:
    int EmpId;
    string Dept;
};

int main() {
    Teacher T1;
    T1.name = "Aman";
    T1.EmpId = 101;
    T1.Dept = "Computer Science";

    cout << "Name: " << T1.name << endl;
    cout << "Emp ID: " << T1.EmpId << endl;
    cout << "Department: " << T1.Dept << endl;
    return 0;
}