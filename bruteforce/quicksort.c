#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void quicksort();
int main()
{
    int array[]={3,4,1,2,9,6,5,2};
    int length=sizeof(array)/sizeof(array[0]);
    quicksort(array,0,length-1);

    printf("sorted array is:");
    for(int i=0;i<length;i++)
    {
        printf("%d ,",array[i]);
    }
    return 0;
}
void quicksort(int array[],int low, int high)
{
    int flag;
    if(low<high)
    {
        int i=low;
        int j=high;
        int piovt=low;
        while(i<j)
        {
            while(array[i]<=array[piovt])
            {
                i++;
            }
            while(array[j]>array[piovt])
            {
                j--;
            }
            if(i<j)
            {
            flag=array[i];
            array[i]=array[j];
            array[j]=flag;
            }
        }
        flag=array[piovt];
        array[piovt]=array[j];
        array[j]=flag;

        quicksort(array,low,j-1);
        quicksort(array,j+1,high);

    }
}

