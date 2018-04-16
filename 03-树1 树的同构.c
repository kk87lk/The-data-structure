#include <stdio.h>
#include <stdlib.h>
#define MaxTree 10
#define ElementType char
#define Tree int
#define Null -1
struct TreeNode
{
    ElementType Element;
    Tree Left;
    Tree right;
}T1[MaxTree],T2[MaxTree];
int main(){
    Tree R1,R2;
    R1=BuildTree(T1);
    
    R2=BuildTree(T2);

    if(Isomorphic(R1,R2)){

        printf("Yes\n");

    }else {
        
        printf("No\n");
    
    }

    return 0;

}
Tree BuildTree(struct TreeNode T[]){
    int N = 0;
    int i = 0;
    char cl , cr ;
    Tree Root;
    scanf("%d", &N);
    int check[N];
    for (i = 0; i < N;i++){
        check[i] = 0;
    }
        if (N)
        {
            for (i = 0; i < N; i++)
            {
                scanf("%c%c%c\n", &T[i].Element, &cl, &cr);
                if (cl != '-')
                {
                    T[i].Left = cl - '0';
                    check[T[i].Left] = 1;
                }
                else
                    T[i].Left = Null;

                if (cr != '-')
                {
                    T[i].right = cr - '0';
                    check[T[i].right] = 1;
                }
                else
                    T[i].right = Null;
            }
            for (i = 0; i < N;i++){
                if(!check[i]) break;
            }
            Root = i;
        }
    return Root;
}
int Isomorphic(Tree R1,Tree R2){
    if((R1==Null)&&R2==Null)
        return 1;
    if(((R1==Null)&&(R2!=Null))||((R1!=Null)&&(R2==Null)))
        return 0;
    if(T1[R1].Element != T2[R2].Element)
        return 0;
    if ((T1[R1].Left == Null)&&(T2[R2].right == Null))
        return  Isomorphic(T1[R1].right, T2[R2].right);
    if(((T1[R1].Left!=Null)&&(T2[R2].Left!=Null))&&((T1[T1[R1].Left].Element)==(T2[T2[R2].Left].Element)))
        return (Isomorphic(T1[R1].Left, T2[R2].Left) && Isomorphic(T1[R1].right, T2[R2].right));
        else return(Isomorphic(T1[R1].Left,T2[R2].right)&&Isomorphic(T1[R1].right,T2[R2].Left));
}