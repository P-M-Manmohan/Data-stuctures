#include<stdio.h>
#include<stdlib.h>
#define max 5
int front  = -1;
int rear = -1;
int queue[max];

void dequeue()
{
    if(front == -1)
    {
        printf("queue overflow\n");
        return;
    }
    printf("deleted element =%d\n",queue[front]);
    if(front==rear)
    {
        front=rear=-1;
        return;   
    }
    front=(front+1)%max;
}

void enqueue(int x)
{
    if(front ==(rear+1)%max)
    {
        printf("queue overflow\n");
        return;
    }
    printf("successfully pushed\n");
    if(front==-1)
    {
        front=0;
    }
    rear=(rear+1)%max;
    queue[rear]=x;
}

void display()
{
    int i;
    if(rear==-1)
    {
        printf("queue empty\n");
        return;
    }
    printf("elements in the queue are : ");
    for(i=front;i!=rear;i=(i+1)%max)
    {
        printf("%d",queue[i]);
    }
    printf("%d \n",queue[rear]);
}

void size()
{
    int j=1,i;
    if(rear==-1)
    {
        printf("queue is empty\n");
        return;
    }
    for(i=front;i!=rear;i=(i+1)%max)
    {
        j=(j+1)%max;
    }
    printf("size of the queue is : %d\n",j);
}

void isEmpty()
{
    if(rear==-1)
    {
        printf("queue is empty\n");
        return;
    }
    printf("queue is not empty\n");
}

int main()
{
    int op,x;
    do
    {
        printf("1.Enqueue\n2.Dequeue\n3.Display\n,4.Is emmpty\n5.Size\n6.Exit\n");
        printf("Enter your option : ");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
                printf("enter the element : ");
                scanf("%d",&x);
                enqueue(x);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                isEmpty();
                break;
            case 5:
                size();
                break;
            case 6:
                exit(0);
        }
    } while (1);   
}