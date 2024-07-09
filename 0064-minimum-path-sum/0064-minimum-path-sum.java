class Solution {
    public int minPathSum(int[][] grid) {
        int n = grid.length, m = grid[0].length;
        int prev[] = new int[m];
        for(int i = 0; i < n; i++){
            int curr[] = new int[m];
            for(int j = 0; j < m; j++){
                if(i == 0 && j == 0){
                    curr[j] = grid[0][0];
                } else{
                    int up = (i < 1) ? Integer.MAX_VALUE : prev[j];
                    int lt = (j < 1) ? Integer.MAX_VALUE : curr[j - 1];
                    curr[j] = Math.min(up, lt) + grid[i][j];
                }
            }
            prev = curr;
        }
        return prev[m - 1];
    }
}