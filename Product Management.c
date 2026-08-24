#include <stdio.h>
#include <string.h>

struct Product
{
    int id;
    char name[50];
    float price;
    int quantity;
};

int main()
{
    struct Product p[100];
    int count = 0;
    int choice, id, i, found;
    float total;

    do
    {
        printf("\n========== PRODUCT MANAGEMENT SYSTEM ==========\n");
        printf("1. Add Product\n");
        printf("2. Display Products\n");
        printf("3. Search Product\n");
        printf("4. Update Product\n");
        printf("5. Delete Product\n");
        printf("6. Total Inventory Value\n");
        printf("7. Exit\n");
        printf("===============================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("\nEnter Product ID: ");
                scanf("%d", &p[count].id);

                printf("Enter Product Name: ");
                scanf(" %[^\n]", p[count].name);

                printf("Enter Price: ");
                scanf("%f", &p[count].price);

                printf("Enter Quantity: ");
                scanf("%d", &p[count].quantity);

                count++;

                printf("\nProduct added successfully!\n");
                break;

            case 2:
                if (count == 0)
                {
                    printf("\nNo products available.\n");
                }
                else
                {
                    printf("\n--------------- PRODUCT LIST ---------------\n");
                    printf("ID\tName\t\tPrice\tQuantity\n");
                    printf("---------------------------------------------\n");

                    for (i = 0; i < count; i++)
                    {
                        printf("%d\t%-15s %.2f\t%d\n",
                               p[i].id,
                               p[i].name,
                               p[i].price,
                               p[i].quantity);
                    }
                }
                break;

            case 3:
                printf("\nEnter Product ID to search: ");
                scanf("%d", &id);

                found = 0;

                for (i = 0; i < count; i++)
                {
                    if (p[i].id == id)
                    {
                        printf("\nProduct Found!\n");
                        printf("Product ID : %d\n", p[i].id);
                        printf("Name       : %s\n", p[i].name);
                        printf("Price      : %.2f\n", p[i].price);
                        printf("Quantity   : %d\n", p[i].quantity);

                        found = 1;
                        break;
                    }
                }

                if (!found)
                {
                    printf("\nProduct not found.\n");
                }
                break;

            case 4:
                printf("\nEnter Product ID to update: ");
                scanf("%d", &id);

                found = 0;

                for (i = 0; i < count; i++)
                {
                    if (p[i].id == id)
                    {
                        printf("Enter New Product Name: ");
                        scanf(" %[^\n]", p[i].name);

                        printf("Enter New Price: ");
                        scanf("%f", &p[i].price);

                        printf("Enter New Quantity: ");
                        scanf("%d", &p[i].quantity);

                        printf("\nProduct updated successfully!\n");

                        found = 1;
                        break;
                    }
                }

                if (!found)
                {
                    printf("\nProduct not found.\n");
                }
                break;

            case 5:
                printf("\nEnter Product ID to delete: ");
                scanf("%d", &id);

                found = 0;

                for (i = 0; i < count; i++)
                {
                    if (p[i].id == id)
                    {
                        for (int j = i; j < count - 1; j++)
                        {
                            p[j] = p[j + 1];
                        }

                        count--;

                        printf("\nProduct deleted successfully!\n");

                        found = 1;
                        break;
                    }
                }

                if (!found)
                {
                    printf("\nProduct not found.\n");
                }
                break;

            case 6:
                total = 0;

                for (i = 0; i < count; i++)
                {
                    total = total + (p[i].price * p[i].quantity);
                }

                printf("\nTotal Inventory Value = %.2f\n", total);
                break;

            case 7:
                printf("\nThank you for using Product Management System!\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 7);

    return 0;
}