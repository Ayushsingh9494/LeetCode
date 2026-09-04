class Solution {
    public int subarraySum(int[] nums, int k) {
        int n = nums.length;
        int[] prefixSum = new int[n+1];
        prefixSum[0] = 0;
        for(int i=1;i<=n;i++){
            prefixSum[i] = prefixSum[i-1] + nums[i-1];
        }
        // [0,1,2,3]
        // [0,1,3,6]
        int cnt = 0;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<=n;j++){
                if(prefixSum[j] - prefixSum[i]==k){
                    cnt++;
                }
            }
        }
        return cnt;
    }
}