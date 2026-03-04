#include <iostream>
#include <string>
using namespace std;

class Teacher {
private:
    double salary;
public:
    string name;
    string dept;
    string subject;
// Parameterized 
    Teacher(string name, string dept, string subject, double salary){
        this->name = name;
        this->dept = dept;
        this->subject = subject;
        this->salary = salary;
    }

// Copy Constructor 
        Teacher(Teacher &orgObj){ // pass by reference
            cout << "I'm Custom copy Constructor" << endl;
            this->name = orgObj.name;
            this->dept = orgObj.dept;
            this->subject = orgObj.subject;
            this->salary = orgObj.salary;
        }


    void changeDept(string newDept){
        dept = newDept;
    }
//setter
    void setSalary(double newSalary) {
        salary = newSalary;
    }
//getter
    double getSalary(){
        return salary;
    }
    void getInfo(){
        cout << "Name : " << name << endl;
        cout << "Subject : " << subject << endl;
        cout << "Dept : " << dept << endl;
    }
};

class Student {
public:
    string name;
    int rollno;
    string course;
    double* cgpaPtr;

    Student(string name, double cgpa) {
        this->name = name;
        cgpaPtr = new double;
        *cgpaPtr = cgpa;
    }

    Student(Student &obj) {
        this->name = obj.name;
        cgpaPtr = new double;
        *cgpaPtr = *obj.cgpaPtr;
    }

    // Destructor
    ~Student() {
        cout << "Hi, I delete everything." << endl;
        delete cgpaPtr; // to prevent memory leak
    }

    void getInfo() {
        cout << "Name : " << name << endl;
        cout << "CGPA : " << *cgpaPtr << endl;
    }
};

int main(){
    Teacher t1("Aman", "Computer Science", "C++", 25000);
    t1.getInfo();

    Teacher t2(t1);
    t2.getInfo();

    Student S1("Rahul Kumar", 8.9);
    S1.getInfo();

    Student S2(S1);
    S2.name = "Neha";
    *(S2.cgpaPtr) = 9.2;
    S2.getInfo();
    S1.getInfo();
    return 0;
}