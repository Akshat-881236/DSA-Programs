// Write a program to apply a shearing transformation to a 2D object (like a square or triangle) and display the original and transformed objects.

#include <graphics.h>
#include <iostream>
using namespace std;

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    int x[3] = {200, 250, 150};
    int y[3] = {150, 250, 250};

    float shx = 1.0;
    float shy = 0.5;

    int xs[3], ys[3];

    for(int i = 0; i < 3; i++)
    {
        xs[i] = x[i] + shx * y[i];
        ys[i] = y[i] + shy * x[i];
    }

    setcolor(WHITE);
    line(x[0], y[0], x[1], y[1]);
    line(x[1], y[1], x[2], y[2]);
    line(x[2], y[2], x[0], y[0]);

    outtextxy(180,120,"Original Triangle");

    setcolor(RED);
    line(xs[0], ys[0], xs[1], ys[1]);
    line(xs[1], ys[1], xs[2], ys[2]);
    line(xs[2], ys[2], xs[0], ys[0]);

    outtextxy(xs[0], ys[0]-20,"Sheared Triangle");

    getch();
    closegraph();
}

// Program Description:
// This program applies a shearing transformation to a triangle defined by its vertices (x, y). The shearing factors `shx` and `shy` are used to calculate the new coordinates of the triangle's vertices after shearing. The original triangle is drawn in white, and the sheared triangle is drawn in red. The program also labels both the original and sheared triangles for clarity. Finally, it waits for a key press before closing the graphics window.
// Note: Make sure to have the graphics library properly set up in your development environment to run this code successfully.