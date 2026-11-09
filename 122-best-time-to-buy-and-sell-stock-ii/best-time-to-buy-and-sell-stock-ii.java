class Solution {
    static int helper(int i, int n, int prices[],int available,int dp[][]){
        if(i==n) return 0;
        if(dp[i][available]!=-1) return dp[i][available];
        //if available then we can buy or skip
        if(available==1){
            dp[i][available] = Math.max(prices[i]*-1 + helper(i+1,n,prices,available^1,dp),helper(i+1,n,prices,available,dp));
        }
        //if not that means we can sell or skip
        else{
            dp[i][available] = Math.max(prices[i] + helper(i+1,n,prices,available^1,dp),helper(i+1,n,prices,available,dp));
        }
        return dp[i][available];
    }
    public int maxProfit(int[] prices) {
        int n = prices.length;
        int dp[][] = new int[n][2];
        for(int row[]: dp){
            Arrays.fill(row,-1);            
        }
        return helper(0,n,prices,1,dp);
    }
}