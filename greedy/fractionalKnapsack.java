import java.util.*;
public class fractionalKnapsack
{
    public static void main(String args[])
    {
        int weight[]={1,3,5,4,1,3,2};
		int profit[]={5,10,15,7,8,9,4};
        int capacity=15;
        
        double ratio[][]=new double [weight.length][4];
        int maxPrice=0;

        for(int i=0;i<weight.length;i++)
        {
            ratio[i][0]=i;
            ratio[i][1]=weight[i];
            ratio[i][2]=profit[i];
            ratio[i][3]=(double) (profit[i]/(double)weight[i]);
        }
        Arrays.sort(ratio,Comparator.comparingDouble(o->(o[3])));

        for(int i=0;i<weight.length;i++)
                {
                    for(int j=0;j<4;j++)
                    {
                        
                        System.out.print(ratio[i][j]+" ");
                    }
                    System.out.println("");
                }
                
                
                for(int i=weight.length-1;i>=0;i--)
                {
                    if(capacity>=ratio[i][1])
                    {
                            maxPrice+=ratio[i][2];
                            capacity-=ratio[i][1];
                        }
                        else if(capacity<ratio[i][1])
                        {
                                // maxPrice=maxPrice+(int)(ratio[i][2]/(int)ratio[i][1])*capacity;
                                maxPrice+=ratio[i][3]*capacity;
                                break;
                            }
                 }
                System.out.println("MaxPrice="+maxPrice);        
                         
            }
        }
                