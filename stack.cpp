#include <iostream>
#include <stdio.h>
int size = 10;
struct stack
{
    int a[10];
    int top;
};

void pop(struct stack *s)
{
    if (s->top == -1)
    {
        printf("Stack is empty, nothing to pop!\n");
    }
    else
    {
        printf("Popped element: %d\n", s->a[s->top]);
        s->top--;
    }
}

void display(struct stack *s)
{
    if (s->top == -1)
    {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements:\n");
    for (int i = s->top; i >= 0; i--)
    {
        printf("%d \n", s->a[i]);
    }
}

void push(struct stack *s, int data)
{
    if (s->top == size - 1)
    {
        printf("full");
    }
    else
    {
        s->top++;
        s->a[s->top] = data;
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
    struct stack sv;
    sv.top = -1;
    while (1)
    {
        printf("What do you want to do? \nChoose your option \n1 - Display the stack\n2 - Push to the stack\n3 - Pop the top element\n4 - Exit\n");
        int ch = takeinput();
        int loc, num;
        switch (ch)
        {
        case 1:
            display(&sv);
            printf("\n\n");
            break;
        case 2:
        {
            printf("Pushing to the stack...\n");
            num = takeinput();
            push(&sv, num);
            printf("\n\n");
            break;
        }

        case 3:
        {
            printf("Popping the top element...\n");
            pop(&sv);
            printf("\n\n");
            break;
        }
        // case 4:
        // {
        //     printf("Inserting at location...\n");
        //     printf("Choose the location, ");
        //     loc = takeinput();
        //     printf("Number to be inserted, ");
        //     num = takeinput();
        //     insert_at_location(start, loc, num);
        //     printf("\n\n");
        //     break;
        // }
        // case 5:
        //     printf("Deleting from the beginning...\n");
        //     delete_from_beginning(&start);
        //     printf("\n\n");
        //     break;
        // case 6:
        //     printf("Deleting from the end...\n");
        //     delete_from_end(start);
        //     printf("\n\n");
        //     break;
        // case 7:
        // {
        //     printf("Deleting from the location...\n");
        //     printf("Choose the location, ");
        //     loc = takeinput();
        //     delete_from_location(start, loc);
        //     printf("\n\n");
        //     break;
        // }
        // case 8:
        //     count_nodes(start);
        //     printf("\n\n");
        //     break;
        // case 9:
        //     printf("Reversing the linked list");
        //     reverse_linked_list(&start);
        //     display(start);
        //     printf("\n\n");
        //     break;
        case 4:
            printf("\n\n\nProgram execution complete\n\n\n");
            return 0;
        }
    };
    push(&sv, 20);
}