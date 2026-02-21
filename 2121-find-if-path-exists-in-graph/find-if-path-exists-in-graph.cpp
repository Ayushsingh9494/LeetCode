class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source==destination) return true;
        vector<vector<int>> adj(n);
        vector<int> visited(n);
        for(int i=0;i<edges.size();i++){
            int edgeFrom = edges[i][0];
            int edgeTo = edges[i][1];
            adj[edgeFrom].push_back(edgeTo);
            adj[edgeTo].push_back(edgeFrom);
        }

        queue<int> q;
        q.push(source);
        visited[source] = 1;
        while(!q.empty()){
            int curr =  q.front();
            q.pop();
            for(int i: adj[curr]){
                if(!visited[i]){
                    visited[i] = true;
                    if(i==destination) return true;
                    q.push(i);
                }
            }
        }
        return false;
    }
};