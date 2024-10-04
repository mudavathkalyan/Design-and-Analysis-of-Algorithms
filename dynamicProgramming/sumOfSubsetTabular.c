
//dp with tabulation...
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
    subsetsum(size,sum);
}
int subsetsum(int n,int sum)
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
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
    printf("max ways=%d",memory[n][sum]);
    printf("\nTabulation is:\n");
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            printf("%2d ",memory[i][j]);
        }
        printf("\n");
    }


}