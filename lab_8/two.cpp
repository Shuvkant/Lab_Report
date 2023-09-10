#include <iostream>
#include <iomanip>

// User-defined manipulator
struct FormatManipulator {
    int width;
    int precision;
    char fill;

    FormatManipulator(int w, int p, char f) : width(w), precision(p), fill(f) {}
};

// Overload the << operator for the user-defined manipulator
std::ostream& operator<<(std::ostream& os, const FormatManipulator& manipulator) {
    os.width(manipulator.width);
    os.precision(manipulator.precision);
    os.fill(manipulator.fill);
    return os;
}

// Example usage
int main() {
    double number = 3.14159;

    std::cout << "Default output: " << number << std::endl;

    std::cout << "Formatted output: "
              << FormatManipulator(10, 4, '*') << number << std::endl;

    return 0;
}