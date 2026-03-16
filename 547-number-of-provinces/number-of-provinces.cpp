class Solution {
    private:
    void dfs(int v,vector<vector<int>>& isConnected,vector<int> &visited){
        visited[v]  = 1;
        for(int j=0;j<isConnected.size();j++){
            if(isConnected[v][j] && !visited[j]){
                visited[j] = 1;
                dfs(j,isConnected,visited);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        vector<int> visited(v);
        int cnt = 0;
        for(int i=0;i<v;i++){
            if(!visited[i]){
                cnt++;
                dfs(i,isConnected,visited);
            }
        }
        return cnt;
    // --------------bfs---------------
    //     int v = isConnected.size();
    //     vector<vector<int>> adj(v);
    //     vector<int> visited(v);
    //     for(int i=0;i<v;i++){
    //         for(int j=0;j<v;j++){
    //             if(isConnected[i][j] && i!=j){
    //                 adj[i].push_back(j);
    //             }
    //         }
    //     }

    //     int cnt = 0;
    //     for(int i=0;i<v;i++){
    //         if(!visited[i]){
    //             cnt++;
    //             queue<int> q;
    //             q.push(i);
    //             visited[i] = 1;
    //             while(!q.empty()){
    //                 int n = q.front();
    //                 q.pop();
    //                 for(auto &nbr: adj[n]){
    //                     if(!visited[nbr]){
    //                         visited[nbr] = 1;
    //                         q.push(nbr);
    //                     }
    //                 }
    //             }
    //         }
    //     }
    //     return cnt;
    }
};