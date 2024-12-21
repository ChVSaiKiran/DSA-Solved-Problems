class Solution {
    private int MOD = (int)(1e9 + 7);

    private int fun(int[][] grid, int n, int m, int k, int i, int j, int xr, int dp[][][]){
        if(i == n - 1 && j == m - 1){
            return ((xr ^ grid[i][j]) == k)? 1 : 0;
        }

        if(dp[i][j][xr] != -1){
            return dp[i][j][xr];
        }

        int ans = 0;
        if(i + 1 < n){
            ans += fun(grid, n, m, k, i + 1, j, (xr ^ grid[i][j]), dp);
        }

        if(j + 1 < m){
            ans += fun(grid, n, m, k, i, j + 1, (xr ^ grid[i][j]), dp);
        }

        ans %= MOD;
        return (dp[i][j][xr] = ans);
    }

    public int countPathsWithXorValue(int[][] grid, int k) {
        int n = grid.length, m = grid[0].length;
        int dp[][][] = new int[n][m][16];

        for (int[][] matrix : dp) {
            for(int row[] : matrix){
                Arrays.fill(row, -1);
            }
        }   

        return fun(grid, n, m, k, 0, 0, 0, dp);
    }
}