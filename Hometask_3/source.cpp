#include <iostream>
#include"Vector3D.h"
using namespace std;



int main() {

    double a = 0;
    double b = 0;
    double c = 0;

    cout << "Here we demonstrate, how the basic operations for 3D-Vectors work." << endl;
    cout << "Please enter three coordinates for the first vector: " << endl;
    cin >> a >> b >> c;
    cout << "Now we construct our first vector: ";
    Vector3D x(a,b,c);
    x.print();
    cout << endl << "Please enter the coordinates for the second vector: " << endl;
    cin >> a >> b >> c;
    cout << "This is our second vector: ";
    Vector3D y(a,b,c);
    y.print();
    cout << endl << endl << "This is how we add vectors: ";
    printVector(x);
    cout << "+";
    printVector(y);
    cout << "=";
    printVector(add(x,y));
    cout << endl << endl << "This is how multiplication by a scalar works: " << endl << "Please enter some scalar number: ";
    cin >> a;
    cout << "Now we multiply our first vector by " << a << ": " << endl << a << "*";
    printVector(x);
    cout << "=";
    printVector(multiplyScalar(a,x));
    cout << endl << endl << "Now we calculate the dot product of our two given vectors: ";
    printVector(x);
    cout << "*";
    printVector(y);
    cout << "=" << dotProduct(x,y); 
    cout << endl << endl << "And now we calculate the cross product of our two vectors: ";
    printVector(x);
    cout << "x";
    printVector(y);
    cout << "=";
    printVector(crossProduct(x,y));
    
    return EXIT_SUCCESS;
}