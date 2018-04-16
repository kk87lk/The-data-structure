#include<stdio.h>
struct Poly{
    int ex;
    int co;
}Poly[1001];
int main(){
    int a,b,A[2005]={0},B[1005]={0};

    scanf("%d",&a);
    int temp1,temp2;

    for(int i=0;i<a;i++){
        scanf("%d%d",&Poly[i].co,&Poly[i].ex);//先输入系数，后输入指数
        B[Poly[i].ex]+=Poly[i].co;      //指数作为下标，系数作为数组元素
    }
    scanf("%d",&b);

    for(int i=0;i<b;i++){
        scanf("%d%d",&temp1,&temp2);
        B[temp2]+=temp1;            
        for(int j=0;j<a;j++)
            A[temp2+Poly[j].ex]+=(temp1*Poly[j].co);//指数相加，系数相乘
    }   
    int isfirst=1,haveoutput=0;//isfirst判断是否是第一个输出，haveoutput判断最后是否是零多项式
    for(int i=2000;i>=0;i--){
        if(A[i]!=0){
            if(!isfirst)    printf(" %d %d",A[i],i);
            if(isfirst){
                isfirst=0;
                printf("%d %d",A[i],i);
            }   
            haveoutput=1;   //如果执行了if语句则不是零多项式
        }
    }

    if(!haveoutput) printf("0 0");
    haveoutput=0;   //重置判断第二次输出是否是零多项式
    isfirst=1;      //重置判断第二次输出的第一项
    putchar('\n');
    for(int i=1000;i>=0;i--){
        if(B[i]!=0){
            if(!isfirst)        printf(" %d %d",B[i],i);
            if(isfirst){
                printf("%d %d",B[i],i);
                isfirst=0;
            }
            haveoutput=1;   
        }   

    }       
    if(!haveoutput) printf("0 0");
    return 0;
}