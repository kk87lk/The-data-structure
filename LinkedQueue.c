#include <stdio.h>
#include <stdlib.h>
typedef int elemtype;
typedef struct QueueNode{
    elemtype data;
    struct QueueNode *next;
}LinkedQueueNode;
typedef struct QNode {
    LinkedQueueNode* front;
    LinkedQueueNode* rear;           
}LQueue;
LQueue* Init(){
    LQueue *Q=(LQueue*)malloc(sizeof(LQueue));
    LinkedQueueNode *head=(LinkedQueueNode*)malloc(sizeof(LinkedQueueNode));
    if(head!=NULL && Q!=NULL){
        head->next=NULL;
        Q->front=head;
        Q->rear=head;
    }
    return Q;
}
int isempty(LQueue *Q){
    if(Q->front == Q->rear)
        return 1;
    else
        return 0;
}
void Insert(LQueue *Q,elemtype x){
    LinkedQueueNode *node;
    node=(LinkedQueueNode*)malloc(sizeof(LinkedQueueNode));
    if(node==NULL){
        printf("Insert error!\n");
        exit(1);
    }
    node->data=x;
    node->next=NULL;
    Q->rear->next=node;
    Q->rear=node;
}
void Delete(LQueue *Q){
    LinkedQueueNode *node;
    if(Q->front==Q->rear){
        printf("The Queue is empty!\n");
        exit(1);
    }else{
        node=Q->front->next;
        if(node==Q->rear){
            Q->rear=Q->front;
        }else{
            Q->front->next=node->next;
        }
        free(node);
    }
}
void print(LQueue *Q){
    LinkedQueueNode *p;
    p=Q->front->next;
    while(p){
        printf("%d ",p->data);
        p=p->next;
    }
}
int main(){
    int i;
    LQueue *Q=Init();
    for(i=0;i<6;i++){
        Insert(Q,i);
    }
    print(Q);
    Delete(Q);
    printf("\n");
    print(Q);
}
