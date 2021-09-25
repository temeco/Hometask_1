#include <iostream>
using namespace std;

int Snail(int a, int b, int h) {

int hh = h - a;
int aa = a - b;
int day = 0;

day = 1 + hh/aa + (hh % aa + aa - 1)/aa;

return day;

}

int main() {

    cout << "The snail reaches the top on the " << Snail(5,3,45) << ". day." << endl;
}