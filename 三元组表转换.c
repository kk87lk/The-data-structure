#include <stdio.h>
#include <stdlib.h>
#define Maxsize 100
typedef int Elemtype;
typedef struct{
    int i,j;
    Elemtype v;
}Triple;
typedef struct{
    Triple data[Maxsize+1];
    int mu,nu,tu;
}TSMatrix;
TSMatrix* Transver(TSMatrix* A){
    TSMatrix* B;
    int i,j,k;
    int *num,*cpot;
    num = (int *)malloc((A->nu + 1) * sizeof(int));
    cpot = (int *)malloc((A->nu + 1) * sizeof(int));
    B = malloc(sizeof(TSMatrix));
    B->mu = A->nu;
    B->nu = A->mu;
    B->tu = A->tu;
    if(B->tu>0){
        for ( i = 1; i <= A->nu; i++)
        {
            num[i] = 0;
        }
        for (i = 1; i <= A->tu;i++){
            j = A->data[i].j;
            num[j]++;
        }
        cpot[1] = 1;
        for (i = 2; i <= A->nu;i++){
            cpot[i] = cpot[i - 1] + num[i - 1];
        }
        for (i = 1; i <= A->tu;i++){
            j = A->data[i].j;
            k = cpot[j];
            B->data[k].i = A->data[i].j;
            B->data[k].j = A->data[i].i;
            B->data[k].v = A->data[i].v;
            cpot[i]++;
        }
    }
    return B;
}
TSMatrix* Create(){
    int i,row,col;
    Elemtype value;
    TSMatrix *A = (TSMatrix *)malloc(sizeof(TSMatrix));
    printf("Input the total row col and num of value:");
    scanf("%d%d%d", &A->mu, &A->nu, &A->tu);
    for (i = 1; i <= A->tu;i++){
        printf("Input row col and value:");
        scanf("%d%d%d", &row, &col, &value);                    //规定输入按行序递增
        A->data[i].i = row;
        A->data[i].j = col;
        A->data[i].v = value;
    }
    return A;
}
int PrintTSMatrix(TSMatrix* A){
    if(!A) return -2;
    int i;
    for (i = 1; i <= A->tu;i++){
        printf("row=%d  col=%d  value=%d\n", A->data[i].i, A->data[i].j, A->data[i].v);
    }
    return 1;
}
int main(){
    TSMatrix *A = NULL;
    TSMatrix *B = NULL;
    A = Create();
    PrintTSMatrix(A);
    B = Transver(A);
    printf("\nBelow is the Transered TSM:\n");
    PrintTSMatrix(B);
    return 1;
}