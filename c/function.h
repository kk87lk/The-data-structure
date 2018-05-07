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
//struct student* write(){										//数据存储函数 
//	struct student *head=NULL,*p1,*p2,*p;
//	int n=0,num;
//	printf("先后输入学号,姓名,四门课成绩.(都输入0表示输入结束)\n");
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

