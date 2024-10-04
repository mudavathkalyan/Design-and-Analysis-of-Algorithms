//optimal binary search tree
#include <stdio.h>
#include <limits.h>

int k[] = {1, 2, 3};  // Keys
int f[] = {8, 2, 4};  // Frequencies
int n = sizeof(k) / sizeof(k[0]);  // Number of keys

// Function to calculate the sum of frequencies from index i to j
int sum(int freq[], int i, int j)
{
    int s = 0;
    for (int k = i; k <= j; k++) 
    {
        s += freq[k];
    }
    return s;
}

// Recursive function to find the minimum cost of an optimal binary search tree
int obst(int i, int j) 
{
    //0,n-1
    // Base case: no elements in this range
    if (i > j) 
    {
        return 0;
    }
    // Base case: one element
    if (i == j) 
    {
        return f[i];
    }
    
    int min = INT_MAX;  // Initialize minimum cost as maximum possible value
    int val;

    // Try making each key in the range [i, j] the root and calculate the cost
    for (int k = i; k <= j; k++)
     {
        val = obst(i, k - 1) + obst(k + 1, j) + sum(f, i, j);
        if (val < min) 
        {
            min = val;
        }
    }

    return min;
}

int main() 
{
    int res = obst(0, n - 1);
    printf("MIN = %d\n", res);
    return 0;
}
