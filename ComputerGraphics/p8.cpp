// Simple program on this without glut
// Create a program to draw basic two-dimensional objects like rectangles, triangles, and polygons using inbuilt functions.

#include <graphics.h>
#include <conio.h>
#include <iostream>
#include <cmath>

using namespace std;

// function to draw a rectangle
void drawRectangle(int x1, int y1, int x2, int y2) {
    rectangle(x1, y1, x2, y2);
}

// function to draw a triangle
void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

// function to draw a polygon
void drawPolygon(int points[][2], int n) {
    for (int i = 0; i < n; i++) {
        line(points[i][0], points[i][1], points[(i + 1) % n][0], points[(i + 1) % n][1]);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // Draw a rectangle
    drawRectangle(50, 50, 150, 100);

    // Draw a triangle
    drawTriangle(200, 50, 250, 100, 150, 100);

    // Draw a polygon (pentagon)
    int points[5][2] = {{300, 50}, {350, 100}, {325, 150}, {275, 150}, {250, 100}};
    drawPolygon(points, 5);

    getch();
    closegraph();
    return 0;
}

// Note: Make sure to have the graphics library properly set up in your development environment to run this code successfully.
// Program Description:
// This program uses the graphics.h library to create a simple graphical application that draws basic two-dimensional shapes: a rectangle, a triangle, and a polygon (pentagon). The functions `drawRectangle`, `drawTriangle`, and `drawPolygon` are defined to encapsulate the drawing logic for each shape. The main function initializes the graphics mode, calls the drawing functions to render the shapes on the screen, and waits for a key press before closing the graphics window.
// The program demonstrates the use of basic graphics functions to create simple shapes, and it can be extended to include more complex shapes or additional features as needed.