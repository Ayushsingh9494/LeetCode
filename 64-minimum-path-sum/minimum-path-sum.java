class Solution {
    public int minPathSum(int[][] grid) {
        int r = grid.length;
        int c = grid[0].length;
        int[][] dp = new int[r][c];
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(i==0 && j==0){
                    dp[i][j] = grid[i][j];
                    continue;
                }
                int up = Integer.MAX_VALUE/2;
                int left = Integer.MAX_VALUE/2;
                if(i>0) up = grid[i][j] + dp[i-1][j];
                if(j>0) left = grid[i][j] + dp[i][j-1];
                dp[i][j] = Math.min(up,left);
            }
        }
        return dp[r-1][c-1];
    }
}