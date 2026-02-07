class Solution {
private:
    int n = 0, m = 0;
    int row[4] = {0, 1, 0, -1};
    int col[4] = {1, 0, -1, 0};

    bool isValid(int dx, int dy){
        return dx >= 0 && dy >= 0 && dx < n && dy < m;
    }
    
    bool canVisit(vector<vector<int>>& heights, int allowedVal){
        if(n == 1 && m == 1){
            return true;
        }

        queue<pair<int, int>> q;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        q.push({0, 0}); vis[0][0] = true;

        while(!q.empty()){
            auto [x, y] =  q.front();   q.pop();
            for(int i = 0; i < 4; i++){
                int dx = x + row[i];    int dy = y + col[i];
                if(isValid(dx, dy) && allowedVal >= abs(heights[x][y] - heights[dx][dy]) && !vis[dx][dy]){
                    if(dx == n - 1 && dy == m - 1){
                        return true;
                    }
                    vis[dx][dy] = true; q.push({dx, dy});
                }
            }
        }

        return false;
    }
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        this -> n = heights.size(), this -> m = heights[0].size();

        int l = 0, r = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                for(int k = 0; k < 4; k++){
                    int dx = i + row[k];
                    int dy = j + col[k];
                    if(isValid(dx, dy)){
                        r = max(r, abs(heights[i][j] - heights[dx][dy]));
                    }
                }
            }
        }

        int ans = 1e9;
        while(l <= r){
            int m = (l + r) / 2;
            if(canVisit(heights, m)){
                ans = m;    r = m - 1;
            } else{
                l = m + 1;
            }
        }

        return ans;
    }
};