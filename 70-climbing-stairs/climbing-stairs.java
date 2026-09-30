class Solution {
    public int helper(int n,int[] dp){
        if(n<=1) return 1;
        if(dp[n]!=-1){
            int el = dp[n];
            return el;
        }
        dp[n-1] = helper(n-1,dp);
        dp[n-2] = helper(n-2,dp);
        return dp[n-1] + dp[n-2];
    }
    public int climbStairs(int n) {
        int[] dp = new int[n+1];
        Arrays.fill(dp,-1);
        return helper(n,dp);
    }
}