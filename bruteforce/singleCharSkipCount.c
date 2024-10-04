// checking sub string matched with super string with one charecter skip..
#include<string.h>
#include<stdio.h>
int main()
{
    char super[]="abcdefghiabcdefj";
    char sub[]="ace";
    int l1=strlen(super);
    int l2=strlen(sub);

    int check=(l2*2)-1;/**imp**/
    int j=0,count=0;
    for(int i=0;i<=l1-check;i++)
    {
        if(super[i]==sub[0])
        {
            for(j=1;j<l2;j++)
            {
                if(sub[j]!=super[i+(j*2)])
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
        printf("Sub string not occured in main string");
    else
        printf("Sub string occured %d times:\n",count);
    
}