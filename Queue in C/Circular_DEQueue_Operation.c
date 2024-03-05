#include <stdio.h>
#include <stdlib.h>

struct CDEQueue
{
    int size;
    int f;
    int r;
    int *arr;
};

void displayCDEQueue(struct CDEQueue *cdq)
{
    int temp = cdq->f;
    do
    {
        printf("%d, ", cdq->arr[temp]);
        temp = (temp + 1) % cdq->size;
    } while (temp != (cdq->r + 1) % cdq->size);

    printf("\n");
}

void enqueueF(struct CDEQueue *cdq, int val)
{
    if ((cdq->f - 1 + cdq->size) % cdq->size == cdq->r)
    {
        printf("Queue is Full\n");
    }
    else
    {
        cdq->f = (cdq->f - 1 + cdq->size) % cdq->size;
        cdq->arr[cdq->f] = val;
        printf("%d Insertion successfully from front end\n", val);
    }
}

void enqueueR(struct CDEQueue *cdq, int val)
{
    if ((cdq->r + 1) % cdq->size == cdq->f)
    {
        printf("Queue is Full\n");
    }
    else
    {
        if (cdq->f == 0)
        {
            cdq->f++;
        }
        cdq->r = (cdq->r + 1) % cdq->size;
        cdq->arr[cdq->r] = val;
        printf("%d Insertion successfully from rear end\n", val);
    }
}

void dqueueF(struct CDEQueue *cdq)
{
    int val = cdq->arr[cdq->f];
    if (cdq->f == cdq->r)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("%d Deleted successfully from front end\n", val);
        cdq->f = (cdq->f + 1) % cdq->size;
    }
}

void dqueueR(struct CDEQueue *cdq)
{
    int val = cdq->arr[cdq->r];
    if (cdq->f == cdq->r)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("%d Deleted successfully from rear end\n", val);
        cdq->r = (cdq->r - 1 + cdq->size) % cdq->size;
    }
}

int main()
{
    struct CDEQueue *cdq = (struct CDEQueue *)malloc(sizeof(struct CDEQueue));
    cdq->size = 5;
    cdq->f = cdq->r = 0;
    cdq->arr = (int *)malloc(cdq->size * sizeof(int));

    // displayCDEQueue(cdq);
    enqueueR(cdq, 67);
    enqueueR(cdq, 37);
    enqueueF(cdq, 66);
    enqueueR(cdq, 632);
    enqueueR(cdq, 12);
    enqueueR(cdq, 643);
    enqueueR(cdq, 68);

    displayCDEQueue(cdq);

    dqueueF(cdq);
    dqueueR(cdq);
    dqueueF(cdq);

    displayCDEQueue(cdq);

    free(cdq->arr);
    free(cdq);
    return 0;
}