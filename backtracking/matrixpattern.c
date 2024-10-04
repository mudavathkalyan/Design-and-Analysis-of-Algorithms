#include<stdio.h>
int main()
{
	int n;
	printf("Enter n:");
	scanf("%d",&n);
	int a[n][n];
	int c=1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i;j++)
		{
			int k=i+j;
			a[j][k]=c++;
		}
	}
	//printing...
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i<=j)
			{
				printf("%2d  ",a[i][j]);
			}
			else 
				printf("    ");
		}
		printf("\n");
	}
}
