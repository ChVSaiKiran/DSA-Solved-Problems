class Solution {
private:
    bool canColor(int u, int color, vector<int> &colors, vector<vector<int>> &adj){
        colors[u] = color;
        for(int v : adj[u]){
            if(colors[v] == color){
                return false;
            } else if(colors[v] == -1 && !canColor(v, !color, colors, adj)){
                return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> colors(n, -1);
        for(int i = 0; i < n; i++){
            if(colors[i] == -1 && !canColor(i, 0, colors, graph)){
                return false;
            }
        }

        return true;
    }
};