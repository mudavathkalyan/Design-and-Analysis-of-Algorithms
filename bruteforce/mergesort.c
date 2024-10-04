#include<stdio.h>
int merge();
int mergesort();
int n;
int main()
{
    int arr[]={3,1,5,7,4,2};
    n=sizeof(arr)/sizeof(arr[0]);
    merge(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}
int merge(int arr[],int low,int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        merge(arr,low,mid);
        merge(arr,mid+1,high);
        mergesort(arr,low,mid,high);
    }
}
int mergesort(int arr[],int low,int mid,int high)
{
    int k[n];
    int i,temp;
    i=temp=low;
    int j=mid+1;
    while((i<=mid) && (j<=high))
    {
        if(arr[i]<arr[j])
            k[temp++]=arr[i++];
        else
        {
            k[temp++]=arr[j++];
        }
    }
    while(i<=mid)
    {
        k[temp++]=arr[i++];
    }
    while(j<=high)
    {
        k[temp++]=arr[j++];
    }
    for(int i=low;i<temp;i++)
    {
        arr[i]=k[i];
    }

}
