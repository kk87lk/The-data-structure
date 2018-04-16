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
elemtype Delete(LQueue *Q){
    LinkedQueueNode *node;
    elemtype x;
    if(Q->front==Q->rear){
        printf("The Queue is empty!\n");
        exit(1);
    }else{
        node=Q->front->next;
        x=node->data;
        if(node==Q->rear){
            Q->rear=Q->front;
        }else{
            Q->front->next=node->next;
        }
        free(node);
    }return x;
}
void print(LQueue *Q){
    LinkedQueueNode *p;
    p=Q->front->next;
    while(p){
        printf("%d ",p->data);
        p=p->next;
    }
}
elemtype GetFront(LQueue *Q){
    return (Q->front->next->data);
}
void YHTriangle(int n){
    LQueue *Q=Init();
    int a1,a2;
    int i,k;
    printf("%d\n",1);
    Insert(Q,1);
    Insert(Q,1);
    for(i=2;i<=n;i++){
        Insert(Q,1);
        for(k=0;k<=i-2;k++){
            a1=Delete(Q);
            a2=GetFront(Q);
            printf("%d",a1);
            Insert(Q,a1+a2);
        }
        a2=Delete(Q);
        printf("%d\n",a2);
        Insert(Q,1);
    }
}

int main(int argc, char *argv[]) {
	int n;
    scanf("%d",&n);
    YHTriangle(n);
	return 0;
}
