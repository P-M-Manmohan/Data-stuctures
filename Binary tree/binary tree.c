#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node * right;
    struct node * left;
};

typedef struct node * node;
int i;
int g=0;


node createNode(int x)
{
    node temp;
    temp=(node)malloc(sizeof(node));
    temp->data =x;
    temp->left=temp->right=NULL;
    return temp;
}

int height_node(node root)
{
    if(root==NULL)
        return -1;
    int lefth=0,righth=0;
    lefth=height_node(root->left);
    righth=height_node(root->right);
    return __max(lefth,righth)+1;
}

int balanceFac(node root)
{
    if(root==NULL)
    {
        return -1;
    }
    return (height_node(root->left)-height_node(root->right));
}

int numNodes(node root)
{
    if(root==NULL)
    {
        return 0;
    }
    else
    {
    int lefth=0,righth=0;
    lefth=height_node(root->left);
    righth=height_node(root->right);
    return lefth+righth+1;
    }
}


node insert(int x,node root)
{
    int bal;
    if(root==NULL)
    {
        root=createNode(x);
        return root;
    }
    if(root!=NULL)
    {
    i++;
    root->left=insert(x,root->left);
    }
    bal=balanceFac(root->left);
    if(bal==1)
    {
        insert(x,root->right);
    }
    else if(bal==-1)
    {
        return NULL;
    }
    return root;
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
        printf("%d\n",T->data);
        inorder(T->right);
    }
}

int main()
{
    int o,x;
    node root;                  
    root=NULL;
    while(1){
    printf("enter your option \n1-insert \n2-inorder traversal\n");
    scanf("%d",&o);
    switch(o)
    {
        case 1:
            i=0;
            printf("enter the data : ");
            scanf("%d",&x);
            root=insert(x,root);
            break;
        case 2:
            inorder(root);
            break;
        case 3:
            int h=height_node(root);
            printf("%d\n",h);
            break;
        case 4:
            int n=numNodes(root);
            printf("%d",n+1);
            break;
    }
    }
}       