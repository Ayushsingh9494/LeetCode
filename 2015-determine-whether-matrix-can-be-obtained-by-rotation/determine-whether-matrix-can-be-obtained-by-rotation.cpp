class Solution {
    private:
    bool isEqual(vector<vector<int>> &mat, vector<vector<int>> &target){
        int n = mat.size();
        bool isIt = true;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]!=target[i][j]){
                    isIt = false;
                    break;
                }
            }
        }
        return isIt;
    }
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        for(int i=0;i<4;i++){
            for(int i=0;i<n;i++){
                for(int j=0;j<i;j++){
                    int temp = mat[j][i];
                    mat[j][i] = mat[i][j];
                    mat[i][j] = temp;
                }
            }
            for(int i=0;i<n;i++){
                reverse(mat[i].begin(),mat[i].end());
            }
            if(isEqual(mat,target)) return true;
        }
        return false;
    }
};