// Write a program to apply various coloring techniques to 2D pictures.

#include <graphics.h>
#include <iostream>
using namespace std;

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    // SKY
    setfillstyle(SOLID_FILL, LIGHTBLUE);
    bar(0,0,640,250);

    // GROUND
    setfillstyle(SOLID_FILL, GREEN);
    bar(0,250,640,480);

    // SUN
    setcolor(YELLOW);
    circle(500,80,40);
    setfillstyle(SOLID_FILL,YELLOW);
    floodfill(500,80,YELLOW);

    // HOUSE BODY
    setcolor(WHITE);
    rectangle(200,200,350,320);
    setfillstyle(SOLID_FILL,RED);
    floodfill(210,210,WHITE);

    // ROOF
    setcolor(WHITE);
    line(200,200,275,150);
    line(275,150,350,200);
    setfillstyle(HATCH_FILL,BROWN);
    floodfill(275,180,WHITE);

    // DOOR
    setcolor(WHITE);
    rectangle(260,250,300,320);
    setfillstyle(SOLID_FILL,BROWN);
    floodfill(270,260,WHITE);

    // WINDOW
    setcolor(WHITE);
    rectangle(215,230,245,260);
    setfillstyle(SOLID_FILL,CYAN);
    floodfill(220,235,WHITE);

    // TREE TRUNK
    setcolor(WHITE);
    rectangle(120,230,140,320);
    setfillstyle(SOLID_FILL,BROWN);
    floodfill(125,240,WHITE);

    // TREE LEAVES
    setcolor(GREEN);
    circle(130,200,35);
    setfillstyle(SOLID_FILL,GREEN);
    floodfill(130,200,GREEN);

    // TEXT TITLE
    setcolor(WHITE);
    outtextxy(180,20,"2D Coloring Techniques using graphics.h");

    // TEXT CREDITS SHOWING STUDENT NAME AND ROLL NUMBER
    outtextxy(180,40,"Student Name: Akshat Prasad");
    outtextxy(180,60,"Roll Number: 145609");
    outtextxy(180,80,"Course: Computer Graphics");
    outtextxy(180,100,"Campus: DPG Universe");
    outtextxy(180,120,"Instructor: Ms. Shikha Mathur");

    getch();
    closegraph();
}

// Program Description:
// This program demonstrates various coloring techniques to create a simple 2D scene using the graphics.h library. The scene includes a sky, ground, sun, house with a roof, door, and window, as well as a tree with a trunk and leaves. Different colors and fill styles are used to enhance the visual appeal of the scene. The program initializes the graphics mode, draws the various elements of the scene with appropriate colors and fills, and finally waits for a key press before closing the graphics window.
// Note: Make sure to have the graphics library properly set up in your development environment to run this code successfully.