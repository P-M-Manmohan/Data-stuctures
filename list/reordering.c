#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};
typedef struct node* NODE;

NODE head,head2;


NODE createNode()
{
	NODE newNode;
	newNode=(NODE)malloc(sizeof(struct node));
	newNode->next=NULL;
	return newNode;
}

void display(NODE h)
{
	NODE temp;
	if(h==NULL)
	{
		printf("list is empty\n");
		return;
	}
	temp=h;
	
	printf("The elements in the list are : ");
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}


void insert(int x)
{
	NODE temp,newNode;
	newNode=createNode();
	newNode->data=x;
    if(head==NULL)
    {
        head=newNode;
        return;
    }
	temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=newNode;
	return;
}


void rev(NODE h)
{
    NODE temp,next,prev;
    temp=h;
    prev=NULL;
    while(temp!=NULL)
    {
        next=temp->next;
        temp->next=prev;
        prev=temp;
        temp=next;
    }
    head=prev;
	display(h);
}

void reorder()
{
	NODE temp1,next1,temp2,next2,slow,fast;
	slow=head;
	fast=head->next;
	while(fast!=NULL&&fast->next!=NULL)
	{
		slow=slow->next;
		fast=fast->next->next;
	}
	head2=slow->next;
	slow->next=NULL;
	display(head2);
	rev(head2);
	display(head2);
	temp1=head;
	next1=temp1->next;
	temp2=head2;
	next2=temp2->next;
	while(temp2!=NULL||temp1==NULL)
	{
		temp1->next=temp2;
		temp2->next=next1;
		temp1=next1;
		temp2=next2;
	}	
}

int main()
{
    int o,x;
    head=NULL;
	head2=NULL;
	while(1)
	{
	    printf("enter the operation to be done\n");
   		scanf("%d",&o);
   		switch(o)
    	{
        	case 1:
				printf("enter the element : \n");
				scanf("%d",&x);
            	insert(x);
				break;
			case 2:
				reorder(head);
				break;
			case 3:
				display(head);
				break;
			case 5: 
				rev(head);
				break;
			case 4:
				exit(0);
    	}
	}
}