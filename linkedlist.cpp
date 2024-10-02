#include <iostream>
#include <stdio.h>
struct node
{
    int data;
    struct node *next;
};

void insertatend(struct node *start, int data)
{
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    // printf("enter value for data : ");
    // scanf("%d", &new_node->data);
    new_node->data = data;
    new_node->next = NULL;
    if (start == NULL)
    {
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
    }
}

void display(struct node *start)
{
    if (start == NULL)
    {
        printf("linked list is empty\n");
    }
    struct node *ptr = start;
    while (ptr != NULL)
    {
        printf("%d  \n", ptr->data);
        ptr = ptr->next;
    }
}

void delete_from_end(struct node *start)
{
    if (start == NULL)
    {
        printf("empty list");
    }
    else if (start->next == NULL)
    {
        start = NULL;
        free(start);
    }
    else
    {
        struct node *temp = start;
        struct node *prev = start;
        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
    }
}

void delete_from_location(struct node *start, int loc)
{
    if (start == NULL)
    {
        printf("empty list\n");
    }
    else
    {
        struct node *temp = start;
        struct node *current = start;
        for (int i = 1; i < loc - 1; i++)
        {
            current = temp;
            temp = temp->next;
        }
        current->next = temp->next;
        free(temp);
    }
}

void delete_from_beginning(struct node *start)
{
    if (start == NULL)
    {
        printf("list is empty");
    }
    else if (start->next == NULL)
    {
        struct node *temp = start;
        start = NULL;
        free(temp);
    }
    else
    {
        struct node *temp = start;
        start = start->next;
        free(temp);
    }
}

void insert_at_beginning(struct node *start, int data)
{
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    if (start == NULL)
    {
        new_node->next = NULL;
    }
    else
    {
        new_node->next = start;
    }
    start = new_node;
}

void insert_at_location(struct node *start, int loc, int val)
{
    struct node *temp = start;
    for (int i = 1; i < loc - 1; i++)
    {
        if (temp == NULL)
        {
            printf("temp is null");
        }
        else
        {
            temp = temp->next;
        }
    }
    if (temp == NULL)
    {
        printf("location out of linked list");
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

void count_nodes(struct node *start)
{
    int count = 0;
    struct node *temp = start;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    printf("there are total %d nodes in the linked list.\n", count);
}

void reverse_linked_list(struct node *start)
{
    struct node *q, *r, *s;
    q = start;
    s = NULL;
    while (q->next != NULL)
    {

        r = q->next;
        q->next = s;
        s = q;
        q = r;
    }
    start = q;
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
    struct node *start = NULL;
    start = (struct node *)malloc(sizeof(struct node));

    start->data = 45;
    start->next = NULL;

    while (1)
    {
        printf("What do you want to do? \nChoose your option \n1 - Display linked list\n2 - Insert at the beginning\n3 - Insert at the end\n4 - Insert at a specific location\n5 - Delete from the beginning\n6 - Delete from the end\n7 - Delete from a specific location\n8 - Count the number of nodes\n9 - Reverse the linked list\n10 - Exit\n");
        int ch = takeinput();
        int loc, num;
        switch (ch)
        {
        case 1:
            display(start);
            printf("\n\n");
            break;
        case 2:
        {
            printf("Inserting at the beginning...\n");
            num = takeinput();
            insert_at_beginning(start, num);
            printf("\n\n");
            break;
        }

        case 3:
        {
            printf("Inserting at the end...\n");
            int num1 = takeinput();
            insertatend(start, num1);
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
            insert_at_location(start, loc, num);
            printf("\n\n");
            break;
        }
        case 5:
            printf("Deleting from the beginning...\n");
            delete_from_beginning(start);
            printf("\n\n");
            break;
        case 6:
            printf("Deleting from the end...\n");
            delete_from_end(start);
            printf("\n\n");
            break;
        case 7:
        {
            printf("Deleting from the location...\n");
            printf("Choose the location, ");
            loc = takeinput();
            delete_from_location(start, loc);
            printf("\n\n");
            break;
        }
        case 8:
            count_nodes(start);
            printf("\n\n");
            break;
        case 9:
            printf("Reversing the linked list");
            reverse_linked_list(start);
            display(start);
            printf("\n\n");
            break;
        case 10:
            printf("\n\n\nProgram execution complete\n\n\n");
            return 0;
        }
    };

    // insertatend(start, 20);
    // insertatend(start, 21);
    // insertatend(start, 28);
    // insert_at_location(start, 2, 9);
    // reverse_linked_list(start);

    // // delete_at_end(start);
    // // delete_at_location(start, 3);

    // // not working
    // //  insert_at_beginning(start, 8);
    // //  delete_at_beginning(start);

    // display(start);
    // count_nodes(start);

    return 0;
}