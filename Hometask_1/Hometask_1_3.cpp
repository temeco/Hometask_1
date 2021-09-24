#include <iostream>
using namespace std;

int Snail(float a, float b, float h) {

int day = 0; 

// we want always the next integer bigger than h/(a-b) that why we need to add 1
// If h/(a-b) is already an integer, then the snake reaches the top at 0:00 o'clock, 
// so the equation still holds.

day = h/(a-b)+1;

return day;

}

int main() {

    cout << "The snail reaches the top on the " << Snail(5,3,45) << ". day." << endl;
}