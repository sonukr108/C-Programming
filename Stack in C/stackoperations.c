#include<stdio.h>
#include<stdlib.h>

//Stack is created
struct stack
{
    int size;
    int top;
    int *arr;
};
//This function check the stack is empty or not
int isEmpty(struct stack *ptr){
    if(ptr->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}
//This function check the stack is full or not
int isFull(struct stack *ptr){
    if(ptr->top == ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}
//This function add push the value in stack
void push(struct stack *ptr, int val){
    if(isFull(ptr)){
        printf("Stack is Overflow, Cannot pushed %d on stack\n", val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
        printf("%d pushed successfully on stack\n", val);
    }
}
//This function add pop the value from the stack
void pop(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("Stack is Underflow, Cannot poped from the stack\n");
    }
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        printf("%d poped successfully from the stack\n", val);
    }
}
int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    
    printf("Here 1 -> YES and 0 -> NO\n");
    printf("Before push, Empty : %d \n",isEmpty(sp));
    printf("Before push, Full : %d \n",isFull(sp));

    push(sp,23);
    push(sp,88);
    push(sp,78);
    push(sp,56);
    push(sp,34);
    push(sp,55);
    push(sp,45);
    push(sp,123);
    push(sp,25);
    push(sp,43);
    push(sp,213); // Overflow condition is raised

    printf("After push, Empty : %d \n",isEmpty(sp));
    printf("After push, Full : %d \n",isFull(sp));

    pop(sp);
    pop(sp);
    pop(sp);
    pop(sp);
    pop(sp);
    pop(sp);
    pop(sp);
    pop(sp);
    pop(sp);
    pop(sp);
    pop(sp);   //Underflow condition is raised

    printf("After pop, Empty : %d \n",isEmpty(sp));
    printf("After pop, Full : %d \n",isFull(sp));
    
    return 0;
}