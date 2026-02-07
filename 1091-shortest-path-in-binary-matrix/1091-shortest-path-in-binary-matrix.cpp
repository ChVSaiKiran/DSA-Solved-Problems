class Solution {
private:
    int row[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    int col[8] = {1, 1, 0, -1, -1, -1, 0, 1};

public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1){
            return -1;
        }

        int n = grid.size();
        vector<vector<int>> dis(n, vector<int>(n, -1));
        queue<pair<int, int>> q;    q.push({0, 0});     dis[0][0] = 1;

        while(!q.empty()){
            auto [x, y] = q.front(); q.pop();
            for(int i = 0; i < 8; i++){
                int dx = x + row[i];    int dy = y + col[i];
                if(dx >= 0 && dy >= 0 && dx < n && dy < n && grid[dx][dy] == 0 && dis[dx][dy] == -1){
                    q.push({dx, dy});   dis[dx][dy] = dis[x][y] + 1;
                }
            }
        }

        return dis[n - 1][n - 1];
    }
};