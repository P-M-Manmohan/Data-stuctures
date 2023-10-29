#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int queue[10];
int front=-1;
int rear=-1;


void dequeue()
{
    int x;
    if(front==-1)
    {
        printf("queue overflow.\n");
        return;
    }
    printf("deleted element = %d\n",queue[front]);
    if(front==rear)
    {
        front=rear=-1;
        return;
    }
    front++;

}



void size()
{
    if(front==rear)
    {
        printf("queue is empty.\n");
        return;
    }
    printf("queue size is %d\n",rear-front+1);
}



void isEmpty()
{
    if(front==-1)
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue is not empty.\n");
}



void enqueue(int x)
{
    if(rear==9)
    {
        printf("queue overflow");
        return;
    }
    rear++;
    queue[rear] = x;
    printf("Successfully inserted.\n");
    if(front == -1)
    {
        front++;
    }
}


void display()
{
    int i;
    if(front == -1 && rear ==-1)
    {
        printf("queue is empty\n");
        return;
    }
    printf("elememnts n the queue : ");
    for(i = front;i<=rear;i++)
    {
        printf("%d",queue[i]);
    }
    printf("\n");
}



int main()
{
    int op,x;
    do
    {
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Is Empty\n5.Size\n6.Exit\n");
        printf("Enter your option : ");
        scanf("%d ",&op);
        switch(op)
        {
            case 1:
                printf("Enter element : ");
                scanf("%d",&x);
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
    }while(1);
}