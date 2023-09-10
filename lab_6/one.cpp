#include <iostream>

class Distance {
private:
    float meter;
    float centimeter;

public:
    // Constructor to initialize meter and centimeter
    Distance(float m, float cm) : meter(m), centimeter(cm) {}

    // Function to convert Distance to meters
    float toMeters() {
        return meter + centimeter / 100.0; // 1 meter = 100 centimeters
    }

    // Function to convert Distance to centimeters
    float toCentimeters() {
        return meter * 100.0 + centimeter;
    }
};

int main() {
    float m, cm;

    std::cout << "Enter distance in meters: ";
    std::cin >> m;

    std::cout << "Enter distance in centimeters: ";
    std::cin >> cm;

    // Create a Distance object
    Distance d(m, cm);

    std::cout << "Distance in meters: " << d.toMeters() << " meters" << std::endl;
    std::cout << "Distance in centimeters: " << d.toCentimeters() << " centimeters" << std::endl;

    return 0;
}
