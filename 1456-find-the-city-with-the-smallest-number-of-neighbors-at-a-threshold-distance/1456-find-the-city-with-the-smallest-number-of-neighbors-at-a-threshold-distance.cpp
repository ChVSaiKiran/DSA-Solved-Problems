class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dis(n, vector<int>(n, 1e9));
        for(auto it : edges){
            int u = it[0], v = it[1], edgW = it[2];
            dis[u][v] = edgW;
            dis[v][u] = edgW;
        }

        for(int i = 0; i < n; i++){
            dis[i][i] = 0;
        }

        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }

        int ans = -1, min_cnt = n + 1; 

        for(int i = 0; i < n; i++){
            int cnt = 0;
            for(int j = 0; j < n; j++){
                if(dis[i][j] <= distanceThreshold){
                    cnt++;
                }
            }
            if(min_cnt >= cnt){
                ans = i, min_cnt = cnt;
            }
        }

        return ans;
    }
};