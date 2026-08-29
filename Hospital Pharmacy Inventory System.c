#include <stdio.h>
#include <stdlib.h>

struct Date
{
    int day, month, year;
};

struct Medicine
{
    int id, quantity;
    char name[50], category[30], batch[30];
    float price;
    struct Date expiry;
    struct Medicine *next;
};

struct Medicine *head = NULL;
int n,i;

/* Find medicine by ID */
struct Medicine *findMedicine(int id)
{
    struct Medicine *temp = head;

    while (temp != NULL)
    {
        if (temp->id == id)
            return temp;
        temp = temp->next;
    }

    return NULL;
}

/* Add medicine */
void addMedicine()
{
    struct Medicine *newNode;
    printf("Enter how many types of medicines:\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        newNode=malloc(sizeof(struct Medicine));

     if (newNode == NULL)
     {
        printf("Memory allocation failed!\n");
        return;
     }
    

     printf("\nEnter Medicine ID: ");
     scanf("%d", &newNode->id);

     printf("Enter Medicine Name: ");
     scanf(" %[^\n]", newNode->name);

     printf("Enter Category: ");
     scanf(" %[^\n]", newNode->category);

     printf("Enter Batch Number: ");
     scanf(" %[^\n]", newNode->batch);

     printf("Enter Price: ");
     scanf("%f", &newNode->price);

     printf("Enter Quantity: ");
     scanf("%d", &newNode->quantity);

     printf("Enter Expiry Date (DD MM YYYY): ");
     scanf("%d %d %d", &newNode->expiry.day,
          &newNode->expiry.month, &newNode->expiry.year);

     newNode->next = head;
     head = newNode;

     printf("\nMedicine added successfully!\n");
    }
}

/* Display medicines */
void displayMedicines()
{
    struct Medicine *temp = head;

    if (temp == NULL)
    {
        printf("\nNo medicines available!\n");
        return;
    }

    printf("\n----- MEDICINE INVENTORY -----\n");

    while (temp != NULL)
    {
        printf("\nID: %d\nName: %s\nCategory: %s\nBatch Number: %s"
               "\nPrice: %.2f\nQuantity: %d\nExpiry Date: %02d/%02d/%d\n"
               "--------------------------\n",
               temp->id, temp->name, temp->category, temp->batch,
               temp->price, temp->quantity,
               temp->expiry.day, temp->expiry.month, temp->expiry.year);

        temp = temp->next;
    }
}

/* Search medicine */
void searchMedicine()
{
    int id;
    struct Medicine *temp;

    printf("\nEnter Medicine ID to search: ");
    scanf("%d", &id);

    temp = findMedicine(id);

    if (temp == NULL)
    {
        printf("\nMedicine not found!\n");
        return;
    }

    printf("\nMedicine Found!\nName: %s\nCategory: %s\nBatch: %s"
           "\nPrice: %.2f\nQuantity: %d\nExpiry: %02d/%02d/%d\n",
           temp->name, temp->category, temp->batch, temp->price,
           temp->quantity, temp->expiry.day,
           temp->expiry.month, temp->expiry.year);
}

/* Sell medicine */
void sellMedicine()
{
    int id, qty;
    struct Medicine *temp;

    printf("\nEnter Medicine ID: ");
    scanf("%d", &id);

    temp = findMedicine(id);

    if (temp == NULL)
        printf("\nMedicine not found!\n");
    else
    {
        printf("Enter Quantity to sell: ");
        scanf("%d", &qty);

        if (temp->quantity == 0)
            printf("\nMedicine is unavailable. Cannot sell!\n");
        else if (qty > temp->quantity)
            printf("\nInsufficient stock!\n");
        else
        {
            temp->quantity -= qty;
            printf("\nMedicine sold successfully!\nTotal Bill = %.2f\n",
                   temp->price * qty);
        }
    }
}

/* Update stock */
void updateStock()
{
    int id, qty;
    struct Medicine *temp;

    printf("\nEnter Medicine ID: ");
    scanf("%d", &id);

    temp = findMedicine(id);

    if (temp == NULL)
        printf("\nMedicine not found!\n");
    else
    {
        printf("Enter quantity to add: ");
        scanf("%d", &qty);

        temp->quantity += qty;

        printf("\nStock updated successfully!\nNew quantity: %d\n",
               temp->quantity);
    }
}

/* Low stock */
void lowStock()
{
    struct Medicine *temp = head;
    int limit;

    printf("\nEnter low stock limit: ");
    scanf("%d", &limit);

    printf("\n----- LOW STOCK MEDICINES -----\n");

    while (temp != NULL)
    {
        if (temp->quantity <= limit)
            printf("ID: %d | Name: %s | Quantity: %d\n",
                   temp->id, temp->name, temp->quantity);

        temp = temp->next;
    }
}

/* Expired medicines */
void expiredMedicines()
{
    struct Medicine *temp = head;
    struct Date today;
    int found=0;

    printf("\nEnter today's date (DD MM YYYY): ");
    scanf("%d %d %d", &today.day, &today.month, &today.year);

    printf("\n----- EXPIRED MEDICINES -----\n");

    while (temp != NULL)
    {
        if (temp->expiry.year < today.year ||
            (temp->expiry.year == today.year &&
             temp->expiry.month < today.month) ||
            (temp->expiry.year == today.year &&
             temp->expiry.month == today.month &&
             temp->expiry.day < today.day))

             {
                printf("EXPIRED: %s | Expiry: %02d/%02d/%d\n",temp->name,temp->expiry.day,
                temp->expiry.month,temp->expiry.year);
                found =1;
             }

              temp = temp->next;
    }
    if(found==0)
    {
        printf("NO EXPIRED MEDICINES\n");
    }
}

/* Calculate bill */
void calculateBill()
{
    int id, qty;
    struct Medicine *temp;

    printf("\nEnter Medicine ID: ");
    scanf("%d", &id);

    temp = findMedicine(id);

    if (temp == NULL)
    {
        printf("\nMedicine not found!\n");
        return;
    }

    printf("Enter Quantity: ");
    scanf("%d", &qty);

    if (qty > temp->quantity)
        printf("\nRequired quantity is not available!\n");
    else
        printf("\nMedicine: %s\nPrice: %.2f\nQuantity: %d\nTotal Bill: %.2f\n",
               temp->name, temp->price, qty, temp->price * qty);
}

/* Update price */
void updatePrice()
{
    int id;
    float price;
    struct Medicine *temp;

    printf("\nEnter Medicine ID: ");
    scanf("%d", &id);

    temp = findMedicine(id);

    if (temp == NULL)
        printf("\nMedicine not found!\n");
    else
    {
        printf("Enter new price: ");
        scanf("%f", &price);

        temp->price = price;
        printf("\nPrice updated successfully!\n");
    }
}

int main()
{
    int choice;

    do
    {
        printf("\n================================");
        printf("\n HOSPITAL PHARMACY INVENTORY SYSTEM");
        printf("\n================================");
        printf("\n1. Add Medicine");
        printf("\n2. Display All Medicines");
        printf("\n3. Search Medicine");
        printf("\n4. Sell Medicine");
        printf("\n5. Update Stock");
        printf("\n6. Identify Low Stock Medicines");
        printf("\n7. Identify Expired Medicines");
        printf("\n8. Calculate Total Bill");
        printf("\n9. Update Medicine Price");
        printf("\n10. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: addMedicine(); break;
            case 2: displayMedicines(); break;
            case 3: searchMedicine(); break;
            case 4: sellMedicine(); break;
            case 5: updateStock(); break;
            case 6: lowStock(); break;
            case 7: expiredMedicines(); break;
            case 8: calculateBill(); break;
            case 9: updatePrice(); break;
            case 10: printf("\nThank you! Program closed.\n"); break;
            default: printf("\nInvalid choice!\n");
        }

    } while (choice != 10);

    return 0;
}