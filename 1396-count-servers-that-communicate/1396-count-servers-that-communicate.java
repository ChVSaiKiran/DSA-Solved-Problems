class Solution {
    public int countServers(int[][] grid) {
        int n = grid.length, m = grid[0].length;
        int rows[] = new int[n];
        int cols[] = new int[m];

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    rows[i]++;
                    cols[j]++;
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 && (rows[i] > 1 || cols[j] > 1)){
                    ans++;
                }
            }
        }

        return ans;
    }
}