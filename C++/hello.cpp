#include <iostream>
using namespace std;
int main(){
    float PI = 3.14;
    int r;
    cout << "Enter Radius : ";
    cin >> r;
    cout << "Area of circle is : " << PI*r*r << endl ;
    cout << "Perimeter of circle is : " << 2*PI*r ;
    return 0;
}