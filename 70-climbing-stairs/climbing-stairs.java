class Solution {
    // public int helper(int n,int[] dp){
    //     if(n<=1) return 1;
    //     if(dp[n]!=-1){
    //         int el = dp[n];
    //         return el;
    //     }
    //     dp[n-1] = helper(n-1,dp);
    //     dp[n-2] = helper(n-2,dp);
    //     return dp[n-1] + dp[n-2];
    // }
    public int climbStairs(int n) {
        int prev = 1;
        int curr = 1;
        for(int i=2;i<=n;i++){
            int temp = curr;
            curr = prev + curr;
            prev = temp;
        }
        return curr;
    }
}