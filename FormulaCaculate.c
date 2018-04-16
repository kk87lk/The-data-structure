#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ElemType char 
struct stack{
    ElemType Data;
    struct stack *next;
};
typedef struct stack PtrtoNode;
typedef PtrtoNode* Stack;
int isempty(Stack s){
    if(s->next==NULL)
        return 1;
    else return 0;
}
Stack CreatStack(){
    Stack s;
    s=(Stack)malloc(sizeof(PtrtoNode));
    s->next=NULL;
    return s;
}
void push(Stack s,ElemType x){
    PtrtoNode *TemCell;
    TemCell=(PtrtoNode*)malloc(sizeof(PtrtoNode));
    TemCell->Data=x;
    TemCell->next=s->next;
    s->next=TemCell;
}
char pop(Stack s){
    PtrtoNode* FirstCell;
    ElemType TopElem;
    if(isempty(s))
       {  printf("The Stack is empty!\n");
        exit(1);}
        else{
        FirstCell = s->next; 
        TopElem = FirstCell->Data;
        s->next = FirstCell->next;
        free(FirstCell);
        return TopElem;
        }
}
char* Transfer(Stack S,char *s,char *s2){
    char *p=s;
    int i=0,k=0,cnt=0;
    char s1[100]={'0'};
    char a;
    char a1[1] = {'0'};
    while (i<strlen(s))
    {
        if((*p-'0')>=0&&(*p-'0')<=9){
            a1[0] = p[0];
            //strcat(s1,a1);
            s1[k]=a1[0];
        	k++; 
            p++;
            i++;
        }else{
            if(*p!=')'){
                push(S,*p);
                p++;
                i++;
            }else if(*p==')'){
                do
                {
                    a=pop(S);
                    a1[0] = a;
                    //strcat(s1,a1);
                    s1[k]=a1[0];
					k++;
                }while (S->next->Data!='(');
				pop(S);
                p++;
                i++;
            }
        }
    }
    while (isempty(S)!=1)
    {
        a=pop(S);
        a1[0] = a;
        //strcat(s1,a1);
        s1[k]=a1[0];
        k++;
    }
    //strcpy(s2, s1);
    //puts(s1);
    return s1;
}
int JudgeP(char p){
    int ret;
    switch(p){
        case '+':ret=1;break;
        case '-':ret=2;break;
        case '*':ret=3;break;
        case '/':ret=4;break;
    }
    return ret;
}
char change(int ret){
	char chret;
	switch(ret){
		case 0:chret='0';break;
		case 1:chret='1';break;
		case 2:chret='2';break;
		case 3:chret='3';break;
		case 4:chret='4';break;
		case 5:chret='5';break;
		case 6:chret='6';break;
		case 7:chret='7';break;
		case 8:chret='8';break;
		case 9:chret='9';break;
	}
	return chret;
}
int Operate(int a1,int a2,int judgep){
    int ret;
    switch(judgep){
        case 1:ret=a2+a1;break;
        case 2:ret=a2-a1;break;
        case 3:ret=a2*a1;break;
        case 4:ret=a2/a1;break;
    }
    return ret;
}
void Caculate(Stack S,char *s){
    char *p=s;
    int a1,a2,judgep=0,i=0,ret=0,ret2=0;
    char a,b,chret[1];
    while (i<strlen(s))
    {
        if((*p-'0')>=0&&(*p-'0')<=9){
            push(S,*p);
            p++;
            i++;
        }else{
            judgep=JudgeP(*p);
            a=pop(S);
            b=pop(S);
            a1=a-'0';
            a2=b-'0';
            ret=Operate(a1,a2,judgep);
            chret[0]=change(ret);
            push(S,chret[0]);
            p++;
            i++;
        }
    }
    ret2=pop(S)-'0';
    printf("\n%d",ret2);
}
void printStack(Stack s){
    PtrtoNode* p;
    p=s->next;
    while(p){
        printf("%d\n",p->Data);
        p=p->next;
    }
}
int main(){
    Stack S=CreatStack();
    Stack SS=CreatStack();
    char s[100];
    char s1[100];
    char ss[100];
    printf("Please input the formula:");
    scanf("%s",s);
    getchar();
    //ss=Transfer(S,s,s1);
    strcpy(ss,Transfer(S,s,s1));
	puts(ss);
    printf("\n");
    Caculate(SS,ss);
    

}
