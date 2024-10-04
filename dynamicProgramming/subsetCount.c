//count no of subset with given  difference;


#include<stdio.h>
int array[30];
int memory[20][20];
int subsetsum();
int main()
{
    printf("Enter size:");
    int size;
    int sum=0;
    scanf("%d",&size);
    printf("Enter the array elements:");
    for(int i=0;i<size;i++)
    {
        scanf("%d",&array[i]);
        sum+=array[i];
    }
    printf("Enter difference:");
    int diff;
    scanf("%d",&diff);

    int temp=(diff+sum)/2;
    int check=subsetsum(size,temp);
    printf("No of Subset With Given Difference=%d",check);
}

int subsetsum(int n,int temp)
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=temp;j++)
        {
            if(j==0)
            {
               memory[i][j]=1;
            }
            else if(i==0)
            {
                memory[i][j]=0;
            }
            else if(array[i-1]<=j)
            {
                memory[i][j]=memory[i-1][j-array[i-1]]+memory[i-1][j];
            }
            else
             memory[i][j]=memory[i-1][j];
        }
    }
    return memory[n][temp];
}