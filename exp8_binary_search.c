#include <stdio.h>
#include <stdlib.h>

// Function for binary search
int binarySearch(int arr[], int low, int high, int key)
{
    int mid;

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        // Check if key is present at mid
        if (arr[mid] == key)
        {
            return mid;
        }

        // If key is greater, ignore left half
        if (arr[mid] < key)
        {
            low = mid + 1;
        }
        // If key is smaller, ignore right half
        else
        {
            high = mid - 1;
        }
    }

    // Key is not present
    return -1;
}

// Function to perform recursive binary search
int recursiveBinarySearch(int arr[], int low, int high, int key)
{
    if (high < low)
    {
        return -1;
    }

    int mid = low + (high - low) / 2;

    // If the element is present at the middle
    if (arr[mid] == key)
    {
        return mid;
    }

    // If element is smaller than mid, then it's in left subarray
    if (arr[mid] > key)
    {
        return recursiveBinarySearch(arr, low, mid - 1, key);
    }

    // Else the element can only be present in right subarray
    return recursiveBinarySearch(arr, mid + 1, high, key);
}

// Function to get array input from user
void inputArray(int arr[], int size)
{
    int i;

    printf("\nEnter %d elements in sorted order:\n", size);
    for (i = 0; i < size; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

// Function to display array
void displayArray(int arr[], int size)
{
    int i;

    printf("\nArray elements: ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main()
{
    int *arr, size, key, choice, result, searchChoice;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (size <= 0)
    {
        printf("\nInvalid size! Size should be > 0.\n");
        return 1;
    }

    // Dynamically allocate memory for array
    arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL)
    {
        printf("\nMemory allocation failed!\n");
        return 1;
    }

    // Input array elements
    inputArray(arr, size);

    while (1)
    {
        printf("\n=== BINARY SEARCH MENU ===\n");
        printf("1. Display array\n");
        printf("2. Perform binary search\n");
        printf("3. Exit\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            displayArray(arr, size);
            break;
        case 2:
            printf("\nEnter the element to search: ");
            scanf("%d", &key);

            printf("\nSelect binary search method:\n");
            printf("1. Iterative\n");
            printf("2. Recursive\n");
            printf("Enter your choice (1-2): ");
            scanf("%d", &searchChoice);

            if (searchChoice == 1)
            {
                result = binarySearch(arr, 0, size - 1, key);
            }
            else if (searchChoice == 2)
            {
                result = recursiveBinarySearch(arr, 0, size - 1, key);
            }
            else
            {
                printf("\nInvalid choice! Using iterative method by default.\n");
                result = binarySearch(arr, 0, size - 1, key);
            }

            if (result == -1)
            {
                printf("\n%d not found in the array.\n", key);
            }
            else
            {
                printf("\n%d found at index %d (position %d).\n", key, result, result + 1);
            }
            break;
        case 3:
            printf("\nExiting program. Goodbye!\n");
            free(arr);
            exit(0);
        default:
            printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}