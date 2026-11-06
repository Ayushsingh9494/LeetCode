class Solution {
    static int helper(String s1, String s2, int i, int j, int dp[][]){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];

        if(s1.charAt(i)==s2.charAt(j)){
            dp[i][j] = helper(s1,s2,i-1,j-1,dp);
        }
        else{
            dp[i][j] = Math.min(1+helper(s1,s2,i-1,j,dp),Math.min(1+helper(s1,s2,i,j-1,dp),1+helper(s1,s2,i-1,j-1,dp)));
        }
        return dp[i][j];
    }
    public int minDistance(String word1, String word2) {
        int n1 = word1.length();
        int n2 = word2.length();
        int[][] dp = new int[n1+1][n2+1];
        for(int i=0;i<=n1;i++){
            dp[i][0] = i;
        }
        for(int j=0;j<=n2;j++){
            dp[0][j] = j;
        }
        
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(word1.charAt(i-1)==word2.charAt(j-1)) dp[i][j] = dp[i-1][j-1];
                else{
                    dp[i][j] = Math.min(1+dp[i-1][j],Math.min(1+dp[i][j-1],1+dp[i-1][j-1]));
                }
            }
        }

        return dp[n1][n2];
    }
}