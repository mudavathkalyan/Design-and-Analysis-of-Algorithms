#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
bool isSafe();
void nqueen();
void print();
int a[10];
int main()
{
    int n;
    printf("Ente n :");
    scanf("%d",&n);
    nqueen(n,0);
}
void nqueen(int n, int pos)
{
    if(pos==n)
    {
        print(a,n);
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(isSafe(pos,i))
        {
            a[pos]=i;
            nqueen(n,pos+1);
        }
    }
}
bool isSafe(int pos ,int i)
{
    for(int j=0;j<pos;j++)
    {
        if(a[j]==i)
        {
            return false;
        }
        else if(abs(pos-j)==abs(i-a[j]))
            return false;
    }
    return true;
}
void print(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}
