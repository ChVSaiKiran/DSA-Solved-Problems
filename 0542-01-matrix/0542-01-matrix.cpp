class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m, -1));
        queue<pair<int,int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0){
                    q.push({i, j});
                    ans[i][j] = 0;
                }
            }
        }

        int delRow[] = {0, 1, 0, -1};
        int delCol[] = {1, 0, -1, 0};
        int cnt = 1;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto [x, y] = q.front();
                q.pop();
                for(int i = 0; i < 4; i++){
                    int dx = x + delRow[i];
                    int dy = y + delCol[i];
                    if(dx >= 0 && dy >= 0 && dx < n && dy < m && ans[dx][dy] == -1){
                        ans[dx][dy] = cnt;
                        q.push({dx, dy});
                    }
                }
            }
            cnt++;
        }
        
        return ans;
    }
};