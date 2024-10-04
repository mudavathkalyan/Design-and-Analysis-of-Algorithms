#include <stdio.h>
#include <limits.h>

int keys[] = {1, 2, 3};  // Keys
int freq[] = {8, 2, 4};  // Frequencies
int n = 3;               // Number of keys
int a[22][22];           // Table to store the cost of optimal BST

// Function to calculate the sum of frequencies from index i to j
int sum(int k, int j) 
{
    int s = 0;
    for (int i = k; i <= j; i++) {
        s += freq[i];
    }
    return s;
}

// Function to find the minimum cost of an optimal binary search tree using dynamic programming
void optimal(int low, int n)
 { //0,n
    // Initialize the cost for single keys
    for (int i = 0; i < n; i++) {
        a[i][i] = freq[i];
    }

    // Fill the cost table in a bottom-up manner
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            int k = i + j;
            int min = INT_MAX;
            for (int l = j; l <= k; l++) {
                if (j == k) {
                    a[j][k] = freq[j];
                    continue;
                }
    int d = ((l > j) ? a[j][l - 1] : 0) + ((l < k) ? a[l + 1][k] : 0) + sum(j, k);
                if (d < min) {
                    min = d;
                }
            }
            a[j][k] = min;
        }
    }

    // Print the table
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    // Print the minimum cost of the optimal BST
    printf("Min = %d\n", a[0][n - 1]);
}

int main() {
    optimal(0, n);
    return 0;
}
