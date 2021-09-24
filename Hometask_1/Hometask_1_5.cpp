#include <iostream>
using namespace std;

int IsDivisible(int a, int b) {

    int product = 0;

    // If one of both numbers divides the other then either a%b or b%a is zero. 
    // This is equivalent to the product of both being zero.

    product = (a%b)*(b%a);

    return product+1;

}

int main() {
    cout << "One number is evenly divided by the other, if the integer 1 is printed: ";
    cout << IsDivisible(2,8) << endl;
return 0;
}