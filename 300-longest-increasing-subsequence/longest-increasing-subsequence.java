class Solution {
    static int helper(int i, int n, int[] nums, int dp[][],int prev){
        if(i==n) return 0;

        //logic for first number
        //for rest, we have to check whether the number is greater than the last picked to be eligible
        if(dp[i][prev+1] != -1) return dp[i][prev+1];
        int notPick = helper(i+1,n,nums,dp,prev);
        int pick = 0;
        if(prev==-1 || nums[i]>nums[prev]){
            pick = Math.max(1+ helper(i+1,n,nums,dp,i),helper(i+1,n,nums,dp,prev));
        }
        return dp[i][prev+1] = Math.max(pick,notPick);
    }
    public int lengthOfLIS(int[] nums) {
        int n = nums.length;
        int dp[][] = new int[n][n+1];
        for(int row[]: dp){
            Arrays.fill(row,-1);
        }
        return helper(0,n,nums,dp,-1);
    }
}