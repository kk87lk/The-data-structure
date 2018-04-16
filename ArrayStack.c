#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
struct sNode{
    ElemType *Data;
    int Top;
    int Maxsize;
};
typedef struct sNode* Stack;
Stack create(int Maxsize){
    Stack S=(Stack)malloc(sizeof(struct sNode));
    S->Data=(ElemType*)malloc(sizeof(ElemType)*Maxsize);
    S->Top=-1;
    S->Maxsize=Maxsize;
    return S;
}
int isfull(Stack S){
    if(S->Top==S->Maxsize-1)
        return 1;
    else return 0;
}
int isempty(Stack S){
    if(S->Top==-1)
        return 1;
    else return 0;
}
void Push(Stack S,ElemType x){
    if(isfull(S)){
        printf("The Stack is full!\n");
        exit (1);
    }else{
        S->Data[++(S->Top)]=x;
    }
}
ElemType Pop(Stack S){
    if(isempty(S)){
        printf("The Stack is empty!\n");
        exit (1);
    }else {
        return S->Data[(S->Top)--];
    }
}
void print(Stack S){
    if(isempty(S)){
        printf("The Stack is empty!\n");
        exit (1);
    }
    int i=0;
    for(i=S->Top;i>=0;i--){
        printf("%d\n",S->Data[i]);
    }
}
int main(){
    int x,Maxsize,pushnum,popnum;
    Stack S;
    do{
        printf("1-Creat a Stack\n");
        printf("2-Push an Element\n");
        printf("3-Pop an Element\n");
        printf("0-exit\n");
        printf("Please select an option:");
        scanf("%d",&x);
        switch(x){
            case 1:
            printf("Please input the Maxsize of the Stack:");
            scanf("%d",&Maxsize);
            S=create(Maxsize);
            break;
            
            case 2:
            printf("Please input the Element you want to push:");
            scanf("%d",&pushnum);
            Push(S,pushnum);
            print(S);
            break;

            case 3:
            popnum=Pop(S);
            printf("The poped element is:%d\n",popnum);
            if(isempty(S)){
                printf("The Stack is empty!\n");
                exit(1);
            }else{
                printf("The rest Stack is:\n");
                print(S);
            }
            break;

        }
    } while (x);
    if(!x){
        printf("Thanks to use!\n");
        exit(1);
    }
}