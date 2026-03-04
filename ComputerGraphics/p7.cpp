// Write a program to perform mirror reflection of a 2D shape across the x-axis and y-axis.
// Write a program to perform mirror reflection of a 2D shape
// across X-axis and Y-axis using graphics.h

#include <graphics.h>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>

using namespace std;

// Structure for Point
struct Point {
    int x, y;
};

// Function to draw triangle
void drawTriangle(vector<Point> &shape, int color) {
    setcolor(color);

    for (int i = 0; i < shape.size(); i++) {
        int next = (i + 1) % shape.size();
        line(shape[i].x, shape[i].y,
             shape[next].x, shape[next].y);
    }
}

// Mirror across X-axis
vector<Point> mirrorX(vector<Point> shape, int midY) {
    vector<Point> reflected;

    for (auto p : shape) {
        Point temp;
        temp.x = p.x;
        temp.y = 2 * midY - p.y;   // Reflection formula
        reflected.push_back(temp);
    }

    return reflected;
}

// Mirror across Y-axis
vector<Point> mirrorY(vector<Point> shape, int midX) {
    vector<Point> reflected;

    for (auto p : shape) {
        Point temp;
        temp.x = 2 * midX - p.x;   // Reflection formula
        temp.y = p.y;
        reflected.push_back(temp);
    }

    return reflected;
}

int main() {

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int midX = getmaxx() / 2;
    int midY = getmaxy() / 2;

    // Draw X and Y axis
    setcolor(WHITE);
    line(0, midY, getmaxx(), midY);   // X-axis
    line(midX, 0, midX, getmaxy());   // Y-axis

    // Original Triangle
    vector<Point> triangle;

    triangle.push_back({midX, midY - 100});
    triangle.push_back({midX - 100, midY + 100});
    triangle.push_back({midX + 100, midY + 100});

    // Draw original (RED)
    drawTriangle(triangle, RED);

    // Reflection across X-axis (GREEN)
    vector<Point> reflectX = mirrorX(triangle, midY);
    drawTriangle(reflectX, GREEN);

    // Reflection across Y-axis (BLUE)
    vector<Point> reflectY = mirrorY(triangle, midX);
    drawTriangle(reflectY, BLUE);

    getch();
    closegraph();

    return 0;
}

// Program Description:
// This program demonstrates mirror reflection of a 2D shape (a triangle) across the X-axis and Y-axis using the graphics.h library in C++. The program initializes a graphics window, draws the original triangle in red, and then creates and draws the reflected triangles in green (for X-axis reflection) and blue (for Y-axis reflection). The reflections are calculated using the standard formulas for mirror reflection across axes.