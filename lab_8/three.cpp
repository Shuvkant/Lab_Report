#include <iostream>

class Complex {
private:
    double real;
    double imaginary;

public:
    Complex(double real = 0.0, double imaginary = 0.0)
        : real(real), imaginary(imaginary) {}

    friend std::istream& operator>>(std::istream& in, Complex& complex);
    friend std::ostream& operator<<(std::ostream& out, const Complex& complex);
};

std::istream& operator>>(std::istream& in, Complex& complex) {
    std::cout << "Enter the real part: ";
    in >> complex.real;

    std::cout << "Enter the imaginary part: ";
    in >> complex.imaginary;

    return in;
}

std::ostream& operator<<(std::ostream& out, const Complex& complex) {
    out << complex.real;
    if (complex.imaginary >= 0)
        out << "+";
    out << complex.imaginary << "i";

    return out;
}

int main() {
    Complex c;

    std::cout << "Enter a complex number:" << std::endl;
    std::cin >> c;

    std::cout << "Complex number in a+ib format: " << c << std::endl;

    return 0;
}