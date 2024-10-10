#include <iostream>
#include <stdio.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *start;

void count_nodes()
{
    int count = 0;
    struct node *temp = start;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    printf("there are total %d nodes in the Doubly linked list.\n", count);
}

void delete_from_location(int loc)
{
    if (start == NULL)
    {
        printf("\n\nThe Doubly linked list is empty\n\n");
        return;
    }
    struct node *temp = start;
    struct node *current = NULL;

    if (loc == 1)
    {
        printf("\n\nIf you want to delete the first element, use the delete from beginning function!\n\n");
        return;
    }
    else
    {
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
            }
        }
        if (temp == NULL)
        {
            printf("\n\nThe location is out of Doubly linked list\n\n");
            return;
        }
        current->next = temp->next;
        temp->prev->next = current->next;
        free(temp);
    }
}

void delete_from_begin()
{
    if (start == NULL)
    {
        printf("\n\nCannot delete from empty Doubly linked list\n\n");
    }
    else if (start->next == NULL)
    {
        start = NULL;
    }
    else
    {
        start = start->next;
        start->prev = NULL;
    }
}

void delete_from_end()
{
    if (start == NULL)
    {
        printf("\n\nCannot delete from empty Doubly linked list\n\n");
    }
    else if (start->next == NULL)
    {
        start = NULL;
    }
    else
    {
        struct node *temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        free(temp);
    }
}

void insert_at_location(int loc, int data)
{
    struct node *temp, *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    temp = start;
    if (temp == NULL)
    {
        printf("\n\nCannot insert in empty list\n\n");
        return;
    }
    for (int i = 1; i < loc - 1; i++)
    {

        if (temp != NULL)
        {
            temp = temp->next;
        }
    }
    if (temp == NULL)
    {
        printf("location out of Doubly linked list");
    }
    else
    {
        new_node->data = data;
        new_node->prev = temp;
        temp->next->prev = new_node;
        new_node->next = temp->next;
        temp->next = new_node;
    }
}

void insert_at_beginning(int data)
{
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    if (start == NULL)
    {
        new_node->prev = NULL;
        new_node->next = NULL;
        new_node->data = data;
        start = new_node;
    }
    else if (start != NULL)
    {
        start->prev = new_node;
        new_node->next = start;
        new_node->data = data;
        start = new_node;
    }
}

void insert_at_end(int num)
{
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = NULL;
    if (start == NULL)
    {
        new_node->prev = NULL;

        start = new_node;
    }
    else
    {
        struct node *temp = start;
        while (temp->next != NULL)
        {

            temp = temp->next;
        }
        temp->next = new_node;
        new_node->prev = temp;
    }
}

void display()
{
    if (start == NULL)
    {
        printf("\n\nlinked list is empty\n\n");
    }
    else
    {
        struct node *ptr = start;
        printf("\n\n\nDisplaying linked list....\n");
        while (ptr != NULL)
        {
            printf("%d  \n", ptr->data);
            ptr = ptr->next;
        }
    }
}

int takeinput()
{
    int num;
    printf("Enter the value : ");
    scanf("%d", &num);
    return num;
}

int main()
{
    printf("Doubly linked list program : \n");
    while (1)
    {
        printf("What do you want to do? \nChoose your option \n1 - Display Doubly linked list\n2 - Insert at the beginning\n3 - Insert at the end\n4 - Insert at a specific location\n5 - Delete from the beginning\n6 - Delete from the end\n7 - Delete from a specific location\n8 - Count the number of nodes\n9 - Exit\n");
        int ch = takeinput();
        int loc, num;
        switch (ch)
        {
        case 1:
            display();
            printf("\n\n");
            break;
        case 2:
        {
            printf("\nInserting at the beginning...\n");
            num = takeinput();
            insert_at_beginning(num);
            printf("\n\n");
            break;
        }

        case 3:
        {
            printf("\nInserting at the end...\n");
            int num1 = takeinput();
            insert_at_end(num1);
            printf("\n\n");
            break;
        }
        case 4:
        {
            printf("Inserting at location...\n");
            printf("Choose the location, ");
            loc = takeinput();
            printf("Number to be inserted, ");
            num = takeinput();
            insert_at_location(loc, num);
            printf("\n\n");
            break;
        }
        case 5:
            printf("\nDeleting from the beginning...\n");
            delete_from_begin();
            printf("\n\n");
            break;
        case 6:
            printf("Deleting from the end...\n");
            delete_from_end();
            printf("\n\n");
            break;
        case 7:
        {
            printf("Deleting from the location...\n");
            printf("Choose the location, ");
            loc = takeinput();
            delete_from_location(loc);
            printf("\n\n");
            break;
        }
        case 8:
            printf("\n\n");
            count_nodes();
            printf("\n\n");
            break;
        // case 9:
        //     printf("Reversing the linked list");
        //     reverse_linked_list();
        //     display();
        //     printf("\n\n");
        //     break;
        case 9:
            printf("\n\n\nProgram execution complete\n\n\n");
            return 0;
        }
    };
    return 0;
}