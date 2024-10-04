//-> 0/1 kmapsack with repitation allowed :
#include<stdio.h>
int weight[20],value[20],capicity;
int knapsack();
int max();
int main()
{
    printf("Enter size:");
    int size;
    scanf("%d",&size);

    printf("Enter weights:");
    for(int i=0;i<size;i++)
        scanf("%d",&weight[i]);

    printf("Enter values::");
    for(int i=0;i<size;i++)
        scanf("%d",&value[i]);
    printf("Enter capicity:");
        scanf("%d",&capicity);
    printf(" max value =%d",knapsack(size,capicity));
}
int max( int a,int b)
{
    return a>b?a:b;
}
int knapsack(int n,int capicity)
{
    if(n==0 || capicity==0)
        return 0;
    else if(weight[n-1]<=capicity)
    {
        return max(value[n-1]+knapsack(n,capicity-weight[n-1]),knapsack(n-1,capicity));
    }
    else return knapsack(n-1,capicity);
}
