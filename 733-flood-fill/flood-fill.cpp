class Solution {
    void dfs(int r, int c,vector<vector<int>>& image, int color, int currColor, vector<vector<int>>& visited,int m, int n){
        visited[r][c] = 1;
        image[r][c] = color;
        int delRow[] = {0,0,-1,1};
        int delCol[] = {-1,1,0,0};
        for(int i=0;i<4;i++){
            int newR = r + delRow[i];
            int newC = c + delCol[i];
            if(newR>=0 && newR<m && newC>=0 && newC<n && image[newR][newC]==currColor && visited[newR][newC]==0){
                dfs(newR,newC,image,color,currColor,visited,m,n);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        vector<vector<int>> visited(m,vector<int>(n));
        dfs(sr,sc,image,color,image[sr][sc],visited,m,n);
        return image;
    }
};