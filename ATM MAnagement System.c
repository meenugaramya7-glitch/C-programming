#include <stdio.h>
#include <string.h>

// Function to check balance
void checkBalance(float *balance)
{
    printf("\nCurrent Balance: Rs. %.2f\n", *balance);
}

// Function to deposit money
void depositMoney(float *balance)
{
    float amount;

    printf("\nEnter deposit amount: Rs. ");
    scanf("%f", &amount);

    if (amount <= 0)
    {
        printf("Invalid amount! Deposit must be greater than 0.\n");
    }
    else
    {
        *balance = *balance + amount;
        printf("Amount deposited successfully.\n");
        printf("Updated Balance: Rs. %.2f\n", *balance);
    }
}

// Function to withdraw money
void withdrawMoney(float *balance)
{
    float amount;

    printf("\nEnter withdrawal amount: Rs. ");
    scanf("%f", &amount);

    if (amount <= 0)
    {
        printf("Invalid amount!\n");
    }
    else if (amount > *balance)
    {
        printf("Insufficient balance!\n");
    }
    else
    {
        *balance = *balance - amount;
        printf("Please collect your cash.\n");
        printf("Updated Balance: Rs. %.2f\n", *balance);
    }
}

// Function to transfer money
void transferMoney(float *balance)
{
    float amount;
    long long accountNumber;

    printf("\nEnter receiver account number: ");
    scanf("%lld", &accountNumber);

    printf("Enter transfer amount: Rs. ");
    scanf("%f", &amount);

    if (amount <= 0)
    {
        printf("Invalid transfer amount!\n");
    }
    else if (amount > *balance)
    {
        printf("Insufficient balance for transfer!\n");
    }
    else
    {
        *balance = *balance - amount;

        printf("Rs. %.2f transferred successfully.\n", amount);
        printf("To Account: %lld\n", accountNumber);
        printf("Updated Balance: Rs. %.2f\n", *balance);
    }
}

// Function to display account details
void displayAccountDetails(char name[], long long accountNumber,
                           float *balance)
{
    printf("\n========== ACCOUNT DETAILS ==========\n");
    printf("Account Holder : %s\n", name);
    printf("Account Number : %lld\n", accountNumber);
    printf("Balance        : Rs. %.2f\n", *balance);
    printf("=====================================\n");
}

int main()
{
    char name[50];
    long long accountNumber;
    float balance;
    int choice;

    // Account information
    printf("Enter Account Holder Name: ");
    scanf(" %[^\n]", name);

    printf("Enter Account Number: ");
    scanf("%lld", &accountNumber);

    printf("Enter Initial Balance: Rs. ");
    scanf("%f", &balance);

    if (balance < 0)
    {
        printf("Invalid balance!\n");
        return 0;
    }

    do
    {
        printf("\n\n========== ATM MENU ==========\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Transfer Money\n");
        printf("5. Display Account Details\n");
        printf("6. Exit\n");
        printf("===============================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                checkBalance(&balance);
                break;

            case 2:
                depositMoney(&balance);
                break;

            case 3:
                withdrawMoney(&balance);
                break;

            case 4:
                transferMoney(&balance);
                break;

            case 5:
                displayAccountDetails(name, accountNumber, &balance);
                break;

            case 6:
                printf("\nThank you for using the ATM!\n");
                break;

            default:
                printf("\nInvalid choice! Please select 1-6.\n");
        }

    } while (choice != 6);

    return 0;
}