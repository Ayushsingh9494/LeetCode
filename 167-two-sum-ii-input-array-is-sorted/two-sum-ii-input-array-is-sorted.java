class Solution {
    public int[] twoSum(int[] numbers, int target) {
        // HashMap<Integer,Integer> map = new HashMap<>();
        // map.put(numbers[0],0);
        // for(int i=1;i<numbers.length;i++){
        //     int val = target-numbers[i];
        //     if(map.containsKey(val)) return new int[] {map.get(val)+1,i+1};
        //     map.put(numbers[i],i);
        // }
        // return new int[] {};
        int left = 0;
        int right = numbers.length-1;

        while(left<right){
            int sum = numbers[left] + numbers[right];
            if(sum==target) return new int[] {left+1,right+1};
            else if(sum>target) right--;
            else left++;
        }
        return new int[] {};
    }
}