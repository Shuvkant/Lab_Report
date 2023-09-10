#include <iostream>

class DistanceFeetInch; // Forward declaration

class DistanceMeterCentimeter {
private:
    float meter;
    float centimeter;

public:
    DistanceMeterCentimeter(float m = 0, float cm = 0) : meter(m), centimeter(cm) {}

    // Conversion functions
    float toMeters() const {
        return meter + centimeter / 100.0; // 1 meter = 100 centimeters
    }

    float toCentimeters() const {
        return meter * 100.0 + centimeter;
    }

    // Conversion function to convert to DistanceFeetInch
    DistanceFeetInch toFeetInch() const;

    void displayDistance() const {
        std::cout << "Distance in meter-centimeter: " << meter << " meters, " << centimeter << " centimeters" << std::endl;
    }
};

class DistanceFeetInch {
private:
    float feet;
    float inch;

public:
    DistanceFeetInch(float ft = 0, float in = 0) : feet(ft), inch(in) {}

    // Conversion functions
    float toFeet() const {
        return feet + inch / 12.0; // 1 foot = 12 inches
    }

    float toInches() const {
        return feet * 12.0 + inch;
    }

    // Conversion function to convert to DistanceMeterCentimeter
    DistanceMeterCentimeter toMeterCentimeter() const;

    void displayDistance() const {
        std::cout << "Distance in feet-inch: " << feet << " feet, " << inch << " inches" << std::endl;
    }
};

// Conversion function for DistanceMeterCentimeter to DistanceFeetInch
DistanceFeetInch DistanceMeterCentimeter::toFeetInch() const {
    float totalInches = toCentimeters() * 0.393701; // 1 centimeter = 0.393701 inches
    float feet = totalInches / 12.0;
    float inch = totalInches - (feet * 12.0);
    return DistanceFeetInch(feet, inch);
}

// Conversion function for DistanceFeetInch to DistanceMeterCentimeter
DistanceMeterCentimeter DistanceFeetInch::toMeterCentimeter() const {
    float totalCentimeters = toInches() * 2.54; // 1 inch = 2.54 centimeters
    float meter = totalCentimeters / 100.0;
    float centimeter = totalCentimeters - (meter * 100.0);
    return DistanceMeterCentimeter(meter, centimeter);
}

int main() {
    DistanceMeterCentimeter d1(2, 30); // 2 meters 30 centimeters

    d1.displayDistance();

    // Convert to DistanceFeetInch
    DistanceFeetInch d2 = d1.toFeetInch();
    d2.displayDistance();

    // Convert back to DistanceMeterCentimeter
    DistanceMeterCentimeter d3 = d2.toMeterCentimeter();
    d3.displayDistance();

    return 0;
}