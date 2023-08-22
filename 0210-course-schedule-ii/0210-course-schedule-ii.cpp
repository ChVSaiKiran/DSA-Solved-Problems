class Solution {
    vector<int> ans;
    bool dfs(int V, vector<int> adj[], vector<int> &vis, int u){
        vis[u] = 2;
        for(int v: adj[u]){
            if(vis[v] == 0){
                if(dfs(V, adj, vis, v))
                    return true;
            }
            else if(vis[v] == 2)
                return true;
        }
        vis[u] = 1;
        ans.push_back(u);
        return false;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> vis(numCourses, 0);
        vector<int> adj[numCourses];
        for(auto it:prerequisites)
            adj[it[0]].push_back(it[1]);
        for(int i = 0; i < numCourses; i++)
            if(vis[i] == 0)
                if(dfs(numCourses, adj, vis, i))
                    return {};
        return ans;
    }
};