#include <iostream>
#include <stdio.h>
int size = 10;
struct queue
{
    int a[10];
    int front;
    int rear;
};

void insert(struct queue *q, int data)
{
    if (q->rear == size - 1)
    {
        printf("full");
    }
    else
    {
        q->rear++;
        q->a[q->rear] = data;
        if (q->front == -1)
        {
            q->front = 0;
        }
    }
}

void display(struct queue *q)
{
    for (int i = 0; i <= q->rear; i++)
    {
        printf("d%", q->a[q->front]);
    }
}

int main()
{
    struct queue myq;
    myq.rear = -1;
    myq.front = -1;
}
