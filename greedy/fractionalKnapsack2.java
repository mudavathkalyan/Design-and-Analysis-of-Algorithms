import java.util.*;

public class fractionalKnapsack2 {
    public static void main(String args[]) {
        // int weight[]={1,3,5,4,1,3,2};
        // int profit[]={5,10,15,7,8,9,4};
        // int capacity=15;
        // int weight[]={10,20,30};
        // int profit[]={60,100,120};
        // int capacity=50;
        int weight[] = { 3, 2, 5, 4 };
        int profit[] = { 20, 16, 45, 40 };
        int capacity = 8;

        double ratio[][] = new double[weight.length][3];
        int maxPrice = 0;

        for (int i = 0; i < weight.length; i++)
         {
            ratio[i][0] = weight[i];
            ratio[i][1] = profit[i];
            ratio[i][2] = (double) (profit[i] / (double) weight[i]);
        }
        Arrays.sort(ratio, Comparator.comparingDouble(o -> (o[2])));

        for (int i = weight.length - 1; i >= 0; i--)
         {
            if (capacity >= ratio[i][0])
            {
                maxPrice += ratio[i][1];
                capacity -= ratio[i][0];
            }
             else if (capacity < ratio[i][0]) 
            {
                // maxPrice=maxPrice+(int)(ratio[i][2]/(int)ratio[i][1])*capacity;
                maxPrice += ratio[i][2] * capacity;
                break;
            }
        }
        System.out.println("MaxPrice=" + maxPrice);

    }
}