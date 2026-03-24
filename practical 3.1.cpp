#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string name;
    float basicSalary;
    float bonus;

public:

    Employee(string n, float bSalary) {
        name = n;
        basicSalary = bSalary;
        bonus = 1000;
    }


    Employee(string n, float bSalary, float bns) {
        name = n;
        basicSalary = bSalary;
        bonus = bns;
    }


    inline float calculateSalary() {
        return basicSalary + bonus;
    }

    void display() {
        cout << "\nEmployee Name: " << name;
        cout << "\nBasic Salary: " << basicSalary;
        cout << "\nBonus: " << bonus;
        cout << "\nTotal Salary: " << calculateSalary() << endl;
    }
};

int main() {
    int n;

    cout << "Enter number of employees: ";
    cin >> n;

    Employee* emp[n];

    string name;
    float basic, bonus;
    int choice;

    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for Employee " << i + 1 << endl;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin,name);

        cout << "Enter Basic Salary: ";
        cin >> basic;

        cout << "1.default bonus "<<endl<<"2.custom bonus"<<endl;
        cin >> choice;

        if (choice == 1) {
            emp[i] =new Employee(name, basic);
        } else {
            cout << "Enter Bonus: ";
            cin >> bonus;
            emp[i] =new Employee(name, basic, bonus);
        }
    }

    cout << "\n--- Employee Details ---\n";

    for (int i = 0; i < n; i++) {
        emp[i]->display();
    }



    return 0;
}
