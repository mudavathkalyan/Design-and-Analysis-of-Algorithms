#include<stdio.h>
#include<string.h>
int main()
{
    char superstring[]="kalaacbab";
    char substring[]="acb";

    int l1=strlen(superstring);
    int l2=strlen(substring);
    int j;
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
                printf("Sub string matched");
                return 0;
            }
       }
    }
        printf("String  not matched");

}