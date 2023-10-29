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
    temp->data=x;
    temp->right=temp->left=NULL;
    return temp;
}
node insert(int x,node root)
{
    if(root==NULL)
    {
        root=createNode(x);
        return root;
    }
    else if(x>root->data)
    {
        root->right=insert(x,root->right);
    }
    else if(x<root->data)
    {
        root->left=insert(x,root->left);
    }
    else
    {
        printf("element already exists in the tree.\n");
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

node findMin(node root)
{
    if(root==NULL)
    {
        return NULL;
    }
    else if(root->left==NULL)
    {
        return root;
    }
    else
    {
        return findMin(root->left);
    }
}

node findMax(node root)
{
    if(root==NULL)
    {
        return NULL;
    }
    else if(root->right==NULL)
    {
        return root;
    }
    else
    {
        return findMax(root->right);
    }
}

node find(int x,node root)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(x<root->data)
    {
        return(find(x,root->left));
    }
    else if(x>root->data)
    {
        return(find(x,root->right));
    }
    else if(x==root->data)
    {
    return root;
    }
    else
    {
        return NULL;
    }
}
node makeEmpty(node root)
{
    if(root!=NULL)
    {
        makeEmpty(root->left);
        makeEmpty(root->right);
        free(root);
    }
    return NULL;
}

node delete(int x,node root)
{
    node temp=NULL;
    if(root==NULL)
    {   
        printf("Element not found.\n");
        return root;
    }
    else if(x<root->data)
    {
        root->left=delete(x,root->left);
    }
    else if(x>root->data)
    {
        root->right=delete(x,root->right);
    }

    else if(root->right!=NULL&&root->left!=NULL)
    {
        temp=findMin(root->right);
        printf("%d",temp->data);
        root->data=temp->data;
        root->right=delete(temp->data,root->right);
    }
    else
    {
        temp=root;
        if(root->left==NULL)
        {
            root=root->right;
        }
        else if (root->right==NULL)
        {
            root=root->left;
        }
        free(temp);
    }
    return root;
}

int main()
{
    node root=NULL;
    node min,max;
    int o,x;
    while(1)
    {
        printf("enter the operation to be done: \n1-insert \n2-inorder\n3-preorder\n4-postorder\n5-minimum\n6-maximum\n7-find\n8-delete\n9-Makeempty\n10-exit\n");
        scanf("%d",&o);
        switch(o)
        {
            case 1:
                printf("enter the data to be entered: ");
                scanf("%d",&x);
                root=insert(x,root);
                break;
            case 2:
                if(root==NULL)
                {
                    printf("BST is empty.\n");
                    break;
                }
                printf("The elements in the BST(inorder) are: ");
                inorder(root);
                printf("\n");
                break;
            case 3:
                if(root==NULL)
                {
                    printf("BST is empty.\n");
                    break;
                }
                printf("The elements in the BST(preorder) are: ");
                preorder(root);
                printf("\n");
                break;
            case 4:
                if(root==NULL)
                {
                    printf("BST is empty.\n");
                    break;
                }
                printf("The elements in the BST(postorder) are: ");
                postorder(root);
                printf("\n");
                break;
            case 5:
                min=findMin(root);
                printf("Minimum value in BST is %d\n",min->data);
                break;
            case 6:
                max=findMax(root);
                printf("Maximum value in BST is %d\n",max->data);
                break;
            case 7:
                printf("enter the element to be entered : ");
                scanf("%d",&x);
                if(find(x,root)==NULL)
                {
                    printf("element not found.\n");
                }
                else
                {
                    printf("element found.\n");
                }
                break;
            case 8:
                printf("enter the element to be deleted: ");
                scanf("%d",&x);
                root=delete(x,root);
                break;
            case 9:
                root=makeEmpty(root);
                printf("BST deleted.\n");
                break;
            case 10:
                exit(0);
        }
    }
}