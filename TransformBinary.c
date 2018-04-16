#include <stdio.h>
#include <stdlib.h>
typedef int elemtype;
#define Maxsize 1024
typedef struct stack{
    elemtype Data[Maxsize];
    int top;
}Stack;
Stack *CreatStack(){
    Stack* stack;
    stack=(Stack*)malloc(sizeof(Stack));
    stack->top=-1;
    return stack;
}
void Push(Stack* stack,elemtype x){
    stack->Data[++(stack->top)]=x;
}
elemtype Pop(Stack* stack){
    return stack->Data[(stack->top)--];
}
int main(){
    int n;
    Stack*stack;
    printf("Please input the number:");
    scanf("%d",&n);
    stack=CreatStack();
    while (n)
    {
        Push(stack,n%2);
        n/=2;
    }
    while ((stack->top)!=-1)
    {
        printf("%d",Pop(stack));
    }
    return 0;
}