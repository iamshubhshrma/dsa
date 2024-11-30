#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
struct node
{
    int data;                 // Data value of the node
    struct node *right_child; // Pointer to the right child
    struct node *left_child;  // Pointer to the left child
};

// Function to create a new node
struct node *new_node(int x)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node)); // Allocate memory for the new node
    temp->data = x;                                    // Assign the data value
    temp->left_child = NULL;                           // Initialize the left child as NULL
    temp->right_child = NULL;                          // Initialize the right child as NULL
    return temp;
}

// Function to search for a key in the BST
struct node *search(struct node *root, int x)
{
    if (root == NULL || root->data == x) // If the root is NULL or key is found
        return root;
    else if (x > root->data) // If key is greater, search in the right subtree
        return search(root->right_child, x);
    else // If key is smaller, search in the left subtree
        return search(root->left_child, x);
}

// Function to insert a new key into the BST
struct node *insert(struct node *root, int x)
{
    if (root == NULL)        // If the current subtree is empty
        return new_node(x);  // Create a new node
    else if (x > root->data) // If key is greater, insert in the right subtree
        root->right_child = insert(root->right_child, x);
    else // If key is smaller, insert in the left subtree
        root->left_child = insert(root->left_child, x);
    return root; // Return the updated subtree
}

// Function to find the node with the smallest value in a subtree
struct node *find_minimum(struct node *root)
{
    if (root == NULL) // If the subtree is empty
        return NULL;
    else if (root->left_child != NULL) // Traverse to the leftmost leaf node
        return find_minimum(root->left_child);
    return root; // Return the node with the smallest value
}

// Function to delete_from_tree a node with a given key from the BST
struct node *delete_from_tree(struct node *root, int x)
{
    if (root == NULL) // If the tree is empty
        return NULL;
    if (x > root->data) // If the key is greater, search in the right subtree
        root->right_child = delete_from_tree(root->right_child, x);
    else if (x < root->data) // If the key is smaller, search in the left subtree
        root->left_child = delete_from_tree(root->left_child, x);
    else
    { // If the node to be delete_from_treed is found
        // Case 1: Node with no children
        if (root->left_child == NULL && root->right_child == NULL)
        {
            free(root); // Free the node
            return NULL;
        }
        // Case 2: Node with one child
        else if (root->left_child == NULL || root->right_child == NULL)
        {
            struct node *temp;
            if (root->left_child == NULL) // If there is only a right child
                temp = root->right_child;
            else // If there is only a left child
                temp = root->left_child;
            free(root);  // Free the current node
            return temp; // Return the single child
        }
        // Case 3: Node with two children
        else
        {
            struct node *temp = find_minimum(root->right_child);                 // Find the inorder successor
            root->data = temp->data;                                             // Replace the current node's value
            root->right_child = delete_from_tree(root->right_child, temp->data); // delete_from_tree the inorder successor
        }
    }
    return root; // Return the updated tree
}

// Function to perform Inorder Traversal of the BST
// Inorder traversal visits nodes in ascending order (Left -> Root -> Right)
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left_child);  // Recursively traverse the left subtree
        printf(" %d ", root->data); // Visit the root node
        inorder(root->right_child); // Recursively traverse the right subtree
    }
}

// Function to take user input
int takeinput()
{
    int num;
    printf("Enter the value: ");
    scanf("%d", &num);
    return num;
}

// Menu-driven driver function
int main()
{
    struct node *root = NULL; // Initialize the root of the BST

    printf("Binary Search Tree program:\n");

    while (1)
    { // Infinite loop for the menu
        printf("\nChoose an option:\n");
        printf("1 - Insert a key\n");
        printf("2 - delete_from_tree a key\n");
        printf("3 - Search for a key\n");
        printf("4 - Display Inorder Traversal\n");
        printf("5 - Exit\n");
        int choice = takeinput();
        int key;

        switch (choice)
        {
        case 1: // Insert a key
            printf("Inserting...\n");
            key = takeinput();
            root = insert(root, key);
            break;

        case 2: // delete_from_tree a key
            printf("Deleting...\n");
            key = takeinput();
            root = delete_from_tree(root, key);
            break;

        case 3: // Search for a key
            printf("Searching...\n");
            key = takeinput();
            if (search(root, key))
                printf("Key %d found in the BST.\n", key);
            else
                printf("Key %d not found in the BST.\n", key);
            break;

        case 4: // Display Inorder Traversal
            printf("Inorder Traversal:\n");
            inorder(root);
            printf("\n");
            break;

        case 5: // Exit the program
            printf("Program execution complete.\n");
            return 0;

        default:
            printf("Invalid option. Please try again.\n");
        }
    }
}
