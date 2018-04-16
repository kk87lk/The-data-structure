#include <stdio.h>
#include <stdlib.h>
#define Maxsize 1024
typedef int elemtype;
typedef struct SequenQueue
{
    elemtype data[Maxsize];
    int front;
    int rear;
}SequenQueue;
SequenQueue * Init()
{   
    SequenQueue *Q;
    Q=(SequenQueue*)malloc(sizeof(SequenQueue));
    if(Q!=NULL){
        Q->front=0;
        Q->rear=0;
    }
    return Q;
}
int isempty(SequenQueue *Q){
    if(Q->front==Q->rear)
        return 1;
    else 
        return 0;
}
int isfull(SequenQueue *Q){
    if((Q->rear+1)%Maxsize==Q->front)
        return 1;
    else
        return 0;
}
int length(SequenQueue *Q){
    return ((Q->rear-Q->front+Maxsize)%Maxsize);
}
void Insert(SequenQueue *Q,elemtype x){
    if(isfull(Q)){
        printf("The Queun is Full!\n");
        exit(1);
    }
    Q->data[Q->rear]=x;
    Q->rear=(Q->rear+1)%Maxsize;
}
void Delete(SequenQueue *Q){
    if(Q->front==Q->rear){
        printf("The Queue is empty!\n");
        exit(1);
    }else {
        Q->front=(Q->front+1)%Maxsize;
    }
}
void print(SequenQueue *Q){
    int i=0;
    for(i=Q->front;i<Q->rear;i++){
        printf("%d ",Q->data[i]);
    }
}
int main(){
    SequenQueue *Q;
    Q=Init();
    int i=0;
    for(i=0;i<6;i++){
        Insert(Q,i);
    }
    print(Q);
    Delete(Q);
    printf("\n");
    print(Q);
}