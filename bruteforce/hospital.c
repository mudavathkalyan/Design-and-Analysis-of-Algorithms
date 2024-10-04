//for n villages
//find  a closest point to construct a hospital 
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{
    struct villages
    {
        int x,y;
    };

    int no_of_villages,indexi;
    printf("Enter the n villages:");
    scanf("%d",&no_of_villages);

    struct villages points[no_of_villages];

    for(int i=0;i<no_of_villages;i++)
    {
        printf("Enter the x & y cordinates of village :%d :",i+1);
        scanf("%d%d",&points[i].x,&points[i].y);
    }
    double avg_distance=__INT_MAX__,distance;
    for(int i=0;i<no_of_villages;i++)
    {
        double sum=0;
        for(int j=0;j<no_of_villages;j++)
        {
            distance=sqrt (pow((points[j].x-points[i].x),2) + pow((points[j].y-points[i].y),2));
            sum+=distance;
        }
        double avg=sum/(no_of_villages-1);
        if(avg<avg_distance)
        {
            avg_distance=avg;
            indexi=i;

        }
    }
    printf("Hospital must constructed at: %d,%d and average distance is:%lf",points[indexi].x,points[indexi].y,avg_distance);

    return 0;
}