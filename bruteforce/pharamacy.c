/*
find the farest point from n villages to construct a pharmacitical industry..
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>

int main()
{
    struct villages
    {
        int x,y;
    };

    printf("Enter the no of villages:");
    int no_of_villages;
    scanf("%d",&no_of_villages);
    
    struct villages points[no_of_villages];

    for(int i=0;i<no_of_villages;i++)
    {
        printf("Enter the x & y cordinates villages:%d:",i+1);
        scanf("%d%d",&points[i].x,&points[i].y);
    }

    double distance=0,avg_distance=INT_MIN;
    int indexi;
    for(int i=0;i<no_of_villages;i++)
    {
        double sum=0;
        for(int j=0;j<no_of_villages;j++)
        {
            distance=sqrt(pow(points[i].x-points[j].x,2)+pow(points[i].y-points[j].y,2));
            sum+=distance;
        }
        double avg=(sum)/(no_of_villages-1);
        if(avg>avg_distance)
        {
            avg_distance=avg;
            indexi=i;
        }
    }

        printf("The pharamacy must constructed at points :(%d %d) and max_distance is %lf",points[indexi].x,points[indexi].y,avg_distance);

    return 0;

}