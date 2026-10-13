class Solution {
    public int cherryPickup(int[][] grid) {
        int r = grid.length;
        int c = grid[0].length;
        int [][][] dp = new int[r][c][c];
        
        for(int j1=0;j1<c;j1++){
            for(int j2=0;j2<c;j2++){
                if(j1==j2) dp[r-1][j1][j2] = grid[r-1][j1];
                else dp[r-1][j1][j2] = grid[r-1][j1] + grid[r-1][j2];
            }
        }

        for(int i=r-2;i>=0;i--){
            for(int j1=0;j1<c;j1++){
                for(int j2=0;j2<c;j2++){
                    int maxi = 0;
                    for(int k1=-1;k1<=1;k1++){
                        for(int k2=-1;k2<=1;k2++){
                            int value = 0;
                            if(j1==j2) value = grid[i][j1];
                            else value = grid[i][j1] + grid[i][j2];
                            if(j1+k1>=0 && j1+k1<c && j2+k2>=0 && j2+k2<c){
                                value += dp[i+1][j1+k1][j2+k2];
                            }
                            else value += -1e8;

                            maxi = Math.max(maxi,value);
                        }
                    }

                    dp[i][j1][j2] = maxi;
                }
            }
        }

        return dp[0][0][c-1];

    }
}