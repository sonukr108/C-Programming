#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int * arr;
};
int isEmpty(struct stack * ptr){
    if(ptr->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(struct stack * ptr){
    if(ptr->size == ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

int main()
{
    struct stack * s;
    s->size = 6;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    
    // Insert data in stack manually
    s->arr[0] = 4;
    s->top++;

    s->arr[1] = 7;
    s->top++;

    s->arr[2] = 12;
    s->top++;

    s->arr[3] = 11;
    s->top++;

    s->arr[4] = 13;
    s->top++;

    s->arr[5] = 8;
    s->top++;

    if(isEmpty(s)){
        printf("Stack is empty");
    }
    else{
        printf("Stack is not empty");
    }
    return 0;
}