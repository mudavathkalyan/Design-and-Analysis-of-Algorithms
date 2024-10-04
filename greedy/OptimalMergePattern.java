import java.util.*;

public class OptimalMergePattern 
{
    static int sum = 0;
    static int[] a = {15, 10, 8};

    public static void main(String[] args) 
    {
        int n = a.length;
        int len = n;

        // While there are more than one elements left
        while (len > 1) 
        {
            int small, nextsmall;

            // Find the smallest element
            int pointi = findsmall(len);
            small = a[pointi];
            if (pointi != -1) {
                swap(pointi, len - 1);
            }

            // Find the next smallest element
            int pointj = findsmall(len - 1);
            nextsmall = a[pointj];
            if (pointj != -1) {
                swap(pointj, len - 2);
            }

            // Merge the two smallest elements
            int merged_value = small + nextsmall;
            sum += merged_value;
            a[len - 2] = merged_value;

            // Reduce the length of the array
            len--;

            // Print current state of the array
            // print(len);
            // System.out.println("Current Sum: " + sum);
        }

        // Print the final total sum
        System.out.println("\nTotal Sum = " + sum);
    }

    // Method to find the smallest element's index in the array up to a given length
    public static int findsmall(int len) 
    {
        int small = Integer.MAX_VALUE;
        int pointi = -1;
        for (int i = 0; i < len; i++) {
            if (a[i] < small) {
                small = a[i];
                pointi = i;
            }
        }
        return pointi;
    }

    // Method to swap two elements in the array
    public static void swap(int i, int j) 
    {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    // Method to print the current state of the array
    public static void print(int len) {
        for (int i = 0; i < len; i++) {
            System.out.print(a[i] + " ");
        }
        System.out.println();
    }
}
