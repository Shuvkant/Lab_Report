#include <iostream>

class chaudhary; // Forward declaration of the 'chaudhary' class.

class phanait {
private:
    int HouseId;
    int street;

public:
    phanait() {
        HouseId = 20;
        street = 12;
    }
    friend class chaudhary;
};

class chaudhary {
public:
    void display() {
        // Access the friend class's private member.
        phanait p;
        p.HouseId = 24;
        std::cout << "The modified HouseId is " << p.HouseId;
    }
};

int main() {
    phanait p1;
    chaudhary ch;
    ch.display();
    return 0;
}
