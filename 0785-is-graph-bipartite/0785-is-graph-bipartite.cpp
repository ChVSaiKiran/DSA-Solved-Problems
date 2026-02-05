class Solution {
private:
    bool canColor(int u, int val, vector<int> &color, vector<vector<int>> &graph){
        color[u] = val;
        for(int v : graph[u]){
            if(color[v] == val){
                return false;
            } else if(color[v] == -1 && !canColor(v, !val, color, graph)){
                return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for(int i = 0; i < n; i++){
            if(color[i] == -1 && !canColor(i, 0, color, graph)){
                return false;
            }
        }

        return true;
    }
};