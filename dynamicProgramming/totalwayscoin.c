//returning no of ways of subset  of given sum

#include<stdio.h>
int array[30];
int subsetsum();
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
    printf("no of subset for sum=%d",subsetsum(size,sum));
}
int subsetsum(int n,int sum)
{
    if(sum==0)    return 1;
    if(n==0)    return 0;

    else if(array[n-1]<=sum)
            return  subsetsum(n,sum-array[n-1])+subsetsum(n-1,sum);
    else
        return subsetsum(n-1,sum);
}