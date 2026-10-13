class Solution {
    public int helper(int grid [][], int i, int j1, int j2, int r, int c, int dp[][][]){
        //base condition
        if(j1<0 || j2<0 || j1>=c || j2>=c){
            return Integer.MIN_VALUE/2;
        }
        if(i==r-1){
            if(j1==j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        int maxi = 0;
        for(int k1=-1;k1<=1;k1++){
            for(int k2=-1;k2<=1;k2++){
                if(j1==j2){
                    maxi = Math.max(maxi,grid[i][j1] + helper(grid,i+1,j1+k1,j2+k2,r,c,dp));
                }
                else{
                    maxi = Math.max(maxi,grid[i][j1] + grid[i][j2] + helper(grid,i+1,j1+k1,j2+k2,r,c,dp));
                }
            }
        }

        return dp[i][j1][j2] = maxi;
    }
    public int cherryPickup(int[][] grid) {
        int r = grid.length;
        int c = grid[0].length;
        int [][][] dp = new int[r][c][c];
        for(int[][] matrix: dp){
            for(int[] row: matrix){
                Arrays.fill(row,-1);
            }
        }
        return helper(grid,0,0,c-1,r,c,dp);
    }
}