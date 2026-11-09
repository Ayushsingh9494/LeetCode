class Solution {
    static int helper(int i, int n, int cap, int a, int prices[], int dp[][][]){
        if(cap==0) return 0;
        if(i==n) return 0;

        if(dp[i][a][cap]!=-1) return dp[i][a][cap];

        if(a==1){
            dp[i][a][cap] = Math.max(prices[i]*-1 + helper(i+1,n,cap,0,prices,dp),helper(i+1,n,cap,1,prices,dp));
        }
        else{
            dp[i][a][cap] = Math.max(prices[i] + helper(i+1,n,cap-1,1,prices,dp),helper(i+1,n,cap,0,prices,dp));
        }
        return dp[i][a][cap];
    }
    public int maxProfit(int[] prices) {
        int n = prices.length;
        int[][][] dp = new int[n][2][3];
        for(int mat[][]: dp){
            for(int row[]: mat){
                Arrays.fill(row,-1);
            }
        }

        return helper(0,n,2,1,prices,dp);
    }
}