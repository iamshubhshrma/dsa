#include <iostream>
#include <stdio.h>

// Define the structure for a node in the singly linked list
struct node
{
    int data;          // Data stored in the node
    struct node *next; // Pointer to the next node in the list
};

struct node *start = NULL; // Pointer to the head of the linked list (initially NULL)

// Function to insert a new node at the end of the list
void insertatend(int data)
{
    // Create a new node and allocate memory for it
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data; // Assign data to the new node
    new_node->next = NULL; // The new node's next pointer is NULL as it's the last node

    if (start == NULL)
    {
        // If the list is empty, the new node becomes the head
        start = new_node;
    }
    else
    {
        // Traverse the list to find the last node
        struct node *temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next; // Move to the next node
        }
        temp->next = new_node; // Link the last node to the new node
    }
}

// Function to insert a new node at the beginning of the list
void insert_at_beginning(int data)
{
    // Create a new node and allocate memory for it
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;  // Assign data to the new node
    new_node->next = start; // Point the new node to the current head
    start = new_node;       // Update the head to the new node
}

// Function to insert a new node at a specific location in the list
void insert_at_location(int loc, int val)
{
    if (start == NULL)
    {
        // If the list is empty, insertion at a specific location is invalid
        printf("\n\nCannot insert into an empty list\n\n");
        return;
    }

    struct node *temp = start; // Pointer to traverse the list

    // Traverse to the node before the specified location
    for (int i = 1; i < loc - 1; i++)
    {
        if (temp == NULL)
        {
            // If location exceeds the list bounds, print an error
            printf("Location out of bounds\n");
            return;
        }
        temp = temp->next; // Move to the next node
    }

    // Create a new node and allocate memory for it
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = val;        // Assign data to the new node
    new_node->next = temp->next; // Point the new node to the next node
    temp->next = new_node;       // Link the current node to the new node
}

// Function to delete_from_tree the last node in the list
void delete_from_tree_from_end()
{
    if (start == NULL)
    {
        // If the list is empty, print an error
        printf("The linked list is empty\n");
    }
    else if (start->next == NULL)
    {
        // Special case: If there's only one node, set the list to empty
        start = NULL;
    }
    else
    {
        struct node *temp = start; // Pointer to traverse the list
        struct node *prev = NULL;  // Pointer to track the previous node
        while (temp->next != NULL)
        {
            prev = temp;       // Keep track of the previous node
            temp = temp->next; // Move to the next node
        }
        prev->next = NULL; // Remove the last node
        free(temp);        // Free the memory of the delete_from_treed node
    }
}

// Function to delete_from_tree the first node in the list
void delete_from_tree_from_beginning()
{
    if (start == NULL)
    {
        // If the list is empty, print an error
        printf("\n\nThe linked list is empty\n\n");
    }
    else
    {
        struct node *temp = start; // Pointer to the current head
        start = start->next;       // Update the head to the next node
        free(temp);                // Free the memory of the old head
    }
}

// Function to delete_from_tree a node from a specific location in the list
void delete_from_tree_from_location(int loc)
{
    if (start == NULL)
    {
        // If the list is empty, print an error
        printf("\n\nThe linked list is empty\n\n");
        return;
    }

    struct node *temp = start; // Pointer to traverse the list
    struct node *prev = NULL;  // Pointer to track the previous node

    if (loc == 1)
    {
        // Special case: Location 1 should be handled by `delete_from_tree_from_beginning()`
        delete_from_tree_from_beginning();
    }
    else
    {
        // Traverse to the node at the specified location
        for (int i = 1; i < loc; i++)
        {
            prev = temp; // Keep track of the previous node
            if (temp->next != NULL)
            {
                temp = temp->next; // Move to the next node
            }
            else
            {
                // If location exceeds the list bounds, print an error
                printf("\nLocation not valid\n");
                return;
            }
        }
        prev->next = temp->next; // Bypass the node to be delete_from_treed
        free(temp);              // Free the memory of the delete_from_treed node
    }
}

// Function to display all the nodes in the list
void display()
{
    if (start == NULL)
    {
        // If the list is empty, print a message
        printf("The linked list is empty\n");
    }
    else
    {
        struct node *ptr = start; // Pointer to traverse the list
        printf("\nDisplaying linked list:\n");
        while (ptr != NULL)
        {
            printf("%d  \n", ptr->data); // Print the data of the current node
            ptr = ptr->next;             // Move to the next node
        }
    }
}

// Function to count the total number of nodes in the list
void count_nodes()
{
    int count = 0;             // Initialize count to zero
    struct node *temp = start; // Pointer to traverse the list
    while (temp != NULL)
    {
        count++;           // Increment count for each node
        temp = temp->next; // Move to the next node
    }
    printf("There are total %d nodes in the linked list.\n", count);
}

// Function to reverse the linked list
void reverse_linked_list()
{
    struct node *prev = NULL;     // Pointer to the previous node
    struct node *current = start; // Pointer to the current node
    struct node *next = NULL;     // Pointer to the next node

    while (current != NULL)
    {
        next = current->next; // Store the next node
        current->next = prev; // Reverse the current node's pointer
        prev = current;       // Move prev to the current node
        current = next;       // Move to the next node
    }

    start = prev; // Update the head to the last node (now the first node)
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
    printf("Linked list program:\n");
    while (1)
    {
        printf("Choose an option:\n");
        printf("1 - Display list\n2 - Insert at beginning\n3 - Insert at end\n4 - Insert at location\n");
        printf("5 - delete_from_tree from beginning\n6 - delete_from_tree from end\n7 - delete_from_tree from location\n8 - Count nodes\n9 - Reverse list\n10 - Exit\n");
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
            insertatend(num);
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
            printf("Deleting from beggining...\n");
            delete_from_tree_from_beginning();
            break;
        case 6:
            printf("Deleting from end...\n");
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
            printf("Reversing the linked list...\n");
            reverse_linked_list();
            display();
            break;
        case 10:
            printf("Exiting program...\n");
            return 0; // Exit the program
        default:
            printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
