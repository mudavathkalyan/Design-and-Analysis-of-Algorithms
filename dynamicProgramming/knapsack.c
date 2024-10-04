#include<stdio.h>
#include<stdio.h> 
int size;
int weight[10];
int value[10];
int capacity;
int knapsack();
int max(int a,int b)
{
    return a>b?a:b;
}
int main()
{
    printf("Enter size:");
    scanf("%d",&size);
    printf("Enter the weights:");
    for(int i=0;i<size;i++)
        scanf("%d",&weight[i]);
    printf("Enter value of weights:");
    for(int i=0;i<size;i++)
        scanf("%d",&value[i]);
    printf("Enter capacity:");
        scanf("%d",&capacity);

    printf("maxvalue=%d",knapsack(size,capacity));
    return 0;
}
int knapsack(int n ,int w)
{
    if(n==0 || w==0)
        return 0;
    else if(weight[n-1]<=w)
    {
        return max(value[n-1]+knapsack(n-1,w-weight[n-1]),knapsack(n-1,w));
    }
    else
        knapsack(n-1,w);
}