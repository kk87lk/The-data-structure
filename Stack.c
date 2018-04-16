#include <stdio.h>
#include <stdlib.h>
#define ElemType int 
struct stack{
    ElemType Data;
    struct stack *next;
};
typedef struct stack PtrtoNode;
typedef PtrtoNode* Stack;
int main(){
    Stack s;
    int x,n,pNum;
    Stack CreatStack();
    int isempty(Stack s);
    void push(Stack s,ElemType x);
    void printStack(Stack s);
    int pop(Stack s);
    do{
        printf("1-Creat a Stack\n");
        printf("2-Push an Element\n");
        printf("3-Pop an Element\n");
        printf("0-Exit\n");
        printf("Please select an option:");
        scanf("%d",&x);
        switch(x){
            case 1: 
            s=CreatStack(); 
            break;

            case 2:
            printf("please input the element you want to push:");
            scanf("%d",&n);
            push(s,n);
            printStack(s);
            break;

            case 3:
            pNum=pop(s);
            printf("%d\n",pNum);
            printStack(s);
            break;
            
        }
    }while(x);
    if (!x){
        printf("Thanks to use\n");
        exit(1);
    }

}
Stack CreatStack(){
    Stack s;
    s=(Stack)malloc(sizeof(PtrtoNode));
    s->next=NULL;
    return s;
}
int isempty(Stack s){
    if(s->next==NULL)
        return 1;
    else return 0;
}

void push(Stack s,ElemType x){
    PtrtoNode *TemCell;
    TemCell=(PtrtoNode*)malloc(sizeof(PtrtoNode));
    TemCell->Data=x;
    TemCell->next=s->next;
    s->next=TemCell;
}
int pop(Stack s){
    PtrtoNode* FirstCell;
    ElemType TopElem;
    if(isempty(s))
       {  printf("The Stack is empty!\n");
        exit(1);}
        else{
        FirstCell = s->next; 
        TopElem = FirstCell->Data;
        s->next = FirstCell->next;
        free(FirstCell);
        return TopElem;
        }
}
void printStack(Stack s){
    PtrtoNode* p;
    p=s->next;
    while(p){
        printf("%d\n",p->Data);
        p=p->next;
    }
}