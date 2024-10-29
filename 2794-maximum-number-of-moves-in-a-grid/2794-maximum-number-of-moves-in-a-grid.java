class Solution {
    private int f(int[][] grid, int dp[][], int n, int m, int r, int c){
        if(dp[r][c] != -1){
            return dp[r][c];
        }
        int x = 0, y = 0, z = 0;
        if(c + 1 < m){
            if(r < n && grid[r][c] < grid[r][c + 1])
                x = 1 + f(grid, dp, n, m, r, c + 1);
            if(r - 1 >= 0 && grid[r][c] < grid[r - 1][c + 1])
                y = 1 + f(grid, dp, n, m, r - 1, c + 1);
            if(r + 1 < n && grid[r][c] < grid[r + 1][c + 1])
                z = 1 + f(grid, dp, n, m, r + 1, c + 1);
        }
        return dp[r][c] = Math.max(x, Math.max(y, z));
    }
    public int maxMoves(int[][] grid) {
        int n = grid.length, m = grid[0].length, ans = 0;
        int dp[][] = new int[n][m];
        for(int row[] : dp){
            Arrays.fill(row, -1);
        }
        for(int r = 0; r < n; r++){
            ans = Math.max(ans, f(grid, dp, n, m, r, 0));
        }
        return ans;
    }
}