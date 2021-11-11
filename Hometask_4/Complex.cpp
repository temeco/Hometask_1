#include <iostream>
#include "Complex.h"
using namespace std;
    
Complex operator*(double mult, Complex z) {
    return Complex(mult*z.Re, mult*z.Im);
}

Complex Complex::operator*(double mult) {
    return Complex(mult*Re, mult*Im);
}

std::ostream& operator<<(std::ostream& stream, const Complex& z){
	stream << z.Re << " + " << z.Im << "i";
	return stream;
}

Complex Complex::operator-(){
	return Complex(-Re, -Im);
}

Complex Complex::operator+(Complex z){
	return Complex(Re + z.Re, Im + z.Im);
}


Complex Complex::operator-(Complex z){
	return (*this) + (-z);
}

Complex Complex::operator*(Complex z){
    return Complex(Re*z.Re - Im*z.Im, Re*z.Im + Im*z.Re);
}

bool equal(Complex z1, Complex z2) {
    return (z1.Re == z2.Re & z1.Im == z2.Im);
}


int main (int argc, char* argv[]) {

    //Solve the equation with the given structure
    Complex a(2,5);
    Complex b(17,-4);
    Complex c(34,-63);
    Complex Null(0,0);

    Complex z(10,10);
    

    for (int k=0; k < 20; ++k) {
        for (int l=0; l <20; ++l) {
            if (equal(z*z*z - a*z*z - b*z + c, Null)){
                cout << z << endl;
            }
            z.Im = z.Im - 1;
        }
        z.Im = 10;
        z.Re = z.Re - 1;
    }

    
    return EXIT_SUCCESS;

}


