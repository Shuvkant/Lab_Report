#include <iostream>
#include <string>

// Abstract base class Student
class Student {
protected:
    std::string name;
    int rollNumber;

public:
    Student(const std::string& n, int roll) : name(n), rollNumber(roll) {}

    // Pure virtual function to be implemented by derived classes
    virtual void display() const = 0;
};

// Derived class Engineering
class Engineering : public Student {
private:
    std::string branch;

public:
    Engineering(const std::string& n, int roll, const std::string& b)
        : Student(n, roll), branch(b) {}

    void display() const override {
        std::cout << "Engineering Student - Name: " << name << ", Roll Number: " << rollNumber << ", Branch: " << branch << std::endl;
    }
};

// Derived class Medicine
class Medicine : public Student {
private:
    std::string specialization;

public:
    Medicine(const std::string& n, int roll, const std::string& s)
        : Student(n, roll), specialization(s) {}

    void display() const override {
        std::cout << "Medicine Student - Name: " << name << ", Roll Number: " << rollNumber << ", Specialization: " << specialization << std::endl;
    }
};

// Derived class Science
class Science : public Student {
private:
    std::string field;

public:
    Science(const std::string& n, int roll, const std::string& f)
        : Student(n, roll), field(f) {}

    void display() const override {
        std::cout << "Science Student - Name: " << name << ", Roll Number: " << rollNumber << ", Field: " << field << std::endl;
    }
};

int main() {
    // Create an array of pointers to the base class Student
    const int numStudents = 3;
    Student* students[numStudents];

    // Create objects of derived classes and store them in the array
    students[0] = new Engineering("Alice", 101, "Computer Science");
    students[1] = new Medicine("Bob", 102, "Cardiology");
    students[2] = new Science("Charlie", 103, "Physics");

    // Process and display information using the base class pointers
    for (int i = 0; i < numStudents; ++i) {
        students[i]->display();
    }

    // Clean up allocated memory
    for (int i = 0; i < numStudents; ++i) {
        delete students[i];
    }

    return 0;
}
