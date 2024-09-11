class Solution {
private:
    bool bfs(vector<vector<int>> graph, int u, vector<int> &color){
        queue<int> q({u});
        color[u] = 0;
        while(!q.empty()){
            int u = q.front(); q.pop();
            for(int v : graph[u]){
                if(color[v] == color[u]){
                    return false;
                } else if(color[v] == -1){
                    color[v] = !color[u];
                    q.push(v);
                }
            }
        }
        return true;
    }

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
        vector<int> color(n, -1);
        for(int i = 0; i < n; i++){
            if(color[i] == -1){
                if(bfs(graph, i, color) == false){
                    return false;
                }

                // if(dfs(graph, i, color) == false){
                //     return false;
                // }
            }
        }
        return true;
    }
};