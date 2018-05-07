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
	printf("分别输入学生学号,姓名,语数外成绩，输入0表示输入完成!\n");
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
		printf("输入想要修改的学号!\n");
		scanf("%d",&num);
		//fseek(p3,sizeof(student1)*(num-1),0);
		//fscanf(p3,"%d%s%d%d%d",&student1.num,student1.name,&student1.chinese,&student1.math,&student1.english);
		//printf("%d\n%s\n%d\n%d\n%d",student1.num,student1.name,student1.chinese,student1.math,student1.english); 
		//链表内存不是连续的不能用fseek函数。
		while(p4->num!=num){					//定位修改的位置 
			p4=p4->next;
		}
		printf("%d %s %d %d %d \n",p4->num,p4->name,p4->chinese,p4->math,p4->english);
		printf("输入修改的分数:\n");
		scanf("%d%d%d",&p4->chinese,&p4->math,&p4->english);
		p5=p4=head;
		fclose(p3);					//重新打开date，否则不能覆盖 
		//分析:系统并不知道你什么时候输入结束，不知道的情况下就智能你一直输入，它一直在后面添加而当你关闭程序，系统就知道你输入完毕了
		//这时候，你再输入，系统明白你是重新输入数据，加上wb+就给你覆盖原来的数据了计算机之所以这样设定，是因为计算机没有机制去保证有一个适合的间断点，
		//在你输完一定数据后判断你已经输完本次数据。例如for循环中的fprintf计算机无法知道你希望在第几次覆盖原数据,所以设定fclose（），人为给计算机标识，作判断标志
		//另外如果不fcolse(),可能会导致你最后一次fprintf中输入的数据无法写入文件，计算机有buffer缓存机制，你输入的数据先会进入缓冲，
		//党缓冲满了以后会写入文件，但是极端情况就是你最后输入的内容没有把最后一个缓冲（实际可能非常小）给填满，缓冲没装满，就不会写入文件，
		//这样你的文件就会有所丢失，此外不关闭的话，还可能导致已经写入的文件泄露到其他硬盘文件中，所以fcolse()是必要的
		//有点遗漏，当你一旦fclose()，即使缓冲没有写满，也会将这部分写入文件中
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
