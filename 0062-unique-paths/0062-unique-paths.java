class Solution {
    private int helper(int i, int j, int dp[][]){
        if(i == 0 && j == 0){
            return 1;
        } else if(i < 0 || j < 0){
            return 0;
        } else if(dp[i][j] != 0){
            return dp[i][j];
        } else{
            int up = helper(i - 1, j, dp);
            int lt = helper(i, j - 1, dp);
            return dp[i][j] = up + lt;
        }
    }
    public int uniquePaths(int m, int n) {
        int dp[][] = new int[m][n];
        for(int i = 0; i < m; i++){
            dp[i][0] = 1;
        }
        for(int j = 0; j < n; j++){
            dp[0][j] = 1;
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
}