class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        
        vector<vector<int>> ans(n, vector<int>(m, 0));
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<int,int>> q;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(mat[i][j] == 0){
                    q.push({i, j});
                    vis[i][j] = true;
                }
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        int dis = 0;
        while(!q.empty()){
            dis++;
            int size = q.size();
            while(size--){
                int row = q.front().first, col = q.front().second;
                q.pop();
                for(int i = 0; i < 4; i++){
                    int nrow = row + delrow[i];
                    int ncol = col + delcol[i];
                    if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && !vis[nrow][ncol]){
                        vis[nrow][ncol] = true;
                        ans[nrow][ncol] = dis;
                        q.push({nrow, ncol});
                    }
                }
            }
        }
        return ans;
    }
};