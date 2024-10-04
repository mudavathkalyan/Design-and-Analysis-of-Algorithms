
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
#define max 20

struct point
{
    int x,y;
}flag;
double minimum=INT_MAX;
void qsortx();
void qsorty();
double closepointx();
double closepointy();
double bruteforce();

int main()
{
    int n;
    printf("Enter n points::");
    scanf("%d",&n);
    struct point p[n];
    for(int i=0;i<n;i++)
    {
         printf("Enter x and y cordinates of %d:",(i+1));
        scanf("%d%d",&p[i].x,&p[i].y);
    }
    qsortx(p,0,n-1);
    double min_distance=closepointx(p,0,n-1);
    printf("Min distance=%lf",min_distance);
    return 0;
}
double closepointx(struct point p[],int start,int end)
{
    if(end-start<=3)
    {
        return bruteforce(p,start,end);
    }
    else
    {
        int mid=(start+end)/2;
        double ld=closepointx(p,start,mid);
        double rd=closepointx(p,mid+1,end);
        double minvalue=ld>rd?rd:ld;
        struct point strip[end-start+1];
        int k=0;
        for(int i=start;i<=end;i++)
        {   
            if(abs(p[mid].x-p[i].x)<mid)
            {
                strip[k++]=p[i];
            }

        }
            qsorty(strip,0,k-1);
            double stripdistance=closepointy(strip,0,k-1);
            return stripdistance>minvalue?minvalue:stripdistance;      
    }
}   

double closepointy(struct point p[],int start,int end)
{
    if(end-start<=3)
    {
        return bruteforce(p,start,end);
    }
    else
    {
        int mid=(start+end)/2;
        double ld=closepointy(p,start,mid);
        double rd=closepointy(p,mid+1,end);
        double minvalue=ld>rd?rd:ld;
        struct point strip[end-start+1];
        int k=0;
        for(int i=start;i<=end;i++)
        {   
            if(abs(p[mid].y-p[i].y)<mid)
            {
                strip[k++]=p[i];
            }

        }
            qsorty(strip,0,k-1);
            double stripdistance=closepointy(strip,0,k-1);
            return stripdistance>minvalue?minvalue:stripdistance;
        
    }
}   

double bruteforce(struct point p[] ,int start,int end)
{
   int pointi,pointj;
    for(int i=0;i<end-1;i++)
    {
        for(int j=i+1;j<end;j++)
        {
            double d=sqrt(pow(p[j].x-p[i].x,2)+pow(p[j].y-p[i].y,2));
            if(minimum>d)
            {
                minimum=d;
                pointi=i;
                pointj=j;

            }
        }
    }
     printf("Points=(%d,%d)&(%d,%d)",p[pointi].x,p[pointi].y,p[pointj].x,p[pointj].y);
    return minimum;
}





void qsortx(struct point p[],int low,int high)
{
    if(low<high)
    {
        int i=low;
        int pivot=low;
        int j=high;
        while(i<j)
        {
            while(p[i].x<=p[pivot].x)
            {
                i++;
            }
            while (p[j].x>p[pivot].x)
            {
                j--;
            }
            if(i<j)
            {
                flag=p[i];
                p[i]=p[j];
                p[j]=flag;
            }
        }
        flag=p[pivot];
        p[pivot]=p[j];
        p[j]=flag;
        qsortx(p,low,j-1);
        qsortx(p,j+1,high);
    }
}
void qsorty(struct point p[],int low,int high)
{
    if(low<high)
    {
        int i=low;
        int pivot=low;
        int j=high;
        while(i<j)
        {
            while(p[i].y<=p[pivot].y)
            {
                i++;
            }
            while (p[j].y>p[pivot].y)
            {
                j--;
            }
            if(i<j)
            {
                flag=p[i];
                p[i]=p[j];
                p[j]=flag;
            }
        }
        flag=p[pivot];
        p[pivot]=p[j];
        p[j]=flag;
        qsorty(p,low,j-1);
        qsorty(p,j+1,high);
    }
}