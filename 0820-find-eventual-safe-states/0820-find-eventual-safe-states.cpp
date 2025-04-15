class Solution {
private:
    bool dfs(int u, vector<vector<int>> &graph, vector<int> &vis, vector<int> &ans){
        if(vis[u] == -1){
            return false;
        }

        if(vis[u] != -2){
            return vis[u];
        }

        bool flag = true;
        vis[u] = -1;

        for(int v : graph[u]){
            flag = dfs(v, graph, vis, ans) && flag;
        }

        if(flag){
            ans.push_back(u);
        }
        
        return vis[u] = flag;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        int n = graph.size();
        vector<int> vis(n, -2);

        for(int i = 0; i < n; i++){
            dfs(i, graph, vis, ans);
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};