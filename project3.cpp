#include <iostream>
#include <string>
#include <vector>

// Define a base class 'Person'
class Person {
protected:
    std::string name;

public:
    // Constructor for the 'Person' class
    Person(const std::string& n) : name(n) {}

    // Virtual function for introducing a person
    virtual void introduce() {
        std::cout << "Hello, my name is " << name << std::endl;
    }

    // Pure virtual function for displaying details of a person (abstract method)
    virtual void displayDetails() = 0;
};

// Define a derived class 'Student' that inherits from 'Person'
class Student : public Person {
private:
    int studentID;

public:
    // Constructor for the 'Student' class
    Student(const std::string& n, int id) : Person(n), studentID(id) {
    }

    // Override the 'introduce' method from the base class
    void introduce() override {
        std::cout << "Hi, I'm " << name << " and I'm a student." << std::endl;
    }

    // Implement the pure virtual 'displayDetails' method from the base class
    void displayDetails() override {
        std::cout << "Student Details:" << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Student ID: " << studentID << std::endl;
    }

    // Getter for 'studentID'
    int getStudentID() const {
        return studentID;
    }
};

// Define a derived class 'Teacher' that inherits from 'Person'
class Teacher : public Person {
private:
    std::string subject;

public:
    // Constructor for the 'Teacher' class
    Teacher(const std::string& n, const std::string& subj) : Person(n), subject(subj) {}

    // Override the 'introduce' method from the base class
    void introduce() override {
        std::cout << "Hello, I'm " << name << " and I teach " << subject << "." << std::endl;
    }

    // Implement the pure virtual 'displayDetails' method from the base class
    void displayDetails() override {
        std::cout << "Teacher Details:" << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Subject: " << subject << std::endl;
    }

    // Getter for 'subject'
    std::string getSubject() const {
        return subject;
    }
};

int main() {

    // Create instances of 'Person' and 'Student' classes
    Person* person1 = new Student("Raju", 468);
    Person* person2 = new Teacher("Mr. Akash", "Mathematics");

    // Create a vector of 'Person' pointers to demonstrate polymorphism
    std::vector<Person*> people;
    people.push_back(person1);
    people.push_back(person2);

    // Use polymorphism to introduce and display details of people
    for (const auto& p : people) {
        p->introduce();
        p->displayDetails();
        std::cout << std::endl;
    }

    // Clean up dynamically allocated objects
    delete person1;
    delete person2;

    return 0;
}

