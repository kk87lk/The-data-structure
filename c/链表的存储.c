#include <stdio.h>
#include <stdlib.h>
struct student{
	char name[20];
	int num;
	int chinese;
	int math;
	int english;
	struct student *next;
};
# define len sizeof(struct student)
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	struct student *head,*p1,*p2,*p,student1,*p4,*p5;
	FILE *p3;
	int n=0,num;
	head=NULL;
	printf("�ֱ�����ѧ��ѧ��,����,������ɼ�������0��ʾ�������!\n");
	p2=p1=(struct student*)malloc(len); 
	scanf("%d%s%d%d%d",&p1->num,p1->name,&p1->chinese,&p1->math,&p1->english);
	while(p1->num != 0){
		n+=1;
		if(n==1) head=p1;
		else p2->next=p1;
		p2=p1;
		p1=(struct student*)malloc(len);
		scanf("%d%s%d%d%d",&p1->num,p1->name,&p1->chinese,&p1->math,&p1->english);	
	}
	p2->next=NULL;
	p=head;
	while(p!=NULL){
		printf("%d %s %d %d %d \n",p->num,p->name,p->chinese,p->math,p->english);
		p=p->next;
	}
	p3=fopen("date.txt","wb+");
	if(p3==NULL){
		printf("error!\n");
		exit(1);
	}
	p4=p=head;
	while(p!=NULL){
		fprintf(p3,"%d %s %d %d %d \n",p->num,p->name,p->chinese,p->math,p->english);
		p=p->next;
	}
		printf("������Ҫ�޸ĵ�ѧ��!\n");
		scanf("%d",&num);
		//fseek(p3,sizeof(student1)*(num-1),0);
		//fscanf(p3,"%d%s%d%d%d",&student1.num,student1.name,&student1.chinese,&student1.math,&student1.english);
		//printf("%d\n%s\n%d\n%d\n%d",student1.num,student1.name,student1.chinese,student1.math,student1.english); 
		//�����ڴ治�������Ĳ�����fseek������
		while(p4->num!=num){					//��λ�޸ĵ�λ�� 
			p4=p4->next;
		}
		printf("%d %s %d %d %d \n",p4->num,p4->name,p4->chinese,p4->math,p4->english);
		printf("�����޸ĵķ���:\n");
		scanf("%d%d%d",&p4->chinese,&p4->math,&p4->english);
		p5=p4=head;
		fclose(p3);					//���´�date�������ܸ��� 
		//����:ϵͳ����֪����ʲôʱ�������������֪��������¾�������һֱ���룬��һֱ�ں�����Ӷ�����رճ���ϵͳ��֪�������������
		//��ʱ���������룬ϵͳ�������������������ݣ�����wb+�͸��㸲��ԭ���������˼����֮���������趨������Ϊ�����û�л���ȥ��֤��һ���ʺϵļ�ϵ㣬
		//��������һ�����ݺ��ж����Ѿ����걾�����ݡ�����forѭ���е�fprintf������޷�֪����ϣ���ڵڼ��θ���ԭ����,�����趨fclose��������Ϊ���������ʶ�����жϱ�־
		//���������fcolse(),���ܻᵼ�������һ��fprintf������������޷�д���ļ����������buffer������ƣ�������������Ȼ���뻺�壬
		//�����������Ժ��д���ļ������Ǽ������������������������û�а����һ�����壨ʵ�ʿ��ܷǳ�С��������������ûװ�����Ͳ���д���ļ���
		//��������ļ��ͻ�������ʧ�����ⲻ�رյĻ��������ܵ����Ѿ�д����ļ�й¶������Ӳ���ļ��У�����fcolse()�Ǳ�Ҫ��
		//�е���©������һ��fclose()����ʹ����û��д����Ҳ�Ὣ�ⲿ��д���ļ���
		p3=fopen("date.txt","wb+");
		while(p4!=NULL){
		fprintf(p3,"%d %s %d %d %d ",p4->num,p4->name,p4->chinese,p4->math,p4->english);
		p4=p4->next;
	}
		while(p5!=NULL){
		printf("%d %s %d %d %d \n",p5->num,p5->name,p5->chinese,p5->math,p5->english);
		p5=p5->next;
	}
		fclose(p3);
	return 0;
}
