#include <iostream>
using namespace std;

int phi (int n) {

    if (n <= 1) {
        return n;
    }
    else {
        return phi(n - 1) + phi(n - 2);
    }

}

int main(int argc, char* argv[]) {

    int n;
    
    cout << "Please enter a number: ";
    cin >> n;
    cout << "The " << n << ". Fibonacci number is: " << phi(n) << endl;

    return EXIT_SUCCESS;
}