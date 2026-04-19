#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    int choice;

    cout << "1. Add Item\n";
    cout << "2. View All Items\n";
    cout << "3. Search Item\n";
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1) {
        ofstream file("inventory.txt", ios::app);

        string name;
        int qty;
        float price;

        cout << "Enter item name: ";
        cin >> name;
        cout << "Enter quantity: ";
        cin >> qty;
        cout << "Enter price: ";
        cin >> price;

        file << name << " " << qty << " " << price << endl;

        file.close();
        cout << "Item added!\n";
    }

    else if (choice == 2) {
        ifstream file("inventory.txt");

        string name;
        int qty;
        float price;

        cout << "\nItems List:\n";

        while (file >> name >> qty >> price) {
            cout << name << "  " << qty << "  " << price << endl;
        }

        file.close();
    }

    else if (choice == 3) {
        ifstream file("inventory.txt");

        string searchName;
        cout << "Enter item name to search: ";
        cin >> searchName;

        string name;
        int qty;
        float price;
        bool found = false;

        while (file >> name >> qty >> price) {
            if (name == searchName) {
                cout << "Found: " << name << " " << qty << " " << price << endl;
                found = true;
            }
        }

        if (!found)
            cout << "Item not found!\n";

        file.close();
    }

    else {
        cout << "Invalid choice!";
    }

    return 0;
}
