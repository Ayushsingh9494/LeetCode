class Solution {
    // private:
    // long rowSum(vector<int> row){
    //     long sum = 0;
    //     for(auto i: row){
    //         sum += i;
    //     }
    //     return sum;
    // }

    // long colSum(int c,int m, int n,vector<vector<int>> &grid){
    //     if(c>n) return 0;
    //     long sum =0;
    //     for(int i=0;i<m;i++){
    //         sum += grid[i][c];
    //     }
    //     return sum;
    // }
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        long rowPref[m][n];
        long colPref[m][n];
        long totalSum = 0;
        for(int i=0;i<m;i++){
            rowPref[i][0] = grid[i][0];
            for(int j=1;j<n;j++){
                rowPref[i][j] = rowPref[i][j-1] + grid[i][j];
            }
            totalSum += rowPref[i][n-1];
        }
        if(totalSum%2!=0) return false;

        for(int j=0;j<n;j++){
            colPref[0][j] = grid[0][j];
            for(int i=1;i<m;i++){
                colPref[i][j] = colPref[i-1][j] + grid[i][j];
            } 
        }
        long topSum=0,leftSum=0;

        for(int i=0;i<m;i++){
            topSum += rowPref[i][n-1];
            if(topSum==totalSum/2) return true;
        }

        for(int j=0;j<n;j++){
            leftSum += colPref[m-1][j];
            if(leftSum==totalSum/2) return true;
        }
        // for(int i=0;i<m;i++){
        //     topSum += rowSum(grid[i]);
        //     if(topSum == totalSum/2) return true;
        // }

        // for(int i=0;i<n;i++){
        //     leftSum += colSum(i,m,n,grid);
        //     if(leftSum == totalSum/2) return true;
        // }
        return false;
    }
};