class Solution {
private:
    bool hasCycle(vector<vector<int>> &graph, int u, vector<int> &vis, vector<int> &check){
        vis[u] = 2;
        check[u] = 0;
        for(int v : graph[u]){
            if(vis[v] == -1){
                if(hasCycle(graph, v, vis, check)){
                    return true;
                }
            } else if(vis[v] == 2){
                return true;
            }
        }

        check[u] = 1;
        vis[u] = 1;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, -1), check(n, 1);
        for(int i = 0; i < n; i++){
            if(vis[i] == -1){
                hasCycle(graph, i, vis, check);
            }
        }

        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(check[i]){
                ans.push_back(i);
            }
        }

        return ans;
    }
};