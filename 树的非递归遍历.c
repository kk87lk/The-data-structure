#include <stdio.h>
#include <stdlib.h>
typedef char Elemtype;
#define Maxsize 100
typedef struct Tree Tree;
typedef struct sNode{
    Tree* Data[Maxsize];
    int top;
} Stack;
struct Tree
{
    Elemtype data;
    Tree *left, *right;
    int flag;
};
typedef struct queue{
    Tree *Data[Maxsize];
    int front, rear;
} Queue;
int isemptyQueue(Queue* Q){
    return (Q->front == Q->rear);
}
void InsertQueue(Queue* Q,Tree* root){
    Q->Data[Q->rear] = root;
    Q->rear=(Q->rear + 1) % Maxsize;
}
Tree* Delete(Queue* Q){
    Tree* T;
    T = Q->Data[Q->front];
    Q->front = (Q->front + 1) % Maxsize;
    return T;
}
Queue* CreateQueue(){
    Queue *Q = (Queue *)malloc(sizeof(Queue));
    Q->front = Q->rear = 0;
    return Q;
}
Tree *PreBuildTree()
{
    Elemtype x;
    scanf("%c", &x);
    Tree *Node;
    if (x == ' ')
    {
        Node = NULL;
    }
    else
    {
        Node = (Tree *)malloc(sizeof(Tree));
        Node->data = x;
        Node->flag = 0;
        Node->left = PreBuildTree();
        Node->right = PreBuildTree();
    }
    return Node;
}
int push(Stack* S,Tree* root){
    S->Data[++(S->top)] = root;
    return 1;
}
Tree* pop(Stack* S){
    return S->Data[S->top--];
}
Stack* Create(){
    Stack *S = (Stack *)malloc(sizeof(Stack));
    S->top = -1;
    return S;
}
int isempty(Stack* S){
    return (S->top == -1);
}
void InorderTree(Tree* root){
    Tree *T = root;
    Stack *S = Create();
    while (T||!isempty(S))
    {
        while (T)
        {
            push(S, T);
            T = T->left;
        }
        if(!isempty(S)){
            T = pop(S);
            printf("%c", T->data);
            T = T->right;
        }
    }
}
void PreorderTree(Tree *root)
{
    Tree *T = root;
    Stack *S = Create();
    while (T || !isempty(S))
    {
        while (T)
        {
            push(S, T);
            printf("%c", T->data);
            T = T->left;
        }
        if (!isempty(S))
        {
            T = pop(S);
            T = T->right;
        }
    }
}
void AfterorderTree(Tree* root){
    Tree *T = root;
    Stack *S = Create();
    while (T||!isempty(S))
    {	
        while (T&&T->flag==0)
        {
            push(S, T);
            T->flag++;
            T = T->left;
        }
        if(!isempty(S)){
            T = pop(S);
            if(T->right&&T->right->flag==0){
                push(S, T);
            }else{
                printf("%c", T->data);
            }
            T = T->right;
        }else{
        	return;
		}
    }
}
void LineOrder(Tree* root){
    Queue *Q = CreateQueue();
    Tree *T;
    if(!root) return;
    InsertQueue(Q, root);
    while (!isemptyQueue(Q))
    {
        T = Delete(Q);
        printf("%c", T->data);
        if(T->left) InsertQueue(Q,T->left);
        if(T->right) InsertQueue(Q,T->right);
    }
}
int main(){
    Tree *root = PreBuildTree();
    printf("In order:");
    InorderTree(root);
    printf("\nPre order:");
    PreorderTree(root);
    printf("\nAfter order:");
    AfterorderTree(root);
    printf("\nLine order:");
    LineOrder(root);
    return 0;
}
