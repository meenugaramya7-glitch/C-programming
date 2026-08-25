#include <stdio.h>
#include <math.h>

int binaryToDecimal(long long n) {
    int decimal = 0, base = 1, rem;

    while (n > 0) {
        rem = n % 10;
        decimal += rem * base;
        base *= 2;
        n /= 10;
    }

    return decimal;
}

void decimalToBinary(int n) {
    int binary[32], i = 0;

    if (n == 0) {
        printf("Binary = 0");
        return;
    }

    while (n > 0) {
        binary[i++] = n % 2;
        n /= 2;
    }

    printf("Binary = ");
    for (i = i - 1; i >= 0; i--)
        printf("%d", binary[i]);
}

void decimalToOctal(int n) {
    printf("Octal = %o", n);
}

void decimalToHex(int n) {
    printf("Hexadecimal = %X", n);
}

int main() {
    int choice, decimal;
    long long binary;

    printf("NUMBER SYSTEM CONVERSION\n");
    printf("1. Binary to Decimal\n");
    printf("2. Decimal to Binary\n");
    printf("3. Decimal to Octal\n");
    printf("4. Decimal to Hexadecimal\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter binary number: ");
            scanf("%lld", &binary);
            printf("Decimal = %d", binaryToDecimal(binary));
            break;

        case 2:
            printf("Enter decimal number: ");
            scanf("%d", &decimal);
            decimalToBinary(decimal);
            break;

        case 3:
            printf("Enter decimal number: ");
            scanf("%d", &decimal);
            decimalToOctal(decimal);
            break;

        case 4:
            printf("Enter decimal number: ");
            scanf("%d", &decimal);
            decimalToHex(decimal);
            break;

        default:
            printf("Invalid choice!");
    }

    return 0;
}
