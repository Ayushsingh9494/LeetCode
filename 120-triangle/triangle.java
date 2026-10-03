class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int r = triangle.size();
        int c = triangle.get(r-1).size();
        int[][] dp = new int[r][c];
        for(int i=0;i<r;i++){
            for(int j=0;j<=i;j++){
                if(i==0 && j==0){
                    dp[i][j] = triangle.get(i).get(j);
                    continue;
                }
                int up = Integer.MAX_VALUE/2;
                int diagonally = Integer.MAX_VALUE/2;

                if(i>0 && j<i) up = triangle.get(i).get(j) + dp[i-1][j];
                if(i>0 && j>0) diagonally = triangle.get(i).get(j) + dp[i-1][j-1];

                dp[i][j] = Math.min(up,diagonally);
            }
        }
        int mini = Integer.MAX_VALUE;
        for(int last: dp[r-1]){
            mini = Math.min(mini,last);
        }
        return mini;
    }
}