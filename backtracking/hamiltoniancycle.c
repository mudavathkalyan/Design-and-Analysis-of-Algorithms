#include <stdio.h>
#include <stdbool.h>

#define MAX 20
// int adj[5][5]={{0, 1, 0, 1, 0},{1, 0, 1, 1, 1},{0, 1, 0, 0, 1},{1, 1, 0, 0, 0},{0, 1, 1, 0, 0}};
int adj[5][5] = {
   {0, 1, 0, 1, 0},
   {1, 0, 1, 1, 1},
   {0, 1, 0, 0, 1},
   {1, 1, 0, 0, 1},
   {0, 1, 1, 1, 0}};
int a[MAX];
int size;

void hc(int pos);
bool issafe(int pos, int vertex);
void print();

int main() 
{
    size = 5;

    // Initialize the path array
    for (int i = 0; i < size; i++) 
    {
        a[i] = -1;
    }

    a[0] = 0; // Start from the first vertex
    hc(1);    // Start the recursive function from the second position

    return 0;
}

void hc(int pos) 
{
    if (pos == size) 
    {       
        print();
        return;
    }
    for (int i = 0; i < size; i++) 
    {
        if (issafe(pos, i)) 
        {
            a[pos] = i;
            hc(pos + 1);
            // a[pos] = -1; // Backtrack: Reset the position for the next iteration
        }
    }
}

bool issafe(int pos, int vertex) 
{
    for (int i = 0; i < pos; i++) 
    {
        if (a[i] == vertex) 
            return false;

        if(adj[a[pos-1]][vertex]!=1)
            return false;

        if(pos==size-1 && adj[vertex][a[0]]!=1)
            return false;
    }
    return true;
}

void print() 
{
    for (int i = 0; i < size; i++) 
    {
        printf("%d ", a[i]); // Print 0-based index
    }
    printf("%d\n", a[0]); // Print the starting vertex to complete the cycle
}
