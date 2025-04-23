#include <stdio.h>
#include <stdlib.h>

// Structure for BST node
struct Node
{
    int data;
    struct Node *left, *right;
};

// Global variable - root pointer
struct Node *root = NULL;

// Function to create a new node
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("\nMemory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node in BST
struct Node *insert(struct Node *node, int value)
{
    // If the tree is empty, return a new node
    if (node == NULL)
    {
        return createNode(value);
    }

    // Otherwise, recur down the tree
    if (value < node->data)
    {
        node->left = insert(node->left, value);
    }
    else if (value > node->data)
    {
        node->right = insert(node->right, value);
    }

    // Return the unchanged node pointer
    return node;
}

// Function to find the node with minimum value in a BST
struct Node *minValueNode(struct Node *node)
{
    struct Node *current = node;

    // Find the leftmost leaf
    while (current && current->left != NULL)
    {
        current = current->left;
    }

    return current;
}

// Function to delete a node from BST
struct Node *deleteNode(struct Node *root, int value)
{
    // Base case
    if (root == NULL)
    {
        return root;
    }

    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (value < root->data)
    {
        root->left = deleteNode(root->left, value);
    }
    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (value > root->data)
    {
        root->right = deleteNode(root->right, value);
    }
    // If key is same as root's key, then this is the node to be deleted
    else
    {
        // Node with only one child or no child
        if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest
        // in the right subtree)
        struct Node *temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to perform inorder traversal of BST
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Function to perform preorder traversal of BST
void preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Function to perform postorder traversal of BST
void postorder(struct Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Function to create a BST with N integers
void createBST()
{
    int n, i, value;

    printf("\nEnter the number of elements to insert: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("\nInvalid input! Number of elements should be > 0.\n");
        return;
    }

    // Clear existing tree if any
    root = NULL;

    printf("\nEnter the elements:\n");
    for (i = 0; i < n; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("\nBinary Search Tree created successfully!\n");
}

// Function to delete an element from BST
void deleteBSTNode()
{
    int value;

    if (root == NULL)
    {
        printf("\nTree is empty! Deletion not possible.\n");
        return;
    }

    printf("\nEnter the element to delete: ");
    scanf("%d", &value);

    root = deleteNode(root, value);

    printf("\nElement %d deleted from the BST!\n", value);
}

// Function to display traversals of BST
void displayTraversals()
{
    if (root == NULL)
    {
        printf("\nTree is empty!\n");
        return;
    }

    printf("\nInorder Traversal: ");
    inorder(root);

    printf("\nPreorder Traversal: ");
    preorder(root);

    printf("\nPostorder Traversal: ");
    postorder(root);

    printf("\n");
}

// Main function
int main()
{
    int choice;

    while (1)
    {
        printf("\n=== BINARY SEARCH TREE OPERATIONS MENU ===\n");
        printf("1. Create a BST\n");
        printf("2. Display traversals (Inorder, Preorder, Postorder)\n");
        printf("3. Delete an element from BST\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            createBST();
            break;
        case 2:
            displayTraversals();
            break;
        case 3:
            deleteBSTNode();
            break;
        case 4:
            printf("\nExiting program. Goodbye!\n");
            exit(0);
        default:
            printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}