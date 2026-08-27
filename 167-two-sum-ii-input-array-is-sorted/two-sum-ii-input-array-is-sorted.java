class Solution {
    public int[] twoSum(int[] numbers, int target) {
        HashMap<Integer,Integer> map = new HashMap<>();
        map.put(numbers[0],0);
        for(int i=1;i<numbers.length;i++){
            int val = target-numbers[i];
            if(map.containsKey(val)) return new int[] {map.get(val)+1,i+1};
            map.put(numbers[i],i);
        }
        return new int[] {};
    }
}