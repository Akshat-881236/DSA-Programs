// Implement a program to draw a circle using Bresenham's circle drawing algorithm.

#include <graphics.h>
#include <iostream>
#include <cmath>

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
// This program implements Bresenham's circle drawing algorithm to draw a circle on the screen. The `drawCircle` function takes the center coordinates (xc, yc) and the radius (r) as input and uses the algorithm to calculate the points on the circumference of the circle. The program initializes the graphics mode, prompts the user for the center coordinates and radius, and then calls the `drawCircle` function to render the circle on the screen. Finally, it waits for a key press before closing the graphics window.