//check reverse of the sub string present in super string...

#include<stdio.h>
#include<string.h>
int fib(int n)
{
    if(n==0 || n==1)
    {
        return 1;
    }
    else 
    {
    return fib(n-1)+fib(n-2);
    }
}
int main()
{
    
  printf("fib=%d",fib(1));
}