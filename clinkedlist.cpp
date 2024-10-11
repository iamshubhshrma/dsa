#include <iostream>
#include <stdio.h>
struct node
{
    int data;
    struct node *next;
};

struct node *start, *last;

void delete_from_location(int loc)
{
    if (start == NULL)
    {
        printf("\n\nThe Circular linked list is empty\n\n");
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
            printf("\n\nThe location is out of Circular linked list\n\n");
            return;
        }
        current->next = temp->next;
        free(temp);
    }
}

void delete_from_end()
{
    if (start == NULL)
    {
        printf("empty circlular linked list");
    }
    else if (start == last)
    {
        // start->next == NULL;
        // free(start);
        start = NULL;
    }
    else
    {
        struct node *temp = start;
        while (temp->next != last)
        {
            temp = temp->next;
        }
        temp->next = start;
        last = temp;
    }
}

void delete_from_beginning()
{
    if (start == NULL)
    {
        printf("empty circlular linked list");
    }
    else if (start == last)
    {
        // start->next == NULL;
        // free(start);
        start = NULL;
    }
    else
    {
        struct node *temp = start;
        start = start->next;
        last->next = start;
        free(temp);
    }
}

void insert_at_location(int loc, int val)
{
    struct node *temp = start;
    if (temp == NULL)
    {
        printf("\n\nCannot insert in empty list\n\n");
        return;
    }

    for (int i = 1; i < loc - 1; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("location out of Circular linked list");
    }
    else
    {
        struct node *new_node;
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = val;
        new_node->next = temp->next;
        temp->next = new_node;
    }
}

void insert_at_end(int data)
{
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    if (start == NULL)
    {
        start = new_node;
        last = new_node;
        last->next = start;
    }
    else
    {
        last->next = new_node;
        last = new_node;
        last->next = start;
    }
}

void insert_at_beginning(int data)
{
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    if (start == NULL)
    {
        start = new_node;
        last = new_node;
        new_node->next = start;
    }
    else
    {
        new_node->next = start;
        start = new_node;
        last->next = new_node;
    }
}

void count_nodes()
{
    int count = 0;
    struct node *temp = start;
    do
    {
        count++;
        temp = temp->next;
    } while (temp != start);
    printf("there are total %d nodes in the Circular linked list.\n", count);
}

void display()
{
    struct node *temp = start;
    if (temp == NULL)
    {
        printf("\nempty circular linked list\n");
    }
    else
    {
        do
        {
            printf("%d \n", temp->data);
            temp = temp->next;
        } while (temp != start);
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
    // Write C++ code here
    printf("linked list program : \n");
    while (1)
    {
        printf("What do you want to do? \nChoose your option \n1 - Display Circular linked list\n2 - Insert at the beginning\n3 - Insert at the end\n4 - Insert at a specific location\n5 - Delete from the beginning\n6 - Delete from the end\n7 - Delete from a specific location\n8 - Count the number of nodes\n9 - Exit\n");
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
            printf("Inserting at the beginning...\n");
            num = takeinput();
            insert_at_beginning(num);
            printf("\n\n");
            break;
        }

        case 3:
        {
            printf("Inserting at the end...\n");
            num = takeinput();
            insert_at_end(num);
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
            printf("Deleting from the beginning...\n");
            delete_from_beginning();
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
            count_nodes();
            printf("\n\n");
            break;
        // case 9:
        //     printf("Reversing the linked list");
        //     reverse_linked_list(&start);
        //     display(start);
        //     printf("\n\n");
        //     break;
        case 9:
            printf("\n\n\nProgram execution complete\n\n\n");
            return 0;
        }
    }
}
