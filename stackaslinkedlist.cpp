#include <iostream>
#include <stdio.h>
struct node
{
    int data;
    struct node *next;
};

struct node *top;

void push(int data)
{
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = top;
    top = new_node;
}

void pop()
{
    if (top == NULL)
    {
        printf("\n\nThe linked list is empty\n\n");
        return;
    }
    else if (top->next == NULL)
    {
        top = NULL;
    }
    else
    {
        struct node *temp = top;
        top = (top)->next; // Move top to the next node
        free(temp);        // Free the old top node
    }
}

void display()
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        struct node *ptr = top;
        printf("\n\n\nDisplaying the Stack....\n");
        while (ptr != NULL)
        {
            printf("%d  \n", ptr->data);
            ptr = ptr->next;
        }
    }
}

void count_nodes()
{
    int count = 0;
    struct node *temp = top;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    printf("there are total %d nodes in the Stack.\n", count);
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
    printf("Stack program : \n");
    while (1)
    {
        printf("What do you want to do? \nChoose your option \n1 - Display the stack\n2 - Push to the stack\n3 - Pop from the stack\n4 - Count the nodes in Stack\n5 - Exit\n");
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
            printf("Push to the stack...\n");
            num = takeinput();
            push(num);
            printf("\n\n");
            break;
        }

        case 3:
        {
            printf("Popped the top element from the stack...\n");
            pop();
            printf("\n\n");
            break;
        }
        case 4:
            count_nodes();
            printf("\n\n");
            break;
        case 5:
            printf("\n\n\nProgram execution complete\n\n\n");
            return 0;
        }
    };
    return 0;
}