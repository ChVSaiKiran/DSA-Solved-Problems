class Solution {
private:
    long fun(vector<vector<int>>& arr, int i, int j,  vector<vector<long>> &dp, vector<vector<bool>> &vis){
        if(i < 0 || j < 0 || j >= arr[i].size()){
            return INT_MAX;
        } 
        
        if(i == 0){
            return dp[0][0] = arr[0][0];
        } 

        if(vis[i][j]){
            return dp[i][j];
        }
        
        vis[i][j] = true;

        long lt = fun(arr, i - 1, j, dp, vis), rt = fun(arr, i - 1, j - 1, dp, vis);
        return dp[i][j] = min(lt, rt) + arr[i][j];
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size(), m = triangle.back().size();
        vector<vector<long>> dp;
        vector<vector<bool>> vis;

        for(int i = 1; i <= m; i++){
            dp.push_back(vector<long> (i, INT_MAX));
            vis.push_back(vector<bool> (i, false));
        }
        long ans = INT_MAX;
        for(int j = 0; j < m; j++){
            ans = min(ans, fun(triangle, n - 1, j, dp, vis));
        }
        return ans;
    }
};