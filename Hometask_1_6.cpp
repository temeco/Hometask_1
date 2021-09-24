#include <iostream>
using namespace std;

int Maximum() {

    int a,b;
    int min, max;

    cout << "Please enter the first number: ";
    cin >> a;
    cout << "Please enter the second number: ";
    cin >> b;

    // Following equations hold:
    // If a < b: a/b=0 && a%b=a and converse
    // If b < a: b/a=0 && b%a=b

    //With the following formular we can calculate the minimum:
    min = ((b/a)*(a%b)+(a/b)*(b%a))/((b/a)+(a/b));

    // Now we want to output that number of the two, that is not equal to the calculated value
    max = (a*(a-min)+b*(b-min))/((a-min)+(b-min));
    
    cout << "The largest of the two given values is: " << max << endl;
    return max;

    }

    int main() {
        Maximum();
    }
