class Solution {
    private int dfs(int grid[][], boolean vis[][], int delrow[], int delcol[], int r, int c){
        vis[r][c] = true;
        int n = grid.length, m = grid[0].length;
        int cnt = 1;
        for(int i = 0; i < 4; i++){
            int nrow = r + delrow[i];
            int ncol = c + delcol[i];
            if(nrow > -1 && nrow < n && ncol > -1 && ncol < m)
                if(!vis[nrow][ncol] && grid[nrow][ncol] == 1)
                    cnt += dfs(grid, vis, delrow, delcol, nrow, ncol);
        }
        return cnt;
    }
    public int numEnclaves(int[][] grid) {
        int n = grid.length, m = grid[0].length, cnt = 0;
        int delrow[] = {1, 0, -1, 0};
        int delcol[] = {0, 1, 0, -1};
        boolean vis[][] = new boolean[n][m];
        for(int i = 0; i < m; i++){
            if(grid[0][i] == 1 && !vis[0][i])
                dfs(grid, vis, delrow, delcol, 0, i);
            if(grid[n - 1][i] == 1 && !vis[n - 1][i])
                dfs(grid, vis, delrow, delcol, n - 1, i);
        }
        for(int i = 0; i < n; i++){
            if(grid[i][0] == 1 && !vis[i][0])
                dfs(grid, vis, delrow, delcol, i, 0);
            if(grid[i][m - 1] == 1 && !vis[i][m - 1])
                dfs(grid, vis, delrow, delcol, i, m - 1);
        }
        for(int i = 1; i < n; i++)
            for(int j = 1; j < m; j++)
                if(grid[i][j] == 1 && !vis[i][j])
                    cnt += dfs(grid, vis, delrow, delcol, i, j);
        return cnt;
    }
}