#include <iostream>
#include <string>
using namespace std;

struct Book {
    int id;
    string title;
    string author;
    int copies;
};

const int MAX_BOOKS = 100;   // maximum number of books the library can hold
Book library[MAX_BOOKS];
int bookCount = 0;

void addBook() {
    if (bookCount >= MAX_BOOKS) {
        cout << "Library is full, cannot add more books!\n";
        return;
    }
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

    library[bookCount++] = b;
    cout << "Book added successfully!\n";
}

void issueBook() {
    int id;
    cout << "Enter Book ID to issue: ";
    cin >> id;
    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == id) {
            if (library[i].copies > 0) {
                library[i].copies--;
                cout << "Book issued successfully!\n";
            } else {
                cout << "No copies available!\n";
            }
            return;
        }
    }
    cout << "Book not found!\n";
}

void returnBook() {
    int id;
    cout << "Enter Book ID to return: ";
    cin >> id;
    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == id) {
            library[i].copies++;
            cout << "Book returned successfully!\n";
            return;
        }
    }
    cout << "Book not found!\n";
}

void displayBooks() {
    cout << "\nLibrary Collection:\n";
    for (int i = 0; i < bookCount; i++) {
        cout << "ID: " << library[i].id
             << " | Title: " << library[i].title
             << " | Author: " << library[i].author
             << " | Copies: " << library[i].copies << endl;
    }
    cout << "Total Books: " << bookCount << endl;
}

int main() {
    int choice;
    do {
        cout << "\n--- Library Menu ---\n";
        cout << "1. Add Book\n";
        cout << "2. Issue Book\n";
        cout << "3. Return Book\n";
        cout << "4. Display Books\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addBook(); break;
            case 2: issueBook(); break;
            case 3: returnBook(); break;
            case 4: displayBooks(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
