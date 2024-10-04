//correct code
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <math.h>
#define MAX_POINTS 100
int flag=1;
struct point 
{
    int x, y;
};

double closestpairx();
double closestpairy();
double bruteforce();
void qsortx();
void qsorty();

int main() 
{
    int n;
    printf("Enter the number of points: ");
    scanf("%d", &n);
    struct point p[MAX_POINTS];

        printf("Enter  all x & y coordinates");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d %d", &p[i].x, &p[i].y);
    }

    qsortx(p, 0, n - 1);
    double min_distance = closestpairx(p, 0, n - 1);
    printf("\nMinimum distance: %lf\n", min_distance);
    return 0;
}

double closestpairx(struct point p[], int start, int end) 
{
    if (end - start <= 3) 
    {
        return bruteforce(p, start, end);
    }
    else 
    {
        int mid = (start + end) / 2;
        double left_distance = closestpairx(p, start, mid);
        double right_distance = closestpairx(p, mid + 1, end);
        double min_distance = (left_distance < right_distance) ? left_distance : right_distance;

        struct point strip[end - start + 1];
        int k = 0;
        for (int i = start; i <= end; i++) {
            if (abs(p[mid].x - p[i].x) < min_distance) 
            {
                strip[k++] = p[i];
            }
        }
        qsorty(strip,0,k-1);
        double stripdis=closestpairy(strip,0,k-1);
        return stripdis>min_distance?min_distance:stripdis;
        // return closestpairy(strip, 0, k - 1) < min_distance ? closestpairy(strip, 0, k - 1) : min_distance;

    }
}

double closestpairy(struct point p[], int start, int end) 
{
    if (end - start <= 3) {
        return bruteforce(p, start, end);
    } 
    else
     {
        int mid = (start + end) / 2;
        double left_distance = closestpairy(p, start, mid);
        double right_distance = closestpairy(p, mid + 1, end);
        double min_distance = (left_distance < right_distance) ? left_distance : right_distance;

        struct point strip[end - start + 1];
        int k = 0;
        for (int i = start; i <= end; i++) {
            if (abs(p[mid].y - p[i].y) < min_distance) 
            {
                strip[k++] = p[i];
            }
        }
        double stripdis=closestpairy(strip,0,k-1);//
        return stripdis>min_distance?min_distance:stripdis;
        // return (closestpairy(strip, 0, k - 1) < min_distance) ? closestpairy(strip, 0, k - 1) : min_distance;
    }
}

double bruteforce(struct point p[], int start, int n) 
{
    double min = INT_MAX;
    
    int pointi,pointj;
    for (int i = start; i < n - 1; i++) 
    {
        for (int j = i + 1; j<n; j++) 
        {
            double distance = sqrt(pow(p[j].x - p[i].x, 2) + pow(p[j].y - p[i].y, 2));
           if(distance<min)
            {
                min=distance;
                 pointi=i;
                 pointj=j;
            }
        }
    }  
        // printf("Points=(%d,%d)&(%d,%d)",p[pointi].x,p[pointi].y,p[pointj].x,p[pointj].y);
    return min; 
}
void qsortx(struct point p[], int low, int high) 
{
    if (low < high) 
    {
        int i = low, j = high;
        struct point pivot = p[low];
        while (i < j) 
        {
            while (p[i].x <= pivot.x && i <= high)
            {
                i++;
            }
            while (p[j].x > pivot.x && j >= low)
            {
                j--;
            }
            if (i < j)
            {
                struct point temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
        struct point temp = p[low];
        p[low] = p[j];
        p[j] = temp;

        qsortx(p, low, j - 1);
        qsortx(p, j + 1, high);
    }
}

void qsorty(struct point p[], int low, int high)
 {
    if (low < high) {
        int i = low, j = high;
        struct point pivot = p[low];
        while (i < j) {
            while (p[i].y <= pivot.y && i <= high)
            {
                i++;
            }
            while (p[j].y > pivot.y && j >= low)
            {
                j--;
            }
            if (i < j)
            {
                struct point temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
        struct point temp = p[low];
        p[low] = p[j];
        p[j] = temp;

        qsorty(p, low, j - 1);
        qsorty(p, j + 1, high);
    }
}
