#include <stdio.h>
#include <stdlib.h>

#define size 5

struct Queue
{
    int a[size];
    int front;
    int rear;
};

void initializeQueue(struct Queue *q)
{
    q->front = -1;
    q->rear = -1;
}

void insertQueue(struct Queue *q, int d)
{
    if (q->rear == size - 1)
    {
        printf("Queue is full. Cannot insert %d.\n", d);
    }
    else
    {
        q->rear++;
        q->a[q->rear] = d;
        if (q->front == -1)
        {
            q->front = 0;
        }
        printf("Inserted %d into the queue.\n", d);
    }
}

void deleteQueue(struct Queue *q)
{
    if (q->front == -1 || q->front > q->rear)
    {

        printf("Queue is empty. No elements to delete.\n");
    }
    else
    {

        printf("Deleted %d from the queue.\n", q->a[q->front]);
        q->front++;
        if (q->front > q->rear)
        {

            q->front = q->rear = -1;
        }
    }
}

void displayQueue(struct Queue *q)
{
    if (q->front == -1)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Queue elements are: ");
        for (int i = q->front; i <= q->rear; i++)
        {
            printf("%d ", q->a[i]);
        }
        printf("\n");
    }
}

int main()
{
    struct Queue q;
    initializeQueue(&q);

    int choice, value;

    while (1)
    {
        printf("\nQueue Operations:\n");
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Display the queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1: // Insert an element
            printf("Enter the value to insert: ");
            scanf("%d", &value);
            insertQueue(&q, value);
            break;

        case 2: // Delete an element
            deleteQueue(&q);
            break;

        case 3: // Display the queue
            displayQueue(&q);
            break;

        case 4: // Exit the program
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}