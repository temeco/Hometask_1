#include <iostream>
using namespace std;

int phi (int n) {

    int x1 = 0;
    int x2 = 1;
    int result = 0;
    int i = 0;

    if (n==0) {
        result = 0;
    }
    else if (n==1) {
        result ==1;
    }
    
    for (i=2; i <= n; i++) {
        result = x1 + x2;
        x1 = x2;
        x2 = result;
    }

    return result;
}

int main() {

    int n;
    
    cout << "Please enter a number: ";
    cin >> n;
    cout << "The " << n << ". Fibonacci number is: " << phi(n) << endl;

    return 0;
}