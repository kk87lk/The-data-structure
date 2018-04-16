#include <stdio.h>
#include <stdlib.h>
typedef int elemtype;
typedef struct list{
    elemtype data;
    struct list*next;
}sqist;
int lenth(sqist *head){
	int j=0;
	sqist *p;
	p=head;
	while(p->next){
		j++;
		p=p->next;
	}return j;
}
void Delete (sqist *head){
	int len;
    sqist *p,*p2;
    p=head->next->next;
    while(p->next){
    	p2=p->next;
    	free(p);
    	p=p2;
	}head->next->next=p;
}
sqist* Creat(){
    int x;
    sqist *p,*head,*tail;
    head=(sqist*)malloc(sizeof(sqist));
    tail = head;
    if(head==NULL){
        return head;
    }
    head->next=NULL;
    scanf("%d",&x);
    while(x){
        p=(sqist*)malloc(sizeof(sqist));
        if(p==NULL)
            return head;
        p->data=x;
        tail->next = p;
        tail = p;
        tail->next = NULL;
        scanf("%d",&x);
    }
    return head;
}
void print(sqist *head){
    sqist *p;
    p=head->next;
    while(p){
        printf("%d ",p->data);
        p=p->next;
    }
}
int main(){
    sqist* head;
    head=Creat();
    print(head);
    printf("\n");
    Delete(head);
    print(head);
    return 0;
}
