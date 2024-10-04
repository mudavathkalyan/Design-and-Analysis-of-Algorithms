#include<stdio.h>
int a[22];
int mcm(int i,int j)
{   
    int min=__INT_MAX__,val;
    if(i==j)
        return 0;
    else
    {
        for(int k=i;k<j;k++)
        {
            val=mcm(i,k)+mcm(k+1,j)+a[i-1]*a[k]*a[j];
            if(val<min) 
                min=val;
        }
        return min;
    }
}
int main()
{
    int n;
    printf("Enter n:");
    scanf("%d",&n);
    printf("Enter values:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Min scalar multiple=%d",mcm(1,n-1));
}
