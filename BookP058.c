#include <stdio.h>
#include <stdlib.h>
#define Maxsize 1024
typedef int elemtype;
typedef struct List{
    elemtype Data[Maxsize];
    int last;
}SequenList;

int FindMax(SequenList *L){
    int i=0,j=0,max;
    max=L->Data[0];
    for(i=0;i<=L->last;i++){
        if(max<L->Data[i]){
            max=L->Data[i];
            j=i;
        }
    }return j;
}

void Insert(SequenList *L,elemtype x,int i){
    int j=0;
    if(L->last>=Maxsize-1){
        printf("The List is full!\n");
        exit(1);
    }
    if(i<1||i>L->last+2){
        printf("Input illegal!\n");
        exit(1);
    }
    for(j=L->last;j>=i-1;j--){
        L->Data[j+1]=L->Data[j];
    }
    L->Data[i-1]=x;
    L->last++;
} 

elemtype Delete(SequenList *L,int i){
    int j=0,elem;
    if(i<1||i>L->last+1){
        printf("Delete illegal!\n");
        exit(1);
    }else{
        elem=L->Data[i-1];
        for(j=i;j<=L->last;j++){
            L->Data[j-1]=L->Data[j];
        }L->last--;
        return elem;
    }
}
int main(){
    SequenList *L;
    L = (SequenList *)malloc(sizeof(SequenList));
    int max=0;
    int i = 0;
    int elem = 0;
    for (i = 0; i < 6;i++){
        L->Data[i] = i;
    }
    L->last = 6;
    max = FindMax(L);
    printf("%d\n",L->Data[max]);
    Insert(L, 6, 7);
    max = FindMax(L);
    printf("%d\n", L->Data[max]);
    elem=Delete(L, 7);
    max = FindMax(L);
    printf("%d\n", L->Data[max]);
    printf("%d\n", elem);
}