#include <iostream>
using namespace std;

int TriangleType(float a, float b, float c) {

    float temp = 0;

    // order a,b,c in descending order
    if (b < a) {
        temp = b;
        b = a;
        a = temp;
    }
    //now a <= b
    if (c < a) {
        temp = c;
        c = a;
        a = temp;
    }
    else if (c < b) {
        temp = c;
        c = b;
        b = temp;
    }
    //now a,b,c are in descending order

    if (a*a + b*b == c*c) {
        cout << "The traingle is of the type: rectangular." << endl;
    }
    else if (a*a + b*b < c*c) {
        cout << "The triangle is of the type: obuse." << endl;
    }
    else {
        cout << "The triangle is of the type: acute." << endl;
    }

    return 0;

}

int main() {
    TriangleType(3,4,5);
}