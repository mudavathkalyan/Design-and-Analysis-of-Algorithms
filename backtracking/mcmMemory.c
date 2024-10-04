#include <stdio.h>
#include <limits.h>

int a[22];
int m[22][22];

int mcm(int i, int j)
{
 if (m[i][j] != -1)
    {
        return m[i][j];
    } 
    else if (i == j)
    {
        return m[i][j] = 0;
    } 
    else
    {
     int val, min = INT_MAX;
        for (int k = i; k < j; k++)
        {
            val = mcm(i, k) + mcm(k + 1, j) + a[i - 1] * a[k] * a[j];
            if (val < min)
            {
                min = val;
            }
        }
        return m[i][j] = min;
    }
}

int main()
{
 int n;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter values: ");
    for (int i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (int i=0; i<22; i++)
    {
        for (int j = 0; j < 22; j++)
        {
            m[i][j] = -1;
        }
    }

    printf("Min scalar product value = %d\n", mcm(1, n - 1));
    return 0;
}
