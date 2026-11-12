class Solution {
    public int lengthOfLIS(int[] nums) {
        int n = nums.length;
        ArrayList<Integer> lis = new ArrayList<>();
        //[]
        lis.add(nums[0]);
        for(int i=1;i<=n-1;i++){
            int idx = Collections.binarySearch(lis,nums[i]);
            int upperBound;
            if(idx>=0) continue;
            else{
                upperBound = -(idx)-1;
            }
            if(upperBound==lis.size()) lis.add(nums[i]);
            else lis.set(upperBound,nums[i]);
        }
        return lis.size();
    }
}