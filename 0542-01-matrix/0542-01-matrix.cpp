class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 1e6));
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<int,int>> q;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(mat[i][j] == 0){
                    q.push({i, j});
                    ans[i][j] = 0;
                }
        while(!q.empty()){
            int sr = q.front().first, sc = q.front().second;
            visited[sr][sc] = true;
            q.pop();
            if(sr + 1 < n){
                ans[sr + 1][sc] = min(ans[sr][sc] + 1, ans[sr + 1][sc]);
                if(!visited[sr + 1][sc])
                    q.push({sr + 1, sc});
            }
            if(sc + 1 < m){
                ans[sr][sc + 1] = min(ans[sr][sc] + 1, ans[sr][sc + 1]);
                if(!visited[sr][sc + 1])
                    q.push({sr, sc + 1});
            }
            if(sr - 1 >= 0){
                ans[sr - 1][sc] = min(ans[sr][sc] + 1, ans[sr - 1][sc]);
                if(!visited[sr - 1][sc])
                    q.push({sr - 1, sc});
            }
            if(sc - 1 >= 0){
                ans[sr][sc - 1] = min(ans[sr][sc] + 1, ans[sr][sc - 1]);
                if(!visited[sr][sc - 1])
                    q.push({sr, sc - 1});
            }
        }
        return ans;
    }
};