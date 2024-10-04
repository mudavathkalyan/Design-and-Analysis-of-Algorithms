#include<stdio.h>
#include<limits.h>
int array[30];
int subset();
int min();
int main()
{
    int size,sum;
    printf("Enter size:");
    scanf("%d",&size);
    printf("Enter elements:");
    for(int i=0;i<size;i++)
    {
        scanf("%d",&array[i]);
    }
    printf("Etner required sum:");
    scanf("%d",&sum);
    printf("min=%d",subset(size,sum));
    return 0;
}
int subset(int n,int sum)
{
    if(sum==0)
        return 0;
    if(n==0)
        return INT_MAX-1000;
    else if(array[n-1]<=sum)
    {
        return min(1+subset(n,sum-array[n-1]),subset(n-1,sum));
    }
    else
      return subset(n-1,sum);
}
int min(int a,int b)
{
    return a>b?b:a;
}