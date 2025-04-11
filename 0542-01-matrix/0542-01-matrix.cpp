class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {        
        int n = mat.size();
        int m = mat[0].size();

        queue<pair<int, int>> q;
        vector<vector<int>> ans(n, vector<int> (m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0){
                    ans[i][j] = 0;
                    q.push({i, j});
                } else{
                    ans[i][j] = INT_MAX;
                }
            }
        }

        int delRow[] = {0, 1, 0, -1};
        int delCol[] = {1, 0, -1, 0};
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            for(int i = 0; i < 4; i++){
                int nx = x + delRow[i];
                int ny = y + delCol[i];
                if(nx >= 0 && ny >= 0 && nx < n && ny < m){
                    if(ans[nx][ny] == INT_MAX){
                        q.push({nx, ny});
                    }
                    ans[nx][ny] = min(ans[nx][ny], ans[x][y] + 1);
                }
            }
            q.pop();
        }
        return ans;
    }
};