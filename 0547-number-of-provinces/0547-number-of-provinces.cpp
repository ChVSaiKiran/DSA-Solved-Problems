class Solution {
private:
    int row[4] = {0, 1, 0, -1};
    int col[4] = {1, 0, -1, 0};

    void dfs(vector<vector<int>>& arr, int x, int y, vector<vector<bool>> &vis){
        if(vis[x][y]){
            return;
        }
        
        vis[x][y] = true;
        for(int i = 0; i < 4; i++){
            int dx = x + row[i];
            int dy = y + col[i];
            if(dx >= 0 && dy >= 0 && dx < arr.size() && dy < arr[0].size() && !vis[dx][dy] && arr[x][y]){
                dfs(arr, dx, dy, vis);
            }
        }

    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), m = isConnected[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && isConnected[i][j]){
                    dfs(isConnected, i, j, vis); cnt++;
                }
            }
        }

        return cnt;
    }
};