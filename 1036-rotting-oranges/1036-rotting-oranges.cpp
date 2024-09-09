class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int cnt = 0, frsh = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<int,int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    vis[i][j] = true;
                    q.push({i, j});
                } else if(grid[i][j] == 1){
                    frsh++;
                }
            }
        }

        while(frsh != 0 && !q.empty()){
            int size = q.size();
            int delRow[] = {0, 1, 0, -1};
            int delCol[] = {1, 0, -1, 0};
            while(size--){
                auto [x, y] = q.front();
                q.pop();
                for(int i = 0; i < 4; i++){
                    int nx = x + delRow[i];
                    int ny = y + delCol[i];
                    if(nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == 1 && !vis[nx][ny]){
                        q.push({nx, ny});
                        vis[nx][ny] = true;
                        frsh--;
                    }
                }
            }
            cnt++;
        }
        
        return frsh == 0 ? cnt : -1;
    }
};