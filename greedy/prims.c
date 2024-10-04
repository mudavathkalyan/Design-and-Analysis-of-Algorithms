//easy
#include<stdio.h>
#include<limits.h>
void prim(int n,int graph[n][n],int parent[],int visited[])
{
        int len=n;
        int v=-1;
        int u=-1;
        while (len>1)
        {
            int min=INT_MAX;
            for(int i=0;i<n;i++)
            {
                if(visited[i]==1)
                {
                    for(int j=0;j<n;j++)
                    {
                        if(graph[i][j]!=0 && visited[j]==0)
                        {
                            if(graph[i][j]<min)
                            {
                                min=graph[i][j];
                                u=i;
                                v=j;
                            }
                        }
                    }
                }
            }
            if(v!=-1)
            {
                visited[v]=1;
                parent[v]=u;
                printf("%d  %d -> %d.",u,v,graph[u][v]);
                len--;
                printf("\n");
            }
        }

        
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
    int parent[n];
    int visited[n];
    parent[0]=0;
    visited[0]=1;

    for(int i=1;i<n;i++)
    {
        parent[i]=-1;
        visited[i]=0;
    }
    printf("\nEdge & weights are:\n");
    prim(n,graph,parent,visited);

}