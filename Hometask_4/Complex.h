#include <iostream>
using namespace std;

struct Complex {

    //fields
    double Re = 0;
    double Im = 0;

    //constructor
    Complex();
    //parametrized constructor
    Complex(double Re = 0, double Im = 0) : Re(Re), Im(Im) {};
    //copying constructor 
    Complex(const Complex& z) : Re(z.Re), Im(z.Im) {};

    //destructor
    ~Complex() {};

    Complex operator-();
    Complex operator*(double mult);
    Complex operator+(Complex z);
    Complex operator-(Complex z);
    Complex operator*(Complex z);
    friend std::ostream& operator<<(std::ostream& stream, const Complex& z);
    friend Complex operator*(double mult, Complex z);

};


