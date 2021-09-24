#include <iostream>
using namespace std;

float PosMoscowRing(float speed, float time) {

int temp = 0;
float result = 0;

temp = (time*speed)/190;

result = (time*speed) - (temp*190);

return result;
}


int main() {
    cout << PosMoscowRing(5.5,6.2) << endl;
    return 0;
}