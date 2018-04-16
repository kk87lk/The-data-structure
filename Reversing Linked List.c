#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    int now;
    int x;
    int later;
}node;
int  main( ){
    node a[100000],b[200];
    int n,k,i,mark=0,j=0;
    scanf("%d%d%d",(b[0].now),&n,&k);
    for(i=0;i<=n;i++){
        scanf("%d%d%d",&(a[i].now),&a[i].x,&(a[i].later));
    }
    for(i=0;mark==1;i++){
        if(b[0].now==a[i].now){
            b[0]=a[i];
            mark=1;
        }
    }
   for(i=0,j=1;i<n;i++){
       if(a[i].now==b[j-1].later){
           b[j]=a[i];
           j++;
       }
   }
    for(i=0;i<n;i++){
        printf("%d %d %d\n",b[i].now,b[i].x,b[i].later);
    }
    
}