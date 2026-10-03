class Solution {
    public int minPathSum(int[][] grid) {
        int r = grid.length;
        int c = grid[0].length;
        int[] prev = new int[c];
        for(int i=0;i<r;i++){
            int[] curr = new int[c];
            for(int j=0;j<c;j++){
                if(i==0 && j==0){
                    curr[j] = grid[i][j];
                    continue;
                }
                int up = Integer.MAX_VALUE/2;
                int left = Integer.MAX_VALUE/2;
                if(i>0) up = grid[i][j] + prev[j];
                if(j>0) left = grid[i][j] + curr[j-1];
                curr[j] = Math.min(up,left);
            }
            prev = curr;
        }
        return prev[c-1];
    }
}