#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#define MAX 10

int top=-1;
char stack[MAX];

int isFull();
int isEmpty();
void push(char);
char pop();
int priority(char);
int CheckIfOperand(char);


int main()
{
    int i;
    char x,exp[10];
    printf("enter the expression\n");
    scanf("%s",exp);
    printf("%s\n ",exp);
    while(exp[i]!='\0')
    {

        if(CheckIfOperand(exp[i])==1)
            printf("%c ",exp[i]);
        else if(exp[i]=='(')
            push(exp[i]);
        else if(exp[i]==')')
            {
                while(stack[top]!='(')
                {
                    x = pop();
                    printf("%c ",x);
                }
                pop();
            }
        else
            {
                if (priority(stack[top])>=priority(exp[i]))
                {
                    x = pop();
                    printf("%c ",x);
                    push(exp[i]);
                }
                else
                push(exp[i]);
            }
    }
}



int isFull()
{
    if(top==MAX-1)
    return 1;
    return 0;
}


int isEmpty()
{
    if(top==-1)
        return 2;
    return 3;
}

 void push(char item)
 {
    if (1==isFull())
       return;
    stack[++top]=item;
 }

 char pop()
 {
    if (2==isEmpty())
        return 0;
    return stack[top--];
 }

 int CheckIfOperand(char term)
 {
    if((term>='a' && term <='z')||(term>='A' && term<='Z'))
        return 1;
 }

int priority(char x)
{
    if (x=='(')
        return 0;
    else if (x=='+'||x=='-')
        return 1;
    else if (x=='/'||x=='*')
        return 2;
    else if (x=='^')
        return 3;
    
}


