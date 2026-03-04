// Create a program to draw a line using Bresenham's line drawing algorithm. 

#include <graphics.h>
#include <math.h>
#include <iostream>
#include <cstdlib>

void bresenham(int x1, int y1, int x2, int y2)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (true)
    {
        putpixel(x1, y1, WHITE);

        if (x1 == x2 && y1 == y2)
            break;

        int err2 = err * 2;

        if (err2 > -dy)
        {
            err -= dy;
            x1 += sx;
        }

        if (err2 < dx)
        {
            err += dx;
            y1 += sy;
        }
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    int x1, y1, x2, y2;

    std::cout << "Enter the coordinates of the first point (x1 y1): ";
    std::cin >> x1 >> y1;

    std::cout << "Enter the coordinates of the second point (x2 y2): ";
    std::cin >> x2 >> y2;

    bresenham(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}

// Program Description :-
// This program implements Bresenham's line drawing algorithm to draw a line between two points in a graphics window. The user is prompted to enter the coordinates of the two points, and the algorithm calculates the intermediate points to create a smooth line. The line is drawn using the `putpixel` function, which sets the color of individual pixels on the screen. The program uses the graphics library to create a window and display the line.