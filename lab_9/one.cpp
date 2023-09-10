#include <iostream>

// Templated function to calculate the sum of elements in an array
template <typename T>
T sum(const T array[], int size) {
    T result = 0;
    for (int i = 0; i < size; ++i) {
        result += array[i];
    }
    return result;
}

int main() {
    // Example 1: Integer array
    int intArray[] = {1, 2, 3, 4, 5};
    int intSum = sum(intArray, 5);
    std::cout << "Sum of integers: " << intSum << std::endl;

    // Example 2: Double array
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double doubleSum = sum(doubleArray, 5);
    std::cout << "Sum of doubles: " << doubleSum << std::endl;

    // Example 3: Float array
    float floatArray[] = {0.5f, 1.5f, 2.5f, 3.5f, 4.5f};
    float floatSum = sum(floatArray, 5);
    std::cout << "Sum of floats: " << floatSum << std::endl;

    // Example 4: Long array
    long longArray[] = {1000, 2000, 3000, 4000, 5000};
    long longSum = sum(longArray, 5);
    std::cout << "Sum of longs: " << longSum << std::endl;

    return 0;
}
