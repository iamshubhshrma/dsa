#include <iostream>
#include <stdio.h>

// Define the structure for a node in the doubly linked list
struct node
{
    int data;          // Data stored in the node
    struct node *prev; // Pointer to the previous node
    struct node *next; // Pointer to the next node
};

struct node *start; // Pointer to the head of the doubly linked list

// Function to count the total number of nodes in the list
void count_nodes()
{
    int count = 0;             // Initialize count to zero
    struct node *temp = start; // Start traversing from the head
    while (temp != NULL)
    {                      // Traverse until the end of the list
        count++;           // Increment count for each node
        temp = temp->next; // Move to the next node
    }
    printf("There are total %d nodes in the Doubly linked list.\n", count);
}

// Function to delete_from_tree a node from a specific location in the list
void delete_from_tree_from_location(int loc)
{
    if (start == NULL)
    {
        // If the list is empty, print an error and return
        printf("\n\nThe Doubly linked list is empty\n\n");
        return;
    }
    struct node *temp = start;   // Temporary pointer to traverse the list
    struct node *current = NULL; // Pointer to hold the previous node

    if (loc == 1)
    {
        // Special case: Location 1 should be handled by `delete_from_tree_from_begin()`
        printf("\n\nIf you want to delete_from_tree the first element, use the delete_from_tree from beginning function!\n\n");
        return;
    }
    else
    {
        // Traverse the list to find the node at the given location
        for (int i = 1; i < loc; i++)
        {
            current = temp; // Keep track of the previous node
            if (temp->next != NULL)
            {
                temp = temp->next; // Move to the next node
            }
            else
            {
                // If we reach the end without finding the location, it's invalid
                printf("\nLocation not valid\n");
                return;
            }
        }
        if (temp == NULL)
        {
            // Handle the case where the location exceeds the list bounds
            printf("\n\nThe location is out of bounds\n\n");
            return;
        }
        // Update the links to bypass the node to be delete_from_treed
        current->next = temp->next;
        if (temp->next)
            temp->next->prev = current; // Update the backward link if it's not the last node
        free(temp);                     // Free memory of the delete_from_treed node
    }
}

// Function to delete_from_tree the first node in the list
void delete_from_tree_from_begin()
{
    if (start == NULL)
    {
        // If the list is empty, print an error
        printf("\n\nCannot delete_from_tree from an empty Doubly linked list\n\n");
    }
    else if (start->next == NULL)
    {
        // Special case: If there's only one node, set the list to empty
        start = NULL;
    }
    else
    {
        // General case: Update the head to the second node and adjust pointers
        start = start->next;
        start->prev = NULL; // Remove the backward link to the delete_from_treed node
    }
}

// Function to delete_from_tree the last node in the list
void delete_from_tree_from_end()
{
    if (start == NULL)
    {
        // If the list is empty, print an error
        printf("\n\nCannot delete_from_tree from an empty Doubly linked list\n\n");
    }
    else if (start->next == NULL)
    {
        // Special case: If there's only one node, set the list to empty
        start = NULL;
    }
    else
    {
        // Traverse to the last node
        struct node *temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        // Update the backward link of the second last node
        temp->prev->next = NULL;
        free(temp); // Free memory of the last node
    }
}

// Function to insert a new node at a specific location in the list
void insert_at_location(int loc, int data)
{
    struct node *temp, *new_node;
    new_node = (struct node *)malloc(sizeof(struct node)); // Allocate memory for the new node
    temp = start;                                          // Start traversing from the head

    if (temp == NULL)
    {
        // If the list is empty, insertion at a location is invalid
        printf("\n\nCannot insert into an empty list\n\n");
        return;
    }

    // Traverse to the node before the given location
    for (int i = 1; i < loc - 1; i++)
    {
        if (temp != NULL)
        {
            temp = temp->next;
        }
    }

    if (temp == NULL)
    {
        // If the location exceeds the list bounds, print an error
        printf("Location out of bounds\n");
    }
    else
    {
        // Update pointers to insert the new node
        new_node->data = data;
        new_node->prev = temp;       // Point back to the current node
        new_node->next = temp->next; // Point forward to the next node
        if (temp->next)
            temp->next->prev = new_node; // Update the backward link of the next node
        temp->next = new_node;           // Link the current node to the new node
    }
}

// Function to insert a new node at the beginning of the list
void insert_at_beginning(int data)
{
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node)); // Allocate memory for the new node
    new_node->data = data;

    if (start == NULL)
    {
        // If the list is empty, the new node becomes the only node
        new_node->prev = NULL;
        new_node->next = NULL;
        start = new_node; // Update the head pointer
    }
    else
    {
        // Update pointers to insert the new node at the beginning
        start->prev = new_node;
        new_node->next = start;
        new_node->prev = NULL; // Set backward link of the new node to NULL
        start = new_node;      // Update the head pointer
    }
}

// Function to insert a new node at the end of the list
void insert_at_end(int num)
{
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node)); // Allocate memory for the new node
    new_node->data = num;
    new_node->next = NULL; // The last node's next is always NULL

    if (start == NULL)
    {
        // If the list is empty, the new node becomes the only node
        new_node->prev = NULL;
        start = new_node; // Update the head pointer
    }
    else
    {
        // Traverse to the last node
        struct node *temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        // Update pointers to add the new node at the end
        temp->next = new_node;
        new_node->prev = temp;
    }
}

// Function to display all the nodes in the list
void display()
{
    if (start == NULL)
    {
        printf("\n\nDoubly linked list is empty\n\n");
    }
    else
    {
        struct node *ptr = start; // Start traversing from the head
        printf("\n\nDisplaying Doubly linked list:\n");
        while (ptr != NULL)
        {
            printf("%d  \n", ptr->data); // Print the data of the current node
            ptr = ptr->next;             // Move to the next node
        }
    }
}

// Helper function to take input from the user
int takeinput()
{
    int num;
    printf("Enter the value: ");
    scanf("%d", &num); // Read the input value
    return num;
}

int main()
{
    printf("Doubly linked list program:\n");
    while (1)
    {
        printf("Choose an option:\n");
        printf("1 - Display list\n2 - Insert at beginning\n3 - Insert at end\n4 - Insert at location\n");
        printf("5 - delete_from_tree from beginning\n6 - delete_from_tree from end\n7 - delete_from_tree from location\n8 - Count nodes\n9 - Exit\n");
        int ch = takeinput(); // Read the user's choice
        int loc, num;
        switch (ch)
        {
        case 1:
            display(); // Display the list
            break;
        case 2:
            printf("Inserting at the beginning...\n");
            num = takeinput(); // Take input for the new node's data
            insert_at_beginning(num);
            break;
        case 3:
            printf("Inserting at the end...\n");
            num = takeinput();
            insert_at_end(num);
            break;
        case 4:
            printf("Inserting at location...\n");
            printf("Enter location: ");
            loc = takeinput();
            printf("Enter number to insert: ");
            num = takeinput();
            insert_at_location(loc, num);
            break;
        case 5:
            delete_from_tree_from_begin();
            break;
        case 6:
            delete_from_tree_from_end();
            break;
        case 7:
            printf("Deleting from location...\n");
            printf("Enter location: ");
            loc = takeinput();
            delete_from_tree_from_location(loc);
            break;
        case 8:
            count_nodes();
            break;
        case 9:
            printf("Exiting program...\n");
            return 0; // Exit the program
        default:
            printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
