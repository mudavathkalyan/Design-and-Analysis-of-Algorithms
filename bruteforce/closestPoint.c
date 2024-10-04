#include<stdio.h>
#include<string.h>
#include<math.h>
#include<limits.h>

int main() 
{
    struct points 
    {
        int x, y;
    };
    int n;
    int min =INT_MAX;
    int pointi,pointj;
	printf("Enter no of points:");
    scanf("%d", &n);
    struct points p[n];
    
    printf("Enter all  x&y cordinates:");
    for(int i = 0; i < n; i++) 
    {
        scanf("%d %d", &p[i].x, &p[i].y);
    }

    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++) 
        {
            int distance = sqrt(pow(p[i].x - p[j].x, 2) + pow(p[i].y - p[j].y, 2));
            if(distance < min) 
            {
                min = distance;
                pointi = i;
                pointj = j;
            }
        }
    }

    printf("Closest points are: (%d,%d) and (%d,%d)\n", p[pointi].x, p[pointi].y, p[pointj].x, p[pointj].y);
    printf("Minimum distance: %d\n", min);

    return 0;
}
