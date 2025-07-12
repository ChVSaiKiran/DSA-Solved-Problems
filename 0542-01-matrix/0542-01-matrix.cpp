class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int, int>> q;
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 1e9));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0){
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        int delRow[] = {0, 1, 0, -1};
        int delCol[] = {1, 0, -1, 0};

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;   q.pop();
            for(int i = 0; i < 4; i++){
                int nx = x + delRow[i];
                int ny = y + delCol[i];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && ans[nx][ny] > ans[x][y] + 1){
                    ans[nx][ny] = ans[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        return ans;
    }
};