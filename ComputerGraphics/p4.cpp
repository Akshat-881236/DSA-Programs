// Write a program to draw a circle using the Midpoint Circle algorithm.

#include <graphics.h>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>

class Point {
public:
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
};

void drawCircle(int xc, int yc, int r) {
    int x = 0;
    int y = r;
    int d = 3 - 2 * r;

    while (x <= y) {
        // Draw the eight symmetrical points
        putpixel(xc + x, yc + y, RED);
        putpixel(xc - x, yc + y, RED);
        putpixel(xc + x, yc - y, RED);
        putpixel(xc - x, yc - y, RED);
        putpixel(xc + y, yc + x, RED);
        putpixel(xc - y, yc + x, RED);
        putpixel(xc + y, yc - x, RED);
        putpixel(xc - y, yc - x, RED);

        if (d < 0) {
            d = d + 4 * x + 6;
        } else {
            d = d + 4 * (x - y) + 10;
            y--;
        }
        x++;
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    int xc, yc, r;

    std::cout << "Enter the center coordinates of the circle (xc yc): ";
    std::cin >> xc >> yc;

    std::cout << "Enter the radius of the circle: ";
    std::cin >> r;

    drawCircle(xc, yc, r);

    getch();
    closegraph();
    return 0;
}

// Program Description :-
// This program implements the Midpoint Circle algorithm to draw a circle in a graphics window. The user is prompted to enter the center coordinates and the radius of the circle. The algorithm calculates the points on the circumference of the circle using symmetry and draws them using the `putpixel` function. The program uses the graphics library to create a window and display the circle.
// The Midpoint Circle algorithm is an efficient way to determine the points needed for rasterizing a circle. It uses a decision parameter to determine whether to move vertically or horizontally to the next point on the circle's circumference, ensuring that the circle is drawn smoothly and accurately.