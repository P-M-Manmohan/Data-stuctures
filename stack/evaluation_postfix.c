#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 30

int arr[max],top=-1;

int isEmpty()
{
    if(top==-1)
    {
        return 0;
    }
    return 1;
}
void push(int x)
{
    if(top==max)
    {
        printf("Stack overflow\n");
        return;
    }
    top++;
    arr[top]=x;
}

int pop()
{
    int x;
    if(top==-1)
    {
        return 0;
    }
    x=arr[top];
    top--;
    return x;
}


void Conv(char * e)
{
    int len,i,a,b;
    len=strlen(e);
    for(i=0;i<len;i++)
    {
        if(e[i]>'0' && e[i]<'9')
        {
            int a=(int) e[i];
            a=a-48;
            push(a);
            continue;
        }
        else
        {
            int b=(int) pop();
            int a=(int) pop();

            if(e[i]=='+')
            {
            push(a+b);
            }
            else if(e[i]=='-')
            {
                push(a-b);
            }
            else if(e[i]=='*')
            {
                push(a*b);
            }
            else if(e[i]=='/')
            {
                push(a/b);
            }
            else if(e[i]=='%')
            {
                push(a%b);
            }
            else
            {
                printf("Invalid postifx expression");
                return;
            }
        }
        if(top==-1)
        {
            printf("invalid postfix expression\n");
            return;
        }
    }    
    if(top!=0)
    {
        printf("invalid expression\n");
        return;
    }
    else
    {
    printf("Result : %d\n",arr[top]);
    }
}

int main()
{
    char exp[20],*e;
    printf("enter the postfix expression : ");
    scanf("%s ",exp);
    e=exp;
    Conv(exp);
}