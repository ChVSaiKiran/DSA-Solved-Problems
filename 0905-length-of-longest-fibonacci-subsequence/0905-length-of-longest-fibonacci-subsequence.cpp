class Solution {
private:
    int fun(vector<int> &arr, int x1, int x2, vector<vector<int>> &dp){
        if(x2 >= arr.size()){
            return 0;
        }

        if(dp[x1][x2] != -1){
            return dp[x1][x2];
        }

        for(int x3 = x2 + 1; x3 < arr.size(); x3++){
            long temp = (long)arr[x1] + (long)arr[x2];
            if(temp == arr[x3]){
                return (dp[x1][x2] = 1 + fun(arr, x2, x3, dp));
            }
            
            if(temp < arr[x3]){
                break;
            }
        }

        return dp[x1][x2] = 0;
    }

public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size(), ans = 0;
        vector<vector<int>> dp(n, vector<int>(n, -1));

        for(int x1 = 0; x1 < n; x1++){
            for(int x2 = x1 + 1; x2 < n; x2++){
                ans = max(ans, fun(arr, x1, x2, dp));
            }
        }
        return ans != 0 ? ans + 2 : 0;
    }
};