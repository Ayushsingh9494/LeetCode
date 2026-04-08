class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const int MOD = 1000000007;
        int n = nums.size();
        for(auto query: queries){
        int l = query[0];
        int r = query[1];
        int k = query[2];
        int v = query[3];
        int idx = l;
        while(idx<=r){
            long long temp = nums[idx];
            nums[idx] =(temp*v)%MOD;
            idx+=k;
        }
        }
        int res = 0;
        for(int i=0;i<n;i++){
            res^=nums[i];
        }
        return res;
    }
};