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
Tree* Insert(Tree* root,Elemtype x){
    if(!root){
        root = malloc(sizeof(Tree));
        root->data = x;
        root->left = root->right = NULL;
    }else{
        if(x<root->data)
            root->left = Insert(root->left, x);
        else if(x>root->data)
            root->right = Insert(root->right, x);
    }
    return root;
}
void PreTree(Tree *ROOT)
{
    if (ROOT == NULL)
    {
        return;
    }
    else
    {
        printf("%c", ROOT->data);
        PreTree(ROOT->left);
        PreTree(ROOT->right);
    }
}
Tree* Findmin(Tree* root){
    if(root->left)
    root=Findmin(root->left);
    return root;
}
Tree* Delete(Tree* root,Elemtype x){
    Tree *T;
    if(!root){
        printf("No such element!\n");
    }else{
        if(x<root->data)
            root->left = Delete(root->left, x);
        else if(x>root->data)
            root->right = Delete(root->right, x);
        else{
            if(root->left&&root->right){
                T = Findmin(root->right);
                root->data = T->data;
                root->right = Delete(root->right, root->data);
            }else{
                T = root;
                if(!root->left)
                    root = root->right;
                else
                    root = root->left;
                free(T);
            }
        }
    }
    return root;
}
int main(){
    char x;
    Tree *root = PreBuildTree();
    PreTree(root);
    printf("\n");
    printf("Input the num you want to insert:");
    fflush(stdin);
    scanf("%c", &x);
    Insert(root, x);
    printf("\n");
    PreTree(root);
    printf("\n");
    printf("Input the num you want to delete:");
    fflush(stdin);
    scanf("%c", &x);
    Delete(root, x);
    printf("\n");
    PreTree(root);
}