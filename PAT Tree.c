#include <stdio.h>  
#include <stdlib.h>  
typedef int Tree;  
typedef char ElemType;  
struct TreeNode  
{  
    ElemType data;  
    int left;  
    int right;  
}Tree1[10], Tree2[10];  
Tree buildTree(struct TreeNode Tree[])  
{  
    int N;  
    int flag[10] = { 0 };  
    char l, r;  
    scanf("%d", &N);  
    getchar();  
    //printf("\n----------------%d--------------\n", N);  
    if (N == 0)  
        return -1;  
    for (int i = 0; i < N; i++)  
    {  
        Tree[i].data = getchar();  
        getchar();  
        l = getchar();  
        getchar();  
        r = getchar();  
        getchar();  
        //left  
        if (l != '-')  
        {  
            Tree[i].left = l - '0';  
            //printf("Left = %d\n", l - '0');  
            flag[Tree[i].left] = 1;  
        }  
        else  
            Tree[i].left = -1;  
        //right  
        if (r != '-')  
        {  
            Tree[i].right = r - '0';  
            //printf("Right = %d\n", r - '0');  
            flag[Tree[i].right] = 1;  
        }  
        else  
            Tree[i].right = -1;  
    }  
    int i = 0;  
    for (i = 0; i < N; i++)  
    {  
        //printf("\n----------%d--------------\n", i);  
        if (flag[i] == 0)  
            break;  
    }  
    return i;  
}  
Tree Isomorphic(Tree R1, Tree R2)  
{  
    if ((R1 == -1) && (R2 == -1))  
        return 1;  
    if (((R1 == -1) && (R2 != -1)) || ((R1 != -1) && (R2 == -1)))  
        return 0;  
    if (Tree1[R1].data != Tree2[R2].data)  
        return 0;  
    if ((Tree1[R1].left == -1) && (Tree2[R2].left == -1))  
        return Isomorphic(Tree1[R1].right, Tree2[R2].right);  
    if (((Tree1[R1].left != -1) && (Tree2[R2].left != -1)) &&  
        (Tree1[Tree1[R1].left].data == Tree2[Tree2[R2].left].data))  
        return Isomorphic(Tree1[R1].right, Tree2[R2].right);  
    else  
        return (Isomorphic(Tree1[R1].left, Tree2[R2].right) &&  
        Isomorphic(Tree1[R1].right, Tree2[R2].left));  
}  
int main()  
{  
    Tree T1 = -1, T2 = -1;  
    T1 = buildTree(Tree1);  
    T2 = buildTree(Tree2);  
    //printf("\n---------------%c %d %d-----------%d-------\n", Tree1[T1].data, Tree1[T1].left, Tree1[T1].right, T1);  
    //printf("\n---------------%c %d %d-----------%d-------\n", Tree2[T2].data, Tree2[T2].left, Tree2[T2].right, T2);  
    if (Isomorphic(T1, T2))  
        printf("Yes\n");  
    else  
        printf("No\n");  
    //system("pause");  
    return 0;  
}  