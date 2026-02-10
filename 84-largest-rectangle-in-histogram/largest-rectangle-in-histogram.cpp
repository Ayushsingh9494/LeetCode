class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nextSmaller(n,n);
        vector<int> prevSmaller(n,-1);
        stack<int> st;
        stack<int> st2;
        //nextSmaller
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[i]<=heights[st.top()]){
                st.pop();
            }
        if(st.empty()) nextSmaller[i] = n;
        else nextSmaller[i] = st.top();
        st.push(i);
        }

        for(int i=0;i<n;i++){
            while(!st2.empty() && heights[i]<=heights[st2.top()]){
                st2.pop();
            }

        if(st2.empty()) prevSmaller[i] = -1;
        else prevSmaller[i] = st2.top();
        st2.push(i);
        }

        int maxArea = 0;
        for(int i=0;i<n;i++){
            int area = (nextSmaller[i]-prevSmaller[i]-1)*heights[i];
            maxArea = max(maxArea,area);
        }
        return maxArea;
    }
};