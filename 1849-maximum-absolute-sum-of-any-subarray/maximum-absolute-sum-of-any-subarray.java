class Solution {
    public int maxAbsoluteSum(int[] nums) {
        int maxSoFar = nums[0];
        int maxEndingHere = nums[0];
        int minSoFar = nums[0];
        int minEndingHere = nums[0];

        for(int i=1;i<nums.length;i++){
            maxEndingHere = Math.max(nums[i],maxEndingHere + nums[i]);
            maxSoFar = Math.max(maxSoFar,maxEndingHere);
        }

        for(int i=1;i<nums.length;i++){
            minEndingHere = Math.min(nums[i],minEndingHere + nums[i]);
            minSoFar = Math.min(minSoFar,minEndingHere);
        }

        return Math.max(maxSoFar,Math.abs(minSoFar));
    }
}