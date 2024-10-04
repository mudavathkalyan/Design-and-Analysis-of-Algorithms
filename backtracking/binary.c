#include<stdio.h>
int a[5];
void permut();
void print();
int n; 
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
        print(a,n);
        return;
    }
    for(int i=0;i<2;i++)
    {
        a[pos]=i;
        permut(n,pos+1);
       // printf("\npos=%d\n",pos);
        
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