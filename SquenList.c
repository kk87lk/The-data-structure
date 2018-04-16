#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Maxsize 100
typedef int elemtype;
typedef struct {
    elemtype elem[Maxsize];
    int last;
}list;
int main(){
    void creatlist(list* l);
    void outputlist(list* l);
    void input_element(list* l,elemtype num,int i);
    elemtype delete_element(list* l,int i);
    int search_element(list* l, elemtype num);
    char input[2];
    char selectnum;
    list l1,l2;
    l1.last=-1;
    l2.last=-1;
    l2=l1;
    int insertnum=0,insertplace=0,deletelocation=0,dnum=0,ret=0;
    elemtype searchnum = 0;
    do{
        printf("1--Creat one list\n");
        printf("2--Input element\n");
        printf("3--Delete element\n");
        printf("4--Search element\n");
        printf("5--exit\n");
        printf("Please choose an option:");
        scanf("%s",input);
        while (strlen(input)!=1||(strcmp(input,"6")>0)||(strcmp(input,"1")<0))
        {
            printf("Input Error! Please Input Again!\n");
		    fflush(stdin);
		    scanf("%s",input);
        }   //guarantee the right input
    selectnum=input[0];
    switch(selectnum){
        case '1':creatlist(&l1);
                 l2=l1;
                 outputlist(&l1);
                 fflush(stdin);
                 break;
         case '2':printf("Please input the insert num and the palce you want:");
                  scanf("%d%d",&insertnum,&insertplace);
                  input_element(&l1,insertnum,insertplace);
                  l2=l1;
                  outputlist(&l1);
                  fflush(stdin);
                  break;
        case '3':printf("Please input the element's location you want to delete:");
                 scanf("%d",&deletelocation);
                 dnum=delete_element(&l1,deletelocation);
                 printf("The list before delete element:\n");
                 outputlist(&l2);
                 printf("The list after  delete element:\n");
                 outputlist(&l1);
                 printf("The Deleted element is:%d \n",dnum);
                 fflush(stdin);
                 break;
        case '4':
            printf("Please input the num you want:");
            scanf("%d", &searchnum);
            ret=search_element(&l1, searchnum);
            if(ret){
                printf("The element you want is %d  It is in the %d location.\n", searchnum, ret);
            }else{
                printf("Search error!\n");
                exit(1);
            }
            fflush(stdin);
            break;
    }
    }while (selectnum != '5');
    printf("Thanks using! BYE! \n");
    exit(1);
}
void creatlist(list* l){                         
    int i;
    int total;
    printf("Please input the num of elements:");
    scanf("%d",&total);
    l->last=total-1;
    for(i=0;i<=l->last;i++){
        printf("\nPlease inpt the %d element:",i);
        scanf("%d",&(l->elem[i]));
    }
}
void outputlist(list* l){
    int i;
    for(i=0;i<=l->last;i++){
        printf("The %d element=%d\n",i,l->elem[i]);
    }
}
void input_element(list* l,elemtype num,int i){
    int j;
    if(l->last>=Maxsize-1){
        printf("\n Error! Elements Overflow! \n");
        exit(1);
    }
    else if(i<1||i>l->last+2){
        printf("\n Error! Input Illegal! \n");
        exit(1);
    }
    else {
        for(j=l->last;j>=i-1;j--){
            l->elem[j+1]=l->elem[j];
        }l->elem[i-1]=num;
        l->last++;
    }
}
elemtype delete_element(list* l,int i){
    int j;
    elemtype deletenum;
    if(l->last==-1){
        printf("Error! The list is empty\n");
        exit(1);
    }
    else if(i<1||1>l->last+2){
        printf("Error! Delete illegal!\n");
        exit(1);
    }
    else{
        deletenum=l->elem[i-1];
        for(j=i;j<=l->last;j++){
            l->elem[j-1]=l->elem[j];
        }l->last--;
    }
    return deletenum;
}
int search_element(list* l, elemtype num){
    int j=0,ret=0;
    while(j<=l->last && num != l->elem[j]){
        j++;
    }
    if(j<=l->last){
        ret = j+1;
    }else {
        ret = 0;
    }
    return ret;
}