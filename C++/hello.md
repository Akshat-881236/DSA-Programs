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

# 🧪 C++ Practical Examination Paper  
## (As per :contentReference[oaicite:0]{index=0} – MDU Standard)

**Course:** BCA / B.Sc. (Computer Science) / B.Tech (as applicable)  
**Subject:** Programming in C++ (Practical)  
**Time:** 3 Hours  
**Maximum Marks:** 50  

---

## Instructions:
1. Attempt **any FIVE (5)** questions.
2. Each question carries **equal marks**.
3. Use proper **indentation, comments, and syntax**.
4. Write **output** wherever required.
5. Use only **standard C++** features.

---

## Q1. Basic C++ Program  
Write a C++ program to display the message:  
**“Welcome to C++ Programming”**  
Explain the role of:
- `#include <iostream>`
- `main()` function

---

## Q2. Conditional Statement  
Write a C++ program to input a number from the user and check whether it is:
- Positive
- Negative
- Zero  

Use **if–else if–else** statement.

---

## Q3. Loop-Based Program  
Write a C++ program to print the **first N natural numbers** and their **sum** using a `for` loop.  
Take the value of **N** from the user.

---

## Q4. Function Program  
Write a C++ program to:
- Define a function to check whether a number is **prime or not**
- Call the function from `main()`

---

## Q5. Array Handling  
Write a C++ program to:
- Declare an integer array of size 10
- Input elements from the user
- Find and display the **largest element** in the array

---

## Q6. String Manipulation  
Write a C++ program to:
- Input a string from the user
- Count and display the **number of vowels** present in the string

---

## Q7. Object Oriented Programming  
Write a C++ program using **class and object** to:
- Create a class `Employee`
- Data members: `empId`, `name`, `salary`
- Member functions to input and display employee details

---

## Q8. Constructor Concept  
Write a C++ program to demonstrate the use of a **constructor** by:
- Initializing data members of a class
- Displaying the initialized values

---

### ✦✦✦ End of Question Paper ✦✦✦