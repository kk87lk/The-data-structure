#include <stdio.h>
#include <stdlib.h>
#include "menu.h"    //printmenu����������� 
#include <string.h>
#include "function.h"
struct student{
	int studentnum;
	char name[20];
	float score1;
	float score2;
	float score3;
	float score4; 
	struct student *next;
};
struct student* write(){										//���ݴ洢���� 
	struct student *head=NULL,*p1,*p2,*p;
	int n=0;
	p2=p1=(struct student*)malloc(len); 
	scanf("%d%s%f%f%f%f",&p1->studentnum,p1->name,&p1->score1,&p1->score2,&p1->score3,&p1->score4);
	while(p1-> studentnum != 0){
		n+=1;
		if(n==1) head=p1;
		else p2->next=p1;
		p2=p1;
		p1=(struct student*)malloc(len);
		scanf("%d%s%f%f%f%f",&p1->studentnum,p1->name,&p1->score1,&p1->score2,&p1->score3,&p1->score4);	
	}p2->next=NULL;
	return head;
}
int main(int argc, char *argv[]) {
	int n2=0,delectnum=0,n3=0,n4=0,n5=0,n6=0,n7=0,delectnumcnt=1,modifynum=0,querynumber=0,querynumber1=1,queryname1=1;
	int stucnt=0;
	float score1sum=0,score2sum=0,score3sum=0,score4sum=0;
	char num1[3],file[20],file2[20],file3[20],file4[20],file5[20],file6[20],file7[20],editnum[3],querynum[3],queryname[20];
	char num2,editnum2,querynum2;
	struct student *head=NULL,*p1=NULL,*p2=NULL,*p,*p3,*p4,*phead6=NULL,*phead5=NULL,*phead4=NULL,*phead3=NULL,*phead2=NULL,*phead=NULL,*p5,*p6,*p7,*p8,*p9,*p10,*p11,*p12,*p13,*p14,*p15,*p16,*p17,*p18,*p19,*p20,*p21,*p22,*p23,*p24;
	FILE *fp,*fp2,*fp3,*fp4,*fp5,*fp6,*fp7,*fp8;
	printmenu();
flag1: printf("Please Select an Option(0-8):");
	fflush(stdin);
	scanf("%s",num1);
	while(strlen(num1)!=1||(strcmp(num1,"8")>0)||(strcmp(num1,"0")<0))				//ȷ������׼ȷ 
	{	
		printf("Input Error! Please Input Again!\n");
		fflush(stdin);
		scanf("%s",num1);
	}
		num2=num1[0];	//���븳���±���num2 
		switch(num2){
			case '1':
				p=p1=p2=p3=p4=p5=p6=p7=p9=p9=p10=p11=p12=p13=p14=p15=p16=p17=p18=p19=p20=p21=p22=p23=p24=NULL;
				head=phead=phead2=phead3=phead4=phead5=phead6=NULL;
				n2=0,delectnum=0,n3=0,n4=0,n5=0,n6=0,n7=0,delectnumcnt=1,modifynum=0,querynumber=0,querynumber1=1,queryname1=1,stucnt=0;
				score1sum=0,score2sum=0,score3sum=0,score4sum=0;
				fflush(stdin);
				printf("System has been initialized!\n");
				goto flag1;
				break;
			case '2':
flag2:			printf("��������Ҫ������ļ�!\n");
				fflush(stdin);
				scanf("%s",file);
				fp2=fopen(file,"rb");
				if(fp2==NULL) {
					printf("����ʧ��,������ٴε���!\n");
					fflush(stdin);
					goto flag2;
				}
					p4=p3=(struct student*)malloc(len);
					//fscanf(fp2,"%d%s%f%f%f%f",&p3->studentnum,p3->name,&p3->score1,&p3->score2,&p3->score3,&p3->score4);
					fread(p3,len,1,fp2);		//�������ļ��� fread ������ 
					while(!(feof(fp2))){
						n2+=1;
						if(n2==1) phead=p3;
						else  p4->next=p3;
						p4=p3;
						p3=(struct student*)malloc(len);
						fread(p3,len,1,fp2);
					}p4->next=NULL;
						p5=phead;
						if(p5==NULL){
							printf("%s��������!\n",file);
							goto flag1;
						}
						printf("%s�ڵ�����:\n",file); 
						while(p5!=NULL){
										printf("%d %-4s %5.2f %5.2f %5.2f %5.2f\n",p5->studentnum,p5->name,p5->score1,p5->score2,p5->score3,p5->score4);
										p5=p5->next;
									}	
				goto flag1;
				fflush(stdin);
				break;
			case '3':
				printf("�Ⱥ�����ѧ��,����,���ſγɼ�.(������0��ʾ�������)\n");
				p=write();
				fp=fopen("data.txt","wb+");
				if(fp==NULL){
					printf("Open File Error! Please Open Again!\n");
					exit(1);
				}	
				while(p!=NULL){
				//fprintf(fp,"%d %s %f %f %f %f",p->studentnum,p->name,p->score1,p->score2,p->score3,p->score4);
				fwrite(p,len,1,fp);				//�������ļ��� fwrite д�룡 
				p=p->next;}
				fflush(stdin);
				fclose(fp);
				printf("Input information success!\n");
				goto flag1;
				break;
			case '4':
flag3:			Editmenu();
				printf("Please Select an Option(1-4):");
				fflush(stdin);
				scanf("%s",editnum);
				while(strlen(editnum)!=1||(strcmp(editnum,"4")>0)||(strcmp(editnum,"1")<0))				//ȷ������׼ȷ 
					{	
						printf("Input Error! Please Input Again!\n");
						fflush(stdin);
						scanf("%s",editnum);
					}
				editnum2=editnum[0];        //���븳���±���
				switch(editnum2){
					case '1':
						printf("��������Ҫ׷�ӵ��ļ���!\n");
						fflush(stdin);
						scanf("%s",file2);
						fp3=fopen(file2,"ab+");
						if(fp3==NULL){
							printf("���ļ�ʧ��,������ٴ�!\n");
							fflush(stdin);
							exit(1);
						}
						printf("�Ⱥ�������Ҫ׷��ѧ����ѧ��,����,���ſγɼ�.(������0��ʾ�������)\n");
						p6=write();
						fclose(fp3);
						fp3=fopen(file2,"ab+");
						while(p6!=NULL){
								fwrite(p6,len,1,fp3);				//�������ļ��� fwrite д�룡 
								p6=p6->next;
						}
							printf("׷�����ݳɹ�!���´򿪳��򼴿ɲ鿴!\n");
							fclose(fp3);
							fflush(stdin);
							goto flag3;
							break;
					case '2':
flag4:					printf("�������ļ���ַ:");
						fflush(stdin);
						scanf("%s",file3);
						fp4=fopen(file3,"rb+");
						if(fp4==NULL){
							printf("�ļ���ʧ��,������ٴδ�!\n");
							fflush(stdin);
							goto flag4; 
						}
							p7=p8=(struct student*)malloc(len);
							fread(p7,len,1,fp4);		//�������ļ��� fread ������ 
							while(!(feof(fp4))){
							n3+=1;
							if(n3==1) phead2=p7;
							else  p8->next=p7;
							p8=p7;
							p7=(struct student*)malloc(len);
							fread(p7,len,1,fp4);
							}p8->next=NULL;
flag5:					p11=p9=p10=phead2;
						printf("������ɾ����ѧ��:");
						scanf("%d",&delectnum);
						
						while(p9->studentnum != delectnum){				//ɾ������ 
							p10=p9;
							p9=p9->next;
							if(p9==NULL){
								delectnumcnt=0;
								break;
							}
						}
							if(delectnumcnt==0){
								printf("��������Ч��ѧ��!\n");
								delectnumcnt=1;
								goto flag5;
							}
							p9=p9->next;
							p10->next=p9;
							fclose(fp4);
							fp4=fopen(file3,"wb");	
						while(p11!=NULL){
								fwrite(p11,len,1,fp4);				//�������ļ��� fwrite д�룡 
								p11=p11->next;}	
						printf("ɾ���ɹ�,���´򿪳��򼴿ɲ鿴!\n");
						fclose(fp4);
						fflush(stdin);
						goto flag3;
						break;
					case '3':
flag6:					printf("�������ļ���ַ:");
						fflush(stdin);
						scanf("%s",file4);
						fp5=fopen(file4,"rb+");
						if(fp5==NULL){
							printf("�ļ���ʧ��,������ٴδ�!\n");
							fflush(stdin);
							goto flag6;
						}
							p12=p13=(struct student*)malloc(len);
							fread(p12,len,1,fp5);		//�������ļ��� fread ������ 
							while(!(feof(fp5))){
							n4+=1;
							if(n4==1) phead3=p12;
							else  p13->next=p12;
							p13=p12;
							p12=(struct student*)malloc(len);
							fread(p12,len,1,fp5);
							}p13->next=NULL;
flag7:					p14=p15=phead3;
						printf("������Ҫ�޸���Ϣ��ѧ����ѧ��:");
						scanf("%d",&modifynum);
						while(p14->studentnum != modifynum){	//��λ�޸�λ�� 
							p14=p14->next;
							if(p14==NULL){
								modifynum=0;
								break;
							}
						}	if(modifynum==0){
							printf("��������Ч��ѧ��!\n");
							modifynum=1;
							goto flag7;
						}
							printf("�����޸ĺ����Ϣ:\n");
							scanf("%d%s%f%f%f%f",&p14->studentnum,p14->name,&p14->score1,&p14->score2,&p14->score3,&p14->score4);
							fclose(fp5);
							fp5=fopen(file4,"wb");
							while(p15!=NULL){
								fwrite(p15,len,1,fp5);				//�������ļ��� fwrite д�룡 
								p15=p15->next;
						}
							printf("�޸ĳɹ�!���´򿪳��򼴿ɲ鿴!\n");
							fclose(fp5);
							fflush(stdin);
							goto flag3;
							break;
					case '4':
						goto flag1;
						fflush(stdin);
						break;
				} 
				fflush(stdin);
				break;
			case '5':
flag10: 		Querymenu();
				fflush(stdin);
				printf("Please Select an Option(1-3):");
				fflush(stdin);
				scanf("%s",querynum);
				while(strlen(querynum)!=1||(strcmp(querynum,"3")>0)||(strcmp(querynum,"1")<0))				//ȷ������׼ȷ 
					{	
						printf("Input Error! Please Input Again!\n");
						fflush(stdin);
						scanf("%s",querynum);
					}
				querynum2=querynum[0];        //���븳���±���
				switch(querynum2){
flag8:					case '1':
						printf("�������ļ���ַ:");
						fflush(stdin);
						scanf("%s",file5);
						fp6=fopen(file5,"rb+");
						if(fp6==NULL){
							printf("�ļ���ʧ��,������ٴδ�!\n");
							fflush(stdin);
							goto flag8;
						}
						p16=p17=(struct student*)malloc(len);
							fread(p16,len,1,fp6);		//�������ļ��� fread ������ 
							while(!(feof(fp6))){
							n5+=1;
							if(n5==1) phead4=p16;
							else  p17->next=p16;
							p17=p16;
							p16=(struct student*)malloc(len);
							fread(p16,len,1,fp6);
							}p17->next=NULL;
flag9:						p18=phead4;
							printf("��������Ҫ���ҵ�ѧ��:");
							scanf("%d",&querynumber);
							while(p18->studentnum != querynumber){	//��λ��ѯλ�� 
							p18=p18->next;
							if(p18==NULL){
								querynumber1=0;
								break;
							}
						}	if(querynumber1==0){
							printf("��������Ч��ѧ��!\n");
							querynumber1=1;
							goto flag9;
						}
							printf("��ѯ�ɹ�!����Ϊ��ѧ������Ϣ:\n");
							printf("ѧ��:%d   ����:%s   �ɼ�:%.2f  %.2f  %.2f  %.2f  \n",p18->studentnum,p18->name,p18->score1,p18->score2,p18->score3,p18->score4);
							fclose(fp6);
							fflush(stdin);
							goto flag10;
							break;
					case '2':
flag11:					printf("�������ļ���ַ:");
						fflush(stdin);
						scanf("%s",file6);
						fp7=fopen(file6,"rb+");
						if(fp7==NULL){
							printf("�ļ���ʧ��,������ٴδ�!\n");
							fflush(stdin);
							goto flag11;
						} 
							p19=p20=(struct student*)malloc(len);
							fread(p19,len,1,fp7);		//�������ļ��� fread ������ 
							while(!(feof(fp7))){
							n6+=1;
							if(n6==1) phead5=p19;
							else  p20->next=p19;
							p20=p19;
							p19=(struct student*)malloc(len);
							fread(p19,len,1,fp7);
							}p20->next=NULL;
flag12:						p21=phead5;
							printf("��������Ҫ���ҵ�����:");
							fflush(stdin);
							scanf("%s",queryname);
							while(strcmp(queryname,p21->name) != 0){	//��λ��ѯλ�� 
							p21=p21->next;
							if(p21==NULL){
								queryname1=0;
								break;
							}
						}	if(queryname1==0){
							printf("��������Ч������!\n");
							queryname1=1;
							goto flag12;
						}
							printf("��ѯ�ɹ�!����Ϊ��ѧ������Ϣ:\n");
							printf("ѧ��:%d   ����:%s   �ɼ�:%.2f  %.2f  %.2f  %.2f  \n",p21->studentnum,p21->name,p21->score1,p21->score2,p21->score3,p21->score4);
							fclose(fp7);
							fflush(stdin);
							goto flag10;
							break;
					case '3':
						fflush(stdin);
						goto flag1;
						break;
					}
				break;
			case'6':
flag13:				printf("�������ļ���ַ:");
						fflush(stdin);
						scanf("%s",file7);
						fp8=fopen(file7,"rb+");
						if(fp8==NULL){
							printf("�ļ���ʧ��,������ٴδ�!\n");
							fflush(stdin);
							goto flag13;
						} 
						p22=p23=(struct student*)malloc(len);
							fread(p22,len,1,fp8);		//�������ļ��� fread ������ 
							while(!(feof(fp8))){
							n7+=1;
							if(n7==1) phead6=p22;
							else  p23->next=p22;
							p23=p22;
							p22=(struct student*)malloc(len);
							fread(p22,len,1,fp8);
							}p23->next=NULL;
							p24=phead6;
							if(p24==NULL){
							printf("%s��������!\n",file7);
							goto flag1;
						}
						printf("%s�ڵ�����:\n",file7); 
						while(p24!=NULL){
										printf("%d %-4s %5.2f %5.2f %5.2f %5.2f\n",p24->studentnum,p24->name,p24->score1,p24->score2,p24->score3,p24->score4);
										stucnt++;
										score1sum+=(p24->score1);
										score2sum+=(p24->score2);
										score3sum+=(p24->score3);
										score4sum+=(p24->score4);
										p24=p24->next;
									}	
						printf("�ð�����:%d   score1�ܷ�:%.2f   score2�ܷ�:%.2f   score3�ܷ�:%.2f   score4�ܷ�:%.2f   \n",stucnt,score1sum,score2sum,score3sum,score4sum);
						printf("             score1����:%.2f   score2����:%.2f   score3����:%.2f    score4����:%.2f   \n",score1sum/stucnt,score2sum/stucnt,score3sum/stucnt,score4sum/stucnt);			
				fflush(stdin);
				fclose(fp8);
				goto flag1;
				break;
				
			case '7':
				printf("�������Զ���������ǰĿ¼�� data.txt ��\n"); 
				fflush(stdin);
				goto flag1;
				break;
			case '8':
				printf("�������ļ���ַ:");
						fflush(stdin);
						scanf("%s",file7);
						fp8=fopen(file7,"rb+");
						if(fp8==NULL){
							printf("�ļ���ʧ��,������ٴδ�!\n");
							fflush(stdin);
							goto flag13;
						} 
						p22=p23=(struct student*)malloc(len);
							fread(p22,len,1,fp8);		//�������ļ��� fread ������ 
							while(!(feof(fp8))){
							n7+=1;
							if(n7==1) phead6=p22;
							else  p23->next=p22;
							p23=p22;
							p22=(struct student*)malloc(len);
							fread(p22,len,1,fp8);
							}p23->next=NULL;
							p24=phead6;
							if(p24==NULL){
							printf("%s��������!\n",file7);
							goto flag1;
						}
						printf("%s�ڵ�����:\n",file7); 
						while(p24!=NULL){
										printf("%d %-4s %5.2f %5.2f %5.2f %5.2f\n",p24->studentnum,p24->name,p24->score1,p24->score2,p24->score3,p24->score4);
											p24=p24->next;
									    }	
				fclose(fp8);
				fflush(stdin);
				goto flag1;
				break;
			case '0':
				printf("Thanks to use!\n");
				exit(1); 
		}
	
	return 0;
}
