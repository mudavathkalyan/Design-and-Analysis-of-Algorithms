#include <stdio.h>
#include <limits.h>
#define INF INT_MAX
int solve(int a[], int start, int end);

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter values: ");
    
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    int result = solve(arr, 1, n - 1);
    printf("min = %d", result);
    
    return 0;
}
int solve(int a[], int start, int end) 
{
    if(start >= end)
        return 0;
    int min = INF; // Initialize min to infinity   
    for(int k = start; k <= end - 1; k++) 
    {
        int temp = solve(a, start, k) + solve(a, k + 1, end) + a[start - 1] * a[k] * a[end];
        if(temp < min)
            min = temp;
    }
    return min;
}

