

#include<stdio.h>
#include<string.h>
int main()
{
    char superstring[]="abkablbbab";
    char substring[]="ab";

    int l1=strlen(superstring);
    int l2=strlen(substring);
    int j,count=0;
    for(int i=0;i<=l1-l2;i++)
    {
       if(superstring[i]==substring[0])
       {
            for(j=1;j<l2;j++)
            {
                if(superstring[i+j]!=substring[j])
                {
                    break;
                }
            }
            if(j==l2)
            {
               count++;
            }
       }
    }
    if(count==0)
        printf("Sub string not matched:");
    else
        printf("Sub string matched-%d time:\n\n",count);

}