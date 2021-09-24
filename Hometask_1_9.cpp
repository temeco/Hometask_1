#include <iostream>
using namespace std;

int RomanNumber(int x) {

cout << "The number " << x << " in the Roman numeral system is: ";

    while (x >= 1000) {
        cout << "M";
        x = x - 1000;
    }
    if (x >= 900) {
        cout << "CM";
        x = x - 900;
    }
    if (x >= 500) {
        cout << "D";
        x = x - 500;
    }
    if (x >= 400) {
        cout << "CD";
        x = x - 400;
    }
    while (x >= 100) {
        cout << "C";
        x = x - 100;
    }
    if (x >= 90) {
        cout << "XC";
        x = x -90;
    }
    if (x >= 50) {
        cout << "L";
        x = x -50;
    }
    if (x >= 40) {
        cout << "XL";
        x = x - 40;
    }
    while (x >= 10) {
        cout << "X";
        x = x - 10;
    }
    if (x >= 9) {
        cout << "IX";
        x = x - 9;
    }
    if (x >= 5) {
        cout << "V";
        x = x - 5;
    }
    if ( x >= 4) {
        cout << "IV";
        x = x - 4;
    }
    while (x > 0) {
        cout << "I";
        x = x - 1;
    }
return 0;
}

int main() {
    RomanNumber(1984);
}