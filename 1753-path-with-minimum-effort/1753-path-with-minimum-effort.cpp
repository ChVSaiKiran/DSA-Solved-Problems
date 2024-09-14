// Binary Search Approach
// class Solution {
// private:
//     bool f(vector<vector<int>>& heights, int k){
//         int n = heights.size(), m = heights[0].size();
//         if(n == 1 && m == 1){
//             return true;
//         }

//         vector<vector<bool>> vis(n, vector<bool>(m, false));

//         int delRow[] = {0, 1, 0, -1};
//         int delCol[] = {1, 0, -1, 0};

//         queue<pair<int,int>> q;
//         q.push({0, 0});
//         vis[0][0] = true;

//         while(!q.empty()){
//             int x = q.front().first;
//             int y = q.front().second;
//             q.pop();

//             for(int i = 0; i < 4; i++){
//                 int dx = x + delRow[i];
//                 int dy = y + delCol[i];
//                 if(dx >= 0 && dy >= 0 && dx < n && dy < m && vis[dx][dy] == false){
//                     int val = abs(heights[x][y] - heights[dx][dy]);
//                     if(k >= val){
//                         if(dx == n - 1 && dy == m - 1){
//                             return true;
//                         }
//                         q.push({dx, dy});
//                         vis[dx][dy] = true;
//                     }
//                 }
//             }
//         }

//         return false;
//     }
// public:
//     int minimumEffortPath(vector<vector<int>>& heights) {

//         int mini = 1e6, maxi = 1;
//         for(auto it : heights){
//             for(int i : it){
//                 mini = min(mini, i);
//                 maxi = max(maxi, i);
//             } 
//         }

//         int l = 0, r = (maxi - mini), ans = INT_MAX;
//         while(l <= r){
//             int m = l + (r - l) / 2;
//             bool possible = f(heights, m);
//             if(possible){
//                 ans = m;
//                 r = m - 1;
//             } else{
//                 l = m + 1;
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        int delRow[] = {0, 1, 0, -1};
        int delCol[] = {1, 0, -1, 0};

        set<pair<int,pair<int,int>>> st;
        st.insert({0, {0, 0}});
        dist[0][0] = 0;

        while(!st.empty()){
            auto it = *(st.begin());
            int effort = it.first;
            int x = it.second.first, y = it.second.second;
            st.erase(it);

            for(int i = 0; i < 4; i++){
                int dx = x + delRow[i];
                int dy = y + delCol[i];
                if(dx >= 0 && dy >= 0 && dx < n && dy < m){
                    int currEffort = abs(heights[dx][dy] - heights[x][y]);
                    currEffort = max(currEffort, effort);
                    if(dist[dx][dy] > currEffort){
                        dist[dx][dy] = currEffort;
                        st.insert({currEffort, {dx, dy}});
                    }
                }
            }
        }

        return dist[n - 1][m - 1];
    }
};