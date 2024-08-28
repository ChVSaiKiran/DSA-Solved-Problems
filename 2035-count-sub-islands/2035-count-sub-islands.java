class Solution {
    private boolean f(int[][] A, int[][] B, int n, int m, int x, int y, boolean vis[][]){
        vis[x][y] = true;
        
        // Explore all the neighbour in the B
        int delRow[] = {0, -1, 0, 1};
        int delCol[] = {-1, 0, 1, 0};

        // This flag ensures that whether all the neighbour's of the B are exits in A or not
        boolean flag = true;
        for(int i = 0; i < 4; i++){
            int dx = x + delRow[i];
            int dy = y + delCol[i];

            // Check if the neighbour is vaid & Not Visited
            if(dx >= 0 && dy >= 0 && dx < n && dy < m && B[dx][dy] == 1 && !vis[dx][dy]){
                flag = f(A, B, n, m, dx, dy, vis) && flag;
            }
        }

        return (A[x][y] == B[x][y]) && flag;
    }

    public int countSubIslands(int[][] grid1, int[][] grid2) {
        int n = grid1.length, m = grid1[0].length, cnt = 0;
        boolean vis[][] = new boolean[n][m];

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid2[i][j] == 1 && !vis[i][j]){
                    if(f(grid1, grid2, n, m, i, j, vis)){
                        cnt++;
                    }
                }
            }
        }

        return cnt;
    }
}