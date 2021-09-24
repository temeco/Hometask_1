#include <iostream>
using namespace std;

int main() {

    float a = 0;
    float b = 0; 
    float c = 0; 
    float temp = 0;

    cout << "Please enter the first number: ";
    cin >> a;
    cout << "Please enter the second number: ";
    cin >> b; 
    cout << "Please enter the third number: ";
    cin >> c;

    if (b < a) {
        temp = b;
        b = a;
        a = temp;
    }
    // now a and b are in right order

    if (c < a) {
        temp = c;
        c = a;
        a = temp;
    }
    else if (c < b) {
        temp = b;
        b = c;
        c = temp;
    }

    cout << "The given numbers in non-descending order are: " << a << ", " << b << ", " << c << endl;

    return 0;

}