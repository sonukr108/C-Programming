#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

void displayList(struct Node *ptr)
{
    do
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != NULL);
}

int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));

    // Inserting data on nodes
    head->prev = NULL;
    head->data = 41;
    head->next = second;

    second->prev = head;
    second->data = 85;
    second->next = third;

    third->prev = second;
    third->data = 45;
    third->next = fourth;

    fourth->prev = third;
    fourth->data = 65;
    fourth->next = NULL;

    displayList(head);

    return 0;
}