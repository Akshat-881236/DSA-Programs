// Write a program to perform 3D transformations: translation, rotation, and scaling on a set of 3D points.

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    float x[20], y[20], z[20];

    cout << "Enter number of points: ";
    cin >> n;

    cout << "Enter coordinates (x y z):\n";

    for(int i = 0; i < n; i++)
    {
        cout << "Point " << i+1 << ": ";
        cin >> x[i] >> y[i] >> z[i];
    }

    int choice;

    cout << "\nChoose Transformation\n";
    cout << "1. Translation\n";
    cout << "2. Scaling\n";
    cout << "3. Rotation about Z-axis\n";
    cout << "Enter choice: ";
    cin >> choice;

    if(choice == 1)
    {
        float tx, ty, tz;

        cout << "Enter translation factors (tx ty tz): ";
        cin >> tx >> ty >> tz;

        cout << "\nTranslated Points:\n";

        for(int i = 0; i < n; i++)
        {
            cout << "(" 
                 << x[i] + tx << ", "
                 << y[i] + ty << ", "
                 << z[i] + tz << ")\n";
        }
    }

    else if(choice == 2)
    {
        float sx, sy, sz;

        cout << "Enter scaling factors (sx sy sz): ";
        cin >> sx >> sy >> sz;

        cout << "\nScaled Points:\n";

        for(int i = 0; i < n; i++)
        {
            cout << "("
                 << x[i] * sx << ", "
                 << y[i] * sy << ", "
                 << z[i] * sz << ")\n";
        }
    }

    else if(choice == 3)
    {
        float angle;

        cout << "Enter rotation angle (degree): ";
        cin >> angle;

        float rad = angle * 3.14159265 / 180;

        cout << "\nRotated Points (about Z-axis):\n";

        for(int i = 0; i < n; i++)
        {
            float x1 = x[i] * cos(rad) - y[i] * sin(rad);
            float y1 = x[i] * sin(rad) + y[i] * cos(rad);

            cout << "("
                 << x1 << ", "
                 << y1 << ", "
                 << z[i] << ")\n";
        }
    }

    else
    {
        cout << "Invalid choice\n";
    }

    return 0;
}

// Program Description:
// This program allows the user to perform 3D transformations (translation, scaling, and rotation about the Z-axis) on a set of 3D points. The user first inputs the number of points and their coordinates. Then, based on the user's choice, the program applies the selected transformation to each point and outputs the new coordinates. The transformations are implemented using basic mathematical formulas for translation, scaling, and rotation.
// Note: This program does not include a graphical representation of the points or transformations. It simply outputs the transformed coordinates in the console. To visualize the transformations, additional code would be needed to integrate with a graphics library.