#include <stdio.h>
#include <stdlib.h>
typedef int elemtype;
typedef struct node{
    int row, col;
    elemtype value;
    struct node *right, *down;
} Lnode,*Link;
typedef struct{
    Link *rowhead, *colhead;
    int m, n, len;
} CrossList;

CrossList* CreatCrossList(){
    int m, n, t,i,k;
    int row, col, value;
    CrossList* M=(CrossList*)malloc(sizeof(CrossList));
    printf("Please input the all row , col and numbers of element:");
    scanf("%d%d%d", &m, &n, &t);
    M->m = m;
    M->n = n;
    M->len = t;
    M->rowhead = (Link *)malloc((m + 1) * sizeof(Link *));
    M->colhead = (Link *)malloc((n + 1) * sizeof(Link *));
    for (i = 1; i <= m;i++){
        M->rowhead[i] = NULL;
    }
    for (i = 1; i <= n;i++){
        M->colhead[i] = NULL;
    }
    for (k = 1; k <= t;k++){
        printf("Please input the element's row,col and value:");
        scanf("%d%d%d", &row, &col, &value);
        Lnode *p = (Lnode *)malloc(sizeof(Lnode));
        p->row = row;
        p->col = col;
        p->value = value;
        p->right=p->down=NULL;
        if(M->rowhead[row]==NULL)   M->rowhead[row]=p;
        else{
            Link Q = M->rowhead[row];
            while (Q->right&&Q->right->col<col)
            {
                Q = Q->right;
            }
            p->right = Q->right;
            Q->right = p;
        }
        if(M->colhead[col]==NULL)   M->colhead[col]=p;
        else{
            Link Q2 = M->colhead[col];
            while (Q2->down && Q2->down->row < row)
            {
                Q2 = Q2->down;
            }
            p->down = Q2->down;
            Q2->down = p;
        }
    }
    return M;
}
int printList(CrossList*M){
    int i;
    Lnode *p;
    for (i = 1; i <= M->m;i++){
        p = M->rowhead[i];
        while (p)
    {
        printf("value=%d row=%d col=%d\n",p->value,p->row,p->col);
        if (p->down)
            printf("down's value=%d row=%d col=%d\n", p->down->value, p->down->row, p->down->col);
        if (p->right)
            printf("right's value=%d row=%d col=%d\n", p->right->value, p->right->row, p->right->col);
        p = p->right;
    }  
    }
    return 1;
}
int Find(CrossList*M,elemtype x){
    Lnode *p;
    int i;
    if(!M){
        printf("No CrossList\n");
        return -2;
    }
    for (i = 1; (i <= M->m); i++)
    {
        p = M->rowhead[i];
        while (p)
        {   if(p->value==x){
                printf("The value %d  row:%d  col:%d\n", p->value, p->row, p->col);
                return 1;
        }else if(p->right){
            p = p->right;
        }else
            break;
        }
    }
    if(p->value==x){
        printf("The value %d  row:%d  col:%d\n", p->value, p->row, p->col);
        return 1;
    }else{
        printf("No such value!\n");
        return -1;
    }
}
int FindValue(CrossList*M,int i,int j){
    Lnode *p;
    int k;
    if(i>M->m||j>M->n||i<=0||j<=0){
        printf("Finding illegal\n");
        return -2;
    }
    p = M->rowhead[i];
    for (k = 1; k < j;k++){
        if(!p){
            printf("No such value!\n");
            return -1;
        }else{
            if(p->col!=j)
                p = p->right;
        }  
    }
    if(p){
        printf("The value %d  row:%d  col:%d\n", p->value, p->row, p->col);
        return 1;
    }else{
        printf("No such value!\n");
        return -1;
    }
}
int main(){
    int x,cnt=0,i,j;
    elemtype X;
    CrossList *M = NULL;
    do{
        printf("1.Create a CrossList\n");
        printf("2.Find an element by value\n");
        printf("3.Find an element by coordinates\n");
        printf("4.output current CrossList\n");
        printf("0.exit\n");
        printf("Please select(0-4):");
        scanf("%d", &x);
        switch(x){
        case 1:
            M = CreatCrossList();
            cnt++;
            break;
            
        case 2:if(cnt){
                printf("\ninput the value you want:");
                scanf("%d", &X);
                Find(M, X);
                break;
        }else{
            printf("No CrossList in memory\n");
            continue;
        }
        case 3:if(cnt){
                printf("\ninput the row, col you want:");
                scanf("%d%d", &i,&j);
                FindValue(M, i, j);
                break;
        }else{
            printf("No CrossList in memory\n");
            continue;
        }
        case 4:if(cnt){
                printList(M);
                break;
        }else{
            printf("No CrossList in memory\n");
            continue;
        }
        case 0:
            printf("Thanks to use\n");
            exit(1);
        }
    } while (x);
}
