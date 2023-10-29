#include<stdio.h>
#include<stdlib.h>

int array[10];

void insert(char x)
{
    int hash;
    hash = x % 10;
    while(array[hash]!=-99)
    {
        if(x==array[hash])
        {
            printf("element already exists.\n");
            return;
        }
        hash=(hash+1)%10;
            }
    array[hash]=x;
    return;
}


void search(int x)
{
    int check=0,i,hash;
    hash= x % 10;
    for(i=0;i<10;i++)
    {
        if(x==array[hash])
        {
        check=1;
        break;
        }
        hash=(hash+1)%10;
    }
    if(check==1)
    {
        printf("element found in %d position\n",hash);
    }
    else{
        printf("element not found.\n");
    }
}

int main()
{
    int i,o,y,x;
    for(i=0;i<10;i++)
    {
        array[i]=-99;
    }

    while(1)
    {
        printf("enter the operation to be done\n1-insert\n2-search\n3-exit\n");
        scanf("%d",&o);
        switch(o)
        {
            case 1:
                printf("enter the element to be inserted.\n");
                scanf("%d",&x);
                insert(x);

                break;
            case 2:
                printf("entre the element to be searched.\n");
                scanf("%d",&x);
                search(x);
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("invalid entry.\n");
        }
    }
}