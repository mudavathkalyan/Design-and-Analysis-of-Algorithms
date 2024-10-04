import java.util.*;
class krus
{
    public static void main(String[] args) 
    {
        int graph[][]={
            {0,10,6,5},
            {10,0,0,15},
            {6,0,0,4},
            {5,15,4,0}
        };    
        int src=0;
        kru(graph,src);
    }

    static void kru(int graph[][],int src)
    {
        int n=graph.length;
        int  parent[]=new int[n];
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
        int len=n;
        while (len>1)
        {
        int a[]=findmin(graph,parent);
        int u=a[0];
        int v=a[1];
        int loopNot=loopcheck(graph,parent,u,v);
        if(loopNot==1)
        {
            
            System.out.println("vertices="+u+","+v+" value= "+graph[u][v]); 
            len--;
        }
        graph[u][v]=0;   

       }

    }

    static int[] findmin(int graph[][],int parent[])
    {
        int n=graph.length;
        int min=Integer.MAX_VALUE;
        int a[]=new int[2];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<graph[0].length;j++)
            {
                if(graph[i][j]!=0 && graph[i][j]<min)
                {
                    min=graph[i][j];
                    a[0]=i;
                    a[1]=j;
                }
            }
        }
        return a;
    }
    static int loopcheck(int graph[][],int parent[],int u,int v)
    {
        int pu=findans(parent,u);
        int pv=findans(parent,v);
        if(pu==pv)
        {
            return 0;
        }
        else 
        {
            parent[pv]=pu;
            return 1;   
        }

    }
    static int findans(int parent[],int t)
    {
        while(parent[t]!=t)
        {
            t=parent[t];
        }
        return t;
    }
}