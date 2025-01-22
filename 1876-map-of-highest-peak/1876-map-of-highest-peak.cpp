class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        queue<int> q;
        int n = isWater.size(), m = isWater[0].size();
        vector<vector<int>> ans(n, vector<int>(m, INT_MAX));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(isWater[i][j] == 1){
                    int idx = (i * m) + j;
                    q.push(idx);
                    ans[i][j] = 0;
                }
            }
        }

        int delRow[] = {0, 1, 0, -1};
        int delCol[] = {1, 0, -1, 0};

        while(!q.empty()){
            int size = q.size();
            while(size-- > 0){
                int idx = q.front(); q.pop();
                int r = idx / m, c = idx % m;
                int lvl = ans[r][c];

                for(int i = 0; i < 4; i++){
                    int nx = r + delRow[i];
                    int ny = c + delCol[i];
                    if(nx >= 0 && nx < n && ny >= 0 && ny < m && ans[nx][ny] > lvl + 1){
                        ans[nx][ny] = lvl + 1;
                        q.push((nx * m) + ny);
                    }
                }
            }
        }

        return ans;
    }
};