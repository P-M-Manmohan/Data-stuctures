#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int top=0;
char stack[20];

void push(char term)
{
    if(top==19)
    {
        printf("stack overflow\n cannot compute");
        exit(0);
    }
    top++;
    stack[top]=term;
}

char pop()
{
    char x;
    if(top==-1)
    {
        exit(0);
    }
    x=stack[top];
    top--;
    return x;
}

int CheckIfOperand(char ch)
{
    if((ch>='a' && ch<='z')||(ch>='A' && ch<='Z'))
    return 1;
}

int priority(char o)
{
    if(o=='(')
    return 0;
    if(o=='+'||o=='-')
    return 1;
    if(o=='*'||o=='/')
    return 3;
    if(o=='^')
    return 4;
}


int main()
{
    char exp[20];
    char x,fin[20];
    int i,j=0,len;
    printf("Enter the expression:\n");
    gets(exp);
    len=strlen(exp);
    for(i=0;i<len;i++)
    {
        if (CheckIfOperand(exp[i])==1)
        {
            fin[j]=exp[i];
            j++;
            continue;
        }
        else if(exp[i]=='(')
        { 
            push(exp[i]);
            continue;
        }
        else if(exp[i]==')')
        {
            while(stack[top]!='(')
            {
                x=pop();
                fin[j]=x;
                j++;
            }
            pop();
            continue;
        }

        while(priority(stack[top])>=priority(exp[i]))
        {
            
            x=pop();
            fin[j]=x;
            j++;
            
        }
        if(top==-1||(priority(stack[top])<=priority(exp[i])))
        {
            push(exp[i]);
            continue;
        }    
    }
    while(top!=-1)
    {
        x=pop();
        if(x!='(')
        {
            fin[j]=x;
            j++;
        }
    }
    for(i=0;i<j;i++)
    printf("%c",fin[i]);
}