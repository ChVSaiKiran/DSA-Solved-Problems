class Solution {
private:
    bool dfs(vector<vector<int>> &graph, int u, vector<int> &vis, vector<int> &dp){
        bool flag = true;
        vis[u] = 2;

        for(int v : graph[u]){
            if(vis[v] == -1){
                flag = dfs(graph, v, vis, dp) && flag;
            } else if(vis[v] == 2){
                return dp[u] = false;
            } else{
                flag = flag && (dp[v] == 1);
            }
        }

        vis[u] = 1;
        return dp[u] = flag;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> dp(n, -1), vis(n, -1);
        for(int i = 0; i < n; i++){
            if(vis[i] == -1){
                dfs(graph, i, vis, dp);
            }
        }
        
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(dp[i] == 1){
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};