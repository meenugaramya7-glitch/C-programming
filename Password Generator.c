#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    int length, i;
    char password[100];

    const char characters[] =
        "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z"
        "a b c d e f g h i j k l m n o p q r s t u v w x y z"
        "01 2 3 4 5 6 7 8 9"
        "! @ # $ % ^ & *";

    int charCount = strlen(characters);

    printf("=================================\n");
    printf("       PASSWORD GENERATOR        \n");
    printf("=================================\n");

    printf("Enter password length (4-99): ");
    scanf("%d", &length);

    if (length < 4 || length > 99) {
        printf("Invalid password length!\n");
        return 1;
    }

    // Initialize random number generator
    srand(time(NULL));

    // Generate password
    for (i = 0; i < length; i++) {
        password[i] = characters[rand() % charCount];
    }

    password[length] = '\0';

    printf("\nGenerated Password: %s\n", password);

    return 0;
}
