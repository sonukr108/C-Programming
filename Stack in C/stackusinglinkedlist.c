#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int data;
    struct stack * next;
};
int isEmpty(struct stack * top){
    if(top == NULL)
        return 1;
    else
        return 0;
}
int isFull(struct stack * top){
    struct stack * p = (struct stack *) malloc (sizeof(struct stack));
    if(p == NULL)
        return 1;
    else
        return 0;
}
struct stack * push(struct stack * top, int val){
    if(isFull(top))
        printf("Stack is overflow\n");
    else{
        struct stack * p = (struct stack *) malloc (sizeof(struct stack));
        p->data = val;
        p->next = top;
        printf("%d Pushed successfully \n",val);
        return p;
    }
}
struct stack * pop(struct stack * top){
    if(isEmpty(top))
        printf("Stack is underflow\n");
    else{
        struct stack * n = top;
        top = top -> next;
        int x = n->data;
        printf("%d Poped successfully \n",x);
        free(n);
        return top;
    }
}
int main(){
    struct stack * head = (struct stack *) malloc (sizeof(struct stack));
    head->data = 24;
    head->next = NULL;
    head = push(head,34);
    head = pop(head);
    head = pop(head);
    head = pop(head);
    head = push(head,33);
    head = pop(head);
    head = pop(head);
    head = pop(head);
    head = pop(head);
    head = pop(head);
    return 0;
}