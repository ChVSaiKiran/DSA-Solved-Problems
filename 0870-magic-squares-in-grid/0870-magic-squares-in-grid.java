class Solution {
    private int f(int[][] grid, int x, int y){
        int temp[] = new int[9], d1 = 0, d2 = 0, cnt = 0;
        int row[] = new int[3], col[] = new int[3];
        for(int i = x; i < x + 3; i++){
            for(int j = y; j < y + 3; j++){
                if(grid[i][j] >= 1 && grid[i][j] <= 9){
                    temp[grid[i][j] - 1]++;
                    if(cnt == 0 || cnt == 8){
                        d1 += grid[i][j];
                    }
                    if(cnt == 2 || cnt == 6){
                        d2 += grid[i][j];
                    }
                    row[i - x] += grid[i][j];
                    col[j - y] += grid[i][j];
                } else{
                    return 0;
                }
                cnt++;
            }
        }

        if(d1 != d2){
            return 0;
        }

        if((row[0] != row[1]) || (row[0] != row[2])){
            return 0;
        }

        if((col[0] != col[1]) || (col[0] != col[2])){
            return 0;
        }

        for(int i : temp) if(i != 1) return 0;

        return 1;
    }
    public int numMagicSquaresInside(int[][] grid) {
        int n = grid.length, m = grid[0].length, ans = 0;
        for(int i = 0; i <= n - 3; i++){
            for(int j = 0; j <= m - 3; j++){
                ans += f(grid, i, j);
            }
        }
        return ans;
    }
}