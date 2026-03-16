class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        vector<vector<int>> adj(v);
        vector<int> visited(v);
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(isConnected[i][j] && i!=j){
                    adj[i].push_back(j);
                }
            }
        }

        int cnt = 0;
        for(int i=0;i<v;i++){
            if(!visited[i]){
                cnt++;
                queue<int> q;
                q.push(i);
                visited[i] = 1;
                while(!q.empty()){
                    int n = q.front();
                    q.pop();
                    for(auto &nbr: adj[n]){
                        if(!visited[nbr]){
                            visited[nbr] = 1;
                            q.push(nbr);
                        }
                    }
                }
            }
        }
        return cnt;
    }
};