#include <iostream>
using namespace std;

struct Vector3D {
    //fields
    double x1 = 0;
    double x2 = 0;
    double x3 = 0;

    //constructor
    Vector3D() {
        this->x1 = 0;
        this->x2 = 0;
        this->x3 = 0;
    }

    Vector3D(double x1, double x2, double x3) {
        this->x1 = x1;
        this->x2 = x2;
        this->x3 = x3;
    }

    Vector3D(const Vector3D& z) {
        this->x1 = z.x1;
        this->x2 = z.x2;
        this->x3 = z.x3;
    }

    //destructor
    ~Vector3D() {

    }

    //methods
    void print() {
        cout << "(" << x1 << "," << x2 << "," << x3 << ")";
    }

};

void printVector(Vector3D x) {
        x.print();
    }

Vector3D add(Vector3D x, Vector3D y) {

        return Vector3D(x.x1+y.x1, x.x2+y.x2, x.x3+y.x3);

    }

Vector3D multiplyScalar(double a, Vector3D x) {
    return Vector3D(a*x.x1, a*x.x2, a*x.x3);
}

double dotProduct(Vector3D x, Vector3D y) {
    return x.x1*y.x1+x.x2*y.x2+x.x3*y.x3;
}

Vector3D crossProduct(Vector3D x, Vector3D y) {
    return Vector3D(x.x2*y.x3 -x.x3*y.x2, x.x3*y.x1-x.x1*y.x3, x.x1*y.x2-x.x2*y.x1);
}