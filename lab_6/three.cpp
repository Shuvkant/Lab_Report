#include <iostream>
#include <string>

class Musicians {
protected:
    std::string stringInstruments[5];
    std::string windInstruments[5];
    std::string percInstruments[5];

public:
    Musicians() {
        // Initialize the string array with string instruments
        stringInstruments[0] = "veena";
        stringInstruments[1] = "guitar";
        stringInstruments[2] = "sitar";
        stringInstruments[3] = "sarod";
        stringInstruments[4] = "mandolin";

        // Initialize the wind array with wind instruments
        windInstruments[0] = "flute";
        windInstruments[1] = "clarinet";
        windInstruments[2] = "saxophone";
        windInstruments[3] = "nadhaswaram";
        windInstruments[4] = "piccolo";

        // Initialize the perc array with percussion instruments
        percInstruments[0] = "tabla";
        percInstruments[1] = "mridangam";
        percInstruments[2] = "bongos";
        percInstruments[3] = "drums";
        percInstruments[4] = "tambour";
    }

    void displayStringInstruments() {
        std::cout << "String Instruments:" << std::endl;
        for (int i = 0; i < 5; i++) {
            std::cout << stringInstruments[i] << std::endl;
        }
    }

    void displayWindInstruments() {
        std::cout << "Wind Instruments:" << std::endl;
        for (int i = 0; i < 5; i++) {
            std::cout << windInstruments[i] << std::endl;
        }
    }

    void displayPercInstruments() {
        std::cout << "Percussion Instruments:" << std::endl;
        for (int i = 0; i < 5; i++) {
            std::cout << percInstruments[i] << std::endl;
        }
    }
};

class TypeIns : public Musicians {
public:
    void get() {
        char choice;
        std::cout << "Type of instruments to be displayed:" << std::endl;
        std::cout << "a. String instruments" << std::endl;
        std::cout << "b. Wind instruments" << std::endl;
        std::cout << "c. Percussion instruments" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 'a':
                displayStringInstruments();
                break;
            case 'b':
                displayWindInstruments();
                break;
            case 'c':
                displayPercInstruments();
                break;
            default:
                std::cout << "Invalid choice" << std::endl;
        }
    }

    void show() {
        get();
    }
};

int main() {
    TypeIns typeIns;
    typeIns.show();
    return 0;
}
