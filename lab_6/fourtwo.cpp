#include <iostream>
#include <cstring>

class Person {
protected:
    char name[50];
    int age;

public:
    Person() {
        std::cout << "Enter name: ";
        std::cin.getline(name, sizeof(name));
        std::cout << "Enter age: ";
        std::cin >> age;
        std::cin.ignore(); // Clear the input buffer
    }

    virtual ~Person() {}

    virtual void printAddress() {
        std::cout << "Base class Person address: " << this << std::endl;
    }
};

class Student : public Person {
private:
    int studentID;

public:
    Student() {
        std::cout << "Enter student ID: ";
        std::cin >> studentID;
    }

    void printAddress() override {
        std::cout << "Derived class Student address: " << this << std::endl;
    }
};

class Employee : public Person {
private:
    int employeeID;

public:
    Employee() {
        std::cout << "Enter employee ID: ";
        std::cin >> employeeID;
    }

    void printAddress() override {
        std::cout << "Derived class Employee address: " << this << std::endl;
    }
};

class Calculator {
public:
    static void calculateAddressSpace(Person* obj) {
        std::cout << "Address space occupied by the object: " << sizeof(*obj) << " bytes" << std::endl;
    }
};

int main() {
    Person person1;
    Student student1;
    Employee employee1;

    std::cout << "------------------------------------" << std::endl;

    Person person2;
    Student student2;
    Employee employee2;

    std::cout << "------------------------------------" << std::endl;

    Person* personPtr1 = &person1;
    Student* studentPtr1 = &student1;
    Employee* employeePtr1 = &employee1;

    Person* personPtr2 = &person2;
    Student* studentPtr2 = &student2;
    Employee* employeePtr2 = &employee2;

    personPtr1->printAddress();
    studentPtr1->printAddress();
    employeePtr1->printAddress();

    Calculator::calculateAddressSpace(personPtr1);
    Calculator::calculateAddressSpace(studentPtr1);
    Calculator::calculateAddressSpace(employeePtr1);

    std::cout << "------------------------------------" << std::endl;

    personPtr2->printAddress();
    studentPtr2->printAddress();
    employeePtr2->printAddress();

    Calculator::calculateAddressSpace(personPtr2);
    Calculator::calculateAddressSpace(studentPtr2);
    Calculator::calculateAddressSpace(employeePtr2);

    return 0;
}
