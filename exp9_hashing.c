#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10

// Structure for hash table
struct HashTable
{
    int *array;
    bool *occupied;
};

// Function to create a hash table
struct HashTable *createHashTable()
{
    struct HashTable *hashTable = (struct HashTable *)malloc(sizeof(struct HashTable));
    hashTable->array = (int *)malloc(SIZE * sizeof(int));
    hashTable->occupied = (bool *)malloc(SIZE * sizeof(bool));

    // Initialize all slots as empty
    for (int i = 0; i < SIZE; i++)
    {
        hashTable->occupied[i] = false;
    }

    return hashTable;
}

// Hash function
int hashFunction(int key)
{
    return key % SIZE;
}

// Function to insert a key into hash table
void insert(struct HashTable *hashTable)
{
    int key, index, i;

    printf("\nEnter the element to insert: ");
    scanf("%d", &key);

    int hKey = hashFunction(key);

    // Linear probing
    for (i = 0; i < SIZE; i++)
    {
        // Linear probing formula
        index = (hKey + i) % SIZE;

        // If slot is empty
        if (!hashTable->occupied[index])
        {
            hashTable->array[index] = key;
            hashTable->occupied[index] = true;
            printf("\n%d inserted at index %d\n", key, index);
            return;
        }
    }

    printf("\nHash Table is full! Cannot insert %d\n", key);
}

// Function to search for a key in hash table
void search(struct HashTable *hashTable)
{
    int key, index, i;

    printf("\nEnter the element to search: ");
    scanf("%d", &key);

    int hKey = hashFunction(key);

    // Linear probing
    for (i = 0; i < SIZE; i++)
    {
        // Linear probing formula
        index = (hKey + i) % SIZE;

        // If slot is found
        if (hashTable->occupied[index] && hashTable->array[index] == key)
        {
            printf("\n%d found at index %d\n", key, index);
            return;
        }

        // If we reach an empty slot
        if (!hashTable->occupied[index])
        {
            break;
        }
    }

    printf("\n%d not found in the hash table\n", key);
}

// Function to delete a key from hash table
void delete(struct HashTable *hashTable)
{
    int key, index, i;

    printf("\nEnter the element to delete: ");
    scanf("%d", &key);

    int hKey = hashFunction(key);

    // Linear probing
    for (i = 0; i < SIZE; i++)
    {
        // Linear probing formula
        index = (hKey + i) % SIZE;

        // If slot is found
        if (hashTable->occupied[index] && hashTable->array[index] == key)
        {
            hashTable->occupied[index] = false;
            printf("\n%d deleted from index %d\n", key, index);
            return;
        }

        // If we reach an empty slot
        if (!hashTable->occupied[index])
        {
            break;
        }
    }

    printf("\n%d not found in the hash table\n", key);
}

// Function to display the hash table
void display(struct HashTable *hashTable)
{
    int i;

    printf("\nHash Table:\n");
    printf("Index\tValue\n");

    for (i = 0; i < SIZE; i++)
    {
        printf("%d\t", i);
        if (hashTable->occupied[i])
        {
            printf("%d", hashTable->array[i]);
        }
        else
        {
            printf("Empty");
        }
        printf("\n");
    }
}

// Main function
int main()
{
    struct HashTable *hashTable = createHashTable();
    int choice;

    while (1)
    {
        printf("\n=== HASH TABLE OPERATIONS MENU ===\n");
        printf("1. Insert element\n");
        printf("2. Search element\n");
        printf("3. Delete element\n");
        printf("4. Display hash table\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insert(hashTable);
            break;
        case 2:
            search(hashTable);
            break;
        case 3:
            delete (hashTable);
            break;
        case 4:
            display(hashTable);
            break;
        case 5:
            printf("\nExiting program. Goodbye!\n");
            free(hashTable->array);
            free(hashTable->occupied);
            free(hashTable);
            exit(0);
        default:
            printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}