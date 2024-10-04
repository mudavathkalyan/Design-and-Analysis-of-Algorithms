#include<stdio.h>
int a[10];
int fib(int );
int main()
{
    int n;
     printf("Enter a number:");
    scanf("%d",&n);
    fib(n);
    return 0;
}
int fib(int n)
{
    for(int i=0;i<=n;i++)
    {
        if(i==0 || i==1)
            a[i]=1;
        else
        a[i]=a[i-1]+a[i-2];
    }
    printf("%d",a[n]);
    return 0;
}
