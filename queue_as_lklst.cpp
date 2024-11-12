#include <iostream>
#include <stdio.h>
struct queue
{
    int data;
    struct queue *next;
    struct queue *front;
    struct queue *rear;
};

struct queue *insert(struct queue *q, int data)
{
    struct queue *p = (struct queue *)malloc(sizeof(struct queue));
    p->data = data;
    p->next = NULL;
    if (q->front == NULL)
    {
        q->front = p;
    }
    else if (q->rear != NULL)
    {
        q->rear->next = p;
    }
    q->rear = p;
    return q;
}

struct queue *delete_from_queue(struct queue *q)
{
    struct queue *temp = q->front;
    q->front = q->front->next;
    free(temp);
    printf("\n\ndeleting from queue\n\n");
    return q;
}

void display(struct queue *q)
{
    if (q->front == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        struct queue *ptr = q->front;
        printf("\n\n\nDisplaying queue....\n");
        while (ptr != NULL)
        {
            printf("%d  \n", ptr->data);
            ptr = ptr->next;
        }
    }
}

void count_queues(struct queue *q)
{
    int count = 0;
    struct queue *temp = q->front;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    printf("there are total %d nodes in the Queue.\n", count);
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
    printf("Queue program : \n");
    struct queue q;
    q.front = NULL;
    q.rear = NULL;
    while (1)
    {
        printf("What do you want to do? \nChoose your option \n1 - Display Queue\n2 - Insert in Queue\n3 - Delete from Queue\n4 - Count the number of queues\n5 - Exit\n");
        int ch = takeinput();
        int loc, num;
        switch (ch)
        {
        case 1:
            display(&q);
            printf("\n\n");
            break;
        case 2:
        {
            printf("\n\n");
            .l̥
                printf("Inserting in Queue...\n");
            int num1 = takeinput();
            insert(&q, num1);
            printf("\n\n");
            break;
        }
        case 4:
            printf("\n\n");
            count_queues(&q);
            printf("\n\n");
            break;
        case 3:
            printf("Deleting from Queue...\n");
            delete_from_queue(&q);
            printf("\n\n");
            break;

        case 5:
            printf("\n\n\nProgram execution complete\n\n\n");
            return 0;
        }
    };
    return 0;
}