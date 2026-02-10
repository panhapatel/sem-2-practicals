#include <stdio.h>
#include <string.h>

struct Book {
    int id;
    char title[50];
    char author[50];
    int copies;
};

struct Book library[100];
int count = 0;

void addBook() {
    struct Book b;
    printf("Enter Book ID: ");
    scanf("%d", &b.id);
    getchar(); // consume newline
    printf("Enter Title: ");
    fgets(b.title, sizeof(b.title), stdin);
   // b.title[strcspn(b.title, "\n")] = 0; // remove newline
    printf("Enter Author: ");
    fgets(b.author, sizeof(b.author), stdin);
    b.author[strcspn(b.author, "\n")] = 0;
    printf("Enter Number of Copies: ");
    scanf("%d", &b.copies);

    library[count++] = b;
    printf("Book added successfully!\n");
}

void issueBook() {
    int id;
    printf("Enter Book ID to issue: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (library[i].id == id && library[i].copies > 0) {
            library[i].copies--;
            printf("Book issued: %s\n", library[i].title);
            return;
        }
    }
    printf("Book not available!\n");
}

void returnBook() {
    int id;
    printf("Enter Book ID to return: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (library[i].id == id) {
            library[i].copies++;
            printf("Book returned: %s\n", library[i].title);
            return;
        }
    }
    printf("Invalid Book ID!\n");
}

void displayTotalBooks() {
    int total = 0;
    for (int i = 0; i < count; i++) {
        total += library[i].copies;
    }
    printf("Total available books: %d\n", total);
}
void displayAllBooks() {
    printf("\n--- Library Collection ---\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d | Title: %s | Author: %s | Copies: %d\n",
               library[i].id, library[i].title, library[i].author, library[i].copies);
    }
}


int main() {
    int choice;
    do {
        printf("\n--- Library Menu ---\n");
        printf("1. Add Book\n");
        printf("2. Issue Book\n");
        printf("3. Return Book\n");
        printf("4. Display Total Books\n");
        printf("5. Dispaly All Books\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBook(); break;
            case 2: issueBook(); break;
            case 3: returnBook(); break;
            case 4: displayTotalBooks(); break;
            case 5: displayAllBooks(); break;
            case 6: printf("Exiting...\n"); break;

            default: printf("Invalid choice!\n");
        }
    } while (choice != 6);

    return 0;
}

