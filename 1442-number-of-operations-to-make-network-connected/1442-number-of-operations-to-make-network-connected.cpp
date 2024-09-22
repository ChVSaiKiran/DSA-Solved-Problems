class Solution {
private:
    void dfs(vector<int> adj[], int u, vector<bool> &vis){
        vis[u] = true;

        for(int v : adj[u]){
            if(!vis[v]){
                dfs(adj, v, vis);
            }
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int cnt = 0, edgesCnt = connections.size();

        if(edgesCnt < n - 1){
            return -1;
        }

        vector<int> adj[n];

        for(auto it : connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<bool> vis(n, false);
        

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(adj, i, vis);
                cnt++;
            }
        }

        return cnt - 1;
    }
};