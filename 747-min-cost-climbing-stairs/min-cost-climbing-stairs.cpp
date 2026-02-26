class Solution {
    private:
    int helper(vector<int>& cost,int i,vector<int> & dp){
        if(i==0 || i==1) return 0;
        if(dp[i]!=-1) return dp[i];
        int oneS = cost[i-1] + helper(cost,i-1,dp);
        int twoS = cost[i-2] + helper(cost,i-2,dp);
        dp[i] = min(oneS,twoS);
        return dp[i];
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1,-1);
        dp[0] = 1;
        dp[1] = 1;
        return helper(cost,n,dp);
    }
};