using namespace std;

struct Vector3D {

    //fields
    double x1 = 0;
    double x2 = 0;
    double x3 = 0;

    //constructor
    Vector3D();
    //parametrized constructor
    Vector3D(double x1, double x2, double x3);
    //copying constructor
    Vector3D(const Vector3D& z);

    //destructor
    ~Vector3D();

    //methods
    void print();
};

void printVector(Vector3D x);

Vector3D add(Vector3D x, Vector3D y);

Vector3D multiplyScalar(double a, Vector3D x);

double dotProduct(Vector3D x, Vector3D y);

Vector3D crossProduct(Vector3D x, Vector3D y);