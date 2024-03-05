#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void displayList(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node *enqueue(struct Node *f, struct Node **r, int data)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL)
    {
        printf("Queue if full \n");
    }
    else
    {
        n->data = data;
        n->next = NULL;
        if (f == NULL)
        {
            f = *r = n;
        }
        else
        {
            (*r)->next = n;
            *r = n;
        }
    }
    return f;
}

int dequeue(struct Node **f)
{
    int val = -1;
    struct Node *ptr = *f;
    if (*f == NULL)
    {
        printf("Queue is empty \n");
    }
    else
    {
        val = (*f)->data;
        *f = (*f)->next;
        free(ptr);
    }
    return val;
}

int main()
{
    struct Node *f = NULL;
    struct Node *r = NULL;
    f = enqueue(f, &r, 90);
    f = enqueue(f, &r, 143);
    f = enqueue(f, &r, 430);
    f = enqueue(f, &r, 93);

    printf("Before Dequeue \n");
    displayList(f);

    printf("Dequeuing element %d\n", dequeue(&f));
    printf("Dequeuing element %d\n", dequeue(&f));
    printf("Dequeuing element %d\n", dequeue(&f));
    printf("\nAfter Dequeue \n");
    displayList(f);

    return 0;
}