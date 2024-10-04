// checking sub string matched with super string with one charecter skip..
#include<string.h>
#include<stdio.h>
int main()
{
    char super[]="abcdefghij";
    char sub[]="acfj";
    int l1=strlen(super);
    int l2=strlen(sub);

    int check=(l2*2)-1;/**imp**/
    int j=0,temp=0;
    for(int i=0;i<l1-check;i++)
    {      
        if(super[i]==sub[0])
        {
            int flag=0,k=i;
            for(int j=0;j<l2;j++)
            {
                if(sub[j]!=super[k])
                {
                    flag=1;
                    break;
                }
                k+=(j+2);//k=k+(j+2)
            }
            if(flag==0)
            {
                printf("string mathced at %d index:",i);
                return 0;
            }
        }
    }
    printf("String not matched:");
}