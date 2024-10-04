#include<stdio.h>
#include<stdlib.h>

int main() 
{
    struct points 
    {
        int x,y;
    };
    int n;
    printf("Enter no of points:");
    scanf("%d", &n);
    struct points p[n];
    for(int i = 0; i < n; i++) 
    {
        printf("Enter point %d x&y coordinates:", i + 1);
        scanf("%d %d", &p[i].x, &p[i].y);
    }
    int onpoints=0;
    int a, b, c, value;
    int edgeCount = 0; // Initialize edge count
    for(int i = 0; i < n - 1; i++) 
    {
        for(int j = i + 1; j < n; j++) 
        {
            a = p[j].y - p[i].y;
            b = p[i].x - p[j].x;
            c = p[i].x * p[j].y - p[j].x * p[i].y;
            int np = 0, nn = 0;
    int count=0;
            for(int k = 0; k < n; k++) 
            {
                value = a * p[k].x + b * p[k].y - c;
                if(value > 0) 
                    np++; 
                else if(value < 0) 
                    nn++;
              
            }
           
            if(np == 0 || nn == 0) 
            {
                printf("(%d,%d), (%d,%d) are convex hull points\n", p[i].x, p[i].y, p[j].x, p[j].y);
                edgeCount++; // Increment edge count
            }
        }
    }
    printf("Number of edges in the convex hull: %d\n", edgeCount); // Print edge count
    return 0;
}
