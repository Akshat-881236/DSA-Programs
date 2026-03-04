// Write a program to implement the Cohen-Sutherland line clipping algorithm to clip a line within a rectangular clipping window.

#include <graphics.h>
#include <iostream>
using namespace std;

const int INSIDE = 0;
const int LEFT = 1;
const int RIGHT = 2;
const int BOTTOM = 4;
const int TOP = 8;

int xmin = 100, ymin = 100, xmax = 300, ymax = 300;

int computeCode(double x, double y)
{
    int code = INSIDE;

    if (x < xmin)
        code |= LEFT;
    else if (x > xmax)
        code |= RIGHT;

    if (y < ymin)
        code |= BOTTOM;
    else if (y > ymax)
        code |= TOP;

    return code;
}

void cohenSutherlandClip(double x1, double y1, double x2, double y2)
{
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);

    bool accept = false;

    while (true)
    {
        if ((code1 == 0) && (code2 == 0))
        {
            accept = true;
            break;
        }
        else if (code1 & code2)
        {
            break;
        }
        else
        {
            int code_out;
            double x, y;

            if (code1 != 0)
                code_out = code1;
            else
                code_out = code2;

            if (code_out & TOP)
            {
                x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
                y = ymax;
            }
            else if (code_out & BOTTOM)
            {
                x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
                y = ymin;
            }
            else if (code_out & RIGHT)
            {
                y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
                x = xmax;
            }
            else if (code_out & LEFT)
            {
                y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
                x = xmin;
            }

            if (code_out == code1)
            {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            }
            else
            {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }

    if (accept)
    {
        setcolor(RED);
        line(x1, y1, x2, y2);
    }
}

int main()
{
    int gd = DETECT, gm;

    initgraph(&gd, &gm, (char*)"");

    rectangle(xmin, ymin, xmax, ymax);

    double x1 = 50, y1 = 50, x2 = 350, y2 = 350;

    setcolor(WHITE);
    line(x1, y1, x2, y2);

    cohenSutherlandClip(x1, y1, x2, y2);

    getch();
    closegraph();
}

// Program Description:
// This program implements the Cohen-Sutherland line clipping algorithm to clip a line within a rectangular clipping window defined by the coordinates (xmin, ymin) and (xmax, ymax). The `computeCode` function calculates the region code for a point based on its position relative to the clipping window. The `cohenSutherlandClip` function performs the line clipping using the region codes and updates the endpoints of the line accordingly. The main function initializes the graphics mode, draws the clipping rectangle and the original line, and then calls the clipping function to display the clipped line in red. Finally, it waits for a key press before closing the graphics window.