class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if(grid[0][0] == 1){
            return -1;
        }

        vector<vector<int>> dis(n, vector<int>(m, 1e9));
        int nx[] = {0, 1, 1, 1, 0, -1, -1, -1};
        int ny[] = {1, 1, 0, -1, -1, -1, 0, 1};
        queue<int> q;
        q.push(0);
        dis[0][0] = 1;

        while(!q.empty()){
            int u = q.front(); q.pop();
            int x = u / m, y = u % m;
            for(int i = 0; i < 8; i++){
                int dx = x + nx[i];
                int dy = y + ny[i];
                if(dx >= 0 && dy >= 0 && dx < n && dy < m && grid[dx][dy] == 0 && dis[x][y] + 1 < dis[dx][dy]){
                    dis[dx][dy] = dis[x][y] + 1;
                    q.push(dx * m + dy);
                }
            }
        }

        return dis[n - 1][m - 1] == 1e9 ? -1 : dis[n - 1][m - 1];
    }
};