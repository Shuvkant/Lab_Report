#include <iostream>
#include <string>

class Person {
protected:
    std::string name;

public:
    Person(const std::string& n) : name(n) {}

    virtual void display() const {
        std::cout << "Person: " << name << std::endl;
    }
};

class Employee : virtual public Person {
protected:
    int employeeID;

public:
    Employee(const std::string& n, int id) : Person(n), employeeID(id) {}

    void display() const override {
        std::cout << "Employee: " << name << " (ID: " << employeeID << ")" << std::endl;
    }
};

class Student : virtual public Person {
protected:
    int studentID;

public:
    Student(const std::string& n, int id) : Person(n), studentID(id) {}

    void display() const override {
        std::cout << "Student: " << name << " (ID: " << studentID << ")" << std::endl;
    }
};

class Manager : public Employee, public Student {
public:
    Manager(const std::string& n, int empID, int stdID)
        : Person(n), Employee(n, empID), Student(n, stdID) {}

    void display() const override {
        Employee::display();
        Student::display();
        std::cout << "Manager: " << name << " (Employee ID: " << employeeID << ", Student ID: " << studentID << ")" << std::endl;
    }
};

int main() {
    Manager manager("John Doe", 101, 202);

    // Display the information of the Manager
    manager.display();

    return 0;
}
