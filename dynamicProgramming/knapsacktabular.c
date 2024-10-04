#include<stdio.h>
int weight[20], value[20];
int capacity, n;
int knapsack(int n, int capacity); // Function prototype
int array[21][21];
int max(int a,int b)
{
    return a>b?a:b;
}
int main() 
{
    printf("Enter size:");
    scanf("%d",&n);
    
    printf("Enter the weights:");
    for(int i=0;i<n;i++)
        scanf("%d", &weight[i]);

    printf("Enter value of weights:");
    for(int i=0;i<n;i++)
        scanf("%d",&value[i]);

    printf("Enter capacity:");
    scanf("%d",&capacity); // Adding capacity input
    
    knapsack(n,capacity); // Calling the knapsack function
    return 0;
}
int knapsack(int n,int capacity)
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=capacity;j++)
        {
            if(i==0 || j==0)
                array[i][j]=0;
            
            else if(weight[i-1]<=j)
            {
                    array[i][j]=max(value[i-1]+array[i-1][j-weight[i-1]],array[i-1][j]);

                    //array[i][j]=max(value[i-1]+array[i][j-weight[i-1]],array[i-1][j]);
            }
            else
            {   
                array[i][j]=array[i-1][j];
            }
        }
    }
    printf("maxvalue=%d",array[n][capacity]);

    printf("\nTabulation is:\n");

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=capacity;j++)
        {
            printf("%2d ",array[i][j]);
        }
        printf("\n");
    }


}