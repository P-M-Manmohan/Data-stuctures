#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node * right;
    struct node * left;
};

typedef struct node * node;


node createNode(int x)
{
    node temp;
    temp=(node)malloc(sizeof(node));
    temp->data =x;
    temp->left=temp->right=NULL;
    return temp;
}

void inorder(node T)
{
    if(T==NULL)
    {
        return;
    }
    else
    {
        inorder(T->left);
        printf("%d ",T->data);
        inorder(T->right);
    }
}

void preorder(node T)
{
    if(T==NULL)
    {
        return;
    }
    else
    {
        printf("%d ",T->data);
        preorder(T->left);
        preorder(T->right);
    }
}


void postorder(node T)
{
    if(T==NULL)
    {
        return;
    }
    else
    {
        postorder(T->left);
        postorder(T->right);
        printf("%d ",T->data);  
    }
}


int main()
{
    node root=NULL;
    int a,b,c,d,e,f,g;
    printf("insert values for the binary tree\n");
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    scanf("%d",&d);
    scanf("%d",&e);
    scanf("%d",&f);
    scanf("%d",&g);
    root=createNode(a);
    root->left=createNode(b);
    root->right=createNode(c);
    root->left->left=createNode(d);
    root->left->right=createNode(e);
    root->right->left=createNode(f);
    root->right->right=createNode(g);
    printf("Inorder traversal : ");
    inorder(root);
    printf("\nPreorder traversal: ");
    preorder(root);
    printf("\nPostorder traversal: ");
    postorder(root);
}