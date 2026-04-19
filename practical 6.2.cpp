#include <iostream>
using namespace std;

// Base Class
class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) {
        name = n;
        age = a;
    }

    void displayPerson() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

// Intermediate Class
class Employee : public Person {
protected:
    int empID;

public:
    Employee(string n, int a, int id) : Person(n, a) {
        empID = id;
    }

    void displayEmployee() {
        cout << "Employee ID: " << empID << endl;
    }
};

// Top Class
class Manager : public Employee {
    string dept;

public:
    Manager(string n, int a, int id, string d)
        : Employee(n, a, id) {
        dept = d;
    }

    void displayManager() {
        displayPerson();
        displayEmployee();
        cout << "Department: " << dept << endl;
    }

    int getID() {
        return empID;
    }
};

int main() {

    // -------- STATIC METHOD --------
    Manager m[2] = {
        Manager("Amit", 30, 101, "HR"),
        Manager("Riya", 35, 102, "IT")
    };

    cout << "All Managers:\n";
    for (int i = 0; i < 2; i++) {
        cout << "\nManager " << i+1 << ":\n";
        m[i].displayManager();
    }

    // -------- SEARCH BY ID --------
    int searchID;
    cout << "\nEnter ID to search: ";
    cin >> searchID;

    bool found = false;
    for (int i = 0; i < 2; i++) {
        if (m[i].getID() == searchID) {
            cout << "\nManager Found:\n";
            m[i].displayManager();
            found = true;
        }
    }

    if (!found)
        cout << "Not Found!\n";

    return 0;
}
