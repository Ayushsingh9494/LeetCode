class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left[n];
        left[0] = height[0];
        for(int i=1;i<n;i++){
            left[i] = max(left[i-1],height[i]);
        }

        int right[n];
        right[n-1] = height[n-1];
        for(int i=n-2;i>=0;i--){
            right[i] = max(right[i+1],height[i]);
        }

        int cnt = 0;
        for(int i=0;i<n;i++){
            cnt += min(left[i],right[i])-height[i];
        }
        return cnt;
    }
};






// int n = height.size();
//         int res = 0;
//         int left = 0;
//         int right = n-1;
//         int lmax = 0;
//         int rmax = 0;
//         while(left<right){
//             if(height[left]<=height[right]){
//                 if(lmax<height[left]){
//                     lmax = height[left];
//                 }
//                 else{
//                     res += lmax-height[left];
//                 }
//                 left++;
//             }
//             else{
//                 if(rmax<height[right]){
//                     rmax = height[right];
//                 }
//                 else{
//                     res += rmax-height[right];
//                 }
//                 right--;
//             }
//         }
//         return res;