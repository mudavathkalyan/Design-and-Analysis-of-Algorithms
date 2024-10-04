#include<stdio.h>
#include<stdlib.h>

int partition(int n, int sum, int a[]);
int t[10][10]; // global declaration

int main() 
{
    int a[] = {1,2,5};
    int n = 3;
    int sum = 0;
    for (int i = 0; i < n; i++) 
    {
        sum += a[i];
    }
    if (sum % 2 != 0)
    {
        printf("No equal sum partition\n");
    } 
    else 
    {
        printf("Sum partition possible\n");
        int value = partition(n, sum / 2, a);
        if (value)
        {
            printf("Subset sum exists\n");
        } 
        else 
        {
            printf("Subset sum does not exist\n");
        }
    }
    return 0;
}

int partition(int n, int sum, int a[])
 {
    for (int i = 0; i <= n; i++) 
    {
        for (int j = 0; j <= sum; j++) 
        {
            if (j == 0) 
            {
                t[i][j] = 1;
            }
            if (i == 0) 
            {
                t[i][j] = 0;
            } 
            else if (a[i - 1] <= j) 
            {
                t[i][j] = t[i - 1][j - a[i - 1]] || t[i - 1][j];
            } 
            else 
            {
           t[i][j]=t[i - 1][j];
            }
        }

    }
     printf("\nTabulation is:\n");
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            printf("%2d ",t[i][j]);
        }
        printf("\n");
    }




    return t[n][sum];
}
