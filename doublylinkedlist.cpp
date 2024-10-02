#include <iostream>
#include <stdio.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

void delete_from_begin(struct node *start)
{
    start = start->next;
    start->prev = NULL;
}

void delete_from_end(struct node *start)
{
    struct node *temp = start;
    while (temp != NULL)
    {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
}

void insert_at_loc(struct node *start, int loc, int data)
{
    struct node *temp, *new_node;
    temp = start;
    for (int i = 0; i < loc; i++)
    {
        if (temp == NULL)
        {
            return;
        }
        temp = temp->next;
    }
    new_node->data = data;
    new_node->prev = temp;
    temp->next->prev = new_node;
    new_node->next = temp->next;
    temp->next = new_node;
}

void insert_at_begin(struct node *start, int data)
{
    struct node *new_node;
    if (start == NULL)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->prev = NULL;
        new_node->next = NULL;
        new_node->data = data;
        start = new_node;
    }
    else if (start != NULL)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        start->prev = new_node;
        new_node->next = start;
        new_node->data = data;
        start = new_node;
    }
}

void insert_at_end(struct node *start, int num)
{
    struct node *new_node;
    if (start == NULL)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->prev = NULL;
        new_node->next = NULL;
        start = new_node;
    }
    else if (start != NULL)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = num;
        struct node *temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->prev = temp;
    }
}

void display(struct node *start)
{
    struct node *temp = start;
    if (temp == NULL)
    {
        printf("empty doublylinked list");
    }
    while (temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->next;
        printf("hello from print\n");
    }
}

int main()
{
    struct node *start = NULL;
    insert_at_end(start, 20);
    insert_at_begin(start, 21);
    insert_at_end(start, 28);
    insert_at_loc(start, 1, 13);
    display(start);
    return 0;
}