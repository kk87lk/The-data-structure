#include <stdio.h>
#include <stdlib.h>
struct tree{
    int p;
    int left;
    int right;
} T[10];
int mark = 0;
int main(){
    int R;
    R=buildtree(T);
    search(R);
}
int buildtree(struct tree t[]){
    int n = 0, i = 0, p = 0;
    char l, r;
    int root;
    scanf("%d", &n);
    int check[10] = {0};
    if (n)
    {
        for (i = 0; i < n; i++)
        {	getchar();
            scanf("%c %c", &l, &r);
            T[i].p=i;
        if (l != '-')
        {
            T[i].left = l - '0';
            check[T[i].left] = 1;
        }
        else
            T[i].left = -1;
        if (r != '-')
        {
            T[i].right = r - '0';
            check[T[i].right] = 1;
        }
        else
            T[i].right = -1;
    }
    for (i = 0; i < n; i++)
    {
        if (!check[i])
            break;
    }
    root = i;
    }
    
    return root;
}
int search(int R){
    if((T[R].left==-1)&&T[R].right==-1){
        if(mark)
            printf(" %d", T[R].p);
        else {
            printf("%d", T[R].p);
            mark = 1;
        }
    }else {
        search(T[R].left);
        search(T[R].right);
    }
}
