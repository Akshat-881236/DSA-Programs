// Write a program to apply various coloring techniques to 3D object.

#include <graphics.h>
#include <dos.h>
#include <conio.h>

void drawCube()
{
    setcolor(WHITE);

    rectangle(80,180,140,240);
    rectangle(100,160,160,220);

    line(80,180,100,160);
    line(140,180,160,160);
    line(140,240,160,220);

    setfillstyle(SOLID_FILL,RED);
    floodfill(90,190,WHITE);

    outtextxy(95,250,"CUBE");
}

void drawCuboid()
{
    setcolor(WHITE);

    rectangle(220,180,300,240);
    rectangle(250,160,330,220);

    line(220,180,250,160);
    line(300,180,330,160);
    line(300,240,330,220);

    setfillstyle(HATCH_FILL,CYAN);
    floodfill(230,190,WHITE);

    outtextxy(255,250,"CUBOID");
}

void drawPyramid()
{
    setcolor(WHITE);

    line(420,240,460,170);
    line(460,170,500,240);
    line(420,240,500,240);

    line(460,170,460,240);

    setfillstyle(SLASH_FILL,YELLOW);
    floodfill(460,210,WHITE);

    outtextxy(440,250,"PYRAMID");
}

void drawSphere()
{
    setcolor(WHITE);

    circle(150,340,40);

    setfillstyle(SOLID_FILL,LIGHTBLUE);
    floodfill(150,340,WHITE);

    outtextxy(130,390,"SPHERE");
}

void drawCylinder()
{
    setcolor(WHITE);

    ellipse(350,310,0,360,40,15);
    line(310,310,310,360);
    line(390,310,390,360);
    ellipse(350,360,0,360,40,15);

    setfillstyle(WIDE_DOT_FILL,GREEN);
    floodfill(350,330,WHITE);

    outtextxy(330,390,"CYLINDER");
}

int main()
{
    int gd = DETECT, gm;

    initgraph(&gd,&gm,(char*)"");

    // Background
    setfillstyle(SOLID_FILL, DARKGRAY);
    bar(0,0,640,480);

    setcolor(WHITE);
    settextstyle(BOLD_FONT,HORIZ_DIR,3);
    outtextxy(120,20,"3D OBJECT COLORING TECHNIQUES");

    // Draw objects
    drawCube();
    drawCuboid();
    drawPyramid();
    drawSphere();
    drawCylinder();

    getch();
    closegraph();
}

// Program Description: This program demonstrates various coloring techniques applied to 3D objects such as a cube, cuboid, pyramid, sphere, and cylinder using the graphics library in C++. Each object is drawn with a different fill style and color to showcase the effects of different coloring techniques. The program initializes a graphics window, sets a background color, and then uses functions to draw each object with specific colors and fill styles. The user can view the objects and their respective coloring techniques in the graphics window. The program ends when the user presses a key, at which point the graphics window is closed.