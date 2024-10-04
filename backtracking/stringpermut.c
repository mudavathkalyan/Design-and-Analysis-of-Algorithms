#include<stdio.h>
#include<stdbool.h>
void permut();
int n;
void print();
bool issafe();
char a[10];
int main()
{
     n=3;
    permut(n,0);
    return 0;
}
void permut(int n,int pos)
{   
    if(pos==n)
    {
        print(a,n);
        return;
    }
    else
    {
       for(char i='A';i<='C';i++)
       {
        if(issafe(pos,i))
        {
            a[pos]=(char)i;
            permut(n,pos+1);
        }
       }
    }
}
bool issafe(int pos,int i)
{
    for(int j=0;j<pos;j++)
    {
        if(a[j]==i)
        {
            return false;
        }
    }
    return true;
}
void print(char a[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%c ",a[i]);
    }
    printf("\n");
}


