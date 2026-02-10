#include <iostream>
#include <string>
#include <map>
using namespace std;

struct Book {
    int id;
    string title;
    string author;
    int copies;
};

class Library {
    map<int, Book> books;

public:
    void addBook() {
        Book b;
        cout << "Enter Book ID: ";
        cin >> b.id;
        cin.ignore();
        cout << "Enter Title: ";
        getline(cin, b.title);
        cout << "Enter Author: ";
        getline(cin, b.author);
        cout << "Enter Number of Copies: ";
        cin >> b.copies;

        books[b.id] = b;
        cout << "Book added successfully!\n";
    }

    void issueBook() {
        int id;
        cout << "Enter Book ID to issue: ";
        cin >> id;
        if (books.find(id) != books.end() && books[id].copies > 0) {
            books[id].copies--;
            cout << "Book issued: " << books[id].title << "\n";
        } else {
            cout << "Book not available!\n";
        }
    }

    void returnBook() {
        int id;
        cout << "Enter Book ID to return: ";
        cin >> id;
        if (books.find(id) != books.end()) {
            books[id].copies++;
            cout << "Book returned: " << books[id].title << "\n";
        } else {
            cout << "Invalid Book ID!\n";
        }
    }

    void displayTotalBooks() {
        int total = 0;
        for (auto &pair : books) {
            total += pair.second.copies;
        }
        cout << "Total available books: " << total << "\n";
    }
};

int main() {
    Library lib;
    int choice;

    do {
        cout << "\n--- Library Menu ---\n";
        cout << "1. Add Book\n";
        cout << "2. Issue Book\n";
        cout << "3. Return Book\n";
        cout << "4. Display Total Books\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: lib.addBook(); break;
            case 2: lib.issueBook(); break;
            case 3: lib.returnBook(); break;
            case 4: lib.displayTotalBooks(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
