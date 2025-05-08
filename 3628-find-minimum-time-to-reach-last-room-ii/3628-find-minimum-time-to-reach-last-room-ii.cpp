class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<pair<int, int>>> vis(n, vector<pair<int, int>>(m, {INT_MAX, INT_MAX}));
        vis[0][0] = {0, 1}; 

        int delRow[] = {0, 1, 0, -1};
        int delCol[] = {1, 0, -1, 0};

        set<pair<int, int>> q;
        q.insert({1, 0});

        while(!q.empty()){
            int dis = q.begin()->first;
            int idx = q.begin()->second;
            q.erase(q.begin());

            int x = idx/m, y = idx%m;
            for(int i = 0; i < 4; i++){
                int nx = x + delRow[i];
                int ny = y + delCol[i];

                if(nx >= 0 && ny >= 0 && nx < n && ny < m){
                    int currD = vis[x][y].first, currT = vis[x][y].second;
                    int val = currD + currT, newT = (currT == 1) ? 2 : 1;

                    if(currD < moveTime[nx][ny]){
                        val += (moveTime[nx][ny] - currD);
                    }

                    auto it = make_pair(val, newT);

                    if(it < vis[nx][ny]){
                        vis[nx][ny] = it;
                        q.insert({val, nx * m + ny});
                    }
                    
                }
            }
        }

        return vis[n - 1][m - 1].first;
    }
};