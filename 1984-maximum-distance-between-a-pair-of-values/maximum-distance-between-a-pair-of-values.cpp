class Solution {
    // private:
    // int upperBound(vector<int> &arr,int target){
    // int n = arr.size();
    // int low = 0;
    // int high = n-1;
    // int idx = -1;
    // while(low<=high){
    //     int mid = low + (high-low)/2;
    //     if(arr[mid]>=target){
    //         idx = mid;
    //         low = mid+1;
    //     }
    //     else{
    //         high = mid-1;
    //     }
    // }
    // return idx;
    // }
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int i = 0;
        int j = 0;
        int ans = 0;

        // two - pointers approach

        while(i<n1 && j<n2){
            if(nums1[i]<=nums2[j]){
                ans = max(ans,j-i);
                j++;
            }
            else{
                i++;
                if(i>j) j = i;
            }
        }
        return ans;
    }
};