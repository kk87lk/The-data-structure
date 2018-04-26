#include <stdio.h>
#include <stdlib.h>
typedef char Elemtype;
#define Maxsize 100
typedef struct Tree Tree;
struct Tree{
    Elemtype data;
    Tree *left,*right;
};
Tree* PreBuildTree(){
    Elemtype x;
    scanf("%c", &x);
    Tree *Node;
    if(x==' '){
        Node = NULL;
    }else{
        Node = (Tree *)malloc(sizeof(Tree));
        Node->data = x;
        Node->left = PreBuildTree();
        Node->right = PreBuildTree();
    }
    return Node;
}
void PreTree(Tree* ROOT){
    if(ROOT==NULL){
        return;
    }else{
        printf("%c", ROOT->data);
        PreTree(ROOT->left);
        PreTree(ROOT->right);
    }
}
void InTree(Tree *ROOT)
{
    if (ROOT == NULL)
    {
        return;
    }else{
        InTree(ROOT->left);
        printf("%c", ROOT->data);
        InTree(ROOT->right);
    }
}
void AfterTree(Tree *ROOT)
{
    if (ROOT == NULL)
    {
        return;
    }else{
        AfterTree(ROOT->left);
        AfterTree(ROOT->right);
        printf("%c", ROOT->data);
    }
}
int main(){
    // Tree *root = (Tree *)malloc(sizeof(Tree));
    // root->data = 'A';
    // Tree *left = (Tree *)malloc(sizeof(Tree));
    // left->data = 'B';
    // root->left = left;
    // Tree *right = (Tree *)malloc(sizeof(Tree));
    // right->data = 'C';
    // right->left = right->right = NULL;
    // root->right = right;
    // left->left = (Tree *)malloc(sizeof(Tree));
    // left->left->data = 'D';
    // left->left->left =left->left->right= NULL;
    // left->right = (Tree *)malloc(sizeof(Tree));
    // left->right->data = 'F';
    // left->right->left = left->right->right = NULL;
    Tree *root = PreBuildTree();
    PreTree(root);
    printf("\n");
    InTree(root);
    printf("\n");
    AfterTree(root);
}