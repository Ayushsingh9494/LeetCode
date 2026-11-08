class Solution {
    static boolean helper(String s1, String s2, int i, int j, int dp[][]){
        //base case
        if(i<0 && j<0) return true;
        if(i<0) return false;
        if(j<0){
            for(int id=0;id<=i;id++){
                if(s1.charAt(id)!='*') return false;
            }
            return true;
        }
        if(dp[i][j]!=-1) return (dp[i][j]==1);
        //logic
        //if char is alphabet
        char ch = s1.charAt(i);
        if(ch>='a' && ch<='z'){
            if(ch==s2.charAt(j)) dp[i][j] = (helper(s1,s2,i-1,j-1,dp))? 1 : 0;
            else dp[i][j] = 0;
        }
        //if char is '?'
        else if(ch=='?'){
            dp[i][j] = (helper(s1,s2,i-1,j-1,dp))? 1 : 0;
        }
        //if char is '*'
        else{
            dp[i][j] = (helper(s1,s2,i-1,j-1,dp) || helper(s1,s2,i,j-1,dp) || helper(s1,s2,i-1,j,dp))? 1: 0;
        }
        return (dp[i][j]==1);
    }
    public boolean isMatch(String s, String p) {
        int n1 = p.length();
        int n2 = s.length();
        int dp[][] = new int[n1][n2];
        for(int row[]: dp){
            Arrays.fill(row,-1);
        }
        return helper(p,s,n1-1,n2-1,dp);
    }
}