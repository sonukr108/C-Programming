#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
void displayList(struct Node *head){
    struct Node *ptr = head;
    do{
        printf("Element : %d \n", ptr->data);
        ptr= ptr->next;
    }while(ptr != head);
}

int main(){
    struct Node *head,*second,*third,*fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    
    head->data = 4;
    head->next = second;

    second->data = 10;
    second->next = third;

    third->data = 12;
    third->next = fourth;

    fourth->data = 15;
    fourth->next = head;

    printf("Before insertion \n");
    displayList(head);
    // head = insertAtFirst(head,56);
    // head = insertAtIndex(head,50,4);
    // head = insertAtLast(head,56);
    // printf("After insertion \n");
    // displayList(head);

    return 0;
}