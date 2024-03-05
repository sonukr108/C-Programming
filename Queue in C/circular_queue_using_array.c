#include <stdio.h>
#include <stdlib.h>

struct CircularQueue
{
    int size;
    int f;
    int r;
    int *arr;
};

void enqueue(struct CircularQueue *q, int val)
{
    if ((q->r + 1) % q->size == q->f)
    {
        printf("Queue is full\n");
    }
    else
    {
        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = val;
        printf("%d Insert successfully\n", val);
    }
}

void dequeue(struct CircularQueue *q)
{
    int a;
    if (q->r == q->f)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        q->f = (q->f + 1) % q->size;
        a = q->arr[q->f];
        printf("%d Delete successfully\n", a);
    }
}

int main()
{
    struct CircularQueue q;
    q.size = 10;
    q.f = q.r =0;
    q.arr = (int *)malloc (q.size*sizeof(int));

    enqueue(&q,12);
    enqueue(&q,14);
    enqueue(&q,15);
    enqueue(&q,1345);
    enqueue(&q,13);
    enqueue(&q,78);

    dequeue(&q);
    dequeue(&q);
    dequeue(&q);

    return 0;

}