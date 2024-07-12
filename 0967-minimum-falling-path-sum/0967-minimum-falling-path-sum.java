class Solution {
    private int fun(int[][] matrix, int i, int j, int dp[][]){
        if(j < 0 || j >= matrix[0].length)  return (int)1e8;
        if(i == 0)  return dp[0][j] = matrix[0][j];
        if(dp[i][j] != -1)  return dp[i][j];
        int ld = fun(matrix, i - 1, j - 1, dp);
        int s = fun(matrix, i - 1, j, dp);
        int rd = fun(matrix, i - 1, j + 1, dp);
        return matrix[i][j] + Math.min(s, Math.min(ld, rd));
    }

    public int minFallingPathSum(int[][] matrix) {
        int n = matrix.length, m = matrix[0].length;
        int ans = Integer.MAX_VALUE, prev[] = new int[m];

        for(int j = 0; j < m; j++)
            prev[j] = matrix[0][j];

        for(int i = 1; i < n; i++){
            int curr[] = new int[m];
            for(int j = 0; j < m; j++){
                int ld = matrix[i][j], s = matrix[i][j] + prev[j], rd = matrix[i][j];
                if(j > 0)   ld += prev[j - 1];
                else        ld += 1e8;
                
                if(j + 1 < m)rd += prev[j + 1];
                else        rd += 1e8;
                
                curr[j] = Math.min(s, Math.min(ld, rd));
            }
            prev = curr;
        }
        for(int j = 0; j < m; j++)
            ans = Math.min(ans, prev[j]);
        return ans;
    }
}