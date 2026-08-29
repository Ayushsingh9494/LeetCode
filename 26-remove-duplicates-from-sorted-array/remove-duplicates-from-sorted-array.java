class Solution {
    public int removeDuplicates(int[] nums) {
        HashMap<Integer,Integer> map = new HashMap<>();
        int k=0;
        for(int i=0;i<nums.length;i++){
            if(k==0 || !map.containsKey(nums[i])){
                map.put(nums[i],1);
                nums[k++] = nums[i];
            }
        }

        return k;
    }
}