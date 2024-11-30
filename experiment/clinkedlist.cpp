// Circular Linked List operations in C++
#include <iostream>
#include <stdio.h>

// Define the structure for a node in the circular linked list
struct node
{
    int data;          // Data stored in the node
    struct node *next; // Pointer to the next node in the list
};

// Declare pointers to the start and last node of the circular linked list
struct node *start = NULL, *last = NULL;

// Function to delete_from_tree a node at a specific location
void delete_from_tree_from_location(int loc)
{
    if (start == NULL) // Check if the list is empty
    {
        printf("\n\nThe Circular linked list is empty\n\n");
        return;
    }
    struct node *temp = start;
    struct node *current = NULL;

    // Special case for location 1 (not handled by this function)
    if (loc == 1)
    {
        printf("\n\nIf you want to delete_from_tree the first element, use the delete_from_tree from beginning function!\n\n");
        return;
    }
    else
    {
        // Traverse the list to find the node at the specified location
        for (int i = 1; i < loc; i++)
        {
            current = temp;
            if (temp->next != NULL)
            {
                temp = temp->next;
            }
            else
            {
                printf("\nLocation not valid\n");
                return;
            }
        }

        if (temp == NULL) // If location is out of bounds
        {
            printf("\n\nThe location is out of Circular linked list\n\n");
            return;
        }

        // Update the pointer to skip the node being delete_from_treed
        current->next = temp->next;
        free(temp); // Free the memory of the delete_from_treed node
    }
}

// Function to delete_from_tree a node from the end of the circular linked list
void delete_from_tree_from_end()
{
    if (start == NULL) // Check if the list is empty
    {
        printf("The Circular linked list is empty");
        return;
    }
    else if (start == last) // If there is only one node in the list
    {
        start = NULL; // The list becomes empty
    }
    else
    {
        struct node *temp = start;

        // Traverse to the second last node
        while (temp->next != last)
        {
            temp = temp->next;
        }

        // Update pointers to remove the last node
        temp->next = start;
        last = temp;
    }
}

// Function to delete_from_tree a node from the beginning of the circular linked list
void delete_from_tree_from_beginning()
{
    if (start == NULL) // Check if the list is empty
    {
        printf("The Circular linked list is empty");
        return;
    }
    else if (start == last) // If there is only one node in the list
    {
        start = NULL; // The list becomes empty
    }
    else
    {
        struct node *temp = start;

        // Update start to point to the second node
        start = start->next;
        last->next = start; // Update the last node to point to the new start
        free(temp);         // Free the memory of the delete_from_treed node
    }
}

// Function to insert a node at a specific location in the circular linked list
void insert_at_location(int loc, int val)
{
    struct node *temp = start;

    // Check if the list is empty
    if (temp == NULL)
    {
        printf("\n\nCannot insert in an empty list\n\n");
        return;
    }

    // Traverse to the node just before the specified location
    for (int i = 1; i < loc - 1; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL) // If location is out of bounds
    {
        printf("Location is out of Circular linked list");
    }
    else
    {
        struct node *new_node = (struct node *)malloc(sizeof(struct node)); // Allocate memory for the new node
        new_node->data = val;                                               // Set the data for the new node
        new_node->next = temp->next;                                        // Link the new node to the next node
        temp->next = new_node;                                              // Update the previous node to point to the new node
    }
}

// Function to insert a node at the end of the circular linked list
void insert_at_end(int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node)); // Allocate memory for the new node
    new_node->data = data;                                              // Set the data for the new node

    if (start == NULL) // Check if the list is empty
    {
        start = new_node;   // Set the new node as the start
        last = new_node;    // Set the new node as the last node
        last->next = start; // Point the last node to the start
    }
    else
    {
        last->next = new_node; // Update the last node to point to the new node
        last = new_node;       // Set the new node as the last node
        last->next = start;    // Point the last node to the start
    }
}

// Function to insert a node at the beginning of the circular linked list
void insert_at_beginning(int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node)); // Allocate memory for the new node
    new_node->data = data;                                              // Set the data for the new node

    if (start == NULL) // Check if the list is empty
    {
        start = new_node;       // Set the new node as the start
        last = new_node;        // Set the new node as the last node
        new_node->next = start; // Point the new node to itself
    }
    else
    {
        new_node->next = start; // Point the new node to the current start
        start = new_node;       // Set the new node as the start
        last->next = new_node;  // Update the last node to point to the new start
    }
}

// Function to count the total number of nodes in the circular linked list
void count_nodes()
{
    int count = 0;
    struct node *temp = start;

    // Traverse the list to count the nodes
    do
    {
        count++;
        temp = temp->next;
    } while (temp != start);

    printf("There are total %d nodes in the Circular linked list.\n", count);
}

// Function to display the data of all nodes in the circular linked list
void display()
{
    struct node *temp = start;

    if (temp == NULL) // Check if the list is empty
    {
        printf("\nThe Circular linked list is empty\n");
    }
    else
    {
        do
        {
            printf("%d \n", temp->data); // Print the data of the current node
            temp = temp->next;           // Move to the next node
        } while (temp != start);
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

// Driver function
int main()
{
    printf("Circular linked list program : \n");
    while (1) // Infinite loop for the menu-driven program
    {
        printf("Choose an option:\n1 - Display Circular linked list\n2 - Insert at the beginning\n3 - Insert at the end\n4 - Insert at a specific location");
        printf("\n5 - delete_from_tree from the beginning\n6 - delete_from_tree from the end\n7 - delete_from_tree from a specific location\n8 - Count the number of nodes\n9 - Exit\n");
        int ch = takeinput(); // User's choice
        int loc, num;

        switch (ch)
        {
        case 1:
            display();
            break;
        case 2:
            num = takeinput();
            insert_at_beginning(num);
            break;
        case 3:
            num = takeinput();
            insert_at_end(num);
            break;
        case 4:
            loc = takeinput();
            num = takeinput();
            insert_at_location(loc, num);
            break;
        case 5:
            delete_from_tree_from_beginning();
            break;
        case 6:
            delete_from_tree_from_end();
            break;
        case 7:
            loc = takeinput();
            delete_from_tree_from_location(loc);
            break;
        case 8:
            count_nodes();
            break;
        case 9:
            printf("Program execution complete\n");
            return 0;
        }
    }
}
