class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> arr;
        for(auto row: grid){
            for(int i: row){
                arr.push_back(i);
            }
        }
        nth_element(arr.begin(), arr.begin()+m*n/2, arr.end());
        int median = arr[m*n/2];
        cout << median;
        long long steps = 0;
        for(int i=0;i<m*n;i++){
            if(arr[i]%x != median%x) return -1;
            steps += abs(arr[i]-median)/x;
        }
        return steps;
    }
};