// Implement a program to demonstrate simple animations using transformations such as translation, rotation, and scaling.

#include <graphics.h>
#include <math.h>
#include <dos.h>

void drawBranding()
{
    setcolor(YELLOW);
    settextstyle(BOLD_FONT,HORIZ_DIR,2);
    outtextxy(180,10,"COMPUTER GRAPHICS PRACTICAL");

    setcolor(WHITE);
    settextstyle(DEFAULT_FONT,HORIZ_DIR,1);

    outtextxy(20,40,"Student Name: Akshat Prasad");
    outtextxy(20,60,"Roll Number: 145609");
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd,&gm,(char*)"");

    int x = 0;
    float angle = 0;
    int r = 25;

    while(!kbhit())
    {
        cleardevice();

        // SKY
        setfillstyle(SOLID_FILL,LIGHTBLUE);
        bar(0,140,640,240);

        // GROUND
        setfillstyle(SOLID_FILL,GREEN);
        bar(0,240,640,480);

        // SUN (SCALING)
        setcolor(YELLOW);
        setfillstyle(SOLID_FILL,YELLOW);
        circle(550,170,r);

        // ROAD
        setcolor(WHITE);
        line(0,320,640,320);

        // CAR BODY (TRANSLATION)
        setcolor(RED);
        rectangle(x,270,x+120,310);

        // CAR TOP
        line(x+20,270,x+50,240);
        line(x+50,240,x+90,240);
        line(x+90,240,x+110,270);

        // WHEELS
        setcolor(BLACK);
        circle(x+30,320,20);
        circle(x+90,320,20);

        // WHEEL ROTATION
        setcolor(WHITE);
        line(x+30,320,
             x+30+20*cos(angle),
             320+20*sin(angle));

        line(x+90,320,
             x+90+20*cos(angle),
             320+20*sin(angle));

        // DRAW BRANDING (ALWAYS VISIBLE)
        drawBranding();

        delay(40);

        // Transformations
        x += 5;
        angle += 0.25;
        r += 1;

        if(r > 40)
            r = 25;

        if(x > 640)
            x = -120;
    }

    closegraph();
}

// This program creates a simple animation of a car moving across the screen with rotating wheels and a pulsating sun. The car is translated across the screen, the wheels are rotated, and the sun is scaled to create a dynamic animation. After the animation, a branding screen is displayed with student and course information. 
// Note: This code uses the BGI graphics library, which may require specific setup to run on modern systems.
// The Program output includes a moving car with rotating wheels and a pulsating sun, followed by a branding screen with student and course details.