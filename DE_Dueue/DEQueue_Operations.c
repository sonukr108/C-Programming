#include <stdio.h>
#include <stdlib.h>

struct DEQueue
{
    int size;
    int f;
    int r;
    int *arr;
};

void displayDEQueue(struct DEQueue *dq)
{
    int temp = dq->f;
    while (temp <= dq->r)
    {
        printf("%d, ", dq->arr[temp]);
        temp++;
    }
    printf("\n");
}

void enqueueF(struct DEQueue *dq, int val)
{
    if (dq->f < 0)
    {
        printf("DEQueue is Full from Front side\n");
    }
    else
    {
        dq->f--;
        dq->arr[dq->f] = val;
        printf("%d Insertion successfully on DEQueue from front end\n", val);
    }
}

void enqueueR(struct DEQueue *dq, int val)
{
    if (dq->r == dq->size - 1)
    {
        printf("DEQueue is Full from Rear side\n");
    }
    else
    {
        if (dq->f == -1)
        {
            dq->f++;
        }
        dq->r++;
        dq->arr[dq->r] = val;
        printf("%d Insertion successfully on DEQueue from rear end\n", val);
    }
}

void dqueueF(struct DEQueue *dq)
{
    if (dq->f == dq->r)
    {
        printf("DEQueue is empty from front side\n");
    }
    else
    {
        printf("%d Deletion successfully on DEQueue from front end\n", dq->arr[dq->f]);
        dq->f++;
    }
}

void dqueueR(struct DEQueue *dq)
{
    if (dq->r == dq->f)
    {
        printf("DEQueue is empty from rear side");
    }
    else
    {
        printf("%d Deletion successfully on DEQueue from rear end\n", dq->arr[dq->r]);
        dq->r--;
    }
}

int main()
{
    struct DEQueue *dq = (struct DEQueue *)malloc(sizeof(struct DEQueue));
    dq->size = 5;
    dq->f = dq->r = -1;
    dq->arr = (int *)malloc(dq->size * sizeof(int));

    enqueueF(dq, 10);
    enqueueR(dq, 10);
    enqueueR(dq, 11);
    enqueueR(dq, 12);
    enqueueR(dq, 13);
    enqueueR(dq, 14);
    enqueueR(dq, 15);
    displayDEQueue(dq);
    dqueueF(dq);
    enqueueF(dq, 18);
    displayDEQueue(dq);

    free(dq->arr);
    free(dq);

    return 0;
}
