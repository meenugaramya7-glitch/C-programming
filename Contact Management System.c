#include <stdio.h>

struct Contact {
    char name[30];
    char phone[15];
};

int main() {
    struct Contact c[50];
    int choice, n = 0, i;

    while (1) {
        printf("\n--- Contact Management System ---\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter name: ");
            scanf("%s", c[n].name);

            printf("Enter phone: ");
            scanf("%s", c[n].phone);

            n++;
            printf("Contact added!\n");
        }

        else if (choice == 2) {
            printf("\nContacts:\n");

            for (i = 0; i < n; i++) {
                printf("%d. %s - %s\n",
                       i + 1, c[i].name, c[i].phone);
            }
        }

        else if (choice == 3) {
            printf("Exiting...\n");
            break;
        }

        else {
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
