
class practice
{
    public static void main(String[] args) {
        Solution s=new Solution();
        int nums[]={1,5,11,5};
        if(s.canPartition(nums))
        {
            System.out.println("ok");
        }
        else
        {
            System.out.println("no");
        }
    }
}
class Solution 
{
    public boolean canPartition(int[] nums)
    {

    int n=nums.length;
    int sum=0;
    for(int i=0;i<n;i++)
    {   
        sum+=nums[i];
    }
    if(sum%2!=0)
    {
        return false;
    }
    else
    {
        System.out.println("Going");
       boolean t[][]=new boolean [n+1][sum+1];
        for(int i=0;i<=n;i++)
       {
        for(int j=0;j<=sum;j++)
        {
            if(j==0)
                t[i][j]=true;
            if(i==0)
                t[i][j]=false;
            else if(nums[i-1]<=j)
                t[i][j]=t[i-1][j-nums[i-1]] || t[i-1][j];
            else
                t[i][j]=t[i-1][j];
          }
        }
        if(t[n][sum])
            return true;
        else
            return false;

    }
    }
}
