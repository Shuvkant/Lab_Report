#include <iostream>
#include <fstream>
#include <string>

// Define a structure to store student information
struct Student {
    std::string name;
    int studentId;
    std::string department;
    std::string address;
};

// Function to write student information to a file
void writeStudentToFile(const Student& student, const std::string& filename) {
    std::ofstream outFile(filename, std::ios::app); // Open the file in append mode
    if (!outFile) {
        std::cerr << "Error opening the file for writing." << std::endl;
        return;
    }

    // Write student information to the file
    outFile << "Name: " << student.name << std::endl;
    outFile << "Student ID: " << student.studentId << std::endl;
    outFile << "Department: " << student.department << std::endl;
    outFile << "Address: " << student.address << std::endl;
    outFile << std::endl;

    outFile.close();
}

// Function to read and print student information from a file
void readStudentFromFile(const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "Error opening the file for reading." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(inFile, line)) {
        std::cout << line << std::endl;
    }

    inFile.close();
}

int main() {
    // Create and initialize a student structure
    Student student1 = {"Ram Joshi", 101, "Computer Science", "123 Main St"};
    Student student2 = {"Hari Yadav", 102, "Electrical Engineering", "456 Elm St"};

    // Write student information to a file
    writeStudentToFile(student1, "student_info.txt");
    writeStudentToFile(student2, "student_info.txt");

    // Read and print student information from the file
    std::cout << "Student Information from File:" << std::endl;
    readStudentFromFile("student_info.txt");

    return 0;
}
