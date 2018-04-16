#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Tree
{
    int f,l,r;
}s[10];
int n;
void ListLeave(int k)
{
    int flag = 0;
    int a[20];
    int head = 0,tail = 0;
    a[tail ++] = k;
    while(head < tail)
    {
        if(s[a[head]].l != -1)a[tail ++] = s[a[head]].l;
        if(s[a[head]].r != -1)a[tail ++] = s[a[head]].r;
        if(s[a[head]].l == s[a[head]].r)
        {
            if(flag)printf(" %d",a[head]);
            else printf("%d",a[head]);
            flag ++;
        }
        head ++;
    }
}
int main()
{
    char a,b;
    scanf("%d",&n);
    for(int i = 0;i < n;i ++)
        s[i].f = -1;
    for(int i = 0;i < n;i ++)
    {
        getchar();
        scanf("%c %c",&a,&b);
        if(a!='-')
        {
            s[i].l = a - '0';
            s[a - '0'].f = i;
        }
        else s[i].l = -1;
        if(b!='-')
        {
            s[i].r = b - '0';
            s[b - '0'].f = i;
        }
        else s[i].r = -1;
    }
    for(int i = 0;i < n;i ++)
    {
        if(s[i].f == -1)ListLeave(i);
    }
}