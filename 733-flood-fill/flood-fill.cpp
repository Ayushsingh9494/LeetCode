class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int path = image[sr][sc];
        image[sr][sc] = color;
        if(path==color) return image;
        queue<pair<int,int>> bfs;
        bfs.push({sr,sc});
        int dx[] = {0,0,-1,1};
        int dy[] = {-1,1,0,0};
        while(!bfs.empty()){
            int k = bfs.size();
                while(k--){
                int r = bfs.front().first;
                int c = bfs.front().second;
                bfs.pop();
                for(int i=0;i<4;i++){
                    int nr = r + dx[i];
                    int nc = c + dy[i];
                    if(nr<0||nc<0||nr>=m||nc>=n||image[nr][nc]!=path) continue;
                    image[nr][nc] = color;
                    bfs.push({nr,nc});
                }
            }
        }
    return image;
    }
};