class Solution {
    private:
    int helper(vector<int>& nums,int i,vector<int> &dp){
        if(i==0) return nums[0];
        if(i==-1) return 0;
        if(dp[i]!=-1) return dp[i];
        int rob = nums[i] + helper(nums,i-2,dp);
        int noRob = helper(nums,i-1,dp);
        dp[i] = max(rob,noRob);
        return dp[i];
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,-1);
        dp[0] = nums[0];
        return helper(nums,n-1,dp);
    }
};