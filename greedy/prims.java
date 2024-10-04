//correct code
import java.util.Arrays;
public class prims
{
    static int vertex=5;

    static void print(int parent[],int graph[][])
    {
        System.out.println("Edge \tWeight");
        for(int i=1;i<vertex;i++)
        {
            System.out.println(parent[i]+"-"+i+"\t"+graph[i][parent[i]]);
        }
    } 

    static int minIndex(int key[],boolean exist[])
    {
        int min=Integer.MAX_VALUE;
        int index=-1;
        for(int i=0;i<vertex;i++)
        {
            if(!exist[i] && key[i]<min)
            {
                min=key[i];
                index=i;
            }
        }
        return index;
    }

    
    static void findPrim(int graph[][])
    {
        int key[]=new int[vertex];
        int parent[]=new int[vertex];
        boolean exist[]=new boolean[vertex];
        
        Arrays.fill(key,Integer.MAX_VALUE);
        key[0]=0;
        parent[0]=-1;
        

        for(int i=0;i<vertex-1;i++)
        {
            int r=minIndex(key,exist);
            exist[r]=true;
            for(int c=0;c<vertex;c++)
            {
                if(!exist[c] && graph[r][c]<key[c] && graph[r][c]!=0)
                {
                    parent[c]=r;
                    key[c]=graph[r][c];
                }
            }
        }
        print(parent,graph);
    }

    public static void main(String[] args) 
    {
        int graph[][]=new int[][] {
            {0, 2, 0, 6, 0},
            {2, 0, 3, 8, 5},
            {0, 3, 0, 0, 7},
            {6, 8, 0, 0, 9},
            {0, 5, 7, 9, 0},
        }; 
        findPrim(graph);
    }
}
