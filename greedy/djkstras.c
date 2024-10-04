//Easy
#include<stdio.h>
#include<limits.h>
void djk(int n,int graph[n][n],int visited[],int cost[],int p[])
{
    int len=n;
    int index=0;
    while (len>0)
    {
        int min=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(visited[i]==-1)
            {
                if(cost[i]<min)
                {
                    min=cost[i];
                    index=i;
                }
            }
        }
        visited[index]=1;
        for (int j = 0; j < n; j++)
        {
            if (graph[index][j] != 0 && cost[j] >  cost[index] + graph[index][j]) 
            {
                cost[j] = cost[index] + graph[index][j];
                p[j] = index;
            }
        }

        len--;
    }
    printf("\nEdge & min cost are:\n");
     for (int i = 0; i < n; i++)
    {
        printf("%d-%d :\t%d\n ",0,i, cost[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter n vertices::");
    scanf("%d",&n);

    int graph[n][n];

    printf("Enter the vertices:");
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(i!=j)
            {
                printf("Enter the (%d,%d) weight:",i,j);
                int t;
                scanf("%d",&t);
                graph[i][j]=t;
                graph[j][i]=t; // since undirected graph
            }
            else
            {
                graph[i][j]=0;
            }
        }
    }

    int visited[n];
    int p[n];
    int cost[n];
  

    for(int i=0;i<n;i++)
    {
        cost[i]=INT_MAX;
        visited[i]=-1;
    }
    cost[0]=0;


    djk(n,graph,visited,cost,p);

}