#include <iostream>
#include <vector>

// Define a class template for a queue
template <typename T>
class Queue {
public:
    // Constructor to initialize the queue
    Queue() {}

    // Function to insert an element at the rear of the queue
    void enqueue(const T& item) {
        elements.push_back(item);
    }

    // Function to remove and return an element from the front of the queue
    T dequeue() {
        if (!isEmpty()) {
            T frontElement = elements.front();
            elements.erase(elements.begin());
            return frontElement;
        }
        throw std::runtime_error("Queue is empty.");
    }

    // Function to check if the queue is empty
    bool isEmpty() const {
        return elements.empty();
    }

private:
    std::vector<T> elements;
};

int main() {
    // Create queues of different data types
    Queue<int> intQueue;
    Queue<double> doubleQueue;
    Queue<std::string> stringQueue;

    // Insert data into the queues
    intQueue.enqueue(10);
    intQueue.enqueue(20);
    intQueue.enqueue(30);

    doubleQueue.enqueue(3.14);
    doubleQueue.enqueue(2.718);

    stringQueue.enqueue("Hello");
    stringQueue.enqueue("World");

    // Remove and display data from the queues
    while (!intQueue.isEmpty()) {
        std::cout << "Dequeue int: " << intQueue.dequeue() << std::endl;
    }

    while (!doubleQueue.isEmpty()) {
        std::cout << "Dequeue double: " << doubleQueue.dequeue() << std::endl;
    }

    while (!stringQueue.isEmpty()) {
        std::cout << "Dequeue string: " << stringQueue.dequeue() << std::endl;
    }

    return 0;
}
