#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};
void displayList(struct Node *ptr){
    while(ptr!= NULL){
        printf("Element : %d \n", ptr->data);
        ptr= ptr->next;
    }
}
// Insertion at head of the douobly linked list
struct Node * insertAtFirst(struct Node *head,int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->prev = NULL;
    ptr->next = head;
    head->prev = ptr;
    return ptr;

}
// Insertion at given index of the douobly linked list
struct Node * insertAtIndex(struct Node *head,int data,int index)
{
    struct Node *p = head;
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    for(int i=0;i<index-1;i++){
        p = p->next;
    }    
    ptr->prev = p;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}
// Insertion at last of the douobly linked list
struct Node * insertAtLast(struct Node * head,int data){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node * p = head;
    while(p->next != NULL){
        p = p->next;
    }
    p->next = ptr;
    ptr->prev = p;
    ptr->data = data;
    ptr->next = NULL;
    return head;
}
int main(){
    struct Node *head,*second,*third,*fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->prev = NULL;
    head->data = 4;
    head->next = second;

    second->prev = head;
    second->data = 10;
    second->next = third;

    third->prev = second;
    third->data = 12;
    third->next = fourth;

    fourth->prev = third;
    fourth->data = 15;
    fourth->next = NULL;

    printf("Before insertion \n");
    displayList(head);
    // head = insertAtFirst(head,56);
    // head = insertAtIndex(head,50,4);
    head = insertAtLast(head,56);
    printf("After insertion \n");
    displayList(head);

    return 0;
}