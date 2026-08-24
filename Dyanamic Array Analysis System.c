#include <stdio.h>
#include <stdlib.h>

// Function to find maximum
int findMaximum(int *arr, int n)
{
    int max = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }

    return max;
}

// Function to find minimum
int findMinimum(int *arr, int n)
{
    int min = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min)
            min = arr[i];
    }

    return min;
}

// Function to calculate sum
int calculateSum(int *arr, int n)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
        sum += arr[i];

    return sum;
}

// Function to search an element
int searchElement(int *arr, int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
            return i;
    }

    return -1;
}

// Function to count frequency
int countFrequency(int *arr, int n, int key)
{
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
            count++;
    }

    return count;
}

// Function to reverse array
void reverseArray(int *arr, int n)
{
    int temp;

    for (int i = 0; i < n / 2; i++)
    {
        temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }
}

// Function to display array
void displayArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

int main()
{
    int n, key;
    int *arr;

    // Take number of elements
    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Invalid number of elements!\n");
        return 0;
    }

    // Dynamic memory allocation
    arr = (int *)malloc(n * sizeof(int));

    // Check memory allocation
    if (arr == NULL)
    {
        printf("Memory aloocation failed\n");
        return 0;
    }

    // Accept elements
    printf("Enter %d integer elements:\n", n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Display original array
    printf("\nOriginal Array: ");
    displayArray(arr, n);

    // Maximum and minimum
    printf("Maximum Element: %d\n", findMaximum(arr, n));
    printf("Minimum Element: %d\n", findMinimum(arr, n));

    // Sum and average
    int sum = calculateSum(arr, n);
    float average = (float)sum / n;

    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", average);

    // Search element
    printf("\nEnter element to search: ");
    scanf("%d",&key);

    int position = searchElement(arr, n, key);

    if (position != -1)
        printf("Element %d found at position %d.\n",
               key, position + 1);
    else
        printf("Element %d not found.\n", key);

    // Frequency
    printf("Frequency of %d: %d\n",
           key, countFrequency(arr, n, key));

    // Reverse array
    reverseArray(arr, n);

    printf("\nReversed Array: ");
    displayArray(arr, n);

    // Release memory
    free(arr);

    printf("\nMemory released successfully.\n");

    return 0;
}