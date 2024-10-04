#include<stdio.h>

int wt[]={3,2,5,4};
int val[]={20,16,45,40};
int capacity=8;
int size=4;
int a[4];
int max=0;
void print()
{
    for(int i=0;i<size;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");


}
void check(int n)
{
    int v=0,w=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==1)
        {
            v+=val[i];
            w+=wt[i];
        }
    }
    if(w<=capacity)
    {
        if(max<v)
        {
            max=v;
            print();
        }
    }

}
void knap(int n,int pos)
{
    if(n==pos)
    {
        check(n);
        return;
    }
    for(int i=0;i<2;i++)
    {
      a[pos]=i;
      knap(n,pos+1);  
    }
}
int main()
{
    knap(size,0);
    printf("max-value=%d\n",max);
    return 0;
}