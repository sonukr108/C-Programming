#include<stdio.h>
#include<stdlib.h>

struct Node
{
    char data;
    struct Node * next;
};
int main(){
    char a[] = {"Hello world"};
    printf("%c",a);
    return 0;
}
