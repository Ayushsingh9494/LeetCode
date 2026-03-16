class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> rotten;
        int tot = 0;
        int cnt = 0;
        int min = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0) tot++;
                if(grid[i][j]==2) rotten.push({i,j});
            }
        }

        int dx[4] = {0,1,-1,0};
        int dy[4] = {1,0,0,-1}; 
        while(!rotten.empty()){
            int k = rotten.size();
            cnt += k;
            while(k--){
                int x = rotten.front().first;
                int y = rotten.front().second;
                rotten.pop();

                for(int i=0;i<4;i++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if(nx<0 || ny<0 || nx>=m || ny>=n || grid[nx][ny]!=1){
                        continue;
                    }
                    grid[nx][ny] = 2;
                    rotten.push({nx,ny});
                }
            }
            if(!rotten.empty()) min++;
        }
        return (tot==cnt)? min: -1;
    }
};