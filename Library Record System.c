#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

// Inner structure to store publication date
struct Date {
    int day;
    int month;
    int year;
};

// Outer structure to store complete book records
struct Book {
    int bookID;
    char title[100];
    char author[50];
    float price;
    struct Date pubDate; // Nesting the Date structure here
};

// Function prototypes
void addBook(struct Book library[], int *count);
void displayBooks(struct Book library[], int count);
void searchBook(struct Book library[], int count);

int main() {
    struct Book library[MAX_BOOKS];
    int bookCount = 0;
    int choice;

    while (1) {
        printf("\n=== LIBRARY RECORD SYSTEM ===\n");
        printf("1. Add New Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book by ID\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        
        // Clear input buffer newline character left by scanf
        getchar(); 

        switch (choice) {
            case 1:
                addBook(library, &bookCount);
                break;
            case 2:
                displayBooks(library, bookCount);
                break;
            case 3:
                searchBook(library, bookCount);
                break;
            case 4:
                printf("Exiting system. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Function to add a book record
void addBook(struct Book library[], int *count) {
    if (*count >= MAX_BOOKS) {
        printf("Library database is full!\n");
        return;
    }

    struct Book newBook;

    printf("\nEnter Book ID: ");
    scanf("%d", &newBook.bookID);
    getchar();                // Clear buffer

    printf("Enter Book Title: ");
    fgets(newBook.title, sizeof(newBook.title), stdin);
    newBook.title[strcspn(newBook.title, "\n")] = 0;         // Remove trailing newline

    printf("Enter Author Name: ");
    fgets(newBook.author, sizeof(newBook.author), stdin);
    newBook.author[strcspn(newBook.author, "\n")] = 0;         // Remove trailing newline

    printf("Enter Price: ");
    scanf("%f", &newBook.price);

    // Accessing elements inside the nested structure using double dot (.) operators

    printf("Enter Publication Date (DD MM YYYY): ");
    scanf("%d %d %d", &newBook.pubDate.day, &newBook.pubDate.month, &newBook.pubDate.year);

    // Save the temporary structure into our database array

    library[*count] = newBook;
    (*count)++;

    printf("Book record added successfully!\n");
}

// Function to print all book records

void displayBooks(struct Book library[], int count) {
    if (count == 0) {
        printf("\nNo books available in the library record.\n");
        return;
    }

    printf("\n--------------------------------------------------------------------------------\n");
    printf("%-7s %-25s %-20s %-8s %-12s\n", "ID", "Title", "Author", "Price", "Pub Date");
    printf("--------------------------------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        // Accessing values from the nested structure variable
        printf("%-7d %-25s %-20s $%-7.2f %02d/%02d/%04d\n", 
               library[i].bookID, 
               library[i].title, 
               library[i].author, 
               library[i].price, 
               library[i].pubDate.day, 
               library[i].pubDate.month, 
               library[i].pubDate.year);
    }
    printf("--------------------------------------------------------------------------------\n");
}

// Function to look up a book using its unique ID
void searchBook(struct Book library[], int count) {
    if (count == 0) {
        printf("\nNo books available to search.\n");
        return;
    }

    int searchID;
    int found = 0;

    printf("\nEnter Book ID to search: ");
    scanf("%d", &searchID);

    for (int i = 0; i < count; i++) {
        if (library[i].bookID == searchID) {
            printf("\n--- Book Found ---\n");
            printf("ID: %d\n", library[i].bookID);
            printf("Title: %s\n", library[i].title);
            printf("Author: %s\n", library[i].author);
            printf("Price: $%.2f\n", library[i].price);
            // Double dot syntax for nested member visibility
            printf("Publication Date: %02d/%02d/%04d\n", 
                   library[i].pubDate.day, 
                   library[i].pubDate.month, 
                   library[i].pubDate.year);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Book with ID %d not found.\n", searchID);
    }
}