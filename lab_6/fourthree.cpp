#include <iostream>
#include <string>

class Person {
protected:
    std::string name;
    int age;

public:
    Person() : name(""), age(0) {}

    void enterData() {
        std::cout << "Enter name: ";
        std::cin >> name;
        std::cout << "Enter age: ";
        std::cin >> age;
    }

    void printAddress() {
        std::cout << "Address of Person object: " << this << std::endl;
    }
};

class Student : public Person {
private:
    int studentID;

public:
    Student() : studentID(0) {}

    void assignStudentRecord(int id) {
        studentID = id;
    }

    void changeStudentRecord(int id) {
        studentID = id;
    }

    void deleteStudentRecord() {
        studentID = 0;
    }

    void printAddress() {
        std::cout << "Address of Student object: " << this << std::endl;
    }
};

class Employee : public Person {
private:
    int employeeID;

public:
    Employee() : employeeID(0) {}

    void assignEmployeeRecord(int id) {
        employeeID = id;
    }

    void changeEmployeeRecord(int id) {
        employeeID = id;
    }

    void deleteEmployeeRecord() {
        employeeID = 0;
    }

    void printAddress() {
        std::cout << "Address of Employee object: " << this << std::endl;
    }
};

int main() {
    Person person1;
    Person person2;
    Student student1;
    Student student2;
    Employee employee1;
    Employee employee2;

    person1.enterData();
    person2.enterData();
    student1.enterData();
    student2.enterData();
    employee1.enterData();
    employee2.enterData();

    person1.printAddress();
    person2.printAddress();
    student1.printAddress();
    student2.printAddress();
    employee1.printAddress();
    employee2.printAddress();

    // Calculate address space occupied by objects
    std::cout << "Size of Person object: " << sizeof(Person) << " bytes" << std::endl;
    std::cout << "Size of Student object: " << sizeof(Student) << " bytes" << std::endl;
    std::cout << "Size of Employee object: " << sizeof(Employee) << " bytes" << std::endl;

    return 0;
}
