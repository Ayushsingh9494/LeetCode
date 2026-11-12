class Solution {
    public List<Integer> largestDivisibleSubset(int[] nums) {
        int n = nums.length;
        Arrays.sort(nums);
        int dp[] = new int[n];
        Arrays.fill(dp,1);
        
        //hash numsay
        int[] hash = new int[n];
        
        int maxi = 0;
        int lastIndex = 0;
        for(int i=0;i<=n-1;i++){
            hash[i] = i;
            for(int prev=0;prev<=i-1;prev++){
                if(nums[i]%nums[prev]==0 && 1+dp[prev]>dp[i]){
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }
            if(dp[i]>maxi){
                maxi = dp[i];
                lastIndex = i;
            }
        }
        
        List<Integer> lis = new ArrayList<>();
        lis.add(nums[lastIndex]);
        while(hash[lastIndex]!=lastIndex){
            lastIndex = hash[lastIndex];
            lis.add(nums[lastIndex]);
        }
        
        Collections.reverse(lis);
        return lis;
    }
}