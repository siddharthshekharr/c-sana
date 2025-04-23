#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME_LENGTH 50
#define MAX_STUDENTS 100

// Structure for Student
struct Student
{
    int id;
    char name[MAX_NAME_LENGTH];
    float gpa;
};

// Structure for Node in Linked List
struct Node
{
    struct Student data;
    struct Node *next;
};

// Structure for Student Database
struct StudentDatabase
{
    struct Node *head;
    int count;
};

// Function to create an empty database
struct StudentDatabase *createDatabase()
{
    struct StudentDatabase *db = (struct StudentDatabase *)malloc(sizeof(struct StudentDatabase));
    db->head = NULL;
    db->count = 0;
    return db;
}

// Function to create a new node
struct Node *createNode(struct Student student)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("\nMemory allocation failed!\n");
        exit(1);
    }
    newNode->data = student;
    newNode->next = NULL;
    return newNode;
}

// Function to add a student to the database
void addStudent(struct StudentDatabase *db)
{
    if (db->count >= MAX_STUDENTS)
    {
        printf("\nDatabase is full! Cannot add more students.\n");
        return;
    }

    struct Student student;

    printf("\nEnter student details:\n");
    printf("ID: ");
    scanf("%d", &student.id);

    // Check if ID already exists
    struct Node *current = db->head;
    while (current != NULL)
    {
        if (current->data.id == student.id)
        {
            printf("\nStudent with ID %d already exists! Please use a unique ID.\n", student.id);
            return;
        }
        current = current->next;
    }

    printf("Name: ");
    getchar(); // Clear input buffer
    fgets(student.name, MAX_NAME_LENGTH, stdin);
    student.name[strcspn(student.name, "\n")] = 0; // Remove newline

    printf("GPA: ");
    scanf("%f", &student.gpa);

    struct Node *newNode = createNode(student);

    // Insert at the beginning
    newNode->next = db->head;
    db->head = newNode;
    db->count++;

    printf("\nStudent added successfully!\n");
}

// Function to delete a student from the database
void deleteStudent(struct StudentDatabase *db)
{
    if (db->head == NULL)
    {
        printf("\nDatabase is empty! No students to delete.\n");
        return;
    }

    int id;
    printf("\nEnter student ID to delete: ");
    scanf("%d", &id);

    struct Node *current = db->head;
    struct Node *prev = NULL;

    // If head node itself holds the student to be deleted
    if (current != NULL && current->data.id == id)
    {
        db->head = current->next;
        free(current);
        db->count--;
        printf("\nStudent with ID %d deleted successfully!\n", id);
        return;
    }

    // Search for the student to be deleted
    while (current != NULL && current->data.id != id)
    {
        prev = current;
        current = current->next;
    }

    // If student not found
    if (current == NULL)
    {
        printf("\nStudent with ID %d not found!\n", id);
        return;
    }

    // Unlink the node from linked list
    prev->next = current->next;
    free(current);
    db->count--;

    printf("\nStudent with ID %d deleted successfully!\n", id);
}

// Function to search for a student by ID
void searchStudent(struct StudentDatabase *db)
{
    if (db->head == NULL)
    {
        printf("\nDatabase is empty! No students to search.\n");
        return;
    }

    int id;
    printf("\nEnter student ID to search: ");
    scanf("%d", &id);

    struct Node *current = db->head;

    while (current != NULL)
    {
        if (current->data.id == id)
        {
            printf("\nStudent found:\n");
            printf("ID: %d\n", current->data.id);
            printf("Name: %s\n", current->data.name);
            printf("GPA: %.2f\n", current->data.gpa);
            return;
        }
        current = current->next;
    }

    printf("\nStudent with ID %d not found!\n", id);
}

// Function to update student information
void updateStudent(struct StudentDatabase *db)
{
    if (db->head == NULL)
    {
        printf("\nDatabase is empty! No students to update.\n");
        return;
    }

    int id;
    printf("\nEnter student ID to update: ");
    scanf("%d", &id);

    struct Node *current = db->head;

    while (current != NULL)
    {
        if (current->data.id == id)
        {
            printf("\nCurrent student details:\n");
            printf("ID: %d\n", current->data.id);
            printf("Name: %s\n", current->data.name);
            printf("GPA: %.2f\n", current->data.gpa);

            printf("\nEnter new details:\n");
            printf("Name: ");
            getchar(); // Clear input buffer
            fgets(current->data.name, MAX_NAME_LENGTH, stdin);
            current->data.name[strcspn(current->data.name, "\n")] = 0; // Remove newline

            printf("GPA: ");
            scanf("%f", &current->data.gpa);

            printf("\nStudent information updated successfully!\n");
            return;
        }
        current = current->next;
    }

    printf("\nStudent with ID %d not found!\n", id);
}

// Function to sort students by ID using Bubble Sort
void sortStudentsById(struct StudentDatabase *db)
{
    if (db->head == NULL || db->head->next == NULL)
    {
        printf("\nDatabase has 0 or 1 student, no need to sort.\n");
        return;
    }

    struct Node *i, *j;
    struct Student temp;
    bool swapped;

    for (i = db->head; i != NULL; i = i->next)
    {
        swapped = false;
        for (j = db->head; j->next != NULL; j = j->next)
        {
            if (j->data.id > j->next->data.id)
            {
                // Swap data
                temp = j->data;
                j->data = j->next->data;
                j->next->data = temp;
                swapped = true;
            }
        }
        if (!swapped)
        {
            break;
        }
    }

    printf("\nStudents sorted by ID successfully!\n");
}

// Function to sort students by name using Bubble Sort
void sortStudentsByName(struct StudentDatabase *db)
{
    if (db->head == NULL || db->head->next == NULL)
    {
        printf("\nDatabase has 0 or 1 student, no need to sort.\n");
        return;
    }

    struct Node *i, *j;
    struct Student temp;
    bool swapped;

    for (i = db->head; i != NULL; i = i->next)
    {
        swapped = false;
        for (j = db->head; j->next != NULL; j = j->next)
        {
            if (strcmp(j->data.name, j->next->data.name) > 0)
            {
                // Swap data
                temp = j->data;
                j->data = j->next->data;
                j->next->data = temp;
                swapped = true;
            }
        }
        if (!swapped)
        {
            break;
        }
    }

    printf("\nStudents sorted by name successfully!\n");
}

// Function to sort students by GPA using Bubble Sort
void sortStudentsByGpa(struct StudentDatabase *db)
{
    if (db->head == NULL || db->head->next == NULL)
    {
        printf("\nDatabase has 0 or 1 student, no need to sort.\n");
        return;
    }

    struct Node *i, *j;
    struct Student temp;
    bool swapped;

    for (i = db->head; i != NULL; i = i->next)
    {
        swapped = false;
        for (j = db->head; j->next != NULL; j = j->next)
        {
            if (j->data.gpa < j->next->data.gpa)
            { // Sort in descending order
                // Swap data
                temp = j->data;
                j->data = j->next->data;
                j->next->data = temp;
                swapped = true;
            }
        }
        if (!swapped)
        {
            break;
        }
    }

    printf("\nStudents sorted by GPA (descending) successfully!\n");
}

// Function to display all students
void displayAllStudents(struct StudentDatabase *db)
{
    if (db->head == NULL)
    {
        printf("\nDatabase is empty! No students to display.\n");
        return;
    }

    struct Node *current = db->head;
    int count = 1;

    printf("\n=== STUDENT DATABASE ===\n");
    printf("Total students: %d\n\n", db->count);

    while (current != NULL)
    {
        printf("Student %d:\n", count);
        printf("ID: %d\n", current->data.id);
        printf("Name: %s\n", current->data.name);
        printf("GPA: %.2f\n", current->data.gpa);
        printf("------------------------\n");

        current = current->next;
        count++;
    }
}

// Main function
int main()
{
    struct StudentDatabase *db = createDatabase();
    int choice, sortChoice;

    while (1)
    {
        printf("\n=== STUDENT DATABASE MANAGEMENT SYSTEM ===\n");
        printf("1. Add a student\n");
        printf("2. Delete a student\n");
        printf("3. Search for a student\n");
        printf("4. Update student information\n");
        printf("5. Sort students\n");
        printf("6. Display all students\n");
        printf("7. Exit\n");
        printf("Enter your choice (1-7): ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addStudent(db);
            break;
        case 2:
            deleteStudent(db);
            break;
        case 3:
            searchStudent(db);
            break;
        case 4:
            updateStudent(db);
            break;
        case 5:
            printf("\n=== SORT MENU ===\n");
            printf("1. Sort by ID\n");
            printf("2. Sort by Name\n");
            printf("3. Sort by GPA (descending)\n");
            printf("Enter your choice (1-3): ");
            scanf("%d", &sortChoice);

            switch (sortChoice)
            {
            case 1:
                sortStudentsById(db);
                break;
            case 2:
                sortStudentsByName(db);
                break;
            case 3:
                sortStudentsByGpa(db);
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
            }
            break;
        case 6:
            displayAllStudents(db);
            break;
        case 7:
            printf("\nExiting program. Goodbye!\n");
            // Free memory
            struct Node *current = db->head;
            struct Node *next;
            while (current != NULL)
            {
                next = current->next;
                free(current);
                current = next;
            }
            free(db);
            exit(0);
        default:
            printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}