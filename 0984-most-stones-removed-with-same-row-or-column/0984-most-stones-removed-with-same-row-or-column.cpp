class Solution {
private:
    unordered_map<int, vector<int>> rows, cols;
    void dfs(int x, int y, vector<vector<bool>> &vis){
        vis[x][y] = true;
        for(int ny : rows[x]){
            if(y != ny && vis[x][ny] == false){
                dfs(x, ny, vis);
            }
        }

        for(int nx : cols[y]){
            if(x != nx && vis[nx][y] == false){
                dfs(nx, y, vis);
            }
        }
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = -1, m = -1;
        for(auto stone : stones){
            int x = stone[0], y = stone[1];
            rows[x].push_back(y), cols[y].push_back(x);
            n = max(n, x), m = max(m, y);
        }

        int ans = stones.size(); // Assume that we can pick all the stones
        vector<vector<bool>> vis(n + 1, vector<bool> (m + 1, false));
        for(auto stone : stones){
            int x = stone[0], y = stone[1];
            if(vis[x][y] == 0){
                dfs(x, y, vis); // In Every Group of Connected Stones, at the end we will left with one stone
                ans--;
            }
        }

        return ans;
    }
};