#include <stdio.h>
#include <limits.h>

int subset(int n, int sum);

int n;
int arr1[11];
int memory[11][1000]; // Adjust the size based on constraints
int arr2[1000]; // Adjust the size based on constraints

int main()
{
    printf("Enter n:");
    scanf("%d",&n);
    int sum = 0;
    printf("Enter the inputs:");
    for(int i = 0; i < n; i++) 
    {
        scanf("%d", &arr1[i]);
        sum += arr1[i];
    }
    printf("sum=%d",sum);
    printf("Min Subset Difference: %d\n", subset(n, sum));
    return 0;
}

int subset(int n, int sum)
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            if(j==0)
                memory[i][j]=1;
            else if(i==0)
            {
                memory[i][j]=0;
            }
            else if(arr1[i - 1] <= j) 
            {
                memory[i][j] = memory[i - 1][j - arr1[i - 1]] || memory[i - 1][j];
            } 
            else 
            {
                memory[i][j] = memory[i - 1][j];
            }
        }
    }
    printf("\nTabulation is:\n");
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            printf("%d ",memory[i][j]);
        }
        printf("\n");
    }

    int min = INT_MAX;
    for(int i = 0; i <= sum / 2; i++) 
    {
        if(memory[n][i] == 1) {
            min = min < (sum - 2 * i) ? min : (sum - 2 * i);
        }
    }

    return min;
}
