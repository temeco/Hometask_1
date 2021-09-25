#include <iostream>
using namespace std;

int PosMoscowRing(float speed, int hours) {

    int result = 0;

    result = speed*hours;
    result = (result % 190 + 190) % 190;

    return result;

}


int main() {
    cout << PosMoscowRing(5.5,6.2) << endl;
    return 0;
}