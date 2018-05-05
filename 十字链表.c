#include <stdio.h>
#include <stdlib.h>
typedef int Elemtype;
typedef struct node{
    int row,col;
    struct node *down,*right;
    union v_next{
        Elemtype v;
        struct node *next;
    } V_next;
} MNode, *MLink;
MLink CreatMLink(){
    MLink H;
    MNode *p, *q;
    int i, j, m, n, t, k;
    Elemtype v;
    scanf("%d%d%d", &m, &n, &t);
    int S = m > n ? m : n;
    MNode *hd[S + 1];
    H = malloc(sizeof(MNode));
    H->row = m;
    H->col = n;
    hd[0] = H;
    for (i = 1; i <=S;i++){
        p = malloc(sizeof(MNode));
        p->row = 0;
        p->col = 0;
        p->right = p;
        p->down = p;
        hd[i] = p;
        hd[i - 1]->V_next.next = p;
    }
    hd[S]->V_next.next = H;
    for (k = 1; k <= t;k++){
        scanf("%d%d%d", &i, &j, &v);
        p = malloc(sizeof(MNode));
        p->row = i;
        p->col = j;
        p->V_next.v = v;
        
        q = hd[i];
        while (q->right!=hd[i]&&(q->right->col)<j)
        {
            q = q->right;
        }
        p->right = q->right;
        q->right = p;

        q = hd[j];
        while (q->down != hd[j] && (q->down->row) < i)
        {
            q = q->down;
        }
        p->down = q->down;
        q->down = p;
    }
    return H;
}
int main(){
    MLink H=CreatMLink();
    printf("%d\n\n%d",H->V_next.next->V_next.next->V_next.next->down->V_next.v,H->V_next.next->V_next.next->right->V_next.v);
    
}
