#include <iostream>
using namespace std;

long Binomial(int n, int k) {

    if (k==0 || n==k) {
        return 1;
    }
    else {
        return Binomial(n-1,k-1)+Binomial(n-1,k);
    }
}

int main() {

    int n = 0;
    int k = 0;

    cout << "We will calculate the binomial coefficient (n,k)." << endl;
    cout << "Please enter the number n: ";
    cin >> n;
    cout << "Please enter the number k: ";
    cin >> k;
    cout << "The binomial coefficient of (" << n << "," << k << ") is: " << Binomial(n,k) << endl;

    return 0;
}