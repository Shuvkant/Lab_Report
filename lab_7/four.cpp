#include <iostream>
#include <typeinfo>

class Vehicle {
public:
    virtual void displayType() const {
        std::cout << "This is a Vehicle." << std::endl;
    }
};

class Bus : public Vehicle {
public:
    void displayType() const override {
        std::cout << "This is a Bus." << std::endl;
    }
};

class Car : public Vehicle {
public:
    void displayType() const override {
        std::cout << "This is a Car." << std::endl;
    }
};

class Bike : public Vehicle {
public:
    void displayType() const override {
        std::cout << "This is a Bike." << std::endl;
    }
};

int main() {
    Vehicle* vehicles[4];

    vehicles[0] = new Bus();
    vehicles[1] = new Car();
    vehicles[2] = new Bike();
    vehicles[3] = new Vehicle(); // A generic Vehicle

    for (int i = 0; i < 4; ++i) {
        // Using dynamic_cast to check the actual type
        if (Bus* bus = dynamic_cast<Bus*>(vehicles[i])) {
            std::cout << "Dynamic cast: Bus" << std::endl;
        } else if (Car* car = dynamic_cast<Car*>(vehicles[i])) {
            std::cout << "Dynamic cast: Car" << std::endl;
        } else if (Bike* bike = dynamic_cast<Bike*>(vehicles[i])) {
            std::cout << "Dynamic cast: Bike" << std::endl;
        } else {
            std::cout << "Dynamic cast: Vehicle" << std::endl;
        }

        // Using typeid operator to check the type
        if (typeid(*vehicles[i]) == typeid(Bus)) {
            std::cout << "Type ID: Bus" << std::endl;
        } else if (typeid(*vehicles[i]) == typeid(Car)) {
            std::cout << "Type ID: Car" << std::endl;
        } else if (typeid(*vehicles[i]) == typeid(Bike)) {
            std::cout << "Type ID: Bike" << std::endl;
        } else {
            std::cout << "Type ID: Vehicle" << std::endl;
        }

        vehicles[i]->displayType();
        delete vehicles[i];
    }

    return 0;
}
