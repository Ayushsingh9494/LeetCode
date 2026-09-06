class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        List<Integer> arr = new ArrayList<>();
        // Map<Integer,Integer> map = new HashMap<>();

        // for(int i: nums){
        //     map.put(i,map.getOrDefault(i,0)+1);
        // }

        // for (int key : map.keySet()) {
        //     if(map.get(key)==2){
        //         arr.add(key);
        //     }  // extra lookup
        // }

        for(int i=0;i<nums.length;i++){
            int index = Math.abs(nums[i]) - 1;
            if(nums[index] < 0){
                arr.add(Math.abs(nums[i]));
            }
            nums[index] = -nums[index];
        }

        return arr;
    }
}