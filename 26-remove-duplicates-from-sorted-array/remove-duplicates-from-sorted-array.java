class Solution {
    public int removeDuplicates(int[] nums) {
        Map<Integer,Boolean> seen = new LinkedHashMap<>();
        int k=0;
        for(int i=0;i<nums.length;i++){
            if(!seen.containsKey(nums[i])){
                seen.put(nums[i],true);
            }
        }
        int i=0;
        for(int key: seen.keySet()){
            nums[i++] = key;
        }

        return seen.size();
    }
}