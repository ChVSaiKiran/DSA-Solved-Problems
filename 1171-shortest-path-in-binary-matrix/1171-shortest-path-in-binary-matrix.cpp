class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n - 1][n - 1] == 1){
            return -1;
        }

        vector<vector<int>> dis(n, vector<int>(n, 1e9));
        dis[0][0] = 1;

        int delRow[] = {0, 1, 1, 1, 0, -1, -1, -1};
        int delCol[] = {1, 1, 0, -1, -1, -1, 0, 1};
        queue<pair<int, int>> q;
        q.push({0, 0});

        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();

            for(int i = 0; i < 8; i++){
                int dx = x + delRow[i], dy = y + delCol[i];
                if(dx >= 0 && dy >= 0 && dx < n && dy < n){
                    if(grid[dx][dy] == 0 && dis[dx][dy] > dis[x][y] + 1){
                        dis[dx][dy] = dis[x][y] + 1;
                        q.push({dx, dy});
                    }
                }
            }
        }

        return dis[n - 1][n - 1] == 1e9 ? -1 : dis[n - 1][n - 1];
    }
};