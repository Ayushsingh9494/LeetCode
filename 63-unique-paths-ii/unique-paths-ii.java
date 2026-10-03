class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int r = obstacleGrid.length;
        int c = obstacleGrid[0].length;
        if(obstacleGrid[0][0]==1) return 0; 

        int[] prev = new int[c];

        prev[0] = 1;
        for(int i=0;i<r;i++){
            int[] curr = new int[c];
            for(int j=0;j<c;j++){
                if(i==0 && j==0){
                    curr[j] = 1;
                    continue;
                }
                if(obstacleGrid[i][j]==1){
                    curr[j] = 0;
                    continue;
                }
                int up = 0;
                int left = 0;
                if(i>0) up = prev[j];
                if(j>0) left = curr[j-1];
                curr[j] = up + left;
            }
            prev = curr;
        }
        return prev[c-1];
    }
}