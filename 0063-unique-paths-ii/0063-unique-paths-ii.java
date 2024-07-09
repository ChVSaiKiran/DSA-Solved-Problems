class Solution {
    private int fun(int[][] arr, int i, int j, int dp[][]){
        if(i == 0 && j == 0 && arr[i][j] == 0){
            return 1;
        } else if(i < 0 || j < 0 || arr[i][j] == 1){
            return 0;
        } else if (dp[i][j] != -1){
            return dp[i][j];
        } else{
            int up = fun(arr, i - 1, j, dp), left = fun(arr, i, j - 1, dp);
            return dp[i][j] = up + left;
        }
    }
    public int uniquePathsWithObstacles(int[][] arr) {
        if(arr[0][0] == 1)
            return 0;
        int n = arr.length, m = arr[0].length;
        int prev[] = new int[m];
        for(int i = 0; i < n; i++){
            int curr[] = new int[m];
            for(int j = 0; j < m; j++){
                if(i == 0 && j == 0){
                    curr[j] = 1;
                } else if(arr[i][j] == 1){
                    curr[j] = 0;
                } else{
                    int up = (i < 1) ? 0 : prev[j], left = (j < 1) ? 0 : curr[j - 1];
                    curr[j] = up + left;
                }
            }
            prev = curr;
        }
        return prev[m - 1];
    }
}