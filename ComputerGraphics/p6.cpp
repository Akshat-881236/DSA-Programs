// Create a program to perform 2D transformations: translation, rotation, and scaling on a given set of points.

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Point {
    double x, y;
};

void translate(vector<Point>& points, double tx, double ty) {
    for (auto& point : points) {
        point.x += tx;
        point.y += ty;
    }
}

void rotate(vector<Point>& points, double angle) {
    double radians = angle * M_PI / 180.0;
    double cosA = cos(radians);
    double sinA = sin(radians);
    
    for (auto& point : points) {
        double xNew = point.x * cosA - point.y * sinA;
        double yNew = point.x * sinA + point.y * cosA;
        point.x = xNew;
        point.y = yNew;
    }
}

void scale(vector<Point>& points, double sx, double sy) {
    for (auto& point : points) {
        point.x *= sx;
        point.y *= sy;
    }
}

void printPoints(const vector<Point>& points) {
    for (const auto& point : points) {
        cout << "(" << point.x << ", " << point.y << ")" << endl;
    }
}

int main() {
    vector<Point> points = {{1, 2}, {3, 4}, {5, 6}};
    
    cout << "Original Points:" << endl;
    printPoints(points);
    
    translate(points, 2, 3);
    cout << "\nAfter Translation (tx=2, ty=3):" << endl;
    printPoints(points);
    
    rotate(points, 45);
    cout << "\nAfter Rotation (angle=45 degrees):" << endl;
    printPoints(points);
    
    scale(points, 2, 2);
    cout << "\nAfter Scaling (sx=2, sy=2):" << endl;
    printPoints(points);
    
    return 0;
}

// This program defines a Point structure to represent 2D points and implements three functions for performing translation, rotation, and scaling transformations on a vector of points. The main function demonstrates the usage of these transformations by applying them to a set of points and printing the results after each transformation. 
// Note: The program uses the C++14 language standard version, and it includes the necessary headers for input/output operations, vector manipulation, and mathematical functions.
// To compile the program, use a C++14 compliant compiler with the following command:
// g++ -std=c++14 p6.cpp -o p6
// The output will show the original points, the points after translation, rotation, and scaling transformations. It will not include any graphical representation, as it is a console-based application.