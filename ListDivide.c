#include <stdio.h>
#include <stdlib.h>
typedef int elemtype;
typedef struct Node{
    elemtype Data;
    struct Node *next;
}Node;
Node* CreatList (){
    int n,i;
    Node *head,*p,*new;
    printf("Please input the num of elements in the list:");
    scanf("%d",&n);
    p=head=(Node*)malloc(sizeof(Node));
    head->next=NULL;
    for(i=0;i<n;i++){
        new=(Node*)malloc(sizeof(Node));
        scanf("%d",&(new->Data));
        p->next=new;
        p=new;
    }
    p->next=NULL;
    return head;
}
void DisplayList(Node *head){
    Node *p;
    p=head->next;
    if(!p){
    	printf("error\n");
    	exit(1);
	}
    while(p){
        printf("%d ",p->Data);
        p=p->next;
    }
}
Node* FindP(Node*head){
    Node *p;
    p=head->next;
    while (p)
    {
        if(p->Data%2!=0){
            break;
        }else{
            p=p->next;
        }
    }
    return p;
}
Node* FindQ(Node *head){
    Node*q;
    q=head->next;
    while (q)
    {
        if(q->Data%2==0){
            break;
        }else{
            q=q->next;
        }
    }
    return q;
}
Node* LinkP(Node*head,Node*Phead){
    Node*p,*pnode,*pnew;
    p=FindP(head);
    if(!p){
    	printf("\nerror!\n");
    	exit(1);
	}
    pnode=(Node*)malloc(sizeof(Node));
    pnode->Data=p->Data;
    Phead->next=pnode;
    p=p->next;
    while(p){
        if(p->Data%2!=0){
            pnew=(Node*)malloc(sizeof(Node));
            pnew->Data=p->Data;
            pnode->next=pnew;
            pnode=pnode->next;
            p=p->next;
        }else{
            p=p->next;
        }
    }pnode->next=NULL;
    return Phead;
}
Node* LinkQ(Node*head,Node*Qhead){
    Node*q,*qnode,*qnew;
    q=FindQ(head);
    if(!q){
    	printf("\nerror!\n");
    	exit(1);
	}
    qnode=(Node*)malloc(sizeof(Node));
    qnode->Data=q->Data;
    Qhead->next=qnode;
    q=q->next;
    while(q){
        if(q->Data%2==0){
            qnew=(Node*)malloc(sizeof(Node));
            qnew->Data=q->Data;
            qnode->next=qnew;
            qnode=qnode->next;
            q=q->next;
        }else{
            q=q->next;
        }
    }qnode->next=NULL;
    return Qhead;
}
int main(){
    Node*head,*Qhead,*Phead;
    Phead=(Node*)malloc(sizeof(Node));
    Qhead=(Node*)malloc(sizeof(Node));
    head=CreatList();
    printf("Initial List:");
    DisplayList(head);
    LinkP(head,Phead);
    LinkQ(head,Qhead);
    printf("\nOdd List:");
    DisplayList(Phead);
    printf("\nEven List:");
    DisplayList(Qhead);
}
