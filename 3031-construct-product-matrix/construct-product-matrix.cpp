class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        const int MOD = 12345;
        int m = grid.size();
        int n = grid[0].size();
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
        for(int i=0;i<m*n;i++){
            prefix[i] = pref;
            pref = single[i]*pref%MOD;
        }
        for(int i=m*n-1;i>=0;i--){
            suffix[i] = suff;
            suff = single[i]*suff%MOD;
        }
        int idx=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                grid[i][j] = prefix[idx] * suffix[idx] % MOD;
                idx++;
            }
        }
        return grid;
    }
};