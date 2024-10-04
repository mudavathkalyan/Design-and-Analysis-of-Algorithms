#include<stdio.h>



int stair(int n)
{
    if(n==0 ||n==1)
    {
        return 1;
    }
    else
    {
        return stair(n-1)+stair(n-2);
    }
}
int main()
{

    printf("Enter no of steps:");
    int n;
    scanf("%d",&n);
    printf(" no of ways=%d",stair(n));
    return 0;
}
