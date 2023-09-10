#include <iostream>

class Complex {
protected:
    double real;
    double imag;

public:
    Complex() : real(0.0), imag(0.0) {}

    Complex(double r, double i) : real(r), imag(i) {}

    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    void enterComplexNumber() {
        std::cout << "Enter real part: ";
        std::cin >> real;
        std::cout << "Enter imaginary part: ";
        std::cin >> imag;
    }

    void displayComplexNumber() const {
        std::cout << real << " + " << imag << "i" << std::endl;
    }
};

int main() {
    Complex complex1;
    Complex complex2;

    std::cout << "Enter the first complex number:" << std::endl;
    complex1.enterComplexNumber();

    std::cout << "Enter the second complex number:" << std::endl;
    complex2.enterComplexNumber();

    Complex resultAddition = complex1 + complex2;
    Complex resultSubtraction = complex1 - complex2;

    std::cout << "Result of addition: ";
    resultAddition.displayComplexNumber();

    std::cout << "Result of subtraction: ";
    resultSubtraction.displayComplexNumber();

    return 0;
}
