class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>> vis(n, vector<int>(m, INT_MAX));
        vis[0][0] = 0;

        int delRow[] = {0, 1, 0, -1};
        int delCol[] = {1, 0, -1, 0};
        queue<pair<int, int>> q;    q.push({0, 0});
        while(!q.empty()){
            int x = q.front().first;    
            int y = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++){
                int nx = x + delRow[i]; int ny = y + delCol[i];
                if(nx >= 0 && ny >= 0 && nx < n && ny < m){
                    int val = 0;
                    if(vis[x][y] <= moveTime[nx][ny]){
                        val = (moveTime[nx][ny] - vis[x][y]) + 1;
                    } else{
                        val = 1;
                    }

                    if(vis[x][y] + val < vis[nx][ny]){
                        vis[nx][ny] = vis[x][y] + val;  q.push({nx, ny});
                    }
                }
            }
        }

        return vis[n - 1][m - 1];
    }
};