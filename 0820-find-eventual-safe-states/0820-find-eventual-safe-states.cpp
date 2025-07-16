class Solution {
private:
    bool dfs(int u, vector<int> &vis, vector<bool> &safe, vector<vector<int>> &graph){
        if(safe[u]){
            return true;
        }

        if(vis[u] != 0){
            return safe[u];
        }

        vis[u] = 2;
        bool val = true;
        for(int v : graph[u]){
            val = dfs(v, vis, safe, graph) && val;
        }

        vis[u] = 1;
        return safe[u] = val;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> vis(n, 0);
        vector<bool> safe(n, false);
        for(int i = 0; i < n; i++){
            if(vis[i] == 0)
            dfs(i, vis, safe, graph);
        }

        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(safe[i]){
                ans.push_back(i);
            }
        }

        return ans;
    }
};