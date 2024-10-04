

import java.util.*;
public class optimalSearch
{
    static int keys[]=new int[]{1,2,3};
    static int freq[]=new int[]{8,2,4};
    public static void main(String[] args)
     {
            int r=obst(0,keys.length-1);
            System.out.println("res="+r);
    }
    static int obst(int i,int j)
    {   
        if (i > j) 
        {
            return 0;
        }
        if(i==j)
        {
            return freq[i];
        }
        int value=0;
        int min=Integer.MAX_VALUE;
        for (int k = i; k <= j; k++)
        {
           value = obst(i, k - 1) + obst(k + 1, j) + sum(freq, i, j);
           if (value < min) 
           {
               min = value;
           }
       }
       return min;
    }
    static int sum(int freq[],int i,int j)
    {   
        int s=0;
        for(int k=i;k<=j;k++)
        {
            s+=freq[k];
        }
        return s;
    }
}