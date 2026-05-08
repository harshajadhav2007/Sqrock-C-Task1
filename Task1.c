#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

class Student {
private:
    int id;
    std::string name;
    float gpa;

public:
    Student(int id, std::string name, float gpa) 
        : id(id), name(name), gpa(gpa) {}

    // Getters
    int getId() const { return id; }
    std::string getName() const { return name; }
    float getGpa() const { return gpa; }

    // Setters
    void setName(std::string newName) { name = newName; }
    void setGpa(float newGpa) { gpa = newGpa; }

    void displayHeader() {
        std::cout << std::left << std::setw(10) << "ID" 
                  << std::setw(20) << "Name" 
                  << std::setw(5) << "GPA" << std::endl;
        std::cout << "---------------------------------------" << std::endl;
    }

    void displayRecord() const {
        std::cout << std::left << std::setw(10) << id 
                  << std::setw(20) << name 
                  << std::setw(5) << gpa << std::endl;
    }
};

// Function Prototypes
void addStudent(std::vector<Student>& students);
void viewStudents(const std::vector<Student>& students);
void updateStudent(std::vector<Student>& students);
void deleteStudent(std::vector<Student>& students);

int main() {
    std::vector<Student> students;
    int choice;

    do {
        std::cout << "\n--- Student Record Management System ---" << std::endl;
        std::cout << "1. Add Student" << std::endl;
        std::cout << "2. View All Students" << std::endl;
        std::cout << "3. Update Student Details" << std::endl;
        std::cout << "4. Delete Student" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: addStudent(students); break;
            case 2: viewStudents(students); break;
            case 3: updateStudent(students); break;
            case 4: deleteStudent(students); break;
            case 5: std::cout << "Exiting program..." << std::endl; break;
            default: std::cout << "Invalid choice! Please try again." << std::endl;
        }
    } while (choice != 5);

    return 0;
}

void addStudent(std::vector<Student>& students) {
    int id;
    std::string name;
    float gpa;

    std::cout << "Enter ID: ";
    std::cin >> id;
    std::cin.ignore(); // Clear newline
    std::cout << "Enter Name: ";
    std::getline(std::cin, name);
    std::cout << "Enter GPA: ";
    std::cin >> gpa;

    students.emplace_back(id, name, gpa);
    std::cout << "Student added successfully!" << std::endl;
}

void viewStudents(const std::vector<Student>& students) {
    if (students.empty()) {
        std::cout << "No records found." << std::endl;
        return;
    }
    
    std::cout << "\n--- All Student Records ---" << std::endl;
    std::cout << std::left << std::setw(10) << "ID" << std::setw(20) << "Name" << "GPA" << std::endl;
    for (const auto& s : students) {
        s.displayRecord();
    }
}

void updateStudent(std::vector<Student>& students) {
    int id;
    bool found = false;
    std::cout << "Enter Student ID to update: ";
    std::cin >> id;

    for (auto& s : students) {
        if (s.getId() == id) {
            std::string newName;
            float newGpa;
            std::cin.ignore();
            std::cout << "Enter New Name: ";
            std::getline(std::cin, newName);
            std::cout << "Enter New GPA: ";
            std::cin >> newGpa;

            s.setName(newName);
            s.setGpa(newGpa);
            std::cout << "Record updated successfully!" << std::endl;
            found = true;
            break;
        }
    }
    if (!found) std::cout << "Student ID not found." << std::endl;
}

void deleteStudent(std::vector<Student>& students) {
    int id;
    std::cout << "Enter Student ID to delete: ";
    std::cin >> id;

    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->getId() == id) {
            students.erase(it);
            std::cout << "Student record deleted." << std::endl;
            return;
        }
    }
    std::cout << "Student ID not found." << std::endl;
}
