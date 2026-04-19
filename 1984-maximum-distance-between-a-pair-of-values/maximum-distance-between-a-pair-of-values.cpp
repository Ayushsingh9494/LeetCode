class Solution {
    private:
    int upperBound(vector<int> &arr,int target){
    int n = arr.size();
    int low = 0;
    int high = n-1;
    int idx = -1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid]>=target){
            idx = mid;
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return idx;
    }
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        vector<pair<int,int>> res;
        int n1 = nums1.size();
        int n2 = nums2.size();
        int maxD = 0;

        for(int i=0;i<n1;i++){
            maxD = max(maxD,upperBound(nums2,nums1[i])-i);
        }
        return maxD;
        // for(int i=0;i<n1;i++){
        //     for(int j=0;j<n2;j++){
        //         if(i<=j && nums1[i]<=nums2[j]){
        //             res.push_back({i,j});
        //         }
        //     }
        // }
        // int maxD = 0;
        // for(auto p: res){
        //     maxD = max(p.second-p.first,maxD);
        // }
        // return maxD;
    }
};