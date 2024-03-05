#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node * next;
};
void displayList(struct Node * ptr){
    while (ptr != NULL)
    {
        printf("Element : %d\n",ptr->data);
        ptr = ptr->next;
    }
    
}
void insertAfterNode(struct Node * prevNode,int data){
    struct Node * ptr = (struct Node * )malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;
}
int main()
{
    struct Node * head = (struct Node *)malloc(sizeof(struct Node ));
    struct Node * second = (struct Node *)malloc(sizeof(struct Node ));
    struct Node * third = (struct Node *)malloc(sizeof(struct Node ));
    struct Node * fourth = (struct Node *)malloc(sizeof(struct Node ));

    head->data = 23;
    head->next = second;

    second->data = 53;
    second->next = third;

    third->data = 22;
    third->next = fourth;

    fourth->data = 76;
    fourth->next = NULL;

    printf("Before insertion\n");
    displayList(head);
    insertAfterNode(second,34);
    printf("After insertion\n");
    displayList(head);
    return 0;

}