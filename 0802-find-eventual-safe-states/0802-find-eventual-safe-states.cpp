class Solution {
private:
    int dfs(int u, vector<vector<int>> &graph, vector<int> &safe){
        if(safe[u] == 1){
            return 1;
        }

        int res = 1;    safe[u] = -1;
        for(int v : graph[u]){
            if (safe[v] == -1){ //cycle came
                res = 0;
            } else if(safe[v] == -2){ //not visited, so visiting
                res = dfs(v, graph, safe) && res;
            } else{
                res = safe[v] && res; // already visited
            }
        }

        safe[u] = res;
        return res;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> safe(graph.size(), -2);
        for(int i = 0; i < graph.size(); i++){
            if(safe[i] == -2){
                dfs(i, graph, safe);
            }
        }

        vector<int> ans;
        for(int i = 0; i < graph.size(); i++){
            if(safe[i] == 1){
                ans.push_back(i);
            }
        }

        return ans;
    }
};