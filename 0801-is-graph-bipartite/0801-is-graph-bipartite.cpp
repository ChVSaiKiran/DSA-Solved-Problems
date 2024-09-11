class Solution {
private:
    bool dfs(vector<vector<int>>& graph, int u, vector<int> &arr){
        bool flag = true;
        for(int v : graph[u]){
            if(arr[v] == -1){
                arr[v] = !arr[u];
                flag = dfs(graph, v, arr) && flag;
            } else if(arr[v] == arr[u]){
                return false;
            }
        }
        return flag;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> arr(n, -1);
        for(int i = 0; i < n; i++){
            if(arr[i] == -1){
                arr[i] = 0;
                if(dfs(graph, i, arr) == false){
                    return false;
                }
            }
        }
        return true;
    }
};