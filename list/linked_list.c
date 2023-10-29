#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};
typedef struct node* NODE;

NODE head;

NODE createNode()
{
	NODE newNode;
	newNode=(NODE)malloc(sizeof(struct node));
	newNode->next=NULL;
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

void front(int x)
{
	NODE newNode;
	newNode=createNode();
	newNode->data=x;
	newNode->next=head;
	head=newNode;
	return;
}

void end(int x)
{
	NODE temp,newNode;
	newNode=createNode();
	temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=newNode;
	newNode->data=x;
	return;
	
}
void between(int x)
{
	NODE temp,newNode;
	int i,pos;
	printf("enter the postion where data must be entered\n");
	scanf("%d",&pos);
	if((pos>(length( )+1))||pos<1)
	{
		printf("Such postion does not exist in the SLL\n");
		return;
		
	}
	if(pos==1)
	{
		front(x);
		return;
	}
	if(pos==(length()+1))
	{
		end(x);
		return;
	}
	temp=head;
	for(i=1;i<pos-1;i++)
	{
		temp=temp->next;
	}
	newNode=createNode();
	newNode->data=x;
	newNode->next=temp->next;
	temp->next=newNode;
	return;
}

void Insert(int x)
{
	NODE newNode;
	int o,pos;
		if(head==NULL)
	{
		newNode=createNode();
		newNode->data=x;
		head=newNode;
		return;
	}
	printf("which postion should the data be entered\n1-front\n2-inbetween\n3-end\n");
	scanf("%d",&o);
	switch(o)
	{
		case 1:
			front(x);
			break;
		case 2:
			between(x);
			break;
		case 3:
			end(x);
			break;
		default:
			printf("invalid entry");
			return;
	}
	return;
}

void display( )
{
	NODE temp;
	if(head==NULL)
	{
		printf("list is empty\n");
		return;
	}
	temp=head;
	
	printf("The elements in the list are : ");
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

void delete()
{
	NODE prev,temp;
	int i,pos;
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
	free(temp);
} 

void rev()
{
	NODE prev,next,temp;
	if(head==NULL||length()==1)
	{
		if(length()==1)
		{
			return;
		}
		printf("The list is empty\n");
		return;
	}
	if(length()<3)
	{
		temp=head;
		next=temp->next;
		next->next=temp;
		temp->next=NULL;
		head=next;
		return;
	}
	prev=head;
	temp=prev->next;
	next=temp->next;
	while(1)
	{
		temp->next=prev;
		if(next->next==NULL)
		{
			next->next=temp;
			head->next=NULL;
			head=next;
			return;
		}
		prev=temp;
		temp=next;
		next=next->next;
	}
}
int main()
{
	NODE temp,NewNode;
	int i,x;
	head=NULL;
	do
	{
		printf("enter the operation to be done\n1-newNode\n2-display\n3-length\n4-delete\n5-reverse the list\n6-exit\n");
		scanf("%d",&i);
		switch(i)
		{
			case 1:
				printf("enter the data to be entered\n");
				scanf("%d",&x);
				Insert(x);
				break;
			case 2:
				display();
				break;
			case 3:
				printf("length of list : %d\n",length());
				break;
			case 4:
				delete();
				break;
			case 6:
				exit(0);
			case 5:
				rev();
				printf("successfully reveresed\n");
				display();
				break;
			default:
				printf("invalid entry\n");
				break;
		}
	}while(1);
}