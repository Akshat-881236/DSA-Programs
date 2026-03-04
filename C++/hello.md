# Hello World Program in C++

## 🔹 Object-Oriented Programming (OOP) – Definition

<table border="1" cellpadding="8">
<tr>
<th>Aspect</th>
<th>Description</th>
</tr>
<tr>
<td>Definition</td>
<td>Object-Oriented Programming (OOP) is a programming paradigm that organizes programs using objects that represent real-world entities.</td>
</tr>
<tr>
<td>Main Idea</td>
<td>Combines data (variables) and behavior (functions) into a single unit called a class.</td>
</tr>
<tr>
<td>Key Concepts</td>
<td>Encapsulation, Inheritance, Polymorphism, Abstraction</td>
</tr>
<tr>
<td>Encapsulation</td>
<td>Encapsulation is wrapping up of data & member functions in a single unit called class.</td>
</tr>
</table>

---

## 🔹 C++ – Definition

<table border="1" cellpadding="8">
<tr>
<th>Point</th>
<th>Explanation</th>
</tr>
<tr>
<td>Type</td>
<td>General-purpose, high-level programming language</td>
</tr>
<tr>
<td>Creator</td>
<td>Bjarne Stroustrup</td>
</tr>
<tr>
<td>Paradigms Supported</td>
<td>Procedural Programming + Object-Oriented Programming</td>
</tr>
<tr>
<td>Usage</td>
<td>System software, applications, games, competitive programming</td>
</tr>
</table>

---

## 🔹 Procedural Programming (PP) vs Object-Oriented Programming (OOP)

<table border="1" cellpadding="8">
<tr>
<th>Feature</th>
<th>Procedural Programming (PP)</th>
<th>Object-Oriented Programming (OOP)</th>
</tr>
<tr>
<td>Approach</td>
<td>Function-oriented</td>
<td>Object-oriented</td>
</tr>
<tr>
<td>Focus</td>
<td>Logic & procedures</td>
<td>Data & behavior</td>
</tr>
<tr>
<td>Data Security</td>
<td>Low</td>
<td>High (Encapsulation)</td>
</tr>
<tr>
<td>Reusability</td>
<td>Limited</td>
<td>High</td>
</tr>
<tr>
<td>Examples</td>
<td>C</td>
<td>C++, Java</td>
</tr>
</table>

---

## 🔹 Program Description

This program prints welcome messages, takes two user inputs as strings, compares their lengths, and displays the difference in character count.

---

## 🔹 Updated C++ Program

```cpp
#include <iostream>
#include <string.h>
using namespace std;

int main(){
    cout << "Hello World" << endl;
    cout << "Hello Coders" << endl;

    string s1;
    cout << "Enter a Statement : ";
    cin >> s1;

    string s2;
    cout << "Enter another Statement : ";
    cin >> s2;

    if (s1.length() > s2.length()) {
        cout << "Statement 1 has "
             << s1.length() - s2.length()
             << " characters more than Statement 2." << endl;
    }
    else if (s1.length() < s2.length()) {
        cout << "Statement 2 has "
             << s2.length() - s1.length()
             << " characters more than Statement 1." << endl;
    }
    else {
        cout << "Both statement has equal length i.e., "
             << s1.length() << endl;
    }

    cout << "Thank You";
    return 0;
}
```

## 🔹Preprocessor

### In this program 
```cpp
#include <iostream>
```
It is a headerfile preprocessor that is used to tell the compiler that the program is written in C++ .

## 🔹Constructor

Special method invoked automatically at time of object creation. Used for Initialisation .

<ul>
<li> Same name as class </li>
<li> Constructor doesn't have a return type </li>
<li> Only called once (automatically) , at object creation </li>
<li> Memory allocation happens when constructor is called </li>

### Example :

```cpp
#include <iostream>
#include <string>
using namespace std;

class Teacher {
private:
    double salary;
public:
// Non - Parameterized 
    Teacher(){
        dept = "Computer Science";
    }

    string name;
    string dept;
    string subject;

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
};

class Student {
    string name;
    int rollno;
    string course;
};

int main(){
    Teacher t1; // constructor call
    t1.name = "Shradha";
    t1.subject = "C++";
    t1.setSalary(25000);

    cout << t1.dept << endl;
    return 0;
}
```

## Constructor are of three types :-
<li>Non-parameterized Constructor </li>
<li>Parameterized Constructor</li>
<li>Copy Constructor </li>

## this Pointer :-

<b>this</b> is a special pointer in C++ that points to the current object . 

<code>this->prop</code> is same as <code>*(this).prop</code>

## C++ Examples using <code>this->prop</code> :-

```cpp
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
    string name;
    int rollno;
    string course;
};

int main(){
    Teacher t1("Aman", "Computer Science", "C++", 25000);
    t1.getInfo();
    return 0;
}
```

```cpp
// Output of the Program :-

Name : Aman
Subject : C++
Dept : Computer Science
```

## Copy Constructor :-
Special Constructor (default) used to copy properties of one object into another .

``` cpp
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
    string name;
    int rollno;
    string course;
};

int main(){
    Teacher t1("Aman", "Computer Science", "C++", 25000);
    t1.getInfo();

    Teacher t2(t1);
    t2.getInfo();
    return 0;
}
```
``` cpp
// Output of the Program :-
Name : Aman
Subject : C++
Dept : Computer Science
I'm Custom copy Constructor
Name : Aman
Subject : C++
Dept : Computer Science
```

#### Type of Copy  Constructor :-
1. Shallow Copy
2. Deep Copy