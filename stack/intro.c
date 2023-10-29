#include<stdio.h>
#include <stdlib.h>
#define SIZE 5

int stack_arr[SIZE],top = -1;
void push();
void pop();
void show();

int main()
{
    int choice;

    while(1)
    {
        printf("\nPerform operations on the stack:\n");
        printf("\n 1-Push element into stack\n2-Pop element ou tof stack\n3-Display the elements in the stack\n4-Exit program\n");
        printf("Enter you rchoice : \n");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            show();
            break;
        case 4:
            exit(1);
        default:
            printf("invalid choice");
        }

    }
}

void push()
{
    int x;
    if (top== SIZE-1)
    {
        printf("\n OVERFLOW");
    }
    else
    {
        printf("\nEnter the element to be added to the stack:\n");
        scanf("%d",&x);
        top=top+1;
        stack_arr[top] = x;
    }
}


void pop()
{
    if (top == -1)
    {
        printf("\n UNDERFLOW");
    }
    else
    {
        printf("element %d has been poped from the stack",stack_arr[top]);
        top=top-1;
    }
}

void show()
{
    int i;
    if (top == -1)
    {
        printf("\nUNDER FLOW");
    }
    else
    {
        printf("\nElements present in the stack are: \n");
        for(i = top; i>=0;i--)
        {
            printf("%d\n",stack_arr[i]);
        }
    }
}