class Solution {
    public int helper(int grid [][], int i, int j1, int j2, int r, int c, int dp[][][]){
        //base condition
        if(j1>=c || j2>=c || j1<0 || j2<0){
            return Integer.MIN_VALUE/2;
        }
        if(i==r-1){
            if(j1==j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        int maxi = -100;
        for(int it=-1;it<=1;it++){
            for(int j=-1;j<=1;j++){
                if(j1==j2){
                    maxi = Math.max(maxi,grid[i][j1] + helper(grid,i+1,j1+it,j2+j,r,c,dp));
                }
                else maxi = Math.max(maxi,grid[i][j1] + grid[i][j2] + helper(grid,i+1,j1+it,j2+j,r,c,dp));
            }
        }

        return dp[i][j1][j2] = maxi;
    }
    public int cherryPickup(int[][] grid) {
        int r = grid.length;
        int c = grid[0].length;
        int[][][] dp = new int[r][c][c];
        for(int[][] matrix: dp){
            for(int[]row: matrix){
                Arrays.fill(row,-1);
            }
        }
        return helper(grid,0,0,c-1,r,c,dp);
    }
}