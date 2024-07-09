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
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int n = obstacleGrid.length, m = obstacleGrid[0].length;
        int dp[][] = new int[n][m];
        for (int[] row : dp) 
            Arrays.fill(row, -1); 
        return fun(obstacleGrid, n - 1, m - 1, dp);
    }
}