#include<stdio.h>
int a[15];
void permut();
void print();
int n; 
int isSafe(int pos,int i)
{
    for(int j=0;j<pos;j++)
    {
        if(a[j]==i)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    printf("Enter n:");
    scanf("%d",&n);
    permut(n,0);
    return 0;
}
void permut(int n,int pos)
{
    if(pos==n)
    {
        print(a,n);//no need to pass a
        return;
    }
    for(int i=0;i<n;i++)
    {
       if(isSafe(pos,i))
       {
         a[pos]=i;
         permut(n,pos+1); 
       }
    }
}
void print(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}   
