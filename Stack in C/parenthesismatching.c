#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int size;
    int top;
    char * arr;
};
int isEmpty(struct stack *ptr){
    if(ptr->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}
void push(struct stack *ptr, char c){
    ptr->top++;
    ptr->arr[ptr->top] = c;
}
void pop(struct stack *ptr){
    ptr->top--;
}
void parenthesisCheck(char exp[],int length){
    struct stack *sp;
    sp->size = length;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size*sizeof(char));
    for(int j=0 ; j<length ; j++){
        if(exp[j] == '(')
        {
            push(sp,exp[j]);
        }
        else if(exp[j] == ')'){
            if(isEmpty(sp)){
                push(sp,exp[j]);
            }
            else{
                pop(sp);
            }
        }
    }
    if(isEmpty(sp)){
        printf("\nParenthes is mached");
    }
    else{
        printf("\nParenthes is not mached");
    } 
}
int main(){
    char exp[] = {"(A(+B)*(B*C)()"}; 
    int length = sizeof(exp)/sizeof(char);
    printf("Length of expression is : %d\n",length);
    printf("%s\n",exp);
    parenthesisCheck(exp,length);

    return 0;
}