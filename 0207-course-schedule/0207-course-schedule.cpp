class Solution {
private:
    bool hasCycle(vector<int> adj[], int u, vector<int> &vis){
        vis[u] = 2;
        for(int v : adj[u]){
            if(vis[v] == 0){
                if(hasCycle(adj, v, vis)){
                    return true;
                }
            } else if(vis[v] == 2){
                return true;
            }
        }
        vis[u] = 1;
        return false;
    }

public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int> adj[n];
        for(auto &it : prerequisites){
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(n, 0);
        for(int i = 0; i < n; i++){
            if(vis[i] == 0 && hasCycle(adj, i, vis)){
                return false;
            }
        }
        
        return true;
    }
};