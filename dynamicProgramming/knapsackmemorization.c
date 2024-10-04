#include<stdio.h>
int weight[20], value[20];
int capacity, n;
int memory[21][21]; // Increasing the size of memory array
int knapsack(int n, int capacity); // Function prototype

int max(int a, int b)
{
    return a > b ? a : b;
}

int main() 
{
    printf("Enter size:");
    scanf("%d", &n);
    
    printf("Enter the weights:");
    for(int i = 0; i < n; i++)
        scanf("%d", &weight[i]);

    printf("Enter value of weights:");
    for(int i = 0; i < n; i++)
        scanf("%d", &value[i]);

    printf("Enter capacity:");
    scanf("%d", &capacity); // Adding capacity input
    
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= capacity; j++)
            memory[i][j] = -1;
    }

    printf("max value=%d", knapsack(n, capacity)); // Calling the knapsack function
    return 0;
}

int knapsack(int n, int capacity) 
{
    if(memory[n][capacity] != -1)
        return memory[n][capacity];
    if(n == 0 || capacity == 0)
        return memory[n][capacity]=0;

    if(weight[n - 1] <= capacity)
        return memory[n][capacity]=max(value[n-1]+knapsack(n-1,capacity-weight[n-1]),knapsack(n-1,capacity));
        //  return memory[n][capacity]=max(value[n-1]+knapsack(n,capacity-weight[n-1]),knapsack(n-1,capacity));//for repitation
    else
        return memory[n][capacity]=knapsack(n-1,capacity);        
}
