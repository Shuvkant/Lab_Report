#include <iostream>
#include <stdexcept>

// Function that throws different types of exceptions
void throwException(int choice) {
    if (choice == 1) {
        throw std::runtime_error("Runtime error occurred.");
    } else if (choice == 2) {
        throw std::logic_error("Logic error occurred.");
    } else if (choice == 3) {
        throw std::out_of_range("Out of range error occurred.");
    }
}

int main() {
    try {
        int choice;
        std::cout << "Enter 1 for runtime error, 2 for logic error, 3 for out of range error: ";
        std::cin >> choice;

        throwException(choice);
    } catch (const std::runtime_error& e) {
        std::cerr << "Caught runtime_error: " << e.what() << std::endl;
    } catch (const std::logic_error& e) {
        std::cerr << "Caught logic_error: " << e.what() << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Caught out_of_range: " << e.what() << std::endl;
    } catch (...) {
        // Catch all other exceptions
        std::cerr << "Caught an unknown exception." << std::endl;
    }

    return 0;
}
