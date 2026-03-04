#include <iostream>
using namespace std;

class Math {
    public:
    int add(int a, int b) {
        return a + b;
    }
    double add(double a, double b) {
        return a + b;
    }
    int add(int a, int b, int c) {
        return a + b + c;
    }
};

int main(){
    Math m1;
    Math m2;
    Math m3;
    Math m4;

    cout << "Sum is : " << m1.add(4, 5, 7) << endl;
    cout << "Sum is : " << m2.add(5.7, 9.8) << endl;
    cout << "Sum is : " << m3.add(45, 10) << endl;
    cout << "Sum is : " << m4.add(2, 4, 7) << endl;
    return 0;
}