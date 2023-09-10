#include <iostream>
#include <string>

class Person {
protected:
    std::string name;
    int age;

public:
    Person() {
        name = "";
        age = 0;
    }

    void enterInfo() {
        std::cout << "Enter name: ";
        std::cin >> name;
        std::cout << "Enter age: ";
        std::cin >> age;
    }

    void printAddress() {
        std::cout << "Address of the Person object: " << this << std::endl;
    }
};

class Student : public Person {
public:
    void changeInfo() {
        std::cout << "Enter new name for the student: ";
        std::cin >> name;
        std::cout << "Enter new age for the student: ";
        std::cin >> age;
    }

    void deleteInfo() {
        name = "";
        age = 0;
    }
};

class Employee : public Person {
public:
    void changeInfo() {
        std::cout << "Enter new name for the employee: ";
        std::cin >> name;
        std::cout << "Enter new age for the employee: ";
        std::cin >> age;
    }

    void deleteInfo() {
        name = "";
        age = 0;
    }
};

int main() {
    Person person1;
    Student student1;
    Employee employee1;
    Person person2;
    Student student2;
    Employee employee2;

    person1.enterInfo();
    student1.enterInfo();
    employee1.enterInfo();
    person2.enterInfo();
    student2.enterInfo();
    employee2.enterInfo();

    std::cout << "Addresses of objects:" << std::endl;
    person1.printAddress();
    student1.printAddress();
    employee1.printAddress();
    person2.printAddress();
    student2.printAddress();
    employee2.printAddress();

    std::cout << "Size of Person object: " << sizeof(person1) << " bytes" << std::endl;
    std::cout << "Size of Student object: " << sizeof(student1) << " bytes" << std::endl;
    std::cout << "Size of Employee object: " << sizeof(employee1) << " bytes" << std::endl;

    return 0;
}
