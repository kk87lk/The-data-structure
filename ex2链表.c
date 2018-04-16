#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct LNode
{
    ElemType data;      
    struct LNode *next; 
} LNode;                
LNode *L;
LNode *creat_L();
void out_L(LNode *L);
void insert_L(LNode *L, int i, ElemType e);
ElemType delete_L(LNode *L, int i);
int locat_L(LNode *L, ElemType e);
int main()
{
    int i, k, loc;
    ElemType e, x;
    char ch;
    do
    {
        printf("\n\n\n");
        printf("\n\n     1. 建立线性链表 ");
        printf("\n\n     2. 在i位置插入元素e");
        printf("\n\n     3. 删除第i个元素，返回其值");
        printf("\n\n     4. 查找值为 e 的元素");
        printf("\n\n     5. 结束程序运行");
        printf("\n======================================");
        printf("\n     请输入您的选择 (1,2,3,4,5)");
        scanf("%d", &k);
        switch (k)
        {
        case 1:
        {
            L = creat_L();
            out_L(L);
        }
        break;
        case 2:
        {
            printf("\n i,e=?");
            scanf("%d,%d", &i, &e);
            insert_L(L, i, e);
            out_L(L);
        }
        break;
        case 3:
        {
            printf("\n i=?");
            scanf("%d", &i);
            x = delete_L(L, i);
            out_L(L);
            if (x != -1)
                printf("\n x=%d\n", x);
        }
        break;
        case 4:
        {
            printf("\n e=?");
            scanf("%d", &e);
            loc = locat_L(L, e);
            if (loc == -1)
                printf("\n 未找到 %d", loc);
            else
                printf("\n 已找到，元素位置是 %d", loc);
        }
        break;
        } 
        printf("\n ----------------");
    } while (k >= 1 && k < 5);
    printf("\n               再见！");
    printf("\n 打回车键，返回。");
    ch = getch();
}
LNode *creat_L(){
    LNode *h, *p, *s;
    ElemType x;
    h = (LNode *)malloc(sizeof(LNode));
    h->next = NULL;
    p = h;
    printf("\n  data=?");
    scanf("%d", &x);  /*  输入第一个数据元素 */
    while (x != -111) /*  输入-111，结束循环 */
    {
        s = (LNode *)malloc(sizeof(LNode)); /*  分配新结点 */
        s->data = x;
        s->next = NULL;
        p->next = s;
        p = s;
        printf("data=?( -111 end) ");
        scanf("%d", &x); /* 输入下一个数据*/
    }
    return (h);
}
/* 输出单链表中的数据元素*/
void out_L(LNode *L)
{
    LNode *p;
    char ch;
    p = L->next;
    printf("\n\n");
    while (p != NULL)
    {
        printf("%5d", p->data);
        p = p->next;
    };
  printf("\n\n 打回车键，继续。"); ch=getch(); 
} /* out_link */
/*  在i位置插入元素e  */

void insert_L(LNode *L, int i, ElemType e)
{
    LNode *s, *p, *q;
    int j;
    p = L; /* 找第i-1个结点  */
    j = 0;
    while (p != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (p == NULL || j > i - 1)
        printf("\n i ERROR !");
    else
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = e;
        s->next = p->next;
        p->next = s;
    }
}
ElemType delete_L(LNode *L, int i)
{
    LNode *p, *q;
    int j;
    ElemType x;
    p = L;
    j = 0;
    while (p->next != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (p->next == NULL)
    {
        printf("\n i ERROR !");
        return (-1);
    }
    else
    {
        q = p->next;
        x = q->data;
        p->next = q->next;
        free(q);
        return (x);
    }
} /* delete_L */
/*  查找值为 e 的元素, 返回它的位置  */
int locat_L(LNode *L, ElemType e)
{
    LNode *p;
    int j = 1;
    p = L->next;
    while (p != NULL && p->data != e)
    {
        p = p->next;
        j++;
    }
    if (p != NULL)
        return (j);
    else
        return (-1);
} /* locat_L */
