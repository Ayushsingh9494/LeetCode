class Solution {
    static int helper(int m, int n,int dp[][]){
        if(m<=0 || n<=0) return 0;
        if(m==1 && n==1) return 1;
        if(dp[m-1][n-1]!=-1) return dp[m-1][n-1];
        int up = helper(m-1,n,dp);  
        int left = helper(m,n-1,dp);  
        return dp[m-1][n-1] = up + left;
    }
    public int uniquePaths(int m, int n) {
        int[][] dp = new int[m][n];
        for(int[] rows: dp){
            Arrays.fill(rows,-1);
        }
        return helper(m,n,dp);
    }
}