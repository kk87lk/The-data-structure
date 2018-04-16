#include <stdio.h>
#include <stdlib.h>
int main(){
    int compare(long int a,long int b,long int c);
    long int a=0,b=0,c=0;
    int i=0,n=0;
    long int mark[11]={0};
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%ld%ld%ld",&a,&b,&c);
        mark[i]=compare(a,b,c);
    }
    for(i=0;i<n;i++){
        if(mark[i]==1){
            printf("Case #%d: true\n",i+1);
        }else {
            printf("Case #%d: false\n",i+1);
        }
    }
}
int compare(long int a,long int b,long int c){
    long int temp;
    temp=a+b;
    if(temp>c) return 1;
    else return 0;
}