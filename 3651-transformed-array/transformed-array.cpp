class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n,0);
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                result[i] = nums[i];
            }
            else if(nums[i]<0){
                int absI = abs(nums[i]);
                int idx = ((i-absI)%n + n)%n;
                result[i] = nums[idx];
            }
            else{
                int idx = (i+nums[i])%n;
                result[i] = nums[idx];
            }
        }
        return result;
    }
};