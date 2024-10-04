#include <stdio.h>
#include <limits.h>

int min(int a, int b) {
    return a > b ? b : a;
}
int array[30];
int subset(int n, int sum);

int main() {
    int size=4, sum;
    // printf("Enter size: ");
    // scanf("%d", &size);
    printf("Enter elements: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
    printf("Enter required sum: ");
    scanf("%d", &sum);
    int result = subset(size, sum);
    
    if (result == INT_MAX - 1000) 
    {
        printf("No valid subset found.\n");
    } else 
    {
        printf("Minimum number of elements needed = %d\n", result);
    }
    return 0;
}

int subset(int n, int sum) {
    int dp[n+1][sum+1];
    
    // Initialize the dp array
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
            if (j == 0) {
                dp[i][j] = 0; // Zero sum can always be achieved with 0 elements
            } else if (i == 0) {
                dp[i][j] = INT_MAX - 1000; // If no elements, no positive sum can be achieved
            } else if (array[i - 1] <= j) {
                dp[i][j] = min(1 + dp[i][j - array[i - 1]], dp[i - 1][j]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][sum];
}

