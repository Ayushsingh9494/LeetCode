class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        const int MOD = 12345;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans(m,vector<int>(n));
        long long pref=1;
        long long suff = 1;
        vector<int> single;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                single.push_back(grid[i][j]);
            }
        }
        vector<long long> suffix(m*n);
        vector<long long> prefix(m*n);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[i][j] = pref;
                pref = grid[i][j]*pref%MOD;
            }
        }
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                ans[i][j] = ans[i][j] * suff % MOD;
                suff = grid[i][j]* suff % MOD;
            }
        }
        
        return ans;
    }
};