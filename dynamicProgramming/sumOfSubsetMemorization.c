//dp with memorization...
#include<stdio.h>
int array[30];
int memory[30][30];
int subsetsum(int n, int sum);
int main()
{
    printf("Enter size:");
    int size;
    scanf("%d",&size);
    printf("Enter the array elements:");
    for(int i=0;i<size;i++)
        scanf("%d",&array[i]);
    printf("Enter the requires sum:");
    int sum;
    scanf("%d",&sum);

    for(int i=0;i<=size;i++)
    {
        for(int j=0;j<=sum;j++)
            memory[i][j]=-1;
    }
    printf("no of subset for sum=%d",subsetsum(size,sum));
}
int subsetsum(int n,int sum)
{
    if(memory[n][sum]!=-1)
        return memory[n][sum];
    if(sum==0)   
         return memory[n][sum]=1;
    if(n==0)   
         return memory[n][sum]=0;

    if(array[n-1]<=sum)
            return memory[n][sum]=subsetsum(n-1,sum-array[n-1])+subsetsum(n-1,sum);
    else
        return memory[n][sum]=subsetsum(n-1,sum);
}