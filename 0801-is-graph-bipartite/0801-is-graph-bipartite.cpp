class Solution {
private:
    bool cancolour(vector<vector<int>>& graph, int u, vector<int> &colour){
        for(int v : graph[u]){
            if(colour[v] == -1){
                colour[v] = !colour[u];
                if(cancolour(graph, v, colour) == false){
                    return false;
                }
            } else if(colour[v] == colour[u]){
                return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colour(n, -1);
        for(int i = 0; i < n; i++){
            if(colour[i] == -1){
                colour[i] = 0;
                if(cancolour(graph, i, colour) == false){
                    return false;
                }
            }
        }
        return true;
    }
};