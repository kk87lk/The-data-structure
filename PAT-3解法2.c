#include<stdio.h>

#define N 10000
int main() {
    int a[N]= {0};//第一个单项式
    int b[N]= {0};//第二个单项式
    int c[N]= {0};//求积
    int d[N]= {0};//求和
    int i,m,f;
    scanf("%d",&i);
    while(i--) {
        scanf("%d %d",&m,&f);
        a[f]+=m;
    }
    scanf("%d",&i);
    while(i--) {
        scanf("%d %d",&m,&f);
        b[f]+=m;
    }
    for(int i=N-1; i>=0; i--) {
        if(a[i]) {
            for(int j=0; j<N; j++) {
                if(b[j]) {
                    c[i+j]+=a[i]*b[j];
                }
            }
        }
    }
    int cnt=0;
    for(int i=N-1; i>=0; i--) {

        if(c[i]) {
            if(cnt)printf(" ");
            printf("%d %d",c[i],i);
            cnt++;
        }

    }
    if(!cnt)printf("0 0");

    for(int i=N-1; i>=0; i--)
        if(a[i])
            d[i]+=a[i];
    for(int j=0; j<N; j++)
        if(b[j])
            d[j]+=b[j];

printf("\n");

     cnt=0;
    for(int i=N-1; i>=0; i--) {

        if(d[i]) {
            if(cnt)printf(" ");
            printf("%d %d",d[i],i);
            cnt++;
        }

    }
    if(!cnt)printf("0 0");
    return 0;
}