#include <iostream>

class DistanceFeetInch;

class DistanceMeterCentimeter {
private:
    float meter;
    float centimeter;

public:
    DistanceMeterCentimeter(float m, float cm) : meter(m), centimeter(cm) {}

    // Conversion function to convert to DistanceFeetInch
    DistanceFeetInch toFeetInch();

    void display() {
        std::cout << "Distance in meter-centimeter: " << meter << " meters " << centimeter << " centimeters" << std::endl;
    }
};

class DistanceFeetInch {
private:
    float feet;
    float inch;

public:
    DistanceFeetInch(float ft, float in) : feet(ft), inch(in) {}

    // Conversion function to convert to DistanceMeterCentimeter
    DistanceMeterCentimeter toMeterCentimeter();

    void display() {
        std::cout << "Distance in feet-inch: " << feet << " feet " << inch << " inches" << std::endl;
    }
};

// Conversion function from DistanceMeterCentimeter to DistanceFeetInch
DistanceFeetInch DistanceMeterCentimeter::toFeetInch() {
    float totalInches = (meter * 100 + centimeter) / 2.54; // 1 inch = 2.54 centimeters
    float feet = totalInches / 12;
    float inch = totalInches - feet * 12;
    return DistanceFeetInch(feet, inch);
}

// Conversion function from DistanceFeetInch to DistanceMeterCentimeter
DistanceMeterCentimeter DistanceFeetInch::toMeterCentimeter() {
    float totalInches = feet * 12 + inch;
    float cm = totalInches * 2.54; // 1 inch = 2.54 centimeters
    float meter = cm / 100;
    cm = cm - (static_cast<int>(meter) * 100); // Remaining centimeters
    return DistanceMeterCentimeter(meter, cm);
}

int main() {
    // Example using DistanceMeterCentimeter
    DistanceMeterCentimeter distanceMC(5, 30);
    distanceMC.display();
    DistanceFeetInch convertedFI = distanceMC.toFeetInch();
    convertedFI.display();

    // Example using DistanceFeetInch
    DistanceFeetInch distanceFI(2, 6);
    distanceFI.display();
    DistanceMeterCentimeter convertedMC = distanceFI.toMeterCentimeter();
    convertedMC.display();

    return 0;
}
