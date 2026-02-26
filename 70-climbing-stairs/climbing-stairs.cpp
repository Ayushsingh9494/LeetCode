class Solution {
    public:
    int helper(vector<int> &dp, int n){
        if(n<=0) return n+1;
        if(dp[n]!=-1) return dp[n];
        int step1 = helper(dp,n-1);
        int step2 = helper(dp,n-2);
        dp[n] = step1 + step2;
        return dp[n];
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        dp[0] = 1;
        return helper(dp,n);
    }
};