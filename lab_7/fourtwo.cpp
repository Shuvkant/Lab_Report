#include <iostream>
#include <typeinfo>

using namespace std;

class Vehicle {
public:
    virtual void print() = 0;
};

class Bus : public Vehicle {
public:
    void print() override {
        cout << "This is a bus." << endl;
    }
};

class Car : public Vehicle {
public:
    void print() override {
        cout << "This is a car." << endl;
    }
};

class Bike : public Vehicle {
public:
    void print() override {
        cout << "This is a bike." << endl;
    }
};

int main() {
    Vehicle* vehicle = new Bus();

    // Use dynamic_cast to check if the pointer points to a Bus object.
    Bus* bus = dynamic_cast<Bus*>(vehicle);
    if (bus != nullptr) {
        cout << "The pointer points to a Bus object." << endl;
    } else {
        cout << "The pointer does not point to a Bus object." << endl;
    }

    // Use typeid to get the type of the object pointed to by the pointer.
    const std::type_info& typeinfo = typeid(*vehicle);
    cout << "The type of the object is: " << typeinfo.name() << endl;

    return 0;
}
