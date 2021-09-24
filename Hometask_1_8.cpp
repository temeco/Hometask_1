#include <iostream>
using namespace std;

int EvenOdd(int a, int b, int c) {

    if (a % 2 == 0 || b % 2 == 0 || c % 2 == 0) {
        cout << "There is at least one even number contained." << endl;
    }
    else {
        cout << "There is no even number contained." << endl;
    }
    if (a % 2 != 0 || b % 2 != 0 || c % 2 != 0) {
        cout << "There is at least one odd number contained." << endl;
    }
    else {
        cout << "There is no odd number contained." << endl;
    }

    return 0;
    }

int main() {
    EvenOdd(1,2,1);
    return 0;
}