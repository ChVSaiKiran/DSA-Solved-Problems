class Solution {
private:
    void dfs(vector<vector<int>>& arr, int u, vector<bool> &vis){
        vis[u] = true;
        for(int v = 0; v < arr.size(); v++){
            if(arr[u][v]){   
                if(!vis[v]){
                    dfs(arr, v, vis);
                }
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), ans = 0;
        vector<bool> vis(n, false);
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(isConnected, i, vis);
                ans++;
            }
        }

        return ans;
    }
};