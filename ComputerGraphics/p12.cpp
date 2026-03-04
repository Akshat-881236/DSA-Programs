// Write a program to implement line clipping using the Cohen-Sutherland line clipping algorithm.

#include <graphics.h>
#include <iostream>
using namespace std;

const int INSIDE = 0;
const int LEFT = 1;
const int RIGHT = 2;
const int BOTTOM = 4;
const int TOP = 8;

int xmin = 150, ymin = 100, xmax = 450, ymax = 350;

int computeCode(int x, int y)
{
    int code = INSIDE;

    if(x < xmin)
        code |= LEFT;
    else if(x > xmax)
        code |= RIGHT;

    if(y < ymin)
        code |= BOTTOM;
    else if(y > ymax)
        code |= TOP;

    return code;
}

void cohenSutherland(int x1,int y1,int x2,int y2)
{
    int code1 = computeCode(x1,y1);
    int code2 = computeCode(x2,y2);

    bool accept = false;

    while(true)
    {
        if(code1 == 0 && code2 == 0)
        {
            accept = true;
            break;
        }
        else if(code1 & code2)
        {
            break;
        }
        else
        {
            int code_out;
            int x,y;

            if(code1 != 0)
                code_out = code1;
            else
                code_out = code2;

            if(code_out & TOP)
            {
                x = x1 + (x2-x1)*(ymax-y1)/(y2-y1);
                y = ymax;
            }
            else if(code_out & BOTTOM)
            {
                x = x1 + (x2-x1)*(ymin-y1)/(y2-y1);
                y = ymin;
            }
            else if(code_out & RIGHT)
            {
                y = y1 + (y2-y1)*(xmax-x1)/(x2-x1);
                x = xmax;
            }
            else
            {
                y = y1 + (y2-y1)*(xmin-x1)/(x2-x1);
                x = xmin;
            }

            if(code_out == code1)
            {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1,y1);
            }
            else
            {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2,y2);
            }
        }
    }

    if(accept)
    {
        setcolor(RED);
        line(x1,y1,x2,y2);
    }
}

int main()
{
    int gd = DETECT, gm;

    initgraph(&gd,&gm,(char*)"");

    rectangle(xmin,ymin,xmax,ymax);

    int x1 = 100, y1 = 50, x2 = 500, y2 = 400;

    setcolor(WHITE);
    line(x1,y1,x2,y2);

    cohenSutherland(x1,y1,x2,y2);

    getch();
    closegraph();
}

// This program implements the Cohen-Sutherland line clipping algorithm. It defines a rectangular clipping window and a line segment. The algorithm determines whether the line segment is completely inside, completely outside, or partially inside the clipping window. If the line segment is partially inside, it calculates the intersection points with the clipping window and draws the clipped line segment in red. 
// The program uses the graphics library to display the clipping window and the line segment.