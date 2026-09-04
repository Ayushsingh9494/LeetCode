class Solution {
    public int removeDuplicates(int[] nums) {
        int j = 0;
        int i = 1;
        while(i<nums.length){
            if(nums[i] != nums[j]){
                j++;
                nums[j] = nums[i];
            }
            else{
                i++;
            }
        }
        return ++j;
    }
    
}