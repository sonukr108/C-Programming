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
struct Node * deleteAtFirst(struct Node * head){
    struct Node *p = head;
    head = head->next;
    head->prev = NULL;
    free(p);
    return head;
}
struct Node * deleteAtIndex(struct Node * head, int index){
    struct Node * p = head;
    struct Node * q = head->next;
    struct Node * m;
    for(int i=0;i<index-1;i++){
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    m = q->next;
    m->prev = p;
    free(q);
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

    printf("Before deletion \n");
    displayList(head);
    // head = deleteAtFirst(head);
    head = deleteAtIndex(head,2);
    printf("After deletion \n");
    displayList(head);

    return 0;
}