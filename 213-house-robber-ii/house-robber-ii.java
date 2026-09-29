class Solution {
    static int helper(int[] nums){
        int n = nums.length;
        int[] dp = new int[n];
        dp[0] = nums[0];
        if(n>1) dp[1] = Math.max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            dp[i] = Math.max(dp[i-1],dp[i-2]+nums[i]);
        }
        return dp[n-1];
    }
    public int rob(int[] nums) {
        int n = nums.length;
        if(n==1) return nums[0];
        int[] num1 = new int[n-1];
        int[] num2 = new int[n-1];

        for(int i=0;i<n-1;i++){
            num1[i] = nums[i]; 
        } 
        for(int i=1;i<n;i++){
            num2[i-1] = nums[i]; 
        } 
        return Math.max(helper(num1),helper(num2));
    }
        
        
}