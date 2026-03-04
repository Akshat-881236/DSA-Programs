// #include <graphics.h>
// #include <conio.h>

// int main()
// {
//     int gd = DETECT, gm;

//     initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

//     // Drawing a Point
//     putpixel(100, 100, WHITE);

//     // Drawing a Line
//     line(150, 100, 300, 100);

//     // Drawing a Rectangle
//     rectangle(150, 150, 300, 250);

//     // Drawing a Circle
//     circle(400, 200, 50);

//     // Drawing a Polygon (Triangle)
//     int points[] = {200, 300, 250, 350, 150, 350, 200, 300};
//     drawpoly(4, points);

//     getch();
//     closegraph();
//     return 0;
// }

#include <graphics.h>
#include <conio.h>

int main()
{
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // Point
    putpixel(100, 100, WHITE);

    // Line
    line(150, 100, 300, 100);

    // Rectangle
    rectangle(150, 150, 300, 250);

    // Circle
    circle(400, 200, 50);

    // Polygon (Triangle)
    int points[] = {200, 300, 250, 350, 150, 350, 200, 300};
    drawpoly(4, points);

    getch();
    closegraph();
    return 0;
}