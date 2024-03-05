#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(struct stack *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("Stack is Overflow\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
void pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack is Underflow\n");
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        printf("%d poped successfully from the stack\n");
    }
}
int stackTop(struct stack *ptr)
{
    return ptr->arr[ptr->top];
}
int stackBottom(struct stack *ptr)
{
    return ptr->arr[0];
}
int main()
{
    struct stack *sp; //= (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));

    push(sp, 23);
    push(sp, 65);
    push(sp, 89);
    push(sp, 67);
    push(sp, 26);
    push(sp, 24);
    push(sp, 13);
    push(sp, 12);
    push(sp, 43);
    push(sp, 32);
    // push(sp,42); // stack Overflow

    printf("The top most value of the stack : %d\n", stackTop(sp));
    printf("The bottom most value of the stack : %d\n", stackBottom(sp));

    return 0;
}