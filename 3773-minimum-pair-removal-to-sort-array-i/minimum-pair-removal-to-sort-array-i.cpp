class Solution {
    private:
    bool isSorted(vector<int> &nums){
        int n = nums.size();
        bool flag = true;
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                flag = false;
                break;
            }
        }
        if(flag) return true;
        return false;
    }
public:
    int minimumPairRemoval(vector<int>& nums) {
        int steps = 0;
        while(nums.size()>1){
            if(isSorted(nums)) break;
            int idx = -1;
            int minSum = INT_MAX;
            for(int i=0;i<nums.size()-1;i++){
                int adjSum = nums[i]+nums[i+1];
                if(adjSum<minSum){
                    minSum = adjSum;
                    idx = i;
                }
            }
            steps++; 
            nums[idx] = minSum;
            nums.erase(nums.begin()+idx+1);
         }
        return steps;
    }
};