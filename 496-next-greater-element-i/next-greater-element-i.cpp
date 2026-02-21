class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        vector<int> greater(nums2.size(),-1);
        for(int i=nums2.size()-1;i>=0;i--){
            while(!st.empty() && nums2[i]>=st.top()){
                st.pop();
            }

            if(!st.empty()) greater[i] = st.top();

            st.push(nums2[i]);
        }
        for(int i=0;i<nums1.size();i++){
            auto idx = find(nums2.begin(),nums2.end(),nums1[i]);
            int id = idx - nums2.begin();
            nums1[i] = greater[id];
        }
        return nums1;
    }
};







// int n1 = nums1.size();
//         int n2 = nums2.size();
//         vector<int> res;
//         for(int i=0;i<n1;i++){
//             int greater = -1;
//             auto it = find(nums2.begin(),nums2.end(),nums1[i]);
//             if(it!=nums2.end()){
//                 size_t idx = it - nums2.begin();
//                 for(int j=idx;j<n2;j++){
//                     if(nums2[j]>nums1[i]){
//                         greater = nums2[j];
//                         break;
//                     }
//                 }
//             }
//             res.push_back(greater);
//         }
//         return res;