class Solution {
    static boolean helper(int nums[], int idx, int target,int dp[][]){
        if(target==0) return true;
        if(idx==0) return(nums[0]==target);

        if(dp[idx][target]!=-1) return (dp[idx][target]==1);      
        boolean notTake = helper(nums,idx-1,target,dp);
        boolean take = false;
        if(nums[idx]<=target) take = helper(nums,idx-1,target-nums[idx],dp);

        dp[idx][target] = (take || notTake)? 1 : 0;
        return (notTake || take);
    }
    public boolean canPartition(int[] nums) {
        int n = nums.length;
        int sum = 0;
        for(int i: nums){
            sum += i;
        }
        if(sum%2!=0) return false;
        int[][] dp = new int[n][sum/2+1];
        for(int[] row: dp){
            Arrays.fill(row,-1);
        }
        return helper(nums,n-1,sum/2,dp);
    }
}