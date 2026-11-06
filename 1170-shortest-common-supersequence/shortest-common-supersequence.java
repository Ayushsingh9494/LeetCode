class Solution {
    static int helper(String s1, String s2, int i1, int i2, int dp[][]){
        if(i1==0 || i2==0){
            return 0;
        }
        if(dp[i1][i2]!=-1) return dp[i1][i2];
        boolean match = (s1.charAt(i1-1)==s2.charAt(i2-1));
        if(match) dp[i1][i2] = 1 + helper(s1,s2,i1-1,i2-1,dp);
        else dp[i1][i2] = Math.max(helper(s1,s2,i1-1,i2,dp),helper(s1,s2,i1,i2-1,dp));
        return dp[i1][i2];
    }
    public String shortestCommonSupersequence(String str1, String str2) {
        int n1 = str1.length();
        int n2 = str2.length();
        int dp[][] = new int[n1+1][n2+1];
        for(int row[]: dp){
            Arrays.fill(row,-1);
        }
        int lcs = helper(str1,str2,n1,n2,dp);
        String scs = "";
        int i=n1;
        int j=n2;
        while(i>0 && j>0){
            if(str1.charAt(i-1)==str2.charAt(j-1)){
                scs += str1.charAt(i-1);
                i--;
                j--;
            }
            else if(dp[i][j-1]>dp[i-1][j]){
                scs += str2.charAt(j-1);
                j--;
            }
            else{
                scs += str1.charAt(i-1);
                i--;
            }
            
        } 
        while(i>0){
            scs += str1.charAt(i-1);
            i--;
        }
        while(j>0){
            scs += str2.charAt(j-1);
            j--;
        }
        return new StringBuilder(scs).reverse().toString();
    }
}