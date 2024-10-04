import java.util.*;

public class Dijkstras 
{
	private static final int V = 5;  // Number of vertices in the graph
	
    int minKey(int key[], boolean mstSet[]) 
    {
        int min = Integer.MAX_VALUE, minIndex = -1;

        for (int v = 0; v < V; v++) 
        {
            if (!mstSet[v] && key[v] < min) 
            {
                min = key[v];
                minIndex = v;
            }
        }

        return minIndex;
    }
    
    void printSSP(int key[], int n) 
    {
        System.out.println("Vertex \t Distance from source");
        for (int i = 1; i < n; i++) 
        {
            System.out.println(i + "\t" + key[i]);
        }
    }
    
    void dijkstras(int graph[][], int src) 
    {
        int key[] = new int[V];    // will hold the shortest distance from src
        boolean mstSet[] = new boolean[V]; // To represent set of vertices included in shortest path

        Arrays.fill(key, Integer.MAX_VALUE); // Initialize all keys as INFINITE
        key[src] = 0; // Make key 0 so that this vertex is picked as first vertex

        for (int count = 0; count < V - 1; count++) 
        {
            int u = minKey(key, mstSet);
            mstSet[u] = true;

            for (int v = 0; v < V; v++) 
            {
                if (graph[u][v] != 0 && !mstSet[v] && key[u]!= Integer.MAX_VALUE && key[u]+graph[u][v] < key[v]) 
                {
                    key[v] = key[u]+graph[u][v];
                }
            }
        }

        printSSP(key, V);
    }
    
    public static void main(String[] args) 
    {
	    Dijkstras d = new Dijkstras();
	    int graph[][] = new int[][]{
	        {0, 2, 0, 6, 0},
	        {2, 0, 3, 8, 5},
	        {0, 3, 0, 0, 7},
	        {6, 8, 0, 0, 9},
	        {0, 5, 7, 9, 0}
	    };
	
	    d.dijkstras(graph, 0);
    }

}
