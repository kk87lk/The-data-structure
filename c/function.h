#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define len sizeof(struct student)
//struct student{
//	int studentnum;
//	char name[20];
//	float score1;
//	float score2;
//	float score3;
//	float score4; 
//	struct student *next;
//};
//struct student* write(){										//���ݴ洢���� 
//	struct student *head=NULL,*p1,*p2,*p;
//	int n=0,num;
//	printf("�Ⱥ�����ѧ��,����,���ſγɼ�.(������0��ʾ�������)\n");
//	p2=p1=(struct student*)malloc(len); 
//	scanf("%d%s%f%f%f%f",&p1->studentnum,p1->name,&p1->score1,&p1->score2,&p1->score3,&p1->score4);
//	while(p1-> studentnum != 0){
//		n+=1;
//		if(n==1) head=p1;
//		else p2->next=p1;
//		p2=p1;
//		p1=(struct student*)malloc(len);
//		scanf("%d%s%f%f%f%f",&p1->studentnum,p1->name,&p1->score1,&p1->score2,&p1->score3,&p1->score4);	
//	}p2->next=NULL;
//	p2->next=NULL;
//	return head;
//}

