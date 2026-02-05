class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m, INT_MAX));

        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0){
                    ans[i][j] = 0;  q.push({i, j});
                }
            }
        }

        int row[4] = {0, 1, 0, -1};
        int col[4] = {1, 0, -1, 0};
        while(!q.empty()){
            int x = q.front().first, y = q.front().second;  q.pop();
            for(int i = 0 ; i < 4; i++){
                int dx = x + row[i];    int dy = y + col[i];
                if(dx >= 0 && dy >= 0 && dx < n && dy < m && mat[dx][dy] == 1 && ans[dx][dy] > ans[x][y] + 1){
                    ans[dx][dy] = ans[x][y] + 1;
                    q.push({dx, dy});
                }
            }
        }

        return ans;
    }
};