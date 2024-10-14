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
    }
}

int main()
{
    struct queue *myq = (struct queue *)malloc(sizeof(struct queue));
    myq->rear = -1;
    myq->front = -1;
}
