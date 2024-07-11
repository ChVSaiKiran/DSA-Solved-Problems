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
    int minimumTotal(vector<vector<int>>& arr) {
        int n = arr.size(), m = arr.back().size();
        vector<long> dp;

        for(int i = 0; i < n; i++){
            vector<long> curr(m, INT_MAX);
            for(int j = 0; j < arr[i].size(); j++){
                if(i == 0 && j == 0){
                    curr[0] = arr[0][0];
                } else{
                    long lt = dp[j], rt = j > 0 ? dp[j - 1] : INT_MAX;
                    curr[j] = min(lt , rt) + arr[i][j];
                }
            }
            dp = curr;
        }
        return *min_element(dp.begin(), dp.end());
    }
};