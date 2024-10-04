#include<stdio.h>
int fib(int);
#define size 10
int a[size];
int main()
{
    printf("Enter a number:");
    int n;
    scanf("%d",&n);
    for(int i=0;i<10;i++)
        a[i]=-1;
    //initially setting a elements as -1;
    printf("%d",fib(n));
    return 0;
}

int fib(int n)
{
    if(a[n]!=-1)
        return a[n];
    if(n==0 || n==1)
        return a[n]=1;
    else
        return a[n]=fib(n-1)+fib(n-2);
}
