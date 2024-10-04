#include<stdio.h>
#include<limits.h>
int a[22];
int m[22][22];

void mcm(int low,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=n-i;j++)
        {
            int k=i+j;
            if(j==k)
            {
                m[j][k]=0;continue;
            }
            int min=INT_MAX;
            for(int l=j;l<k;l++)
            {
                int d=m[j][l]+m[l+1][k]+a[j-1]*a[l]*a[k];
                if(d<min)
                    min=d;
            }
            m[j][k]=min;

        }
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            printf("%2d  ",m[i][j]);
        }
        printf("\n");
    }
    printf("value=%d",m[1][n]);
}
int main()
{
    int n;
    printf("Enter n:");
    scanf("%d",&n);
    printf("Enter the values:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    mcm(1,n-1);
    return 0;
}