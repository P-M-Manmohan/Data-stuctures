#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	int data;
	struct node *next;
    struct node *prev;
};
typedef struct node* NODE;

NODE head;

NODE createNode()
{
    NODE newNode;
    newNode=(NODE)malloc(sizeof(NODE));
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}

int length()
{
    int i=1;
    NODE temp;
    if(head==NULL)
    {
        return 0;
    }
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
        i++;
    }
    return i;
}

void insert()
{
    NODE newNode,temp;
    int i,pos,x;
    newNode=createNode();
    printf("enter the position for data to be entered\n");
    scanf("%d",&pos);
    printf("enter the data to be entered\n");
    scanf("%d",&x);
    if(pos<1)
    {
        printf("invalid position entered\n");
        return;
    }
    newNode->data=x;
    if(head==NULL)
    {
     head=newNode;
     printf("successfully inserted\n");
     return;   
    }
    temp=head;
    if(pos>=length()+1)
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->prev=temp;
        printf("successfully inserted\n");
        return;
    }
    if (pos==1)
    {
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
        printf("successfully inserted\n");
        return;
    }
    for(i=1;i<pos-1;i++)
    {
        temp=temp->next;
    }
    temp->next->prev=newNode;
    newNode->next=temp->next;
    temp->next=newNode;
    newNode->prev=temp;
    printf("successfully inserted\n");
    return;
}

void delete()
{
	NODE prev,temp;
	int i,pos;
    if(head==NULL)
    {
        printf("The list is empty.\n");
        return;
    }
	printf("enter the position where the element must be deleted.\n");
	scanf("%d",&pos);
	if((pos>=length()+1)||pos<1)
	{
		printf("Node does not exist in that position.\n");
		return;
	}
	temp=head;
	if(pos==1)
	{
		printf("deleted element is %d\n",head->data);
		head=head->next;
        if(head!=NULL)
        {
            head->prev=NULL;
        }
		free(temp);
		return;
	}

	if(pos==length())
	{
		for(i=2;i<pos;i++)
		{
			temp=temp->next;
		}
		printf("deleted element is %d\n",temp->next->data);
		free(temp->next);
		temp->next=NULL;
		return;
	}
	for(i=1;i<pos;i++)
	{
		prev=temp;
		temp=temp->next;
	}
	printf("The deleted element is %d\n",temp->data);
	prev->next=temp->next;
    temp->next->prev=prev;
	free(temp);
}

void display()
{
    NODE temp;
    int o;
    temp=head;
    if(head==NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("enter the direction for display \n1-head to tail\n2-tail to head\n");
    scanf("%d",&o);
    printf("The elements in the list are : ");
    switch(o)
    {
        case 1:
            while(temp!=NULL)
            {
                printf(" %d ",temp->data);
                temp=temp->next;
            }
            break;
        case 2:
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            while(temp!=NULL)
            {
                printf(" %d ",temp->data);
                temp=temp->prev;
            }
            break;
        default:
            printf("invalid entry\n");
    }
    printf("\n");
}

void rev()
{
    NODE temp,next;
    if(head==NULL||length()==1)
    {
        if(head==NULL)
        {
            printf("List is empty");
            return;
        }
        return;
    }

    if(length()<3)
    {
        head->next->next=head->next->prev;
        head->next->prev=NULL;
        head->prev=head->next;
        head->next=NULL;
        head=head->prev;
        printf("Successfully reversed\n");
        display();
        return;
    }
    temp=head->next;
	next=temp->next;
	while(1)
	{
		temp->next=temp->prev;
        temp->prev=next;
		if(next->next==NULL)
		{               
			next->next=temp;
            next->prev=NULL;
            head->prev=head->next;
			head->next=NULL;
			head=next;
            printf("Successfully reversed\n");
            display();
			return;
		}
		temp=next;
		next=next->next;
	}
}

int main()
{
    int o;
    head=NULL;
    do
    {
        printf("enter the operation to be held\n1-insertion\n2-delete\n3-display\n4-reverse list\n5-length\n6-exit\n");
        scanf("%d",&o);
        switch(o)
        {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                rev();
                break;
            case 5:
                printf("length of the list is %d\n",length());
                break;
            case 6:
                exit(0);
            default:
                printf("invalid entry\n");
                break;
        }
    }while(1);      
}