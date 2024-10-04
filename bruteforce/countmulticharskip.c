// checking sub string matched with super string with one charecter skip..
#include<string.h>
#include<stdio.h>
int main()
{
    char super[]="abcdefghijkjabcdefghij";
    char sub[]="acfj";
    int l1=strlen(super);
    int l2=strlen(sub);
    int count=0;
    int check=(l2*2)-1;/**imp**/
    int j=0,temp=0;
    for(int i=0;i<l1-check;i++)
    {      
        if(super[i]==sub[0])
        {
            int flag=0,k;
            for(int j=0,k=i;j<l2;j++)
            {
                if(sub[j]!=super[k])
                {
                    flag=1;
                    break;
                }
                k+=(j+2);
            }
            if(flag==0)
            {
                count++;
            }
        }
    }
    if(count==0)
    printf("String not matched:");
    else
        printf("Sub string occured %d tmes:",count);

}   